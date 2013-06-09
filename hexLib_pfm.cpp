#include "wx_pch.h"
#include "hexLib_main.h"

M__PFM::M__PFM( void ) :
	M_FILE()
{
	dd___endian = null;
}
ui08 M__PFM::m_getEndian( Text name )
{
	name.UpperCase();
	if ( name == Text( wxT("BIG") ) )
		return HEX_ENDIAN_BIG;
	else if ( name = Text( wxT("LBIG") ) )
		return HEX_ENDIAN_LBIG;
	else
		return HEX_ENDIAN_LITTLE;
}
Text M__PFM::m_getEndian( ui08 endian )
{
	switch ( endian )
	{
	case HEX_ENDIAN_BIG:
		return Text( wxT("BIG") );
	case HEX_ENDIAN_LBIG:
		return Text( wxT("LBIG") );
	default:
		return Text( wxT("LITTLE") );
	}
}
void M__PFM::lib_show( void )
{
	tbox_name->ChangeValue( m_tmp.name );
	tbox_file->ChangeValue( m_tmp.file );
	dd___endian->Select( m_tmp.endian );
}
// Connection of events
void M__PFM::lib_connect( void )
{
	if ( m_libC )
		return;
	file_connect();
	dd___endian->Connect( dd___endian->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M__PFM::dd___endian_onchange ), null, this );
	m_libC = true;
}
void M__PFM::lib_disconnect( void )
{
	if ( !m_libC )
		return;
	file_disconnect();
	dd___endian->Disconnect( dd___endian->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( M__PFM::dd___endian_onchange ), null, this );
	m_libC = false;
}
void M__PFM::main_connect( void )
{
	if ( m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Connect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__PFM::p____main_onfocus ), null, this );
		p____main->Connect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__PFM::p____main_onblur ), null, this );
		lib_connect();
	}
	m_mainC = true;
}
void M__PFM::main_disconnect( void )
{
	lib_disconnect();
	if ( !m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Disconnect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M__PFM::p____main_onfocus ), null, this );
		p____main->Disconnect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M__PFM::p____main_onblur ), null, this );
	}
	m_mainC = false;
}
// Events
void M__PFM::p____main_onfocus( wxFocusEvent& event )
{
	m_lib->setGuiMode( HEX_LIST_PFM );
}
void M__PFM::p____main_onblur( wxFocusEvent &event )
{
	m_lib->setGuiMode( -1 );
}
void M__PFM::dd___endian_onchange( wxCommandEvent& event )
{
	m_tmp.endian = dd___endian->GetSelection();
}