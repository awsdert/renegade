#include "wx_pch.h"
#include "hexLib_main.h"
#include "hexLib_app.h"
#include "hexLib_gui.h"

bool M_FIND::eJump( void )
{
	Bin* now = (Bin*)m_lib->m_now;
	zxProc proc;
	if ( !proc.zxNewHandle( now->bind.data() ) )
	{
		wxMessageBox( m_lang->text[ m_lang->txt_failedtoloadappfile ], m_lang->text[ m_lang->txt_error ] );
		return false;
	}
	ui32 rMax  = ( m_eRows * 0x10 );
	Ram  ram = now->at( now->ramNo );
	ui64 rFull = ram.bytes, addr = (ram.addr + eAddr);
	ui32 i = 0u, bytes = ( rFull > rMax ) ? rMax : rFull;
	ui32 aBytes = sizeof( size_t );
	for ( ui08 d = 0u; d < ram.depth; ++d )
	{
		if ( proc.zxGetMemory( addr, &addr, aBytes ) != aBytes )
		{
			wxMessageBox( m_lang->text[ m_lang->txt_failedtoreadmemory ], m_lang->text[ m_lang->txt_error ] );
			return false;
		}
	}
	ui08 *data = new ui08[ bytes ];
	i = proc.zxGetMemory( addr, data, bytes );
	if ( i != bytes )
	{
		for ( ; i < bytes; ++i )
			data[ i ] = 0u;
	}
	proc.zxDelHandle();
	eUpdate( data, bytes );
	delete data;
	return true;
}
void M_FIND::eJump2( ui64 addr )
{
	while ( addr & 0xFLL ) --addr;
	while ( addr & 0xF0LL ) addr -= 0x10LL;
	if ( addr > 0uLL && addr >= 0x100LL ) addr -= 0x100LL;
	eAddr = addr;
	if ( !isAuto )
	{
		if ( wait == 0 )
			eJump();
		else
			m_gui->NewEditThread();
	}
}
void M_FIND::eScroll( int dir, bool isGridSrc, bool isWheelSrc )
{
	if ( isEShown )
	{
		int x = 0, y = 0, rw = 0, rh = 0, vw = 0, vh = 0;
		edit_g->CalcUnscrolledPosition( 0, 0, &x, &y );
		if ( x == iXVH )
		{
			edit_g->GetSize( &rw, &rh );
			edit_g->GetVirtualSize( &vw, &vh );
			if ( isWheelSrc )
				dir = ( !isGridSrc || vh == rh || y == iYVH ) ? dir : 0;
			if ( dir > 0 )
			{
				if ( ( !isGridSrc || isUpLast ) && eAddr > 0xFFuLL )
					eAddr -= 0x100LL;
				isUpLast = ( isGridSrc ) ? true : isUpLast;
			}
			else if ( dir < 0 )
			{
				if ( ( !isGridSrc || !isUpLast ) && eAddr < 0xFFFFFFFFFFFFFF00LL )
					eAddr += 0x100LL;
				isUpLast = ( isGridSrc ) ? false : isUpLast;
			}
			if ( !isAuto )
				eJump();
		}
		iXVH = x;
		iYVH = y;
	}
}
void M_FIND::eUpdate( ui08* data, ui16 bytes )
{
	Text txt;
	size_t i = 0;
	ui08 col = 0u;
	bool bt, sb = false;
	char a[ 0x11 ] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0 };
	int r = m_eRows, rEnd = edit_g->GetNumberRows(), c = 0x12, cEnd = edit_g->GetNumberCols();
	bt = ( r < rEnd );
	sb = bt;
	if ( bt )
		edit_g->DeleteRows( r, rEnd - r, false );
	bt = ( r > rEnd );
	sb = ( sb || bt );
	if ( bt )
		edit_g->AppendRows( r - rEnd, false );
	bt = ( c < cEnd );
	sb = ( sb || bt );
	if ( bt )
		edit_g->DeleteCols( c, cEnd - c, false );
	bt = ( c > cEnd );
	sb = ( sb || bt );
	if ( bt )
		edit_g->AppendRows( c - cEnd, false );
	if ( sb )
	{
		edit_g->Scroll( iXVH, iYVH );
		isUpLast = true;
	}
	rEnd = r;
	cEnd = c - 2u;
	int s = ( edit_g->GetColLabelSize() * 2 ) + 2;
	for ( c = 0; c < cEnd; ++c, ++col )
	{
		txt.Printf( wxT( "%01X" ), col );
		edit_g->SetColLabelValue( c, txt );
		edit_g->SetColumnWidth( c, s );
	}
	edit_g->SetColLabelValue( 0x10, wxT("Ascii") );
	edit_g->SetColLabelValue( 0x11, wxT("UTF8") );
	ui08 B = 0u;
	ui64 addr = eAddr;
	if ( sync_rl->GetSelection() == 0 && !addr_txt->HasCapture() )
	{
		txt.Printf( wxT( "%llX" ), addr );
		addr_txt->ChangeValue( txt );
	}
	Bin* bin = (Bin*)m_lib->m_now;
	ui64 rFull = bin->at( bin->ramNo ).bytes;
	edit_g->SetRowLabelSize( 150 );
	for ( r = 0; r < rEnd; ++r )
	{
		txt.Printf( wxT( "%016llX" ), addr );
		edit_g->SetRowLabelValue( r, txt );
		for ( c = 0; c < cEnd; ++c, ++i, ++addr )
		{
			B = ( addr < rFull && i < bytes ) ? data[ i ] : 0u;
			a[ c ] = B;
			txt.Printf( wxT( "%02X" ), B );
			edit_g->SetCellValue( r, c, txt );
		}
		edit_g->SetCellValue( r, 0x10, txt.FromAscii( a ) );
		edit_g->SetCellValue( r, 0x10, txt.FromUTF8( a ) );
	}
}