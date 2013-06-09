#include "hexLib_main.h"

M_LOAD::M_LOAD( void )
{
	loadNow	= false;
	loadDef	= false;
	des = NULL;
	src = NULL;
	m_lang = NULL;
}
bool M_LOAD::check( void )
{
	Text msg;
	if ( des == NULL )
		msg += wxT("\ndes");
	if ( src == NULL )
		msg += wxT("\nsrc");
	if ( !msg.empty() )
	{
		if ( m_lang == NULL )
		{
			wxMessageBox( wxT("m_lang cannot be NULL"), m_lang->text[ m_lang->txt_error ] );
			return false;
		}
		wxMessageBox( m_lang->text[ m_lang->txt_thefollowingarestillnull ] + msg,
			m_lang->text[ m_lang->txt_error ] );
		return false;
	}
	return true;
}