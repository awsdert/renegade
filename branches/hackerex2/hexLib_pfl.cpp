#include "wx_pch.h"
#include "hexLib_main.h"
M__PFL::M__PFL( void ) :
	M_FILE()
{
	ta___notes = null;
	tbox_sid = null;
	tbox_pid = null;
}
void M__PFL::lib_show( void )
{
	Text txt;
	txt.Printf( wxT("%04X"), m_tmp.profile );
	tbox_pid->ChangeValue( txt );
	tbox_sid->ChangeValue( m_tmp.serial );
	ta___notes->ChangeValue( m_tmp.notes );
	m_show( m_tmp.region );
}
void M__PFL::m_show( ui32 region )
{
	si32 i = 0;
	clb__region->Clear();
	clb__region->Append( oRegion.m_txt );
	bool all = ( region == 0u );
	for ( i = 0; i < REG_COUNT; ++i )
		clb__region->Check( i, ( all || ( region & oRegion.m_bit[ i ] ) > 0u ) );
	dd___region->Select( all ? 1 : 2 );
	clb__region->Enable( !all );
}
// Connection of events
void M__PFL::lib_connect( void )
{
	if ( m_libC )
		return;
	file_connect();
	ta___notes->Connect( ta___notes->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::ta___notes_onchange ), NULL, this );
	tbox_sid->Connect( tbox_sid->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::tbox_sid_onchange ), NULL, this );
	tbox_pid->Connect( tbox_pid->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::tbox_pid_onchange ), NULL, this );
	m_libC = true;
}
void M__PFL::lib_disconnect( void )
{
	if ( !m_libC )
		return;
	file_disconnect();
	ta___notes->Disconnect( ta___notes->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::ta___notes_onchange ), NULL, this );
	tbox_sid->Disconnect( tbox_sid->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::tbox_sid_onchange ), NULL, this );
	tbox_pid->Disconnect( tbox_pid->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__PFL::tbox_pid_onchange ), NULL, this );
	m_libC = false;
}
void M__PFL::main_connect( void )
{
	if ( m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Connect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__PFL::p____main_onfocus ), null, this );
		p____main->Connect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__PFL::p____main_onblur ), null, this );
		lib_connect();
	}
	m_mainC = true;
}
void M__PFL::main_disconnect( void )
{
	lib_disconnect();
	if ( !m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Disconnect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__PFL::p____main_onfocus ), null, this );
		p____main->Disconnect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__PFL::p____main_onblur ), null, this );
	}
	m_mainC = false;
}
// Events
void M__PFL::p____main_onfocus( wxFocusEvent& event )
{
	m_lib->setGuiMode( HEX_LIST_PFM );
}
void M__PFL::p____main_onblur( wxFocusEvent &event )
{
	m_lib->setGuiMode( -1 );
}