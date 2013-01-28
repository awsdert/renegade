#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
void hexDB::eGrid_Connect( wxGrid* grid, wxChoice* hook, wxSpinButton* spin, wxTextCtrl* gridTB, wxTextCtrl* addr, wxTextCtrl* value, wxButton* jump, wxButton* read, wxButton* write )
{
	m_eGrid = grid;
	m_eJump	= jump;
	m_eGet	= read;
	m_eSet	= write;
	m_eAddr	= addr;
	m_eSpin = spin;
	m_eHook	= hook;
	m_eValue	= value;
	m_eGridTB	= gridTB;
	/*
	const int iEnd = 3;
	int i, id = grid->GetId(),
		t[ iEnd ] = { wxEVT_SCROLLWIN_TOP, wxEVT_SCROLLWIN_LINEUP, wxEVT_SCROLLWIN_PAGEUP },
		b[ iEnd ] = { wxEVT_SCROLLWIN_BOTTOM, wxEVT_SCROLLWIN_LINEDOWN, wxEVT_SCROLLWIN_PAGEDOWN };
	for ( i = 0; i < iEnd; ++i )
	{
		grid->Connect( t[ i ],
			wxScrollWinEventHandler( hexDB::eGrid_OnScrollHome ), NULL, this );
		grid->Connect( b[ i ],
			wxScrollWinEventHandler( hexDB::eGrid_OnScrollLast ), NULL, this );
	}
	// */
	grid->Connect( wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eGrid_OnMouseWheel ), NULL, this );
	// */
	gridTB->Connect( gridTB->GetId(), wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eGrid_OnMouseWheel ), NULL, this );
	// */
	jump->Connect( jump->GetId(), wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eGrid_OnMouseWheel ), NULL, this );
	// */
	jump->Connect( jump->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eJump_OnClick ), NULL, this );
	read->Connect( read->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eGet_OnClick ), NULL, this );
	write->Connect( write->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eSet_OnClick ), NULL, this );
}
void hexDB::eGrid_Disconnect( void )
{
	wxGrid* grid = m_eGrid;
	/*
	const int iEnd = 3;
	int i,id = grid->GetId(),
		t[ iEnd ] = { wxEVT_SCROLLWIN_TOP, wxEVT_SCROLLWIN_LINEUP, wxEVT_SCROLLWIN_PAGEUP },
		b[ iEnd ] = { wxEVT_SCROLLWIN_BOTTOM, wxEVT_SCROLLWIN_LINEDOWN, wxEVT_SCROLLWIN_PAGEDOWN };
	for ( i = 0; i < iEnd; ++i )
	{
		grid->Disconnect( t[ i ],
			wxScrollWinEventHandler( hexDB::eGrid_OnScrollHome ), NULL, this );
		grid->Disconnect( b[ i ],
			wxScrollWinEventHandler( hexDB::eGrid_OnScrollLast ), NULL, this );
	}
	// */
	grid->Disconnect( wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eGrid_OnMouseWheel ), NULL, this );
	// */
	m_eGridTB->Disconnect( m_eGridTB->GetId(), wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eJump_OnMouseWheel ), NULL, this );
	// */
	m_eJump->Disconnect( m_eJump->GetId(), wxEVT_MOUSEWHEEL,
		wxMouseEventHandler( hexDB::eJump_OnMouseWheel ), NULL, this );
	// */
	m_eJump->Disconnect( m_eJump->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eJump_OnClick ), NULL, this );
	m_eGet->Disconnect( m_eGet->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eGet_OnClick ), NULL, this );
	m_eSet->Disconnect( m_eSet->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler( hexDB::eSet_OnClick ), NULL, this );
}
void hexDB::m_eGridJump( bool fromThread )
{
	ui64 a = m_eGridAddr;
	osHdl hApp = NewAppHandle( fromThread ? m_binNameE : (bin.name + osDotExe) );
	while ( ( a & 0xF ) > 0uLL ) --a;
	while ( ( a & 0xF0 ) > 0uLL ) a -= 0x10;
	ui08 r = bin.ramNo;
	ui64 RBytes = bin[ r ].bytes;
	size_t mbytes = ( m_eGrid->GetNumberRows() * 0x10 );
	size_t rbytes = ( RBytes > mbytes ) ? mbytes : RBytes;
	ui64 mAddr = RBytes - rbytes;
	if ( a > mAddr )
		a = mAddr;
	ui08 *data = new ui08[ rbytes ];
	size_t i = GetAppRam( hApp, bin[ r ].addr + a, data, rbytes );
	if ( hApp == NULL || i != rbytes )
	{
		for ( ; i < rbytes; ++i )
			data[ i ] = 0u;
	}
	DelAppHandle( hApp );
	eGrid( 0x30, a, data, rbytes );
	delete [] data;
}
void hexDB::eGrid_OnScroll( bool isVertical, int move )
{
	if ( nowL == HEX_LIST_EDIT )
	{
		wxGrid* grid = m_eGrid;
		int y, rw, rh, vw, vh;
		grid->GetSize( &rw, &rh );
		grid->GetVirtualSize( &vw, &vh );
		bool hasSB = (vh > rh);
		grid->CalcUnscrolledPosition( 0, 0, &eXVH, &y );
		if ( isVertical && hasSB ? ( y == eYVH ) : ( move != 0 ) )
		{
			ui64 a = m_eGridAddr;
			if ( hasSB ? ( y <= 0 ) : ( move > 0 ) )
			{
				if ( a >= 0x100LL ) a -= 0x100LL;
				else a = 0uLL;
			}
			else
			{
				if ( a < ( 0uLL - 0x100LL ) ) a += 0x100LL;
				else a = 0uLL;
			}
			m_eGridAddr = a;
			if ( !m_gui->m_editOn )
				m_eGridJump();
		}
		eYVH = y;
	}
}
void hexDB::eJump_OnClick( wxCommandEvent& event )
{
	m_eGridAddr = 0u;
	GetHex( &m_eGridAddr, m_eGridTB->GetValue(), 8u );
	m_gui->m_editAdd = m_gui->SetGTime( m_eHook->GetSelection() );
	if ( !m_gui->m_editOn )
		m_gui->NewEditThread();
}
void hexDB::eJump_OnMouseWheel( wxMouseEvent& event )
{
	eGrid_OnScroll( true, event.GetWheelRotation() );
	event.Skip();
}
void hexDB::eGet_OnClick( wxCommandEvent& event )
{
	ui64 a = 0u;
	GetHex( &a, m_eAddr->GetValue(), 8u );
	size_t s = m_eSpin->GetValue(), i = 0;
	ui08 *v = new ui08[ s ];
	osHdl h = NewAppHandle( bin.name + osDotExe );
	i = GetAppRam( h, bin[ bin.ramNo ].addr + a, v, s );
	if ( i != s )
	{
		for ( ; i < s; ++i )
			v[ i ] = 0u;
	}
	DelAppHandle( h );
	Text txt;
	GetTxt( txt, v, s );
	m_eValue->ChangeValue( txt );
	delete [] v;
	ui32 t = ( m_eGrid->GetNumberRows() * 0x10 );
	ui64 e = (m_eGridAddr + t);
	if ( a < m_eGridAddr || a > e )
	{
		while ( ( a & 0xF ) > 0uLL ) --a;
		while ( ( a & 0xF0 ) > 0uLL ) a -= 0x10;
		if ( a > 0uLL && t > 0x200 ) a -=0x100;
		m_eGridAddr = a;
	}
	if ( !m_gui->m_editOn )
		m_eGridJump();
}
void hexDB::eSet_OnClick( wxCommandEvent& event )
{
	ui64 a = 0u;
	GetHex( &a, m_eAddr->GetValue(), 8u );
	size_t s = m_eSpin->GetValue();
	ui08 *v = new ui08[ s ];
	GetHex( v, m_eValue->GetValue(), s );
	osHdl h = NewAppHandle( bin.name + osDotExe );
	if ( h != NULL )
		SetAppRam( h, bin[ bin.ramNo ].addr + a, v, s );
	DelAppHandle( h );
	delete [] v;
	ui32 t = ( m_eGrid->GetNumberRows() * 0x10 );
	ui64 e = (m_eGridAddr + t);
	if ( a < m_eGridAddr || a > e )
	{
		while ( ( a & 0xF ) > 0uLL ) --a;
		while ( ( a & 0xF0 ) > 0uLL ) a -= 0x10;
		if ( a > 0uLL && t > 0x200 ) a -=0x100;
		m_eGridAddr = a;
	}
	if ( !m_gui->m_editOn )
		m_eGridJump();
}
void hexDB::eGrid_OnMouseWheel( wxMouseEvent& event )
{
	eGrid_OnScroll( true, event.GetWheelRotation() );
	event.Skip();
}
void hexDB::eGrid_OnScrollHome( wxScrollWinEvent& event )
{
	eGrid_OnScroll( event.GetOrientation() == wxVERTICAL, 0 );
	event.Skip();
}
void hexDB::eGrid_OnScrollLast( wxScrollWinEvent& event )
{
	eGrid_OnScroll( event.GetOrientation() == wxVERTICAL, 0 );
	event.Skip();
}