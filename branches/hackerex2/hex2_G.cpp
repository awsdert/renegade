#include "hex2_G.h"

G::G( wxWindow* parent ) : HexGUI( parent )
{
// TODO(awsdert) 0: Refine G()
	// Lists
	m_bCwd		= true;
	m_bListCfg	= true;
	m_siListNow	= HEX_LIST_SESSION;
	m_aPanels[ 0 ]	= HexName_P;
	m_aPanels[ 1 ]	= HexFile_P;
	m_aPanels[ 2 ]	= HexEndian_P;
	m_aPanels[ 3 ]	= HexBin_P;
	m_aPanels[ 4 ]	= HexRam_P;
	m_aPanels[ 5 ]	= HexPfl_P;
	m_aPanels[ 6 ]	= HexHck_P;
	m_aPanels[ 7 ]	= HexAddr_P;
	m_aPanels[ 8 ]	= HexVal_P;
	m_aPanels[ 9 ]	= HexQ_P;
	m_aPanels[ 10 ]	= HexOut_P;
	m_aPanels[ 11 ]	= HexRamData_P;
	m_aPanels[ 12 ] = HexState_P;
	m_db.appsLB		= HexList_LB;
	m_db.codesTree	= HexCode_TC;
	m_db.hacksTree	= HexHack_TC;
	m_db.tmpCfg		= false;
	m_db.tmpMode	= HEX_LIST_SESSION;
	Text path		= m_bCwd ? wxGetCwd() + xsDirUp : wxGetDataDir(), val;
	path += wxT("hex.ini");
	wxFileConfig cfg( wxT("HackerEX2"), wxT("Awsdert"), path );
	cfg.SetPath( wxT("/Configuration") );
	cfg.Read( wxT("Session" ), &val, getGlobalName() );
	LoadData( m_db, HexList_LB, HEX_LOAD_SAVE2TEMP, val );
	LoadStateD( m_db.state );
	UpdatePanels();
	UpdateTheme( wxT("crystal-clear-icons-by-everaldo") );
}
G::~G()
{
	Text path = m_bCwd ? wxGetCwd() + xsDirUp : wxGetDataDir(), name;
	path += xsDirSep + wxT("hex.ini");
	const Text Def		= getGlobalName();
	const Text appName	= wxT("HackerEX2");
	const Text vendor	= wxT("Awsdert");
	wxFileConfig cfgN( appName, vendor, path ), cfgT( appName, vendor, path + cTild );
	cfgN.SetPath( wxT("/Configuration") );
	cfgN.Write( wxT("Session" ), m_db.state.nameOld );
	if ( cfgN.HasEntry( wxT("TotalSessions") ) )
		cfgN.DeleteEntry( wxT("TotalSessions") );
	TxtA data;
	LoadStates(	m_db.state,	cfgT, cfgN, data, Def, true, false );
	LoadOrgs(	m_db.org, 	cfgT, cfgN, data, Def, true, false );
	for ( int i = 0; i < HEX_LIST_COUNT; ++i )
	{
		name = m_db.nowP[ i ] + cTild;
		if ( wxFileExists(	name ) )
			wxRemoveFile(	name );
		name = m_db.oldP[ i ] + cTild;
		if ( wxFileExists(	name ) )
			wxRemoveFile(	name );
	}
}
void G::HexGUI_TB_OnToolExec( wxCommandEvent& event )
{
// TODO(awsdert) 0: Refine G::HexGUI_TB_OnToolExec()
	switch ( event.GetId() )
	{
	case HexMain_TT_ID:
		m_bListCfg = true;
		UpdatePanels();
		break;
	case HexList_TT_ID:
		m_bListCfg = false;
		UpdatePanels();
		break;
	case HexSave_TT_ID:
		m_db.tmpCfg		= false;
		m_db.tmpMode	= m_siListNow;
		LoadData( m_db, HexList_LB, HEX_LOAD_SAVE2FILE, m_db.getNowN( m_siListNow ) );
		break;
	}
}

void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
	LBox* lb = HexList_LB;
	int i = lb->GetSelection();
	Text name = lb->GetString( i );
	if ( m_bListCfg )
		m_siListNow = i;
	else
	{
		m_db.tmpCfg		= false;
		m_db.tmpMode	= m_siListNow;
		UpdateList( m_db, lb, name );
		ShowData( m_db );
	}
}
void G::HexHack_TC_OnSelect( wxTreeEvent& event )
{
	TrID* data		= (TrID*)HexHack_TC->GetItemData( event.GetItem() );
	m_db.hacks.hackNow = data->index;
	m_db.tmpCfg		= false;
	m_db.tmpMode	= HEX_LIST_HACK;
	m_db.tmpRelist	= false;
	LoadData( m_db, m_db.tmpLB, HEX_LOAD_LIST, m_db.hacks[ data->index ].name );
}
void G::HexCode_TC_OnSelect( wxTreeEvent& event )
{
	TrID* data		= (TrID*)HexCode_TC->GetItemData( event.GetItem() );
	if ( data->index < 0 )
		return;
	m_db.codeNo		= data->index;
	m_db.tmpCfg		= false;
	m_db.tmpMode	= HEX_LIST_CODE;
	m_db.tmpRelist	= false;
	LoadData( m_db, m_db.tmpLB, HEX_LOAD_LIST, getGlobalName() );
}
void G::HexState_B_OnClick( wxCommandEvent& event )
{
	LoadStateD( m_db.state );
}
