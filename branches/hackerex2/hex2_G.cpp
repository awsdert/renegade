#include "wx_pch.h"
#include "hex2_G.h"

G::G( wxWindow* parent, bool user ) :
	HexGUI( parent )
{
// NOTE: Quick link to GUI constructor
	// Lists
	m_bCwd		= true;
	m_bListCfg	= true;
	m_siListNow	= HEX_LIST_SESSION;
	m_siListOld = -1;
	int i = 0;
	m_db.pb = HexProgress_PB;
	m_aPanels[ i ]	= HexName_P;
	m_aPanels[ ++i ]	= HexFile_P;
	m_aPanels[ ++i ]	= HexEndian_P;
	m_aPanels[ ++i ]	= HexBin_P;
	m_aPanels[ ++i ]	= HexRam_P;
	m_aPanels[ ++i ]	= HexPfl_P;
	m_aPanels[ ++i ]	= HexHook_P;
	m_aPanels[ ++i ]	= HexHck_P;
	m_aPanels[ ++i ]	= HexAddr_P;
	m_aPanels[ ++i ]	= HexVal_P;
	m_aPanels[ ++i ]	= HexQ_P;
	m_aPanels[ ++i ]	= HexOut_P;
	m_aPanels[ ++i ]	= HexRamData_P;
	m_aPanels[ ++i ]	= HexState_P;
	m_aPanels[ ++i ]	= HexCode_P;
	m_aPanels[ ++i ]	= HexGrid_P;
	m_aPanels[ ++i ]	= HexTree_P;
	m_db.appsLB		= HexList_LB;
	m_db.codesTree	= HexCode_TC;
	m_db.hacksTree	= HexHack_TC;
	m_db.tmpCfg		= false;
	m_db.tmpMode	= HEX_LIST_SESSION;
	wxStandardPaths stdPaths;
	Text path		= m_bCwd ? wxGetCwd() : stdPaths.GetUserDataDir(), val, txt;
	path += xsDirSep + wxT("hex.ini");
	m_db.nowP[ HEX_LIST_ORG ] = path;
	m_db.oldP[ HEX_LIST_ORG ] = path;
	CfgF* cfg = new CfgF( wxT("HackerEX2"), wxT("Awsdert"), path );
	m_db.ini = cfg;
	cfg->SetPath( wxT("/Configuration") );
	cfg->Read( wxT("Session" ), &val, m_db.getDefN() );
	LoadData( m_db, HexList_LB, HEX_LOAD_SAVE2TEMP, val );
//#define TEST_HEXSFIEEE754
#ifdef TEST_HEXSFIEEE754
	ui32 v32 = 0u;
	GetHexFromSF_IEEE754( &v32, wxT("-1.2e-23"), 4u );
	txt.Printf( wxT("%08X: %01e"), v32, v32 );
	wxMessageBox( txt );
#endif
	LoadStateD( m_db.state );
	UpdatePanels();
	const Text DefTheme = wxT("crystal-clear-icons-by-everaldo");
	cfg->Read( wxT("Theme"), &val, DefTheme );
	UpdateTheme( val );
}
G::~G()
{
	m_db.killThreads = true;
	CfgF* cfgN = m_db.ini;
	Text name;
	if ( cfgN != NULL )
	{
		Text path = m_db.nowP[ HEX_LIST_ORG ] + cTild;
		const Text Def		= getGlobalName();
		const Text appName	= wxT("HackerEX");
		const Text vendor	= wxT("Awsdert");
		CfgF cfgT( appName, vendor, path );
		cfgN->SetPath( wxT("/Configuration") );
		cfgN->Write( wxT( "Session" ), m_db.state.nameOld );
		cfgN->Write( wxT( "Theme" ), wxT("crystal-clear-icons-by-everaldo") );
		if ( cfgN->HasEntry( wxT("TotalSessions") ) )
			cfgN->DeleteEntry( wxT("TotalSessions") );
		TxtA data;
		LoadStates(	m_db.state,	cfgT, *cfgN, data, Def, true, false );
		LoadOrgs(	m_db.org, 	cfgT, *cfgN, data, Def, true, false );
	}
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
// TODO(awsdert) Still need to add other tool bar actions
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
	case HexNew_TT_ID:
		m_db.tmpCfg		= false;
		m_db.tmpMode	= m_siListNow;
		LoadData( m_db, HexList_LB, HEX_LOAD_SAVE2FILE, m_db.getNowN( -1 ) );
		break;
	}
}
void G::HexBinExec_B_OnClick( wxCommandEvent& event )
{
	// TODO: Implement Launcher
}
bool l_hack = false;
time_t l_hackNext = 0, l_hackAdd = 0;
void SetGTime( time_t& v, int i )
{
	time_t sec = 1000, min = sec * 60;
	switch ( i )
	{
	case 1: v = 500; break;
	case 2: v = sec; break;
	case 3: v = sec * 5; break;
	case 4: v = sec * 30; break;
	case 5: v = min; break;
	case 6: v = min * 5; break;
	case 7: v = min * 30; break;
	case 8: v = min * 60; break;
	default: v = 0;
	}
}
void G::HexBinHack_B_OnClick( wxCommandEvent& event )
{
	m_db.useCodes();
	int i = HexHook_DD->GetSelection();
	SetGTime( l_hackAdd, i );
	l_hack = ( i > 0 );
	l_hackNext = ( i > 0 ) ? time(NULL) + l_hackAdd : 0;
}
void G::G_OnIdle( wxIdleEvent& event )
{
	time_t now = time(NULL);
	if ( l_hack && now >= l_hackNext )
	{
		m_db.useCodes();
		l_hackNext = now + l_hackAdd;
	}
}
void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
	LBox* lb = HexList_LB;
	int i = lb->GetSelection();
	Text name = lb->GetString( i );
	if ( m_bListCfg )
		m_siListNow = i;
	else if ( m_siListNow < HEX_LIST_HACK )
	{
		m_db.tmpCfg		= false;
		m_db.tmpMode	= m_siListNow;
		m_db.bin.ramNo = HexRam_LB->GetSelection();
		UpdateList( m_db, lb, name );
		ShowData( m_db );
	}
}
void G::HexHack_TC_OnSelect( wxTreeEvent& event )
{
	TrID* data = (TrID*)HexHack_TC->GetItemData( event.GetItem() );
	EditHack( m_db.hacks, m_db.hacks.hackOld );
	m_db.getCodes( data->index );
	m_siListNow = HEX_LIST_HACK;
	ShowPanels();
	//*
	ShowHack( m_db.hacks, data->index );
	ListCodes( HexCode_TC, m_db.appsLB, m_db.codes, m_db.format.format, 0, true );
	m_db.hacks.hackOld = data->index;
	//*/
}
void G::HexCode_TC_OnSelect( wxTreeEvent& event )
{
	m_siListNow	= HEX_LIST_CODE;
	TrID* data	= (TrID*)HexCode_TC->GetItemData( event.GetItem() );
	m_db.codeNo	= data->index;
	ShowPanels();
	//*
	ShowCode( m_db.codes[ data->index ] );
	ListCodes( HexCode_TC, m_db.appsLB, m_db.codes, m_db.format.format, data->index, false );
	//*/
}
void G::HexState_B_OnClick( wxCommandEvent& event )
{
	LoadStateD( m_db.state );
}
