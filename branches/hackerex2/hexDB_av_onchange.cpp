#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
/* *
void hexDB::val__onshow(	wxShowEvent& event )
{
#define LC_TEXT( m_o, m_e, m_h ) m_o->Connect( m_o->GetId(), m_e, m_h, NULL, this )
#define LC_TXT( m_o, m_h ) LC_TEXT( m_o, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( m_h ) )
#define LD_TEXT( m_o, m_e, m_h ) m_o->Disconnect( m_o->GetId(), m_e, m_h, NULL, this )
#define LD_TXT( m_o, m_h ) LC_TEXT( m_o, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( m_h ) )
	if ( !event.GetShow() )
	{
		switch ( oldL )
		{
			case HEX_LIST_CODE:
				LD_TXT( m_hTree.val__txt, hexDB::addr_onchange );
				break;
			case HEX_LIST_EDIT:
				LD_TXT( m_eGrid.v_txt, hexDB::val__onchange );
				break;
		}
	}
	else
	{
		switch ( nowL )
		{
			case HEX_LIST_CODE:
				LC_TXT( m_hTree.val__txt, hexDB::addr_onchange );
				break;
			case HEX_LIST_EDIT:
				LC_TXT( m_eGrid.v_txt, hexDB::val__onchange );
				break;
		}
	}
}
void hexDB::valT_onchange( wxCommandEvent& event )
{
	int vType = event.GetSelection();
	wxChoice* dbox = (wxChoice*)event.GetEventObject();
	if ( vType < 0 )
	{
		vType = HEX_TYPE_HEX;
		dbox->Select( HEX_TYPE_HEX );
	}
	switch ( nowL )
	{
		case HEX_LIST_CODE:
			m_hTree.code.hex = vType;
			break;
		case HEX_LIST_FIND:
			m_oGrid.vType = vType;
			break;
		case HEX_LIST_EDIT:
			m_eGrid.vType = vType;
			break;
	}
}
/* */