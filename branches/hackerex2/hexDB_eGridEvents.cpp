#include "wx_pch.h"
#include "hex2_G.h"
M_EGRID::M_EGRID( void ) :
	wxEvtHandler()
{
	gui = NULL;
	db	= NULL;
	rows	= 0x30;
	grid_g	= NULL;
	jump_b	= NULL;
	get_b	= NULL;
	set_b	= NULL;
	hook_dd	= NULL;
	size_sb	= NULL;
	sync_rl	= NULL;
	a_txt	= NULL;
	v_txt	= NULL;
	nAddr	= 0u;
	iXVH	= 0;
	iYVH	= 0;
	isAuto	= false;
	isShown	= false;
	isUpLast = true;
	isActive = false;
}
void M_EGRID::sync_connect( void )
{
	if ( grid_g == NULL || jump_b == NULL || get_b == NULL || set_b == NULL ||
		hook_dd == NULL || size_sb == NULL || a_txt == NULL || v_txt == NULL ||
		sync_rl == NULL )
		wxMessageBox( _("Pointer/s not set"), _("Error") );
	else
	{
		sync_rl->Connect( sync_rl->GetId(), wxEVT_SHOW, wxShowEventHandler( M_EGRID::sync_onshow ), NULL, this );
		if ( sync_rl->IsShown() )
			sync_m_connect();
	}
}
void M_EGRID::sync_disconnect( void )
{
	if ( grid_g == NULL || jump_b == NULL || get_b == NULL || set_b == NULL ||
		hook_dd == NULL || size_sb == NULL || a_txt == NULL || v_txt == NULL ||
		sync_rl == NULL )
		wxMessageBox( _("Pointer/s not set"), _("Error") );
	else
	{
		sync_rl->Disconnect( sync_rl->GetId(), wxEVT_SHOW, wxShowEventHandler( M_EGRID::sync_onshow ), NULL, this );
		sync_m_disconnect();
	}
}
void M_EGRID::sync_onshow( wxShowEvent& event )
{
	if ( event.GetShow() )
		sync_m_connect();
	else
		sync_m_disconnect();
	event.Skip();
}
void M_EGRID::sync_m_connect( void )
{
	if ( isShown )
		return;
	isShown = true;
#define LC_EGRID( m_o, m_e, m_h ) m_o->Connect( m_e, m_h, NULL, this )
#define LC_EGRID_I( m_o, m_e, m_h ) m_o->Connect( m_o->GetId(), m_e, m_h, NULL, this )
#define LC_EGRID_S( m_o, m_e, m_h ) LC_EGRID( m_o, m_e, wxScrollWinEventHandler( m_h ) )
#define LC_EGRID_W( m_o, m_h ) LC_EGRID_I( m_o, wxEVT_MOUSEWHEEL, wxMouseEventHandler( m_h ) )
#define LC_EGRID_B( m_o, m_h ) LC_EGRID_I( m_o, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_h ) )
	LC_EGRID_S( grid_g, wxEVT_SCROLLWIN_TOP, M_EGRID::onscrollb );
	LC_EGRID_S( grid_g, wxEVT_SCROLLWIN_BOTTOM, M_EGRID::onscrolle );
	LC_EGRID( grid_g, wxEVT_MOUSEWHEEL, wxMouseEventHandler( M_EGRID::grid_onmwheel ) );
	LC_EGRID_W( jump_b, M_EGRID::misc_onmwheel );
	LC_EGRID_W( a_txt, M_EGRID::misc_onmwheel );
	LC_EGRID_I( hook_dd, wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M_EGRID::hook_onchoice ) );
	LC_EGRID_B( jump_b, M_EGRID::jump_onclick );
	LC_EGRID_B( get_b, M_EGRID::get_onclick ); 
	LC_EGRID_B( set_b, M_EGRID::set_onclick );
}
void M_EGRID::sync_m_disconnect( void )
{
	if ( isShown )
		return;
	isShown = false;
#define LD_EGRID( m_o, m_e, m_h ) m_o->Disconnect( m_e, m_h, NULL, this )
#define LD_EGRID_I( m_o, m_e, m_h ) m_o->Disconnect( m_o->GetId(), m_e, m_h, NULL, this )
#define LD_EGRID_S( m_o, m_e, m_h ) LD_EGRID( m_o, m_e, wxScrollWinEventHandler( m_h ) )
#define LD_EGRID_W( m_o, m_h ) LD_EGRID_I( m_o, wxEVT_MOUSEWHEEL, wxMouseEventHandler( m_h ) )
#define LD_EGRID_B( m_o, m_h ) LD_EGRID_I( m_o, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_h ) )
	LD_EGRID_S( grid_g, wxEVT_SCROLLWIN_TOP, M_EGRID::onscrollb );
	LD_EGRID_S( grid_g, wxEVT_SCROLLWIN_BOTTOM, M_EGRID::onscrolle );
	LD_EGRID( grid_g, wxEVT_MOUSEWHEEL, wxMouseEventHandler( M_EGRID::grid_onmwheel ) );
	LD_EGRID_W( jump_b,	M_EGRID::misc_onmwheel );
	LD_EGRID_W( a_txt,	M_EGRID::misc_onmwheel );
	LD_EGRID_I( hook_dd, wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M_EGRID::hook_onchoice ) );
	LD_EGRID_B( jump_b,	M_EGRID::jump_onclick );
	LD_EGRID_B( get_b,	M_EGRID::get_onclick );
	LD_EGRID_B( set_b,	M_EGRID::set_onclick );
}
void M_EGRID::jump_onclick( wxCommandEvent &event )
{
	ui64 a = 0u;
	GetHex( &a, a_txt->GetValue(), 8u );
	jump2( a );
	event.Skip();
}
void M_EGRID::set_onclick( wxCommandEvent &event )
{
	ui64 a = 0u;
	GetHex( &a, a_txt->GetValue(), 8u );
	size_t s = size_sb->GetValue();
	ui08 *v = new ui08[ s ];
	GetHex( v, a_txt->GetValue(), s );
	osHdl h = NewAppHandle( db->bin.name + osDotExe );
	if ( h != NULL )
		SetAppRam( h, db->bin[ db->bin.ramNo ].addr + a, v, s );
	DelAppHandle( h );
	delete [] v;
	jump2( a );
	event.Skip();
}
void M_EGRID::get_onclick( wxCommandEvent &event )
{
	ui64 a = 0u;
	GetHex( &a, a_txt->GetValue(), 8u );
	size_t s = size_sb->GetValue(), i = 0;
	ui08 *v = new ui08[ s ];
	osHdl h = NewAppHandle( db->bin.name + osDotExe );
	i = GetAppRam( h, db->bin[ db->bin.ramNo ].addr + a, v, s );
	if ( i != s )
	{
		for ( ; i < s; ++i )
			v[ i ] = 0u;
	}
	DelAppHandle( h );
	Text txt;
	GetTxt( txt, v, s );
	v_txt->ChangeValue( txt );
	delete [] v;
	jump2( a );
	event.Skip();
}
void M_EGRID::grid_onmwheel( wxMouseEvent& event )
{
	if ( db->nowL == HEX_LIST_EDIT )
		scroll( event.GetWheelRotation(), true );
	event.Skip();
}
void M_EGRID::misc_onmwheel( wxMouseEvent& event )
{
	if ( db->nowL == HEX_LIST_EDIT )
		scroll( event.GetWheelRotation() );
	event.Skip();
}
void M_EGRID::hook_onchoice( wxCommandEvent& event )
{
	if ( db->nowL == HEX_LIST_EDIT )
		wait = gui->SetGTime( event.GetSelection() );
	event.Skip();
}
void M_EGRID::onscrollb( wxScrollWinEvent& event )
{
	if ( db->nowL == HEX_LIST_EDIT && event.GetOrientation() == wxVERTICAL )
		scroll( 1, true, false );
	event.Skip();
}
void M_EGRID::onscrolle( wxScrollWinEvent& event )
{
	if ( db->nowL == HEX_LIST_EDIT && event.GetOrientation() == wxVERTICAL )
		scroll( -1, true, false );
	event.Skip();
}