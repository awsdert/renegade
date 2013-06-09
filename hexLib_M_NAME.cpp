#include "hexLib_main.h"

M_NAME::M_NAME( void )
{
	m_libC = false;
	m_mainC = false;
	m_nameC = false;
	p____main = null;
	p____name = null;
	lbl__name = null;
	tbox_name = null;
	m_lib = null;
	m_lang = null;

}
void M_NAME::name_connect( void )
{
	if ( m_nameC )
		return;
	if ( tbox_name != null )
		tbox_name->Connect( tbox_name->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::tbox_name_onchange ), null, m_lib );
	m_nameC = true;
}
void M_NAME::name_disconnect( void )
{
	if ( !m_nameC )
		return;
	if ( tbox_name != null )
		tbox_name->Disconnect( tbox_name->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::tbox_name_onchange ), null, m_lib );
	m_nameC = false;
}