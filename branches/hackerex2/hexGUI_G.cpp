#include "hexGUI_G.hpp"

G::G( wxWindow* parent ) : HexGUI( parent )
{
// TODO(awsdert) 0: Refine G()
	m_hexPath	= wxT("/hackerex");
	m_orgPath	= wxT("/org");
	m_iniCfgPath	= wxT("/Settings");
	m_iniOrgPath	= wxT("/Organisation");
	m_iniThemePath	= wxT("/Themes");
	// Lists
	m_ListCfg = true;
	m_ListCwd = true;
	m_ListNow = 0;
	m_ListOld = 0;
	m_List_Ps.resize( 12 );
	m_List_Ps[  0 ] = HexSession_P;
	m_List_Ps[  1 ] = HexName_P;
	m_List_Ps[  2 ] = HexFile_P;
	m_List_Ps[  3 ] = HexEndian_P;
	m_List_Ps[  4 ] = HexBin_P;
	m_List_Ps[  5 ] = HexRam_P;
	m_List_Ps[  6 ] = HexPfl_P;
	m_List_Ps[  7 ] = HexHck_P;
	m_List_Ps[  8 ] = HexPtr_P;
	m_List_Ps[  9 ] = HexVal_P;
	m_List_Ps[ 10 ] = HexQ_P;
	m_List_Ps[ 11 ] = HexOut_P;
	UpdatePanels();
	UpdateTheme( wxT("visualpharm-win8") );
}
G::~G() {}
void G::HexGUI_TB_OnToolExec( wxCommandEvent& event )
{
// TODO(awsdert) 0: Refine G::HexGUI_TB_OnToolExec()
	switch ( event.GetId() )
	{
	case HexMain_TT_ID:
		m_ListCfg = true;
		break;
	case HexList_TT_ID:
		m_ListCfg = false;
		break;
	case HexLoad_TT_ID:
		LoadDatT();
	}
	UpdatePanels();
}

void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
// TODO(awsdert) 0: Refine G::HexList_LBOnSelect()
	int s = event.GetSelection();
	if ( m_ListCfg )
	{
		m_ListNow = s;
	}
	else
	{
		switch ( m_ListNow )
		{
		case HEX_LIST_ORG:
			ShowOrgD( s );
			break;
		case HEX_LIST_PFM:
			ShowPfmD( s );
			break;
		case HEX_LIST_BIN:
			ShowBinD( s );
			break;
		case HEX_LIST_PFL:
			ShowPflD( s );
			break;
		default:
			m_ListCfg = true;
			m_ListNow = 0;
		}
	}
}
