#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
bool M_FIND::jump( void )
{
	osHdl hApp = NewAppHandle( db->bin.name + osDotExe );
	ui32 rMax  = ( rows * 0x10 );
	Ram  ram = db->bin[ db->bin.ramNo ];
	ui64 rFull = ram.bytes, addr = (ram.addr + nAddr);
	ui32 i = 0u, bytes = ( rFull > rMax ) ? rMax : rFull;
	ui32 aBytes = sizeof( size_t );
	for ( ui08 d = 0u; d < ram.depth; ++d )
	{
		if ( GetAppRam( hApp, addr, &addr, aBytes ) != aBytes )
		{
			wxMessageBox( wxT("Could not get ram pointer, Action cancelled" ) );
			return false;
		}
	}
	ui08 *data = new ui08[ bytes ];
	i = GetAppRam( hApp, addr, data, bytes );
	if ( i != bytes )
	{
		for ( ; i < bytes; ++i )
			data[ i ] = 0u;
	}
	DelAppHandle( hApp );
	update( data, bytes );
	delete data;
	return true;
}
void M_EGRID::jump2( ui64 addr )
{
	while ( addr & 0xFLL ) --addr;
	while ( addr & 0xF0LL ) addr -= 0x10LL;
	if ( addr > 0uLL && addr >= 0x100LL ) addr -= 0x100LL;
	nAddr = addr;
	if ( !isAuto )
	{
		if ( wait == 0 )
			jump();
		else
			gui->NewEditThread();
	}
}
void M_EGRID::scroll( int dir, bool isGridSrc, bool isWheelSrc )
{
	if ( isShown )
	{
		int x = 0, y = 0, rw = 0, rh = 0, vw = 0, vh = 0;
		grid_g->CalcUnscrolledPosition( 0, 0, &x, &y );
		if ( x == iXVH )
		{
			grid_g->GetSize( &rw, &rh );
			grid_g->GetVirtualSize( &vw, &vh );
			if ( isWheelSrc )
				dir = ( !isGridSrc || vh == rh || y == iYVH ) ? dir : 0;
			if ( dir > 0 )
			{
				if ( ( !isGridSrc || isUpLast ) && nAddr > 0xFFuLL )
					nAddr -= 0x100LL;
				isUpLast = ( isGridSrc ) ? true : isUpLast;
			}
			else if ( dir < 0 )
			{
				if ( ( !isGridSrc || !isUpLast ) && nAddr < 0xFFFFFFFFFFFFFF00LL )
					nAddr += 0x100LL;
				isUpLast = ( isGridSrc ) ? false : isUpLast;
			}
			if ( !isAuto )
				jump();
		}
		iXVH = x;
		iYVH = y;
	}
}
void M_EGRID::update( ui08* data, size_t bytes )
{
	Text txt;
	size_t i = 0;
	ui08 col = 0u;
	bool bt, sb = false;
	char a[ 0x11 ] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0 };
	int r = rows, rEnd = grid_g->GetNumberRows(), c = 0x12, cEnd = grid_g->GetNumberCols();
	bt = ( r < rEnd );
	sb = bt;
	if ( bt ) grid_g->DeleteRows( r, rEnd - r, false );
	bt = ( r > rEnd );
	sb = ( sb || bt );
	if ( bt ) grid_g->AppendRows( r - rEnd, false );
	bt = ( c < cEnd );
	sb = ( sb || bt );
	if ( bt ) grid_g->DeleteCols( c, cEnd - c, false );
	bt = ( c > cEnd );
	sb = ( sb || bt );
	if ( bt ) grid_g->AppendRows( c - cEnd, false );
	if ( sb )
	{
		grid_g->Scroll( iXVH, iYVH );
		isUpLast = true;
	}
	rEnd = r;
	cEnd = c - 2u;
	int s = ( grid_g->GetColLabelSize() * 2 ) + 2;
	for ( c = 0; c < cEnd; ++c, ++col )
	{
		txt.Printf( wxT( "%01X" ), col );
		grid_g->SetColLabelValue( c, txt );
		grid_g->SetColumnWidth( c, s );
	}
	grid_g->SetColLabelValue( 0x10, wxT("Ascii") );
	grid_g->SetColLabelValue( 0x11, wxT("UTF8") );
	ui08 B = 0u;
	ui64 addr = nAddr;
	if ( sync_rl->GetSelection() == 0 && !a_txt->HasCapture() )
	{
		txt.Printf( wxT( "%01llX" ), addr );
		a_txt->ChangeValue( txt );
	}
	ui64 rFull = db->bin[ db->bin.ramNo ].bytes;
	grid_g->SetRowLabelSize( 150 );
	for ( r = 0; r < rEnd; ++r )
	{
		txt.Printf( wxT( "%016llX" ), addr );
		grid_g->SetRowLabelValue( r, txt );
		for ( c = 0; c < cEnd; ++c, ++i, ++addr )
		{
			B = ( addr < rFull && i < bytes ) ? data[ i ] : 0u;
			a[ c ] = B;
			txt.Printf( wxT( "%02X" ), B );
			grid_g->SetCellValue( r, c, txt );
		}
		grid_g->SetCellValue( r, 0x10, txt.FromAscii( a ) );
		grid_g->SetCellValue( r, 0x10, txt.FromUTF8( a ) );
	}
}