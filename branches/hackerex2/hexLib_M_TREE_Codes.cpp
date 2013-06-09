#include "wx_pch.h"
#include "hexLib_main.h"
void M_TREE::codes_connect( void )
{
	if ( m_isCodesConnected )
		return;
	m_isShared = ( cNew_b == hDel_b );
	if ( m_isShared && m_isHacksConnected )
		m_hacks_disconnect();
	else
	{
		if (! m_hacks_check() )
			return;
		wxString msg = wxT("These ptrs are still NULL which is not allowed:\n"), txt;
		if ( code_t == NULL )
			txt += wxT(", code_t");
		if ( cNew_b == NULL )
			txt += wxT(", cNew_b");
		if ( cDel_b == NULL )
			txt += wxT(", cDel_b");
		if ( cSet_b == NULL )
			txt += wxT(", cSet_b");
		if ( cGet_b == NULL )
			txt += wxT(", cGet_b");
		if ( !txt.IsEmpty() )
		{
			wxMessageBox( msg + txt.substr( 2 ) );
			return;
		}
	}
	m_codes_connect();
}
void M_TREE::m_codes_connect( void )
{
	if ( m_isCodesConnected )
		return;
	if ( m_isShared && m_isHacksConnected )
		m_hacks_disconnect();
	cNew_b->Connect( cNew_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cNew_b_onclick ), NULL, this );
	cDel_b->Connect( cDel_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cDel_b_onclick ), NULL, this );
	cSet_b->Connect( cSet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cSet_b_onclick ), NULL, this );
	cGet_b->Connect( cGet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cGet_b_onclick ), NULL, this );
	m_isCodesConnected = true;
}
void M_TREE::m_codes_disconnect( void )
{
	if ( !m_isCodesConnected )
		return;
	cNew_b->Disconnect( cNew_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cNew_b_onclick ), NULL, this );
	cDel_b->Disconnect( cDel_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cDel_b_onclick ), NULL, this );
	cSet_b->Disconnect( cSet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cSet_b_onclick ), NULL, this );
	cGet_b->Disconnect( cGet_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_TREE::cGet_b_onclick ), NULL, this );
	m_isCodesConnected = false;
}
void M_TREE::code_t_onshow(	 wxShowEvent&	event )
{
	if ( event.IsShown() )
		m_codes_connect();
	else
		m_codes_disconnect();
	event.Skip();
}
void M_TREE::cType_dd_onchange( wxCommandEvent& event )
{
	ui08 type = cType_dd->GetSelection();
	if ( type >= CODE_COUNT )
		type = CODE_WRITE;
	/* *
	switch ( type )
	{
	case CODE_WRITE:
		break;
	}
	/* */
	m_cNow.type = type;
}