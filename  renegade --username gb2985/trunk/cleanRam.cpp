#include "G.h"
RAM  G::mGetRam( void )
{
	RAM  ram;
	xStr text;
	ram.name     = ramName_TXT->GetValue();
	ram.ptrDepth = ramPtr_SN->GetValue();
	ram.byte     = GetHex( ramByte_TXT->GetValue() );
	ram.size     = GetHex( ramSize_TXT->GetValue() );
	return ram;
}
u64  G::mGetRamByte( s8 index )
{
	u64 byte = 0u;
	BIN bin  = gGetBin();
	if ( index >= 0 && index < bin.GetCount() )
	{
		RAM ram      = bin[ index ];
		byte         = ram.byte;
		u64 nextByte = 0u;
		u8  ptrDepth = ram.ptrDepth;
		if ( hookApp )
		{
			for ( u8 i = 0u; i < ptrDepth; ++i )
			{
				GetRamX( appHandle, byte, &nextByte, 4u );
				if ( nextByte < byte )
				{
					GetRamX( appHandle, byte, &nextByte, 8u );
				}
				byte = nextByte;
			}
		}
		else
		{
			for ( u8 i = 0u; i < ptrDepth; ++i )
			{
				bin_BF.Seek( byte, wxFromStart );
				bin_BF.Read( &nextByte, 4u );
				if ( nextByte < byte )
				{
					bin_BF.Read( &nextByte, 8u );
				}
				byte = nextByte;
			}
			bin_BF.Seek( 0u );
		}
	}
	return byte;
}
u64  G::mGetRamSize( s8 index )
{
	u64 size    = 0u;
	u64 binSize = 0u;
	if ( hookApp )
	{
		GetAppSize( appHandle, binSize );
	}
	else
	{
		binSize = bin_BF.Length();
	}
	if ( index >= 0 )
	{
		RAM ram = gGetBin()[ index ];
		size    = ram.size;
	}
	    size    = ( size == 0u || size > binSize ) ? binSize : size;
	return size;
}
void G::mShowRam( void )
{
	xStr text;
	BIN bin  = gGetBin();
	s8 index = ramName_D->GetSelection();
	RAM  ram = bin[ index ];
	ramName_TXT->ChangeValue( ram.name );
	ramPtr_SN->SetValue( ram.ptrDepth );
	text.Printf( hexVLL, ram.byte );
	ramByte_TXT->ChangeValue( text );
	text.Printf( hexVLL, ram.size );
	ramSize_TXT->ChangeValue( text );
}
void G::NewRam_BOnClick( wxCommandEvent& event )
{
	BIN  bin = gGetBin();
	RAM  ram = mGetRam();
	s8 index = bin.Append( ram );
	gSetBin( bin );
	mShowBin();
	ramName_D->Select( index );
	mShowRam();
}
void G::SetRam_BOnClick( wxCommandEvent& event )
{
	BIN  bin = gGetBin();
	RAM  ram = mGetRam();
	s8 index = ramName_D->GetSelection();
	bin[ index ] = ram;
	ramName_D->SetString( index, ram.name );
	ramName_D->Select( index );
	gSetBin( bin );
}
void G::ramName_DOnChoice( wxCommandEvent& event )
{
	mShowRam();
}
