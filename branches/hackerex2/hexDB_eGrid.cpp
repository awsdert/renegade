#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::eGrid( ui08 rows )
{
	Text txt;
	wxGrid* grid = m_eGrid;
	ui08 rEnd = grid->GetNumberRows(), cEnd = grid->GetNumberCols();
	bool scroll = false;
	ui64 addr = m_eGridAddr;
	if ( rows < rEnd )
	{
		scroll = true;
		grid->DeleteRows( rows, rEnd - rows, false );
	}
	else if ( rows > rEnd )
	{
		scroll = true;
		grid->AppendRows( rows - rEnd, false );
	}
	if ( cEnd > 0x12 )
	{
		scroll = true;
		grid->DeleteCols( 0x12, cEnd - 0x12, false );
	}
	else if ( cEnd < 0x12 )
	{
		scroll = true;
		grid->AppendCols( 0x12 - cEnd, false );
	}
	ui08 r = 0u, c = 0u;
	if ( scroll )
	{
		grid->SetRowLabelSize( 120 );
		for ( ; c < 0x10; ++c )
		{
			txt.Printf( wxT("%X"), c );
			grid->SetColSize( c, 20 );
			grid->SetColLabelValue( c, txt );
		}
		grid->SetColSize( 0x10, 150 );
		grid->SetColSize( 0x11, 150 );
		grid->SetColLabelValue( 0x10, wxT("Ascii") );
		grid->SetColLabelValue( 0x11, wxT("UTF-8") );
		grid->Scroll( eXVH, eYVH );
	}
	txt.Printf( wxT("%016llX"), addr );
	m_eGridTB->ChangeValue( txt );
	for ( ; r < rows; ++r, addr += 0x10 )
	{
		txt.Printf( wxT("%016llX"), addr );
		grid->SetRowLabelValue( r, txt );
		for ( c = 0u; c < 0x12; ++c )
			grid->SetCellValue( r, c, wxT("") );
	}
}
void hexDB::eGrid( ui08 rows, ui64 addr, ui08* data, ui16 bytes )
{
	m_eGridAddr = addr;
	wxGrid* grid = m_eGrid;
	eGrid( rows );
	Text txt;
	ui08 r = 0u, c, a;
	ui16 i = 0u, iNext = 0u, iAdd = sizeof( char ), w = 0u;
	char aTxt[ 0x10 ], *aData = reinterpret_cast< char* >( data );
	for ( ; r < rows; ++r )
	{
		a = 0u;
		for ( c = 0u; ( c < 0x10 && i < bytes ); ++c, ++i )
		{
			txt.Printf( wxT("%01X"), data[ i ] );
			grid->SetCellValue( r, c, txt );
			if ( i == iNext )
			{
				aTxt[ a ] = aData[ w ];
				++w; ++a; iNext += iAdd;
			}
		}
		grid->SetCellValue( r, 0x10, txt.FromAscii( &( aTxt[ 0 ] ) ) );
		grid->SetCellValue( r, 0x11, txt.FromUTF8( &( aTxt[ 0 ] ) ) );
	}
}