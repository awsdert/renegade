#include "hexGUI_G.hpp"

G::G( wxWindow* parent ) : HexGUI( parent )
{
// TODO(awsdert) 0: Refine G()
	m_sep = ( wxGetCwd().Contains( wxT("\\") ) ) ? wxT("\\") : wxT("/");
	m_hexPath	= wxT("/hackerex");
	m_orgPath	= wxT("/org");
	m_iniCfgPath	= wxT("/Settings");
	m_iniOrgPath	= wxT("/Organisation");
	m_iniThemePath	= wxT("/Themes");
	//
	m_Org = 0;
	m_Pfm = 0;
	m_Bin = 0;
	m_Pfl = 0;
	m_Hck = 0;
	// Lists
	m_ListCfg = true;
	m_ListCwd = true;
	m_ListNow = HEX_LIST_ORG;
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
G::~G()
{
	ClearTmps( wxGetCwd() + m_sep + wxT("..") );
	ClearTmps( wxGetDataDir() );
}
void G::ClearTmps( Text path )
{
	if ( !wxDirExists( path ) )
		return;
	wxDir dir;
	dir.Open( path );
	bool b = false;
	Text dspec = wxT("*");
	Text fspec = wxT("*~");
	Text name;
	dir.GetFirst( &name, fspec, wxDIR_FILES );
	for
	(
		b = dir.GetFirst( &name, fspec, wxDIR_DIRS );
		b; b = dir.GetNext( &name )
	)
	{
		if ( wxFileExists( name ) )
			wxRemoveFile( name );
	}
	for
	(
		b = dir.GetFirst( &name, dspec, wxDIR_DIRS );
		b; b = dir.GetNext( &name )
	)
	{
		if ( wxDirExists( name ) )
			ClearTmps( name );
	}
}
void G::HexGUI_TB_OnToolExec( wxCommandEvent& event )
{
// TODO(awsdert) 0: Refine G::HexGUI_TB_OnToolExec()
	switch ( event.GetId() )
	{
	case HexMain_TT_ID:
		m_ListCfg = true;
		UpdatePanels();
		break;
	case HexList_TT_ID:
		m_ListCfg = false;
		UpdatePanels();
		break;
	case HexLoad_TT_ID:
		LoadData();
		break;
	}
}

void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
	ListData( HexList_LB->GetSelection() );
}
