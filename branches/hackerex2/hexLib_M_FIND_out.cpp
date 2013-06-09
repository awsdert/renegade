#include "wx_pch.h"
#include "hexLib_main.h"
void M_FIND::out( ui64 addr, ui08 rows )
{
	BinF file;
	wxGrid *grid = out__g;
	Text text, path;
	ui32 bytes = ( rows * m_oSize );
	ui08* data = new ui08[ bytes ], rCount = grid->GetNumberRows();
	if ( rCount < rows )
		grid->AppendRows( rows - rCount, false );
	else if ( rCount > rows )
		grid->DeleteRows( 0, rCount - rows, false );
	ui64 a = addr;
	zxInt val;
	int q = m_cmp, qEnd = q - 0x12, c = 0, r, rEnd = rows;
	if ( qEnd < 0 )
		qEnd = 0;
	for ( r = 0; r < rEnd; ++r, a += m_oSize )
	{
		text.Printf( wxT("%016llX"), a );
		grid->SetRowLabelValue( r, text );
	}
	for ( ; q >= qEnd; --q, ++c )
	{
		text.Printf( wxT("S: %i"), q );
		grid->SetColLabelValue( c, text );
		text.Printf( wxT("%03i.bin"), q );
		path = m_lib->getTmpWd() + wxT("search") + xsDirSep + text;
		if ( !wxFileExists( path ) )
		{
			text.Clear();
			for ( r = 0; r < rEnd; ++r )
				grid->SetCellValue( r, c, text );
			continue;
		}
		file.Open( path );
		file.Seek( addr, wxFromStart );
		file.Read( data, bytes );
		for ( r = 0; r < rEnd; ++r )
		{
			val.setPtr( &data[ r * m_oSize ], m_oSize );
			text = val.toString().data();
			grid->SetCellValue( r, c, text );
		}
		file.Close();
	}
	delete [] data;
}