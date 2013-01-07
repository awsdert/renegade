///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx_pch.h"

#include "hex2_wxFB.h"

///////////////////////////////////////////////////////////////////////////

HexGUI::HexGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,300 ), wxDefaultSize );
	
	wxBoxSizer* HexGUI_LV;
	HexGUI_LV = new wxBoxSizer( wxVERTICAL );
	
	HexGUI_TB = new wxToolBar( this, HexGUI_TB_ID, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_HORZ_TEXT|wxTB_TEXT );
	HexGUI_TB->SetToolSeparation( 1 );
	HexGUI_TB->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	HexGUI_TB->AddTool( HexMain_TT_ID, _("&Main"), wxNullBitmap, wxNullBitmap, wxITEM_RADIO, wxEmptyString, _("Display main list"), NULL ); 
	
	HexGUI_TB->AddTool( HexList_TT_ID, _("&List"), wxNullBitmap, wxNullBitmap, wxITEM_RADIO, wxEmptyString, _("List data in memory"), NULL ); 
	
	HexGUI_TB->AddTool( HexSave_TT_ID, _("&Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Save memory to file"), NULL ); 
	
	HexGUI_TB->AddSeparator(); 
	
	HexGUI_TB->AddTool( HexNew_TT_ID, _("&New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Add item to memory"), NULL ); 
	
	HexGUI_TB->AddTool( HexDel_TT_ID, _("&Delete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Remove item from memory"), NULL ); 
	
	HexGUI_TB->AddTool( HexSet_TT_ID, _("&Comit"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Apply changes to item in memory"), NULL ); 
	
	HexGUI_TB->AddTool( HexGet_TT_ID, _("&Restore"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Restore to item in memory"), NULL ); 
	
	HexGUI_TB->Realize(); 
	
	HexGUI_LV->Add( HexGUI_TB, 0, wxEXPAND, 0 );
	
	HexQ_TB = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER|wxTB_NOICONS|wxTB_TEXT ); 
	HexQ_TB->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	HexQ_TB->Enable( false );
	
	HexQ_TB->AddTool( HexQDump_TT_ID, _("D"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Dump"), NULL ); 
	
	HexQ_TB->AddTool( HexQFind_TT_ID, _("S"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Search"), NULL ); 
	
	HexQ_TB->AddTool( HexQUndo_TT_ID, _("U"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Undo Search"), NULL ); 
	
	HexQ_TB->AddSeparator(); 
	
	HexQ_TB->AddTool( HexQCT_TT_ID, _("C"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Contains"), NULL ); 
	
	HexQ_TB->AddTool( HexQCF_TTID, _("!C"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Does Not Contain"), NULL ); 
	
	HexQ_TB->AddTool( HexQEQ_TT_ID, _("=="), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Equal To"), NULL ); 
	
	HexQ_TB->AddTool( HexQNE_TT_ID, _("!="), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Not Equal To"), NULL ); 
	
	HexQ_TB->AddTool( HexQMT_TT_ID, _(">"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("More Than"), NULL ); 
	
	HexQ_TB->AddTool( HexQME_TT_ID, _(">="), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("More Than Or Equal To"), NULL ); 
	
	HexQ_TB->AddTool( HexQLT_TT_ID, _("<"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Less Than"), NULL ); 
	
	HexQ_TB->AddTool( HexQLE_TT_ID, _("<="), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, _("Less Than Or Equal To"), NULL ); 
	
	HexQ_TB->Realize(); 
	
	HexGUI_LV->Add( HexQ_TB, 0, wxEXPAND, 5 );
	
	HexGUI_SP = new wxSplitterWindow( this, HexGUI_SP_ID, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME );
	HexGUI_SP->Connect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::HexGUI_SPOnIdle ), NULL, this );
	HexGUI_SP->SetMinimumPaneSize( 200 );
	
	HexBody_SW = new wxScrolledWindow( HexGUI_SP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	HexBody_SW->SetScrollRate( 5, 5 );
	wxBoxSizer* HexBody_LV;
	HexBody_LV = new wxBoxSizer( wxVERTICAL );
	
	HexName_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexName_P->Hide();
	HexName_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexName_LFH;
	HexName_LFH = new wxStaticBoxSizer( new wxStaticBox( HexName_P, wxID_ANY, _("Name") ), wxHORIZONTAL );
	
	HexName_TXT = new wxTextCtrl( HexName_P, HexName_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexName_LFH->Add( HexName_TXT, 1, wxALL, 5 );
	
	HexName_P->SetSizer( HexName_LFH );
	HexName_P->Layout();
	HexName_LFH->Fit( HexName_P );
	HexBody_LV->Add( HexName_P, 0, wxEXPAND | wxALL, 5 );
	
	HexState_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexState_P->Hide();
	
	wxStaticBoxSizer* HexState_LV;
	HexState_LV = new wxStaticBoxSizer( new wxStaticBox( HexState_P, wxID_ANY, _("Session") ), wxVERTICAL );
	
	HexOrgName_S = new wxStaticText( HexState_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexOrgName_S->Wrap( -1 );
	HexState_LV->Add( HexOrgName_S, 0, wxALL, 5 );
	
	HexPfmName_S = new wxStaticText( HexState_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexPfmName_S->Wrap( -1 );
	HexState_LV->Add( HexPfmName_S, 0, wxALL, 5 );
	
	HexBinName_S = new wxStaticText( HexState_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexBinName_S->Wrap( -1 );
	HexState_LV->Add( HexBinName_S, 0, wxALL, 5 );
	
	HexPflName_S = new wxStaticText( HexState_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexPflName_S->Wrap( -1 );
	HexState_LV->Add( HexPflName_S, 0, wxALL, 5 );
	
	HexHackFormat_S = new wxStaticText( HexState_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexHackFormat_S->Wrap( -1 );
	HexState_LV->Add( HexHackFormat_S, 0, wxALL, 5 );
	
	HexState_B = new wxButton( HexState_P, HexState_B_ID, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	HexState_LV->Add( HexState_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	HexState_P->SetSizer( HexState_LV );
	HexState_P->Layout();
	HexState_LV->Fit( HexState_P );
	HexBody_LV->Add( HexState_P, 0, wxEXPAND | wxALL, 5 );
	
	HexFile_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexFile_P->Hide();
	HexFile_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexFile_LFH;
	HexFile_LFH = new wxStaticBoxSizer( new wxStaticBox( HexFile_P, wxID_ANY, _("File") ), wxHORIZONTAL );
	
	HexFile_TXT = new wxTextCtrl( HexFile_P, HexFile_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexFile_LFH->Add( HexFile_TXT, 1, wxALL|wxEXPAND, 5 );
	
	HexFile_P->SetSizer( HexFile_LFH );
	HexFile_P->Layout();
	HexFile_LFH->Fit( HexFile_P );
	HexBody_LV->Add( HexFile_P, 0, wxEXPAND | wxALL, 5 );
	
	HexEndian_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexEndian_P->Hide();
	HexEndian_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexEndian_LFH;
	HexEndian_LFH = new wxStaticBoxSizer( new wxStaticBox( HexEndian_P, wxID_ANY, _("Endian") ), wxHORIZONTAL );
	
	wxString HexEndian_DDChoices[] = { _("Little"), _("Big"), _("Little Big") };
	int HexEndian_DDNChoices = sizeof( HexEndian_DDChoices ) / sizeof( wxString );
	HexEndian_DD = new wxChoice( HexEndian_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, HexEndian_DDNChoices, HexEndian_DDChoices, 0 );
	HexEndian_DD->SetSelection( 0 );
	HexEndian_LFH->Add( HexEndian_DD, 1, wxALL|wxEXPAND, 5 );
	
	HexEndian_P->SetSizer( HexEndian_LFH );
	HexEndian_P->Layout();
	HexEndian_LFH->Fit( HexEndian_P );
	HexBody_LV->Add( HexEndian_P, 0, wxEXPAND | wxALL, 5 );
	
	HexBin_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexBin_P->Hide();
	HexBin_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexBin_LFV;
	HexBin_LFV = new wxStaticBoxSizer( new wxStaticBox( HexBin_P, wxID_ANY, _("Hook > Binary") ), wxVERTICAL );
	
	wxFlexGridSizer* HexBin_LFG;
	HexBin_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexBin_LFG->AddGrowableCol( 1 );
	HexBin_LFG->SetFlexibleDirection( wxBOTH );
	HexBin_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexBinBind_S = new wxStaticText( HexBin_P, wxID_ANY, _("Bind"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinBind_S->Wrap( -1 );
	HexBin_LFG->Add( HexBinBind_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexBinBind_TXT = new wxTextCtrl( HexBin_P, HexBinBind_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFG->Add( HexBinBind_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexBinPath_S = new wxStaticText( HexBin_P, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinPath_S->Wrap( -1 );
	HexBin_LFG->Add( HexBinPath_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexBinPath_TXT = new wxTextCtrl( HexBin_P, HexBinPath_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFG->Add( HexBinPath_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexBin_LFV->Add( HexBin_LFG, 0, wxEXPAND, 5 );
	
	HexBinApp_RB = new wxRadioButton( HexBin_P, wxID_ANY, _("Application (Any)"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFV->Add( HexBinApp_RB, 0, wxALL, 5 );
	
	HexBinWin_RB = new wxRadioButton( HexBin_P, wxID_ANY, _("Application (GUI / GFX)"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFV->Add( HexBinWin_RB, 0, wxALL, 5 );
	
	HexBinFSO_RB = new wxRadioButton( HexBin_P, wxID_ANY, _("File / Archive"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFV->Add( HexBinFSO_RB, 0, wxALL, 5 );
	
	wxGridSizer* HexBin_LG;
	HexBin_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	HexBinExec_B = new wxButton( HexBin_P, HexBinExec_B_ID, _("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinExec_B->SetMinSize( wxSize( 70,-1 ) );
	
	HexBin_LG->Add( HexBinExec_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	HexBinHack_B = new wxButton( HexBin_P, HexBinHack_B_ID, _("Hack"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinHack_B->SetMinSize( wxSize( 70,-1 ) );
	
	HexBin_LG->Add( HexBinHack_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	HexBin_LFV->Add( HexBin_LG, 0, wxEXPAND, 5 );
	
	HexBin_P->SetSizer( HexBin_LFV );
	HexBin_P->Layout();
	HexBin_LFV->Fit( HexBin_P );
	HexBody_LV->Add( HexBin_P, 0, wxEXPAND | wxALL, 5 );
	
	HexRam_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexRam_P->Hide();
	
	wxStaticBoxSizer* HexRam_LFV;
	HexRam_LFV = new wxStaticBoxSizer( new wxStaticBox( HexRam_P, wxID_ANY, _("Memory") ), wxVERTICAL );
	
	HexRam_LB = new wxListBox( HexRam_P, HexRam_LB_ID, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	HexRam_LFV->Add( HexRam_LB, 0, wxALL, 5 );
	
	HexRamData_P = new wxPanel( HexRam_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* HexRamData_LV;
	HexRamData_LV = new wxBoxSizer( wxVERTICAL );
	
	HexRamSize_S1 = new wxStaticText( HexRamData_P, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	HexRamSize_S1->Wrap( -1 );
	HexRamSize_S1->Hide();
	
	HexRamData_LV->Add( HexRamSize_S1, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	wxBoxSizer* HexRamSize_LH;
	HexRamSize_LH = new wxBoxSizer( wxHORIZONTAL );
	
	HexRamSize_S2 = new wxStaticText( HexRamData_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	HexRamSize_S2->Wrap( -1 );
	HexRamSize_LH->Add( HexRamSize_S2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexRamSize_TXT = new wxTextCtrl( HexRamData_P, HexRamSize_TXT_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexRamSize_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexRamSize_LH->Add( HexRamSize_TXT, 1, wxALL, 5 );
	
	HexRamData_LV->Add( HexRamSize_LH, 1, wxEXPAND, 5 );
	
	HexRamData_P->SetSizer( HexRamData_LV );
	HexRamData_P->Layout();
	HexRamData_LV->Fit( HexRamData_P );
	HexRam_LFV->Add( HexRamData_P, 1, wxEXPAND | wxALL, 5 );
	
	HexRam_P->SetSizer( HexRam_LFV );
	HexRam_P->Layout();
	HexRam_LFV->Fit( HexRam_P );
	HexBody_LV->Add( HexRam_P, 0, wxEXPAND | wxALL, 5 );
	
	HexPfl_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexPfl_P->Hide();
	
	wxStaticBoxSizer* HexPfl_LFV;
	HexPfl_LFV = new wxStaticBoxSizer( new wxStaticBox( HexPfl_P, wxID_ANY, _("Profile") ), wxVERTICAL );
	
	wxFlexGridSizer* HexPfl_LFG;
	HexPfl_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexPfl_LFG->AddGrowableCol( 1 );
	HexPfl_LFG->SetFlexibleDirection( wxBOTH );
	HexPfl_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexPID_S = new wxStaticText( HexPfl_P, wxID_ANY, _("Profile ID"), wxDefaultPosition, wxDefaultSize, 0 );
	HexPID_S->Wrap( -1 );
	HexPfl_LFG->Add( HexPID_S, 0, wxALL, 5 );
	
	HexPID_TXT = new wxTextCtrl( HexPfl_P, HexPID_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexPID_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexPfl_LFG->Add( HexPID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexSID_S = new wxStaticText( HexPfl_P, wxID_ANY, _("Serial ID"), wxDefaultPosition, wxDefaultSize, 0 );
	HexSID_S->Wrap( -1 );
	HexPfl_LFG->Add( HexSID_S, 0, wxALL, 5 );
	
	HexSID_TXT = new wxTextCtrl( HexPfl_P, HexSID_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexSID_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexPfl_LFG->Add( HexSID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexPfl_LFV->Add( HexPfl_LFG, 0, wxEXPAND, 5 );
	
	HexNotes_S = new wxStaticText( HexPfl_P, wxID_ANY, _("Notes"), wxDefaultPosition, wxDefaultSize, 0 );
	HexNotes_S->Wrap( -1 );
	HexPfl_LFV->Add( HexNotes_S, 0, wxALL, 5 );
	
	HexNotes_TA = new wxTextCtrl( HexPfl_P, HexNotes_TA_ID, wxEmptyString, wxDefaultPosition, wxSize( 100,100 ), wxTE_DONTWRAP|wxTE_LEFT|wxTE_MULTILINE );
	HexNotes_TA->SetMinSize( wxSize( 100,100 ) );
	
	HexPfl_LFV->Add( HexNotes_TA, 0, wxALL|wxEXPAND, 5 );
	
	wxString HexRegion_DDChoices[] = { _("Profile is..."), _("Show Profiles...") };
	int HexRegion_DDNChoices = sizeof( HexRegion_DDChoices ) / sizeof( wxString );
	HexRegion_DD = new wxChoice( HexPfl_P, HexRegion_DD_ID, wxDefaultPosition, wxDefaultSize, HexRegion_DDNChoices, HexRegion_DDChoices, 0 );
	HexRegion_DD->SetSelection( 0 );
	HexPfl_LFV->Add( HexRegion_DD, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* HexRegion_LFG;
	HexRegion_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexRegion_LFG->AddGrowableCol( 1 );
	HexRegion_LFG->SetFlexibleDirection( wxBOTH );
	HexRegion_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxArrayString HexRegion_CLBChoices;
	HexRegion_CLB = new wxCheckListBox( HexPfl_P, HexRegion_CLB_ID, wxDefaultPosition, wxSize( 75,-1 ), HexRegion_CLBChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	HexRegion_CLB->SetMinSize( wxSize( 75,-1 ) );
	
	HexRegion_LFG->Add( HexRegion_CLB, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	HexRegionAll_RB = new wxRadioButton( HexPfl_P, HexRegionAll_RB_ID, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	HexRegionAll_RB->SetValue( true ); 
	bSizer71->Add( HexRegionAll_RB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexRegionSel_RB = new wxRadioButton( HexPfl_P, HexRegionSel_RB_ID, _("Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( HexRegionSel_RB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexRegion_LFG->Add( bSizer71, 1, wxEXPAND, 5 );
	
	HexPfl_LFV->Add( HexRegion_LFG, 0, wxEXPAND, 5 );
	
	HexPfl_P->SetSizer( HexPfl_LFV );
	HexPfl_P->Layout();
	HexPfl_LFV->Fit( HexPfl_P );
	HexBody_LV->Add( HexPfl_P, 0, wxEXPAND | wxALL, 5 );
	
	HexHck_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexHck_P->Hide();
	
	wxStaticBoxSizer* HexHck_LFV;
	HexHck_LFV = new wxStaticBoxSizer( new wxStaticBox( HexHck_P, wxID_ANY, _("Hack") ), wxVERTICAL );
	
	HexUse_RB = new wxRadioButton( HexHck_P, HexUse_RB_ID, _("Use"), wxDefaultPosition, wxDefaultSize, 0 );
	HexUse_RB->Hide();
	
	HexHck_LFV->Add( HexUse_RB, 0, wxALL, 5 );
	
	HexUse_CB = new wxCheckBox( HexHck_P, HexUse_CB_ID, _("Use"), wxDefaultPosition, wxDefaultSize, 0 );
	HexHck_LFV->Add( HexUse_CB, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->AddGrowableCol( 1 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexHackKids_S = new wxStaticText( HexHck_P, wxID_ANY, _("Can Use"), wxDefaultPosition, wxDefaultSize, 0 );
	HexHackKids_S->Wrap( -1 );
	fgSizer8->Add( HexHackKids_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString HexHackKids_DDChoices[] = { _("One Child"), _("All Children") };
	int HexHackKids_DDNChoices = sizeof( HexHackKids_DDChoices ) / sizeof( wxString );
	HexHackKids_DD = new wxChoice( HexHck_P, HexHackKids_DD_ID, wxDefaultPosition, wxSize( 50,-1 ), HexHackKids_DDNChoices, HexHackKids_DDChoices, 0 );
	HexHackKids_DD->SetSelection( 1 );
	HexHackKids_DD->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer8->Add( HexHackKids_DD, 0, wxALL|wxEXPAND, 5 );
	
	HexHck_LFV->Add( fgSizer8, 0, wxEXPAND, 5 );
	
	HexHck_P->SetSizer( HexHck_LFV );
	HexHck_P->Layout();
	HexHck_LFV->Fit( HexHck_P );
	HexBody_LV->Add( HexHck_P, 0, wxEXPAND | wxALL, 5 );
	
	HexCode_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexCode_P->Hide();
	
	wxStaticBoxSizer* HexCode_LFV;
	HexCode_LFV = new wxStaticBoxSizer( new wxStaticBox( HexCode_P, wxID_ANY, _("Code") ), wxVERTICAL );
	
	wxGridBagSizer* HexCode_LGB;
	HexCode_LGB = new wxGridBagSizer( 0, 0 );
	HexCode_LGB->AddGrowableCol( 1 );
	HexCode_LGB->SetFlexibleDirection( wxBOTH );
	HexCode_LGB->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexCType_S = new wxStaticText( HexCode_P, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	HexCType_S->Wrap( -1 );
	HexCode_LGB->Add( HexCType_S, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString HexCType_DDChoices[] = { _("Write"), _("Copy"), _("Increase"), _("Decrease"), _("Test"), _("List") };
	int HexCType_DDNChoices = sizeof( HexCType_DDChoices ) / sizeof( wxString );
	HexCType_DD = new wxChoice( HexCode_P, HexCType_DD_ID, wxDefaultPosition, wxDefaultSize, HexCType_DDNChoices, HexCType_DDChoices, 0 );
	HexCType_DD->SetSelection( 0 );
	HexCType_DD->SetMinSize( wxSize( 50,-1 ) );
	
	HexCode_LGB->Add( HexCType_DD, wxGBPosition( 0, 1 ), wxGBSpan( 1, 2 ), wxALL|wxEXPAND, 5 );
	
	HexLoop_S = new wxStaticText( HexCode_P, wxID_ANY, _("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
	HexLoop_S->Wrap( -1 );
	HexCode_LGB->Add( HexLoop_S, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexLoop_TXT = new wxTextCtrl( HexCode_P, HexLoop_TXT_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexCode_LGB->Add( HexLoop_TXT, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	HexLoop_SPB = new wxSpinButton( HexCode_P, wxID_ANY, wxDefaultPosition, wxSize( 15,-1 ), wxSP_ARROW_KEYS );
	HexLoop_SPB->SetMinSize( wxSize( 15,-1 ) );
	
	HexCode_LGB->Add( HexLoop_SPB, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );
	
	HexCode_LFV->Add( HexCode_LGB, 1, wxEXPAND, 5 );
	
	HexCode_P->SetSizer( HexCode_LFV );
	HexCode_P->Layout();
	HexCode_LFV->Fit( HexCode_P );
	HexBody_LV->Add( HexCode_P, 0, wxEXPAND | wxALL, 5 );
	
	HexAddr_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexAddr_P->Hide();
	
	wxStaticBoxSizer* HexAddr_LFV;
	HexAddr_LFV = new wxStaticBoxSizer( new wxStaticBox( HexAddr_P, wxID_ANY, _("Address / Pointer") ), wxVERTICAL );
	
	HexAddr_TXT = new wxTextCtrl( HexAddr_P, HexAddr_TXT_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexAddr_TXT->SetMinSize( wxSize( 100,-1 ) );
	
	HexAddr_LFV->Add( HexAddr_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexDepth_S = new wxStaticText( HexAddr_P, wxID_ANY, _("Pointer Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	HexDepth_S->Wrap( -1 );
	HexAddr_LFV->Add( HexDepth_S, 0, wxALL, 5 );
	
	HexDepth_SL = new wxSlider( HexAddr_P, wxID_ANY, 0, 0, 15, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTTOM|wxSL_HORIZONTAL|wxSL_LABELS );
	HexDepth_SL->SetMinSize( wxSize( 100,-1 ) );
	
	HexAddr_LFV->Add( HexDepth_SL, 0, wxALL|wxEXPAND, 5 );
	
	HexAddr_P->SetSizer( HexAddr_LFV );
	HexAddr_P->Layout();
	HexAddr_LFV->Fit( HexAddr_P );
	HexBody_LV->Add( HexAddr_P, 0, wxEXPAND | wxALL, 5 );
	
	HexVal_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexVal_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexVal_LFV;
	HexVal_LFV = new wxStaticBoxSizer( new wxStaticBox( HexVal_P, wxID_ANY, _("Value") ), wxVERTICAL );
	
	wxString HexTest_DDChoices[] = { _("Contains"), _("Does Not Contain"), _("Equal To"), _("Not Equal To"), _("More Than"), _("More Than Or Equal To"), _("Less Than"), _("Less Than Or Equal To") };
	int HexTest_DDNChoices = sizeof( HexTest_DDChoices ) / sizeof( wxString );
	HexTest_DD = new wxChoice( HexVal_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, HexTest_DDNChoices, HexTest_DDChoices, 0 );
	HexTest_DD->SetSelection( 0 );
	HexTest_DD->Hide();
	HexTest_DD->SetMinSize( wxSize( 50,-1 ) );
	
	HexVal_LFV->Add( HexTest_DD, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* HexVal_LF;
	HexVal_LF = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexVal_LF->AddGrowableCol( 0 );
	HexVal_LF->SetFlexibleDirection( wxBOTH );
	HexVal_LF->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexVal_TXT = new wxTextCtrl( HexVal_P, HexVal_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexVal_LF->Add( HexVal_TXT, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );
	
	HexVal_SPB = new wxSpinButton( HexVal_P, wxID_ANY, wxDefaultPosition, wxSize( 15,-1 ), wxSP_ARROW_KEYS );
	HexVal_SPB->SetMinSize( wxSize( 15,-1 ) );
	
	HexVal_LF->Add( HexVal_SPB, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );
	
	HexVal_LFV->Add( HexVal_LF, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* HexVInfo_LF;
	HexVInfo_LF = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexVInfo_LF->AddGrowableCol( 1 );
	HexVInfo_LF->SetFlexibleDirection( wxBOTH );
	HexVInfo_LF->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString HexInc_DDChoices[] = { _("+="), _("-="), _("*="), _("/=") };
	int HexInc_DDNChoices = sizeof( HexInc_DDChoices ) / sizeof( wxString );
	HexInc_DD = new wxChoice( HexVal_P, HexInc_DD_ID, wxDefaultPosition, wxDefaultSize, HexInc_DDNChoices, HexInc_DDChoices, 0 );
	HexInc_DD->SetSelection( 0 );
	HexInc_DD->SetMinSize( wxSize( 40,-1 ) );
	
	HexVInfo_LF->Add( HexInc_DD, 0, wxALL, 5 );
	
	HexInc_TXT = new wxTextCtrl( HexVal_P, HexVal_ID, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	HexInc_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexVInfo_LF->Add( HexInc_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexVType_S = new wxStaticText( HexVal_P, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	HexVType_S->Wrap( -1 );
	HexVInfo_LF->Add( HexVType_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString HexVType_DDChoices[] = { _("Hex"), _("Text"), _("Signed Integer"), _("Unsigned Integer"), _("Float - IEEE754") };
	int HexVType_DDNChoices = sizeof( HexVType_DDChoices ) / sizeof( wxString );
	HexVType_DD = new wxChoice( HexVal_P, HexVType_DD_ID, wxDefaultPosition, wxDefaultSize, HexVType_DDNChoices, HexVType_DDChoices, 0 );
	HexVType_DD->SetSelection( 0 );
	HexVType_DD->SetMinSize( wxSize( 50,-1 ) );
	
	HexVInfo_LF->Add( HexVType_DD, 0, wxALL|wxEXPAND, 5 );
	
	HexVSize_S = new wxStaticText( HexVal_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	HexVSize_S->Wrap( -1 );
	HexVInfo_LF->Add( HexVSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexVSize_SB = new wxSpinCtrl( HexVal_P, HexVSize_SB_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 16, 1 );
	HexVSize_SB->SetMinSize( wxSize( 50,-1 ) );
	
	HexVInfo_LF->Add( HexVSize_SB, 0, wxALL|wxEXPAND, 5 );
	
	HexVal_LFV->Add( HexVInfo_LF, 0, wxEXPAND, 5 );
	
	HexVal_P->SetSizer( HexVal_LFV );
	HexVal_P->Layout();
	HexVal_LFV->Fit( HexVal_P );
	HexBody_LV->Add( HexVal_P, 0, wxEXPAND | wxALL, 5 );
	
	HexQ_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexQ_P->Hide();
	HexQ_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexQ_LFV;
	HexQ_LFV = new wxStaticBoxSizer( new wxStaticBox( HexQ_P, wxID_ANY, _("Search") ), wxVERTICAL );
	
	HexQOut_S = new wxStaticText( HexQ_P, wxID_ANY, _("Results: 0"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQOut_S->Wrap( -1 );
	HexQOut_S->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	HexQ_LFV->Add( HexQOut_S, 0, wxALL, 5 );
	
	wxArrayString HexVSize_CLBChoices;
	HexVSize_CLB = new wxCheckListBox( HexQ_P, HexVSize_CLB_ID, wxDefaultPosition, wxDefaultSize, HexVSize_CLBChoices, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	HexVSize_CLB->SetMinSize( wxSize( 50,100 ) );
	
	HexQ_LFV->Add( HexVSize_CLB, 0, wxALL|wxEXPAND, 5 );
	
	wxString HexQInfo_DDChoices[] = { _("Any of these must be true"), _("All of these must be true"), _("None of these can be true") };
	int HexQInfo_DDNChoices = sizeof( HexQInfo_DDChoices ) / sizeof( wxString );
	HexQInfo_DD = new wxChoice( HexQ_P, HexQInfo_DD_ID, wxDefaultPosition, wxDefaultSize, HexQInfo_DDNChoices, HexQInfo_DDChoices, 0 );
	HexQInfo_DD->SetSelection( 0 );
	HexQInfo_DD->SetMinSize( wxSize( 50,-1 ) );
	
	HexQ_LFV->Add( HexQInfo_DD, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* HexQAddr_LFV;
	HexQAddr_LFV = new wxStaticBoxSizer( new wxStaticBox( HexQ_P, wxID_ANY, _("Address") ), wxVERTICAL );
	
	wxFlexGridSizer* HexQAddr_LFG;
	HexQAddr_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexQAddr_LFG->AddGrowableCol( 1 );
	HexQAddr_LFG->SetFlexibleDirection( wxBOTH );
	HexQAddr_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexQAddrMT_CB = new wxCheckBox( HexQ_P, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddr_LFG->Add( HexQAddrMT_CB, 0, wxALL, 5 );
	
	HexQAddrMT_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddrMT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQAddr_LFG->Add( HexQAddrMT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQAddrME_CB = new wxCheckBox( HexQ_P, wxID_ANY, _(">="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddr_LFG->Add( HexQAddrME_CB, 0, wxALL, 5 );
	
	HexQAddrME_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddrME_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQAddr_LFG->Add( HexQAddrME_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQAddrLT_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddr_LFG->Add( HexQAddrLT_CB, 0, wxALL, 5 );
	
	HexQAddrLT_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddrLT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQAddr_LFG->Add( HexQAddrLT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQAddrLE_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("<="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddr_LFG->Add( HexQAddrLE_CB, 0, wxALL, 5 );
	
	HexQAddrLE_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQAddrLE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQAddr_LFG->Add( HexQAddrLE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQAddr_LFV->Add( HexQAddr_LFG, 1, wxEXPAND, 5 );
	
	HexQ_LFV->Add( HexQAddr_LFV, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* HexQVal_LFV;
	HexQVal_LFV = new wxStaticBoxSizer( new wxStaticBox( HexQ_P, wxID_ANY, _("Value") ), wxVERTICAL );
	
	wxFlexGridSizer* HexQVal_LFG;
	HexQVal_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexQVal_LFG->AddGrowableCol( 1 );
	HexQVal_LFG->SetFlexibleDirection( wxBOTH );
	HexQVal_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexQCT_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("C"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQCT_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQCT_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQCT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQCT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQCF_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("!C"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQCF_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQCF_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQCF_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQCF_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQEQ_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("=="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQEQ_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQEQ_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQEQ_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQEQ_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQNE_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("!="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQNE_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQNE_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQNE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQNE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQMT_CB = new wxCheckBox( HexQ_P, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQMT_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQMT_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQMT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQMT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQME_CB = new wxCheckBox( HexQ_P, wxID_ANY, _(">="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQME_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQME_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQME_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQME_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQLT_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQLT_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQLT_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQLT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQLT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQLE_CB = new wxCheckBox( HexQ_P, wxID_ANY, _("<="), wxDefaultPosition, wxDefaultSize, 0 );
	HexQVal_LFG->Add( HexQLE_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexQLE_TXT = new wxTextCtrl( HexQ_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexQLE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexQVal_LFG->Add( HexQLE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexQVal_LFV->Add( HexQVal_LFG, 1, wxEXPAND, 5 );
	
	HexQ_LFV->Add( HexQVal_LFV, 0, wxEXPAND, 5 );
	
	HexQ_P->SetSizer( HexQ_LFV );
	HexQ_P->Layout();
	HexQ_LFV->Fit( HexQ_P );
	HexBody_LV->Add( HexQ_P, 0, wxEXPAND | wxALL, 5 );
	
	HexOut_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexBody_LV->Add( HexOut_P, 0, wxEXPAND | wxALL, 5 );
	
	HexBody_SW->SetSizer( HexBody_LV );
	HexBody_SW->Layout();
	HexBody_LV->Fit( HexBody_SW );
	HexList_SW = new wxScrolledWindow( HexGUI_SP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxSUNKEN_BORDER|wxVSCROLL );
	HexList_SW->SetScrollRate( 5, 5 );
	wxBoxSizer* HexList_LV;
	HexList_LV = new wxBoxSizer( wxVERTICAL );
	
	HexList_LB = new wxListBox( HexList_SW, HexList_LB_ID, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxNO_BORDER|wxSUNKEN_BORDER ); 
	HexList_LB->SetMinSize( wxSize( 0,-1 ) );
	
	HexList_LV->Add( HexList_LB, 1, wxEXPAND|wxLEFT, 5 );
	
	HexTree_P = new wxPanel( HexList_SW, wxID_ANY, wxDefaultPosition, wxSize( -1,200 ), wxTAB_TRAVERSAL );
	HexTree_P->Hide();
	HexTree_P->SetMinSize( wxSize( -1,200 ) );
	
	wxBoxSizer* HexTree_LH;
	HexTree_LH = new wxBoxSizer( wxHORIZONTAL );
	
	HexTree_LH->SetMinSize( wxSize( -1,200 ) ); 
	HexHack_TC = new wxTreeCtrl( HexTree_P, HexHack_TC_ID, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_SINGLE|wxNO_BORDER );
	HexTree_LH->Add( HexHack_TC, 1, wxEXPAND, 5 );
	
	HexTree_SL = new wxStaticLine( HexTree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	HexTree_LH->Add( HexTree_SL, 0, wxALL|wxEXPAND, 5 );
	
	HexCode_TC = new wxTreeCtrl( HexTree_P, HexCode_TC_ID, wxDefaultPosition, wxSize( 150,-1 ), wxTR_DEFAULT_STYLE|wxTR_HIDE_ROOT|wxNO_BORDER );
	HexCode_TC->SetMinSize( wxSize( 150,-1 ) );
	HexCode_TC->SetMaxSize( wxSize( 200,-1 ) );
	
	HexTree_LH->Add( HexCode_TC, 0, wxALL|wxEXPAND, 5 );
	
	HexTree_P->SetSizer( HexTree_LH );
	HexTree_P->Layout();
	HexList_LV->Add( HexTree_P, 0, wxEXPAND | wxALL, 5 );
	
	HexGrid_P = new wxPanel( HexList_SW, wxID_ANY, wxDefaultPosition, wxSize( -1,200 ), wxTAB_TRAVERSAL );
	HexGrid_P->Hide();
	HexGrid_P->SetMinSize( wxSize( -1,200 ) );
	
	HexGrid_LF = new wxFlexGridSizer( 0, 0, 0, 0 );
	HexGrid_LF->AddGrowableCol( 0 );
	HexGrid_LF->SetFlexibleDirection( wxBOTH );
	HexGrid_LF->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexGrid_LF->SetMinSize( wxSize( -1,200 ) ); 
	HexGrid_P->SetSizer( HexGrid_LF );
	HexGrid_P->Layout();
	HexList_LV->Add( HexGrid_P, 0, wxEXPAND | wxALL, 5 );
	
	HexList_SW->SetSizer( HexList_LV );
	HexList_SW->Layout();
	HexList_LV->Fit( HexList_SW );
	HexGUI_SP->SplitVertically( HexBody_SW, HexList_SW, 200 );
	HexGUI_LV->Add( HexGUI_SP, 1, wxEXPAND, 5 );
	
	this->SetSizer( HexGUI_LV );
	this->Layout();
	HexGUI_ST = this->CreateStatusBar( 1, wxST_SIZEGRIP, HexGUI_ST_ID );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( HexMain_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexList_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexSave_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexNew_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexDel_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexSet_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Connect( HexGet_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	HexState_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexState_B_OnClick ), NULL, this );
	HexLoop_SPB->Connect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexLoop_SBC ), NULL, this );
	HexVal_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexVal_SPB->Connect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexVal_OnSpin ), NULL, this );
	HexInc_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexQCT_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexList_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HexGUI::HexList_LB_OnSelect ), NULL, this );
	HexHack_TC->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexHack_TC_OnSelect ), NULL, this );
	HexCode_TC->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexCode_TC_OnSelect ), NULL, this );
}

HexGUI::~HexGUI()
{
	// Disconnect Events
	this->Disconnect( HexMain_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexList_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexSave_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexNew_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexDel_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexSet_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	this->Disconnect( HexGet_TT_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ) );
	HexState_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexState_B_OnClick ), NULL, this );
	HexLoop_SPB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexLoop_SBC ), NULL, this );
	HexVal_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexVal_SPB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexVal_OnSpin ), NULL, this );
	HexInc_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexQCT_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexList_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HexGUI::HexList_LB_OnSelect ), NULL, this );
	HexHack_TC->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexHack_TC_OnSelect ), NULL, this );
	HexCode_TC->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexCode_TC_OnSelect ), NULL, this );
	
}
