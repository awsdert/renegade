#include "wx_pch.h"
#include "hexLib_main.h"

M__ORG::M__ORG( void ) :
	M_FILE() {}
void M__ORG::lib_show( void )
{
	tbox_name->ChangeValue( m_tmp.name );
	tbox_file->ChangeValue( m_tmp.file );
}
// Connection of events
void M__ORG::lib_connect( void )
{
	if ( m_libC )
		return;
	file_connect();
	m_libC = true;
}
void M__ORG::lib_disconnect( void )
{
	if ( !m_libC )
		return;
	file_disconnect();
	m_libC = false;
}
void M__ORG::main_connect( void )
{
	if ( m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Connect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__ORG::p____main_onfocus ), null, this );
		p____main->Connect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__ORG::p____main_onblur ), null, this );
		lib_connect();
		m_mainC = true;
	}
}
void M__ORG::main_disconnect( void )
{
	lib_disconnect();
	if ( !m_mainC )
		return;
	p____main->Disconnect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__ORG::p____main_onfocus ), null, this );
	p____main->Disconnect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__ORG::p____main_onblur ), null, this );
	m_mainC = false;
}
// Events
void M__ORG::p____main_onfocus( wxFocusEvent& event )
{
	m_lib->setGuiMode( HEX_LIST_ORG );
}
void M__ORG::p____main_onblur( wxFocusEvent &event )
{
	m_lib->setGuiMode( -1 );
}