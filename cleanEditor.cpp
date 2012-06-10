#include "G.h"
void G::FillEditor( void )
{
	SetTime();
	if ( isEdit ) return;
	NewHook();
	edit_G->Freeze();
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
	u16* ram16   = reinterpret_cast< u16* >( ram8 );
	if ( hookApp )
	{
		GetRamX( appHandle, ramStart + byte, ram8, useSize );
	}
	else
	{
		bin_BF.Seek( ramStart + byte, wxFromStart );
		bin_BF.Read( ram8, useSize );
	}
	wxChar cAscii;
	xStr   sAscii;
	xStr   cUnicode;
	xStr   sUnicode;
	xStr   text;
	bool getUnicode = false;
	u32 i = 0u, i16 = 0u, row = 0u, col = 0u;
	u32 rowMax   = edit_G->GetRows();
	u32 rowCount = 0x30;
	if ( rowCount > rowMax ) edit_G->AppendRows( rowCount - rowMax, false );
	else if ( rowCount < rowMax ) edit_G->DeleteRows( rowCount - 1, rowMax - rowCount, false );
	for ( ; ( row < rowCount && byte < divByte && i < useSize ); ++row )
	{
		text.Printf( hex64, byte + i );
		edit_G->SetRowLabelValue( row, text );
		sAscii.Clear();
		sUnicode.Clear();
		for ( col = 0u; ( col < 16u && i < useSize ); ++col, ++i )
		{
			cAscii = ram8[ i ];
			sAscii += cAscii;
			getUnicode = false;
			if ( getUnicode )
			{
				cUnicode.FromUTF8( reinterpret_cast< char* >( &ram16[ i16 ] ) );
				sUnicode  += cUnicode;
				getUnicode = false;
				++i16;
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
	--editIsRecursing;
	edit_G->Thaw();
}
void G::edit_GOnPaint( wxPaintEvent& event )
{
	s32 row = edit_G->GetGridCursorRow();
	s32 col = edit_G->GetGridCursorCol();
	edit_G->ClearSelection();
	edit_G->SetGridCursor( row, col );
	event.Skip();
}
