#include "wx_pch.h"
#include "hex2_G.h"

G::G( wxWindow* parent, bool user ) :
	HexGUI( parent )
{
// NOTE: Quick link to GUI constructor
	hexLib& lib		= m_gui.m_lib;
	// Organisation
	M__ORG& org		= lib.m__org;
	org.name_txt	= HexName_TXT;
	org.file_txt	= HexFile_TXT;
	//org.load_b		= HexLoad_B;
	org.save_b		= HexSave_B;
	org.new_b		= HexNew_B;
	org.del_b		= HexDel_B;
	org.get_b		= HexGet_B;
	org.set_b		= HexSet_B;
	// Platform
	M__PFM& pfm		= lib.m__pfm;
	pfm.name_txt	= HexName_TXT;
	pfm.file_txt	= HexFile_TXT;
	pfm.endian_dd	= HexEndian_DD;
	//pfm.load_b		= HexLoad_B;
	pfm.save_b		= HexSave_B;
	pfm.new_b		= HexNew_B;
	pfm.del_b		= HexDel_B;
	pfm.get_b		= HexGet_B;
	pfm.set_b		= HexSet_B;
	// Binary
	M__BIN& bin		= lib.m__bin;
	bin.name_txt	= HexName_TXT;
	bin.file_txt	= HexFile_TXT;
	bin.path_b		= HexBinPath_B;
	bin.path_txt	= HexBinPath_TXT;
	bin.bind_b		= HexBinBind_B;
	bin.bind_txt	= HexBinBind_TXT;
	//bin.load_b		= HexLoad_B;
	bin.save_b		= HexSave_B;
	bin.new_b		= HexNew_B;
	bin.del_b		= HexDel_B;
	bin.get_b		= HexGet_B;
	bin.set_b		= HexSet_B;
	// Profile
	M__PFL& pfl		= lib.m__pfl;
	pfl.name_txt	= HexName_TXT;
	pfl.file_txt	= HexFile_TXT;
	pfl.pid__txt	= HexPID_TXT;
	pfl.sid__txt	= HexSID_TXT;
	pfl.notes_ta	= HexNotes_TA;
	//pfl.load_b		= HexLoad_B;
	pfl.save_b		= HexSave_B;
	pfl.new_b		= HexNew_B;
	pfl.del_b		= HexDel_B;
	pfl.get_b		= HexGet_B;
	pfl.set_b		= HexSet_B;
	// Search / Results / Editor
	M_FIND& find	= lib.m_find;
	find.addr_txt	= HexAddr_TXT;
	find.val__txt	= HexVal_TXT;
	// - Editor
	find.edit_g		= HexGrid_G;
	find.eGet_b		= HexGet_B;
	find.eSet_b		= HexSet_B;
	find.eJump_b	= HexJump_B;
	// Connect Events
	lib.setGuiMode( HEX_LIST_SESSION );
}
G::~G()
{
	m_gui.m_lib.setGuiMode( -1 );
}
void G::HexFAdd_B_OnClick( wxCommandEvent& event )
{
	int i = HexFormat_LB->GetSelection();
	if ( i >= 0 )
	{
		hexLib& db = m_gui.m_lib;
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
		hexLib& db	= m_gui.m_lib;
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
	m_gui.m_tree->wait = m_gui.SetGTime( i );
	m_gui.NewCodeThread();
}
void G::HexList_LB_OnSelect( wxCommandEvent& event )
{
	hexLib& db = m_gui.m_lib;
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

void G::HexCode_TC_OnSelect( wxTreeEvent& event )
{
	hexLib& lib	= m_gui.m_lib;
	TrID* data	= (TrID*)HexCode_TC->GetItemData( event.GetItem() );
	lib	= data->index;
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
