#include "G.h"
void G::UseHook( void )
{
	xTreeID root = GetHackRoot();
	if ( root.IsOk() )
	{
		SetTime();
		s32 endian = mGetPFMEndian();
		s32 i = 0;
		for ( ; i < 16; ++i )
		{
			hookArray[ i ] = mGetRamByte( i );
		}
		u64 flipped;
		OUTDATA data;
		NewHook();
		if ( isHooked < 1 ) return;
		s32 iCount = mOutArray.size();
		for ( i = 0; i < iCount; ++i )
		{
			data = mOutArray[ i ];
			GetAddress( data.address, flipped, data.size, endian );
			SetRamX( appHandle, flipped, &data.value, data.size  );
		}
		UseHook( root, endian );
		DelHook();
	}
}
void G::UseHook( xTreeID root, s32 endian, s8 cIndex, s8 cCount )
{
	HACK* hack   = mGetHack( root );
	if ( hack->use )
	{
		CODE code;
		u64  value;
		bool tBool;
		bool recurse = false;
		u8   v, vCount;
		u8   i, iCount;
		u64  address, fliped, ptr, pInc;
		s8   p, pCount;
		if ( cCount < 1 )
		{
			recurse = true;
			cCount = hack->GetCount();
		}
		for ( ; cIndex < cCount; ++cIndex )
		{
			code    = ( *hack )[ cIndex ];
			value   = code[ 0 ];
			p       = 0;
			pCount  = code.ptrDepth;
			pInc    = code.increment * code.size;
			v       = 0u;
			vCount  = code.loop;
			address = hookArray[ code.ram ] + code.byte;
			GetAddress( address, fliped, code.size, endian );
			ptr     = fliped;
			if ( hookApp )
			{
				for ( ; p < pCount; ++p )
				{
					fliped = ptr;
					GetRamX( appHandle, fliped, &ptr, 4u );
				}
			}
			else
			{
				for ( ; p < pCount; ++p )
				{
					fliped = ptr;
					bin_BF.Seek( fliped, wxFromStart );
					bin_BF.Read( &ptr, 4u );
				}
			}
			switch ( code.type )
			{
				case CT_WRITE:
					if ( hookApp )
					{
						do
						{
							SetRamX( appHandle, ptr, &value, code.size );
							ptr   += pInc;
							value += code.slide;
							++v;
						} while ( v < vCount );
					}
					else
					{
						do {
							bin_BF.Seek( ptr, wxFromStart  );
							bin_BF.Write( &value, code.size );
							ptr   += pInc;
							value += code.slide;
							++v;
						} while ( v < vCount );
					}
					break;
				case CT_COPY:
					address = ptr + value;
/*
	If feedback indicates this is required then this will
	be used via the code.test value.
/
					GetAddress( address, fliped, code.size, endian );
					address = fliped;
					if ( hookApp )
					{
						for ( ; p < pCount; ++p )
						{
							fliped = address;
							GetRamX( appHandle, fliped, &address, 4u );
						}
					}
					else
					{
						for ( ; p < pCount; ++p )
						{
							fliped = address;
							bin_BF.Seek( fliped, wxFromStart );
							bin_BF.Read( &address, 4u        );
						}
					}
//*/
					if ( hookApp )
					{
						do {
							GetRamX( appHandle, ptr,     &value, code.size );
							SetRamX( appHandle, address, &value, code.size );
							ptr     += pInc;
							address += pInc;
							++v;
						} while ( v < vCount );
					}
					else
					{
						do {
							bin_BF.Seek( ptr,     wxFromStart  );
							bin_BF.Read( &value,  code.size    );
							bin_BF.Seek( address, wxFromStart  );
							bin_BF.Write( &value,  code.size    );
							ptr     += pInc;
							address += pInc;
							++v;
						} while ( v < vCount );
					}
					break;
				case CT_INCREMENT:
					if ( hookApp )
					{
						do
						{
							GetRamX( appHandle, ptr, &value, code.size );
							value   += code.slide;
							SetRamX( appHandle, ptr, &value, code.size );
							ptr     += pInc;
							++v;
						} while ( v < vCount );
					}
					else
					{
						do
						{
							bin_BF.Seek( ptr,    wxFromStart  );
							bin_BF.Read( &value, code.size    );
							value   += code.slide;
							bin_BF.Write( &value, code.size    );
							ptr     += pInc;
							++v;
						} while ( v < vCount );
					}
					break;
				case CT_DECREMENT:
					if ( hookApp )
					{
						do
						{
							GetRamX( appHandle, ptr, &value, code.size );
							value   -= code.slide;
							SetRamX( appHandle, ptr, &value, code.size );
							ptr     += pInc;
							++v;
						} while ( v < vCount );
					}
					else
					{
						do
						{
							bin_BF.Seek(  ptr,     wxFromStart  );
							bin_BF.Read(  &value,  code.size    );
							value   -= code.slide;
							bin_BF.Write( &value,  code.size    );
							ptr     += pInc;
							++v;
						} while ( v < vCount );
					}
					break;
				case CT_TEST:
					{
						value = 0u;
						if ( hookApp ) GetRamX( appHandle, ptr, &value, code.size );
						else
						{
							bin_BF.Seek( ptr, wxFromStart );
							bin_BF.Read( &value, code.size );
						}
						switch ( code.test )
						{
							case gTGot:
								tBool = ( ( value & code[ 0 ] ) >  0u ); break;
							case gTNotG:
								tBool = ( ( value & code[ 0 ] ) == 0u ); break;
							case gTEqual: tBool = ( value == code[ 0 ] ); break;
							case gTNotE:  tBool = ( value != code[ 0 ] ); break;
							case gTMoreT: tBool = ( value >  code[ 0 ] ); break;
							case gTMoreE: tBool = ( value >= code[ 0 ] ); break;
							case gTLessT: tBool = ( value <  code[ 0 ] ); break;
							case gTLessE: tBool = ( value <= code[ 0 ] ); break;
							default: tBool = false;
						}
						if ( tBool )
						{
							if ( code.loop > 0u )
							{
								cIndex += code.loop;
								UseHook( root, endian, cIndex, cIndex + code.loop );
							}
						}
						else
						{
							if ( code.loop > 0u ) cIndex += code.loop;
							else cIndex = cCount;
							recurse = false;
						}
					}
					break;
				case CT_LIST:
					iCount = code.test;
					if ( hookApp )
					{
						do
						{
							address = ptr;
							for ( i = 0u; i < iCount; ++i )
							{
								SetRamX( appHandle, address, &code[ i ], code.size );
								address += code.size;
							}
							ptr += pInc;
							++v;
						} while ( v < vCount );
					}
					else
					{
						do
						{
							bin_BF.Seek( ptr, wxFromStart );
							for ( i = 0u; i < iCount; ++i )
							{
								bin_BF.Write( &code[ i ], code.size );
								bin_BF.Seek( code.size, wxFromCurrent );
							}
							ptr += pInc;
							++v;
						} while ( v < vCount );
					}
					break;
				default:
					cIndex  = cCount;
					recurse = false;
			}
		}
		if ( recurse )
		{
			xTreeID  kid;
			xTreeIDV kidv;
			for
			(
				kid = tree_T->GetFirstChild( root, kidv );
				kid.IsOk();
				kid = tree_T->GetNextChild( root, kidv )
			)
			{
				UseHook( kid, endian );
			}
		}
	}
}
