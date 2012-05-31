#include "G.h"
void G::FillEditor( void )
{
	SetTime();
	if ( isEdit ) return;
	NewHook();
	++editIsRecursing;
	s8  ramNo = editRam_D->GetSelection();
	u64 ramStart = 0u;
	u64 ramEnd   = 0u;
	u32 useSize  = mGetRam( ramStart, ramEnd, ramNo );
	if ( useSize == 0u ) return;
	u64 byte     = GetHex( editGet_TXT->GetValue() );
	if ( byte > 0u )
	{
		while ( ( byte % 0x10  ) > 0 ) byte--;
		while ( ( byte % 0x100 ) > 0 ) byte -= 0x10;
	}
	u32  divByte = byte + 0x100;
	u8*  ram8    = new u8[ useSize ];
	if ( hookApp )
	{
		GetRamX( appHandle, ramStart + byte, ram8, useSize );
	}
	else
	{
		bin_BF.Seek( ramStart + byte, wxFromStart );
		bin_BF.Read( ram8, useSize );
	}
	u16    c;
	wxChar cAscii;
	xStr   sAscii;
	wxChar cUnicode;
	xStr   sUnicode;
	xStr   text;
	bool getUnicode = false;
	edit_G->DeleteRows( 0, edit_G->GetRows(), false );
	u32 i = 0u, row = 0u, col = 0u;
	for ( ; ( row < 0x30 && byte < divByte && i < useSize ); ++row )
	{
		edit_G->AppendRows( 1, false );
		text.Printf( hex64, byte + i );
		edit_G->SetRowLabelValue( row, text );
		sAscii.Clear();
		sUnicode.Clear();
		for ( col = 0u; ( col < 16u && i < useSize ); ++col, ++i )
		{
			cAscii  = ram8[ i ];
			sAscii += cAscii;
			getUnicode = false;
			if ( getUnicode )
			{
				c   = ram8[ i - 1 ];
				c <<= 8u;
				c  += ram8[ i ];
				cUnicode   = c;
				sUnicode  += cUnicode;
				getUnicode = false;
			}
			else getUnicode = true;
			text.Printf( hex8, ram8[ i ] );
			edit_G->SetCellValue( row, col, text );
		}
		edit_G->SetCellValue( row, 16, sAscii );
		edit_G->SetCellValue( row, 17, sUnicode );
	}
	delete [] ram8;
	DelHook();
	if ( isFocus ) edit_G->SelectBlock( editRow, editCol, editRow, editCol, false );
	--editIsRecursing;
}
