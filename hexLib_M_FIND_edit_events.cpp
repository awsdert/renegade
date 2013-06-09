#include "wx_pch.h"
#include "hexLib_main.h"
void M_FIND::sync_connect( void )
{
	if ( edit_g == NULL || eJump_b == NULL || eGet_b == NULL || eSet_b == NULL ||
		hook_dd == NULL || size_spb == NULL || a_txt == NULL || v_txt == NULL ||
		sync_rl == NULL )
		wxMessageBox( _("Pointer/s not set"), m_lang->text[ m_lang->txt_error ] );
	else
	{
		sync_rl->Connect( sync_rl->GetId(), wxEVT_SHOW, wxShowEventHandler( M_FIND::sync_onshow ), NULL, this );
		if ( sync_rl->IsShown() )
			sync_m_connect();
	}
}
void M_FIND::sync_disconnect( void )
{
	if ( edit_g == NULL || eJump_b == NULL || eGet_b == NULL || eSet_b == NULL ||
		hook_dd == NULL || size_spb == NULL || addr_txt == NULL || val__txt == NULL ||
		sync_rl == NULL )
		wxMessageBox( _("Pointer/s not set"), m_lang->text[ m_lang->txt_error ] );
	else
	{
		sync_rl->Disconnect( sync_rl->GetId(), wxEVT_SHOW, wxShowEventHandler( M_FIND::sync_onshow ), NULL, this );
		sync_m_disconnect();
	}
}
void M_FIND::sync_onshow( wxShowEvent& event )
{
	if ( event.GetShow() )
		sync_m_connect();
	else
		sync_m_disconnect();
	event.Skip();
}
void M_FIND::sync_m_connect( void )
{
	if ( isEShown )
		return;
	isEShown = true;
#define LC_EGRID( m_o, m_e, m_h ) m_o->Connect( m_e, m_h, NULL, this )
#define LC_EGRID_I( m_o, m_e, m_h ) m_o->Connect( m_o->GetId(), m_e, m_h, NULL, this )
#define LC_EGRID_S( m_o, m_e, m_h ) LC_EGRID( m_o, m_e, wxScrollWinEventHandler( m_h ) )
#define LC_EGRID_W( m_o, m_h ) LC_EGRID_I( m_o, wxEVT_MOUSEWHEEL, wxMouseEventHandler( m_h ) )
#define LC_EGRID_B( m_o, m_h ) LC_EGRID_I( m_o, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_h ) )
	LC_EGRID_S( edit_g, wxEVT_SCROLLWIN_TOP, M_FIND::oneScrollB );
	LC_EGRID_S( edit_g, wxEVT_SCROLLWIN_BOTTOM, M_FIND::oneScrollE );
	LC_EGRID( edit_g, wxEVT_MOUSEWHEEL, wxMouseEventHandler( M_FIND::eGrid_onmwheel ) );
	LC_EGRID_W( eJump_b, M_FIND::edit_onmwheel );
	LC_EGRID_W( addr_txt, M_FIND::edit_onmwheel );
	LC_EGRID_I( hook_dd, wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M_FIND::hook_onchoice ) );
	LC_EGRID_B( eJump_b, M_FIND::eJump_onclick );
	LC_EGRID_B( eGet_b, M_FIND::eGet_onclick ); 
	LC_EGRID_B( eSet_b, M_FIND::eSet_onclick );
}
void M_FIND::sync_m_disconnect( void )
{
	if ( isEShown )
		return;
	isEShown = false;
#define LD_EGRID( m_o, m_e, m_h ) m_o->Disconnect( m_e, m_h, NULL, this )
#define LD_EGRID_I( m_o, m_e, m_h ) m_o->Disconnect( m_o->GetId(), m_e, m_h, NULL, this )
#define LD_EGRID_S( m_o, m_e, m_h ) LD_EGRID( m_o, m_e, wxScrollWinEventHandler( m_h ) )
#define LD_EGRID_W( m_o, m_h ) LD_EGRID_I( m_o, wxEVT_MOUSEWHEEL, wxMouseEventHandler( m_h ) )
#define LD_EGRID_B( m_o, m_h ) LD_EGRID_I( m_o, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_h ) )
	LD_EGRID_S( edit_g, wxEVT_SCROLLWIN_TOP, M_FIND::oneScrollB );
	LD_EGRID_S( edit_g, wxEVT_SCROLLWIN_BOTTOM, M_FIND::oneScrollE );
	LD_EGRID( edit_g, wxEVT_MOUSEWHEEL, wxMouseEventHandler( M_FIND::eGrid_onmwheel ) );
	LD_EGRID_W( eJump_b,	M_FIND::edit_onmwheel );
	LD_EGRID_W( addr_txt,	M_FIND::edit_onmwheel );
	LD_EGRID_I( hook_dd, wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M_FIND::hook_onchoice ) );
	LD_EGRID_B( eJump_b,	M_FIND::eJump_onclick );
	LD_EGRID_B( eGet_b,	M_FIND::eGet_onclick );
	LD_EGRID_B( eSet_b,	M_FIND::eSet_onclick );
}
void M_FIND::eJump_onclick( wxCommandEvent &event )
{
	ui64 a = zxAtou( addrGuiE.tbox_main->GetValue().data(), 16u );
	eJump2( a );
	event.Skip();
}
void M_FIND::eSet_onclick( wxCommandEvent &event )
{
	ui64 a = zxAtou( addrGuiE.tbox_main->GetValue().data(), 16u );
	size_t s = size_spb->GetValue();
	zxInt val = parseInt( val__txt->GetValue().data() );
	val.setSize( s );
	Bin* now = (Bin*)m_lib->m_now;
	zxProc proc;
	if ( proc.zxNewHandle( now->bind.data() ) )
	{
		proc.zxSetMemory( now->at( now->ramNo ).addr + a, val.m_data, s );
		proc.zxDelHandle();
	}
	eJump2( a );
	event.Skip();
}
void M_FIND::eGet_onclick( wxCommandEvent &event )
{
	ui64 a = zxAtou( addrGuiE.tbox_main->GetValue().data(), 16u );
	size_t s = size_spb->GetValue(), i = 0;
	zxUInt val = 0u;
	val.setSize( s );
	Bin* now = (Bin*)m_lib->m_now;
	zxProc proc;
	proc.zxNewHandle( now->bind.data() );
	if( proc.zxGetMemory( now->at( now->ramNo ).addr + a, val.m_data, s ) != s )
		val = 0u;
	proc.zxDelHandle();
	Text txt = val.toString().data();
	val__txt->ChangeValue( txt );
	eJump2( a );
	event.Skip();
}
void M_FIND::eGrid_onmwheel( wxMouseEvent& event )
{
	if ( m_lib->getGuiMode() == HEX_LIST_EDIT )
		eScroll( event.GetWheelRotation(), true );
	event.Skip();
}
void M_FIND::edit_onmwheel( wxMouseEvent& event )
{
	if ( m_lib->getGuiMode() == HEX_LIST_EDIT )
		eScroll( event.GetWheelRotation() );
	event.Skip();
}
void M_FIND::hook_onchoice( wxCommandEvent& event )
{
	if ( m_lib->getGuiMode() == HEX_LIST_EDIT )
		wait = m_gui->SetGTime( event.GetSelection() );
	event.Skip();
}
void M_FIND::oneScrollB( wxScrollWinEvent& event )
{
	if ( m_lib->getGuiMode() == HEX_LIST_EDIT && event.GetOrientation() == wxVERTICAL )
		eScroll( 1, true, false );
	event.Skip();
}
void M_FIND::oneScrollE( wxScrollWinEvent& event )
{
	if ( m_lib->getGuiMode() == HEX_LIST_EDIT && event.GetOrientation() == wxVERTICAL )
		eScroll( -1, true, false );
	event.Skip();
}