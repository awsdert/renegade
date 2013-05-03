#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
void M_OGRID::out( ui64 addr, ui08 rows )
{
	BinF file;
	Text text, path;
	ui32 bytes = ( rows * vSize );
	ui08* data = new ui08[ bytes ], rCount = grid_g->GetNumberRows();
	if ( rCount < rows )
		grid_g->AppendRows( rows - rCount, false );
	else if ( rCount > rows )
		grid_g->DeleteRows( 0, rCount - rows, false );
	ui64 a = addr;
	int q = qNo, qEnd = q - 0x12, c = 0, r, rEnd = rows;
	if ( qEnd < 0 )
		qEnd = 0;
	for ( r = 0; r < rEnd; ++r, a += vSize )
	{
		text.Printf( wxT("%016llX"), a );
		grid_g->SetRowLabelValue( r, text );
	}
	for ( ; q >= qEnd; --q, ++c )
	{
		text.Printf( wxT("S: %i"), q );
		grid_g->SetColLabelValue( c, text );
		text.Printf( wxT("%03i.bin"), q );
		path = db->wd + wxT("search") + xsDirSep + text;
		if ( !wxFileExists( path ) )
		{
			text.Clear();
			for ( r = 0; r < rEnd; ++r )
				grid_g->SetCellValue( r, c, text );
			continue;
		}
		file.Open( path );
		file.Seek( addr, wxFromStart );
		file.Read( data, bytes );
		for ( r = 0; r < rEnd; ++r )
		{
			GetTxt( text, &( data[ r * vSize ] ), vSize, vType );
			grid_g->SetCellValue( r, c, text );
		}
		file.Close();
	}
	delete [] data;
}