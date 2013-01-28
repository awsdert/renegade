#include "wx_pch.h"
#include "hex2_G.h"

G::G( wxWindow* parent, bool user ) :
	HexGUI( parent )
{
// NOTE: Quick link to GUI constructor
	// Lists
	m_bCwd		= wxFileExists( wxT( "hex.ini" ) );
	m_bListCfg	= true;
	hexDB& db = m_gui.m_db;
	db.nowL	= HEX_LIST_SESSION;
	db.oldL	= -1;
	db.SetGui( &m_gui );
	ui32 i = 0;
	HexFormat_LB->Append( getFormats() );
	db.pb = HexProgress_PB;
	m_aPanels[ i ]		= HexName_P;
	m_aPanels[ ++i ]	= HexFile_P;
	m_aPanels[ ++i ]	= HexState_P;
	m_aPanels[ ++i ]	= HexBin_P;
	m_aPanels[ ++i ]	= HexRam_P;
	m_aPanels[ ++i ]	= HexRamData_P;
	m_aPanels[ ++i ]	= HexPfl_P;
	m_aPanels[ ++i ]	= HexEndian_P;
	m_aPanels[ ++i ]	= HexHook_P;
	m_aPanels[ ++i ]	= HexFormat_P;
	m_aPanels[ ++i ]	= HexHck_P;
	m_aPanels[ ++i ]	= HexCode_P;
	m_aPanels[ ++i ]	= HexQ_P;
	m_aPanels[ ++i ]	= HexOut_P;
	m_aPanels[ ++i ]	= HexEdit_P;
	m_aPanels[ ++i ]	= HexAddr_P;
	m_aPanels[ ++i ]	= HexVal_P;
	m_aPanels[ ++i ]	= HexGrid_G;
	m_aPanels[ ++i ]	= HexTree_P;
	db.appsLB		= HexList_LB;
	db.codesTree	= HexCode_TC;
	db.hacksTree	= HexHack_TC;
	db.tmpCfg		= false;
	db.tmpMode	= HEX_LIST_SESSION;
	Text path		= m_bCwd ? db.cwd : db.stdPaths.GetUserDataDir(), val, txt;
	path += xsDirSep + wxT("hex.ini");
	db.nowP[ HEX_LIST_ORG ] = path;
	db.oldP[ HEX_LIST_ORG ] = path;
	CfgF* cfg = new CfgF( wxT("HackerEX2"), wxT("Awsdert"), path );
	db.ini = cfg;
	cfg->SetPath( wxT("/Configuration") );
	cfg->Read( wxT("Session" ), &val, db.getDefN() );
	db.loadData( HEX_LOAD_SAVE2TEMP, val );
//#define TEST_HEXSFIEEE754
#ifdef TEST_HEXSFIEEE754
	ui32 v32 = 0u;
	GetHexFromSF_IEEE754( &v32, wxT("-1.2e-23"), 4u );
	txt.Printf( wxT("%08X: %01e"), v32, v32 );
	wxMessageBox( txt );
#endif
	LoadStateD( db.state ); 
	UpdatePanels();
	const Text DefTheme = wxT("crystal-clear-icons-by-everaldo");
	cfg->Read( wxT("Theme"), &val, DefTheme );
	UpdateTheme( val );
	db.eGrid_Connect( HexGrid_G, HexHook_DD, HexVSize_SB, HexEdit_TXT, HexAddr_TXT, HexVal_TXT, HexJump_B, HexEGet_B, HexESet_B );
}
G::~G()
{
	hexDB& db = m_gui.m_db;
	db.eGrid_Disconnect();
	m_gui.m_hackAdd = 0;
	m_gui.m_editAdd = 0;
	db.killThreads = true;
	CfgF* cfgN = db.ini;
	Text name;
	if ( cfgN != NULL )
	{
		Text path = db.nowP[ HEX_LIST_ORG ] + cTild;
		const Text Def		= getGlobalName();
		const Text appName	= wxT("HackerEX");
		const Text vendor	= wxT("Awsdert");
		CfgF cfgT( appName, vendor, path );
		cfgN->SetPath( wxT("/Configuration") );
		cfgN->Write( wxT( "Session" ), db.state.nameOld );
		cfgN->Write( wxT( "Theme" ), wxT("crystal-clear-icons-by-everaldo") );
		if ( cfgN->HasEntry( wxT("TotalSessions") ) )
			cfgN->DeleteEntry( wxT("TotalSessions") );
		TxtA data;
		LoadStates(	db.state,	cfgT, *cfgN, data, Def, true, false );
		LoadOrgs(	db.org, 	cfgT, *cfgN, data, Def, true, false );
	}
	for ( int i = 0; i < HEX_LIST_COUNT; ++i )
	{
		name = db.nowP[ i ] + cTild;
		if ( wxFileExists(	name ) )
			wxRemoveFile(	name );
		name = db.oldP[ i ] + cTild;
		if ( wxFileExists(	name ) )
			wxRemoveFile(	name );
	}
}
void G::HexGUI_TB_OnToolExec( wxCommandEvent& event )
{
// TODO(awsdert) Still need to add other tool bar actions
	hexDB& db = m_gui.m_db;
	db.tmpLB	= HexList_LB;
	db.tmpMode	= db.nowL;
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
		db.tmpCfg		= false;
		db.loadData( HEX_LOAD_SAVE2FILE, db.getNowN( db.nowL ) );
		break;
	case HexNew_TT_ID:
		db.tmpCfg		= false;
		db.loadData( HEX_LOAD_SAVE2FILE, db.getNowN( -1 ) );
		break;
	}
}
void G::HexBinExec_B_OnClick( wxCommandEvent& event )
{
	// TODO: Implement Launcher
}
void G::HexFAdd_B_OnClick( wxCommandEvent& event )
{
	int i = HexFormat_LB->GetSelection();
	if ( i >= 0 )
	{
		hexDB& db = m_gui.m_db;
		db.tmpCfg	= false;
		db.tmpMode	= HEX_LIST_FORMAT;
		db.tmpLB	= HexList_LB;
		db.loadData( HEX_LOAD_LIST, HexFormat_LB->GetString( i ) );
		ShowFormat( db.format );
	}
}
void G::HexConvert_B_OnClick( wxCommandEvent& event )
{
	int i = HexFormat_LB->GetSelection();
	if ( i >= 0 )
	{
		hexDB& db	= m_gui.m_db;
		Text name	= HexFormat_LB->GetString( i );
		db.tmpCfg	= false;
		db.tmpMode	= HEX_LIST_FORMAT;
		db.tmpLB	= HexList_LB;
		db.convertF2F( getFormat( name ) );
		db.loadData( HEX_LOAD_LIST, name );
		ShowFormat( db.format );
	}
}
void G::HexBinHack_B_OnClick( wxCommandEvent& event )
{
	int i = HexHook_DD->GetSelection();
	m_gui.m_hackAdd = m_gui.SetGTime( i );
	m_gui.NewCodeThread();
}
void G::G_OnIdle( wxIdleEvent& event )
{
	// TODO: Implement G::G_OnIdle event
}
void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
	hexDB& db = m_gui.m_db;
	LBox* lb = HexList_LB;
	int i = lb->GetSelection();
	Text name = lb->GetString( i );
	if ( m_bListCfg )
		db.nowL = i;
	else if ( db.nowL < HEX_LIST_HACK )
	{
		db.tmpCfg	= false;
		db.tmpMode	= db.nowL;
		db.tmpLB	= lb;
		db.bin.ramNo = HexRam_LB->GetSelection();
		UpdateList( db, name );
		ShowData( db );
	}
}
void G::HexHack_TC_OnSelect( wxTreeEvent& event )
{
	hexDB& db = m_gui.m_db;
	TrID* data = (TrID*)HexHack_TC->GetItemData( event.GetItem() );
	EditHack( db.hacks, db.hacks.hackOld );
	if ( db.nowL != HEX_LIST_HACK )
		ShowPanels( HEX_LIST_HACK, false );
	db.nowL = HEX_LIST_HACK;
	//*
	ShowHack( db.hacks, data->index );
	db.getCodes( data->index );
	ListCodes( HexCode_TC, HexList_LB, db.codes, db.format.format, -1 );
	db.hacks.hackOld = data->index;
	//*/
}
void G::HexCode_TC_OnSelect( wxTreeEvent& event )
{
	hexDB& db	= m_gui.m_db;
	TrID* data	= (TrID*)HexCode_TC->GetItemData( event.GetItem() );
	db.codeNo	= data->index;
	if ( db.nowL != HEX_LIST_CODE )
		ShowPanels( HEX_LIST_CODE, false );
	db.nowL	= HEX_LIST_CODE;
	//*
	ShowCode( db.codes[ data->index ] );
	ListCodes( HexCode_TC, HexList_LB, db.codes, db.format.format, data->index );
	//*/
}
void G::HexState_B_OnClick( wxCommandEvent& event )
{
	LoadStateD( m_gui.m_db.state );
}
