#include "hexDB_hexLib.h"
bool hexLib::M_TREE::m_hacks_check( void )
{
	wxString msg = wxT("These ptrs are still NULL which is not allowed:\n"), txt;
	if ( hack_t == NULL )
		txt += wxT(", hack_t");
	if ( hNew_b == NULL )
		txt += wxT(", hNew_b");
	if ( hDel_b == NULL )
		txt += wxT(", hDel_b");
	if ( hSet_b == NULL )
		txt += wxT(", hSet_b");
	if ( hGet_b == NULL )
		txt += wxT(", hGet_b");
	if ( !txt.IsEmpty() )
	{
		wxMessageBox( msg + txt.substr( 2 ), wxT("Hacks Error") );
		return false;
	}
	return true;
}
void hexLib::M_TREE::hacks_connect( void )
{
	if ( m_isHacksConnected )
		return;
	m_isShared = ( cNew_b == hDel_b );
	if ( m_isShared && m_isCodesConnected )
		m_codes_disconnect();
	else if ( m_hacks_check() )
		m_hacks_connect();
}
void hexLib::M_TREE::m_hacks_connect( void )
{
	if ( m_isHacksConnected )
		return;
	if ( m_isShared && m_isCodesConnected )
		m_codes_disconnect();
	m_lib->m_now = &m_hNow;
	m_lib->m_old = &m_hOld;
	m_lib->m_tmp = &m_hTmp;
	name_txt->Connect( name_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::name_txt_onchange ), NULL, m_lib );
	hNew_b->Connect( hNew_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hNew_b_onclick ), NULL, this );
	hDel_b->Connect( hDel_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hDel_b_onclick ), NULL, this );
	hSet_b->Connect( hSet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hSet_b_onclick ), NULL, this );
	hGet_b->Connect( hGet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hGet_b_onclick ), NULL, this );
	m_isHacksConnected = true;
}
void hexLib::M_TREE::m_hacks_disconnect( void )
{
	if ( !m_isHacksConnected )
		return;
	hNew_b->Disconnect( hNew_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hNew_b_onclick ), NULL, this );
	hDel_b->Disconnect( hDel_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hDel_b_onclick ), NULL, this );
	hSet_b->Disconnect( hSet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hSet_b_onclick ), NULL, this );
	hGet_b->Disconnect( hGet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::M_TREE::hGet_b_onclick ), NULL, this );
	m_isHacksConnected = false;
}