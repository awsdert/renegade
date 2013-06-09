#include "hexLib_main.h"
M__RAM::M__RAM( void )
	: M_NAME()
{
	lbox_main = null;
	lbl__size = null;
	tbox_size = null;
}
void M__RAM::lib_show( void )
{
	Text txt;
	tbox_name->ChangeValue( m_obj.name );
	txt.Printf( wxT("%llX"), m_obj.addr );
	addrGui.tbox_main->ChangeValue( txt );
	txt.Printf( wxT("%llX"), m_obj.bytes );
	tbox_size->ChangeValue( txt );
	addrGui.sl___depth->SetValue( m_obj.depth );
}

void M__RAM::lib_getRam( si08 id )
{
	if ( ramNo >= 0 )
		m_tmp->at( ramNo ) = m_obj;
	if ( id < 0 || id > 15 )
	{
		id = -1;
		m_obj = Ram();
	}
	else
	{
		ui08 i = id;
		if ( i >= m_tmp->size() )
			m_tmp->resize( id + 1 );
		m_obj = m_tmp->at( id );
	}
	ramNo = id;
}
// Connection of events
void M__RAM::lib_connect( void )
{
	if ( m_libC )
		return;
	name_connect();
	lbox_main->Connect( lbox_main->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__RAM::lbox_main_onselect ), null, this );
	tbox_size->Connect( tbox_size->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__RAM::tbox_size_onchange ), null, this );
	m_libC = true;
}
void M__RAM::lib_disconnect( void )
{
	if ( !m_libC )
		return;
	name_disconnect();
	lbox_main->Disconnect( lbox_main->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__RAM::lbox_main_onselect ), null, this );
	tbox_size->Disconnect( tbox_size->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( M__RAM::tbox_size_onchange ), null, this );
	m_libC = false;
}
void M__RAM::main_connect( void )
{
	if ( m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Connect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__RAM::p____main_onfocus ), null, this );
		p____main->Connect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__RAM::p____main_onblur ), null, this );
		lib_connect();
		m_mainC = true;
	}
}
void M__RAM::main_disconnect( void )
{
	lib_disconnect();
	if ( !m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Disconnect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__RAM::p____main_onfocus ), null, this );
		p____main->Disconnect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__RAM::p____main_onblur ), null, this );
	}
	m_mainC = false;
}
// Events
void M__RAM::p____main_onfocus( wxFocusEvent& event )
{
	m_lib->setGuiMode( HEX_LIST_RAM );
}
void M__RAM::p____main_onblur( wxFocusEvent &event )
{
	m_lib->setGuiMode( -1 );
}
void M__RAM::lbox_main_onselect( wxCommandEvent& event )
{
	lib_getRam( binGui->m_tmp.ramNo );
	event.Skip();
}