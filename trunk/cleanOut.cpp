#include "G.h"
void G::ShowOut( s16 no, u8 size )
{
	out_LC->DeleteAllItems();
	s8 col = out_LC->GetColumnCount();
	for ( ; col >= 0; --col )
		{ out_LC->DeleteColumn( col ); }
	if ( IsBetween( no, 0, 255 ) )
	{
		xStr   text, hexC;
		wxListItem item, column;
		wxFile oldDump,     oldByte;
		xStr   oldDumpText, oldByteText;
		xStr   slash     = gGetSlash();
		xStr   path      = wxGetCwd() + slash + wxT( "ram" ) + slash;
		s16    i         = no;
		s16    iCount    = no - 5;
		u32    j         = 0u;
		u32    jNext     = 0u;
		u32    jByte     = 0u;
		u32    jCount    = readSize;
		u32    k         = 0u;
		u8     out       = 0u;
		u8     outCount  = 100u;
		u8*    old8      = new u8[ jCount ];
		u16*   old16     = reinterpret_cast< u16* >( old8 );
		u32*   old32     = reinterpret_cast< u32* >( old8 );
		u64*   old64     = reinterpret_cast< u64* >( old8 );
		bool*  theByte   = new bool[ jCount ];
		oldByteText.Printf( wxT( "byte%02i.bin" ), no );
		oldByte.Open( path + oldByteText );
		u64    address   = 0u;
		u64    nextByte  = 0u;
		wxFileOffset tmp = oldByte.Length();
		if ( tmp >= 0 )
		{
			u64    byteCount = tmp;
			u64    oldValue;
			hexC.Printf( wxT( "%%0%ullX" ), size * 2u );
			if
			(
				iCount < 0 ||
				iCount > i
			)
			{
				iCount = 0;
			}
			item.SetId( 0 );
			item.SetText( wxT( "Address" ) );
			out_LC->InsertColumn( 0, item );
			for
			(
				col = 1;
				i >= iCount;
				--i, ++col
			)
			{
				// Add Column
				text.Printf( wxT( "Value %i" ), col );
				item.SetColumn( col  );
				column.SetId(   col  );
				column.SetText( text );
				out_LC->InsertColumn( col, column );
				// Open File
				text.Printf( wxT( "dump%02u.bin" ), i );
				oldDump.Open( path + text );
				oldByte.Seek( 0u, wxFromStart );
				nextByte = 0u;
				out      = 0u;
				for
				(
					address = 0u, j = jCount;
					( address < byteCount && out < outCount );
					++address, ++j
				)
				{
					if ( j == jCount )
					{
						jByte += jCount;
						if ( jByte > byteCount )
						{
							jByte -= jCount;
							jCount = byteCount - jByte;
							jByte += jCount;
						}
						oldDump.Read( old8,    jCount );
						oldByte.Read( theByte, jCount );
						j     = 0u;
						jNext = 0u;
						k     = 0u;
					}
					if ( j == jNext )
					{
						if ( theByte[ j ] )
						{
							switch ( size )
							{
								case 2u:
									oldValue = old16[ k ];
									break;
								case 4u:
									oldValue = old32[ k ];
									break;
								case 8u:
									oldValue = old64[ k ];
									break;
								default:
									oldValue = old8[ k ];
							}
							item.SetId( out );
							if ( col == 1 )
							{
								text.Printf( hex64, address );
								item.SetColumn( 0  );
								item.SetText( text );
								out_LC->InsertItem( item );
								item.SetColumn( 1  );
							}
							text.Printf( hexC, oldValue );
							item.SetText( text );
							out_LC->SetItem( item );
							++out;
						}
						jNext += size;
						++k;
					}
				}
				oldDump.Close();
			}
			oldByte.Close();
		}
		delete [] old8;
		delete [] theByte;
	}
}
