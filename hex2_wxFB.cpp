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
	this->SetFont( wxFont( 8, 70, 90, 90, false, wxEmptyString ) );
	
	wxBoxSizer* HexGUI_LV;
	HexGUI_LV = new wxBoxSizer( wxVERTICAL );
	
	hexGui_tbar = new wxToolBar( this, hexGui_tbar_id, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_HORZ_TEXT|wxTB_TEXT );
	hexGui_tbar->SetToolSeparation( 1 );
	hexGui_tbar->SetFont( wxFont( 8, 70, 90, 90, false, wxEmptyString ) );
	hexGui_tbar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	HexLoad_B = new wxButton( hexGui_tbar, HexLoad_B_ID, _("L&oad"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexLoad_B );
	HexSave_B = new wxButton( hexGui_tbar, HexSave_B_ID, _("&Save"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexSave_B );
	hexGui_tbar->AddSeparator(); 
	
	HexNew_B = new wxButton( hexGui_tbar, HexNew_B_ID, _("&New"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexNew_B );
	HexDel_B = new wxButton( hexGui_tbar, HexDel_B_ID, _("&Delete"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexDel_B );
	HexSet_B = new wxButton( hexGui_tbar, HexSet_B_ID, _("&Comit"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexSet_B );
	HexGet_B = new wxButton( hexGui_tbar, HexGet_B_ID, _("&Restore"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	hexGui_tbar->AddControl( HexGet_B );
	hexGui_tbar->AddSeparator(); 
	
	hexFont_s = new wxStaticText( hexGui_tbar, wxID_ANY, _("Text Size"), wxDefaultPosition, wxDefaultSize, 0 );
	hexFont_s->Wrap( -1 );
	hexGui_tbar->AddControl( hexFont_s );
	hexFont_sc = new wxSpinCtrl( hexGui_tbar, hexFont_sc_id, wxT("8"), wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 8, 16, 8 );
	hexGui_tbar->AddControl( hexFont_sc );
	hexGui_tbar->Realize(); 
	
	HexGUI_LV->Add( hexGui_tbar, 0, wxEXPAND, 0 );
	
	HexQ_TB = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_NODIVIDER|wxTB_TEXT );
	HexQ_TB->SetToolSeparation( 1 );
	HexQ_TB->SetFont( wxFont( 8, 70, 90, 90, false, wxEmptyString ) );
	HexQ_TB->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	HexQ_TB->Enable( false );
	
	HexQNew__B = new wxButton( HexQ_TB, HexQNew__B_ID, _("N"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQNew__B );
	HexQFind_B = new wxButton( HexQ_TB, HexQFind_B_ID, _("S"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQFind_B->SetToolTip( _("Search") );
	
	HexQ_TB->AddControl( HexQFind_B );
	HexQUndo_B = new wxButton( HexQ_TB, HexQUndo_B_ID, _("U"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQUndo_B->SetToolTip( _("Undo") );
	
	HexQ_TB->AddControl( HexQUndo_B );
	HexQ_TB->AddSeparator(); 
	
	HexQDump_B = new wxButton( HexQ_TB, HexQDump_B_ID, _("D"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQDump_B->SetToolTip( _("Dump") );
	
	HexQ_TB->AddControl( HexQDump_B );
	HexQDC_B = new wxButton( HexQ_TB, HexQDC_B_ID, _("C"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQDC_B );
	HexQNC_B = new wxButton( HexQ_TB, HexQNC_B_ID, _("!C"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQNC_B );
	HexQEQ_B = new wxButton( HexQ_TB, HexQEQ_B_ID, _("=="), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQEQ_B );
	HexQNE_B = new wxButton( HexQ_TB, HexQNE_B_ID, _("!="), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQNE_B );
	HexQMT_B = new wxButton( HexQ_TB, HexQMT_B_ID, _(">"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQMT_B );
	HexQME_B = new wxButton( HexQ_TB, HexQME_B_ID, _(">="), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQME_B );
	HexQLT_B = new wxButton( HexQ_TB, HexQLT_B_ID, _("<"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQLT_B );
	HexQLE_B = new wxButton( HexQ_TB, HexQLE_B_ID, _("<="), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	HexQ_TB->AddControl( HexQLE_B );
	HexQ_TB->AddSeparator(); 
	
	HexProgress_PB = new wxGauge( HexQ_TB, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	HexQ_TB->AddControl( HexProgress_PB );
	HexQ_TB->Realize(); 
	
	HexGUI_LV->Add( HexQ_TB, 0, wxEXPAND, 5 );
	
	HexGUI_SP = new wxSplitterWindow( this, HexGUI_SP_ID, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME );
	HexGUI_SP->Connect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::HexGUI_SPOnIdle ), NULL, this );
	HexGUI_SP->SetMinimumPaneSize( 200 );
	
	HexBody_SW = new wxScrolledWindow( HexGUI_SP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	HexBody_SW->SetScrollRate( 5, 5 );
	wxBoxSizer* HexBody_LV;
	HexBody_LV = new wxBoxSizer( wxVERTICAL );
	
	hexMode_p = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* hexMode_lfv;
	hexMode_lfv = new wxStaticBoxSizer( new wxStaticBox( hexMode_p, wxID_ANY, _("Mode") ), wxVERTICAL );
	
	wxArrayString hexMode_ddChoices;
	hexMode_dd = new wxChoice( hexMode_p, wxID_ANY, wxDefaultPosition, wxDefaultSize, hexMode_ddChoices, 0 );
	hexMode_dd->SetSelection( 0 );
	hexMode_lfv->Add( hexMode_dd, 0, wxALL|wxEXPAND, 5 );
	
	hexMode_p->SetSizer( hexMode_lfv );
	hexMode_p->Layout();
	hexMode_lfv->Fit( hexMode_p );
	HexBody_LV->Add( hexMode_p, 0, wxEXPAND | wxALL, 5 );
	
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
	
	HexHook_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexHook_P->Hide();
	
	wxStaticBoxSizer* HexHook_LFV;
	HexHook_LFV = new wxStaticBoxSizer( new wxStaticBox( HexHook_P, wxID_ANY, _("Do") ), wxVERTICAL );
	
	wxString HexHook_DDChoices[] = { _("Once"), _("Every 500 Milliseconds"), _("Every Second"), _("Every 5 Seconds"), _("Every 30 Seconds"), _("Every Minute"), _("Every 5 Minutes"), _("Every 30 Minutes"), _("Every Hour") };
	int HexHook_DDNChoices = sizeof( HexHook_DDChoices ) / sizeof( wxString );
	HexHook_DD = new wxChoice( HexHook_P, HexHook_DD_ID, wxDefaultPosition, wxSize( -1,-1 ), HexHook_DDNChoices, HexHook_DDChoices, 0 );
	HexHook_DD->SetSelection( 0 );
	HexHook_DD->SetMinSize( wxSize( 50,-1 ) );
	
	HexHook_LFV->Add( HexHook_DD, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	HexHook_P->SetSizer( HexHook_LFV );
	HexHook_P->Layout();
	HexHook_LFV->Fit( HexHook_P );
	HexBody_LV->Add( HexHook_P, 0, wxEXPAND | wxALL, 5 );
	
	HexBin_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexBin_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexBin_LFV;
	HexBin_LFV = new wxStaticBoxSizer( new wxStaticBox( HexBin_P, wxID_ANY, _("Hook > Binary") ), wxVERTICAL );
	
	wxFlexGridSizer* HexBin_LFG;
	HexBin_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexBin_LFG->AddGrowableCol( 1 );
	HexBin_LFG->SetFlexibleDirection( wxBOTH );
	HexBin_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexBinBind_B = new wxButton( HexBin_P, HexBinBind_B_ID, _("Bind"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinBind_B->SetMinSize( wxSize( 50,-1 ) );
	
	HexBin_LFG->Add( HexBinBind_B, 0, wxALL, 5 );
	
	HexBinBind_TXT = new wxTextCtrl( HexBin_P, HexBinBind_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HexBin_LFG->Add( HexBinBind_TXT, 0, wxALL|wxEXPAND, 5 );
	
	HexBinPath_B = new wxButton( HexBin_P, HexPath_B_ID, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
	HexBinPath_B->SetMinSize( wxSize( 50,-1 ) );
	
	HexBin_LFG->Add( HexBinPath_B, 0, wxALL, 5 );
	
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
	
	HexBinExec_B = new wxButton( HexBin_P, HexBinExec_B_ID, _("Launch"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	HexBinExec_B->SetMinSize( wxSize( 70,-1 ) );
	
	HexBin_LG->Add( HexBinExec_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	HexBinKill_B = new wxButton( HexBin_P, HexBinKill_B_ID, _("Close"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	HexBinKill_B->SetMinSize( wxSize( 70,-1 ) );
	
	HexBin_LG->Add( HexBinKill_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
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
	
	HexFormat_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexFormat_P->Hide();
	
	wxStaticBoxSizer* HexFormat_LFV;
	HexFormat_LFV = new wxStaticBoxSizer( new wxStaticBox( HexFormat_P, wxID_ANY, _("Format") ), wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	HexExt_S = new wxStaticText( HexFormat_P, wxID_ANY, _("Ext"), wxDefaultPosition, wxDefaultSize, 0 );
	HexExt_S->Wrap( -1 );
	bSizer8->Add( HexExt_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	HexExt_TXT = new wxTextCtrl( HexFormat_P, HexExt_TXT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( HexExt_TXT, 1, wxALL, 5 );
	
	HexFormat_LFV->Add( bSizer8, 0, wxEXPAND, 5 );
	
	wxGridSizer* HexFormat_LG;
	HexFormat_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	HexFAdd_B = new wxButton( HexFormat_P, HexFAdd_B_ID, _("Add Format"), wxDefaultPosition, wxDefaultSize, 0 );
	HexFormat_LG->Add( HexFAdd_B, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	HexFLine_HR = new wxStaticLine( HexFormat_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	HexFLine_HR->Hide();
	
	HexFormat_LG->Add( HexFLine_HR, 0, wxEXPAND | wxALL, 5 );
	
	HexConvert_B = new wxButton( HexFormat_P, HexConvert_B_ID, _("Convert to"), wxDefaultPosition, wxDefaultSize, 0 );
	HexFormat_LG->Add( HexConvert_B, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	HexMerge_B = new wxButton( HexFormat_P, HexMerge_B_ID, _("Merge with"), wxDefaultPosition, wxDefaultSize, 0 );
	HexFormat_LG->Add( HexMerge_B, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	HexFormat_LFV->Add( HexFormat_LG, 0, wxEXPAND, 5 );
	
	HexFormat_LB = new wxListBox( HexFormat_P, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), 0, NULL, 0 ); 
	HexFormat_LB->SetMinSize( wxSize( 100,-1 ) );
	
	HexFormat_LFV->Add( HexFormat_LB, 1, wxALL|wxEXPAND, 5 );
	
	HexFormat_P->SetSizer( HexFormat_LFV );
	HexFormat_P->Layout();
	HexFormat_LFV->Fit( HexFormat_P );
	HexBody_LV->Add( HexFormat_P, 1, wxEXPAND | wxALL, 5 );
	
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
	
	HexBinHack_B = new wxButton( HexHck_P, HexBinHack_B_ID, _("Hack"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	HexBinHack_B->SetMinSize( wxSize( 70,-1 ) );
	
	HexHck_LFV->Add( HexBinHack_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	HexHck_P->SetSizer( HexHck_LFV );
	HexHck_P->Layout();
	HexHck_LFV->Fit( HexHck_P );
	HexBody_LV->Add( HexHck_P, 0, wxEXPAND | wxALL, 5 );
	
	HexQ_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexQ_P->SetMinSize( wxSize( 100,-1 ) );
	
	wxStaticBoxSizer* HexQ_LFV;
	HexQ_LFV = new wxStaticBoxSizer( new wxStaticBox( HexQ_P, wxID_ANY, _("Search") ), wxVERTICAL );
	
	HexQOut_S = new wxStaticText( HexQ_P, wxID_ANY, _("Results: 0"), wxDefaultPosition, wxDefaultSize, 0 );
	HexQOut_S->Wrap( -1 );
	HexQOut_S->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	HexQ_LFV->Add( HexQOut_S, 0, wxALL, 5 );
	
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
	
	HexQAddr_LFV->Add( HexQAddr_LFG, 1, wxEXPAND, 5 );
	
	HexQ_LFV->Add( HexQAddr_LFV, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* HexQVal_LFV;
	HexQVal_LFV = new wxStaticBoxSizer( new wxStaticBox( HexQ_P, wxID_ANY, _("Value") ), wxVERTICAL );
	
	wxFlexGridSizer* HexQVal_LFG;
	HexQVal_LFG = new wxFlexGridSizer( 0, 2, 0, 0 );
	HexQVal_LFG->AddGrowableCol( 1 );
	HexQVal_LFG->SetFlexibleDirection( wxBOTH );
	HexQVal_LFG->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HexQVal_LFV->Add( HexQVal_LFG, 1, wxEXPAND, 5 );
	
	HexQ_LFV->Add( HexQVal_LFV, 0, wxEXPAND, 5 );
	
	HexQ_P->SetSizer( HexQ_LFV );
	HexQ_P->Layout();
	HexQ_LFV->Fit( HexQ_P );
	HexBody_LV->Add( HexQ_P, 0, wxEXPAND | wxALL, 5 );
	
	HexOut_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexOut_P->Hide();
	
	HexBody_LV->Add( HexOut_P, 0, wxEXPAND | wxALL, 5 );
	
	HexAddr_P = new wxPanel( HexBody_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HexAddr_P->Hide();
	
	wxStaticBoxSizer* HexAddr_LFV;
	HexAddr_LFV = new wxStaticBoxSizer( new wxStaticBox( HexAddr_P, wxID_ANY, _("Address / Pointer") ), wxVERTICAL );
	
	HexJump_B = new wxButton( HexAddr_P, HeJump_B_ID, _("Jump"), wxDefaultPosition, wxDefaultSize, 0 );
	HexAddr_LFV->Add( HexJump_B, 0, wxALL, 5 );
	
	HexAddr_TXT = new wxTextCtrl( HexAddr_P, HexAddr_TXT_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexAddr_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexAddr_LFV->Add( HexAddr_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxString HexEdit_RLChoices[] = { _("Grid Address"), _("Cell Address"), _("Nothing") };
	int HexEdit_RLNChoices = sizeof( HexEdit_RLChoices ) / sizeof( wxString );
	HexEdit_RL = new wxRadioBox( HexAddr_P, wxID_ANY, _("Sync with..."), wxDefaultPosition, wxDefaultSize, HexEdit_RLNChoices, HexEdit_RLChoices, 1, wxRA_SPECIFY_COLS );
	HexEdit_RL->SetSelection( 0 );
	HexAddr_LFV->Add( HexEdit_RL, 0, wxALL|wxEXPAND, 5 );
	
	HexEAddr_P = new wxPanel( HexAddr_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* HexEAddr_LG;
	HexEAddr_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	HexEGet_B = new wxButton( HexEAddr_P, HexEGet_B_iD, _("Read"), wxDefaultPosition, wxDefaultSize, 0 );
	HexEGet_B->SetMinSize( wxSize( 50,-1 ) );
	
	HexEAddr_LG->Add( HexEGet_B, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	HexESet_B = new wxButton( HexEAddr_P, HexESet_B_ID, _("Write"), wxDefaultPosition, wxDefaultSize, 0 );
	HexESet_B->SetMinSize( wxSize( 50,-1 ) );
	
	HexEAddr_LG->Add( HexESet_B, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	HexEAddr_P->SetSizer( HexEAddr_LG );
	HexEAddr_P->Layout();
	HexEAddr_LG->Fit( HexEAddr_P );
	HexAddr_LFV->Add( HexEAddr_P, 0, wxEXPAND | wxALL, 5 );
	
	HexDepth_P = new wxPanel( HexAddr_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* HexDepth_LFV;
	HexDepth_LFV = new wxStaticBoxSizer( new wxStaticBox( HexDepth_P, wxID_ANY, _("Pointer Depth") ), wxVERTICAL );
	
	HexDepth_SL = new wxSlider( HexDepth_P, wxID_ANY, 0, 0, 15, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTTOM|wxSL_HORIZONTAL|wxSL_LABELS );
	HexDepth_SL->SetMinSize( wxSize( 50,-1 ) );
	
	HexDepth_LFV->Add( HexDepth_SL, 0, wxALL|wxEXPAND, 5 );
	
	HexDepth_P->SetSizer( HexDepth_LFV );
	HexDepth_P->Layout();
	HexDepth_LFV->Fit( HexDepth_P );
	HexAddr_LFV->Add( HexDepth_P, 1, wxEXPAND | wxALL, 5 );
	
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
	HexVal_TXT->SetMinSize( wxSize( 50,-1 ) );
	
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
	HexInc_DD->SetMinSize( wxSize( 55,-1 ) );
	
	HexVInfo_LF->Add( HexInc_DD, 0, wxALL|wxEXPAND, 5 );
	
	HexInc_TXT = new wxTextCtrl( HexVal_P, HexVal_ID, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
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
	
	HexVSize_S = new wxStaticText( HexVal_P, wxID_ANY, _("Use Size"), wxDefaultPosition, wxDefaultSize, 0 );
	HexVSize_S->Wrap( -1 );
	HexVInfo_LF->Add( HexVSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* HexVSize_LH;
	HexVSize_LH = new wxBoxSizer( wxHORIZONTAL );
	
	HexVSize_TXT = new wxTextCtrl( HexVal_P, HexVSize_TXT_ID, _("0"), wxDefaultPosition, wxSize( -1,-1 ), wxTE_RIGHT );
	HexVSize_TXT->SetMaxLength( 2 ); 
	HexVSize_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexVSize_LH->Add( HexVSize_TXT, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	HexVSize_SPB = new wxSpinButton( HexVal_P, HexVSize_SPB_ID, wxDefaultPosition, wxSize( 15,-1 ), 0 );
	HexVSize_SPB->SetMinSize( wxSize( 15,-1 ) );
	
	HexVSize_LH->Add( HexVSize_SPB, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	HexVInfo_LF->Add( HexVSize_LH, 1, wxEXPAND, 5 );
	
	HexVMSize_S = new wxStaticText( HexVal_P, wxID_ANY, _("Min Size"), wxDefaultPosition, wxDefaultSize, 0 );
	HexVMSize_S->Wrap( -1 );
	HexVInfo_LF->Add( HexVMSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* HexVMSize_LH;
	HexVMSize_LH = new wxBoxSizer( wxHORIZONTAL );
	
	HexVMSize_TXT = new wxTextCtrl( HexVal_P, HexVMSize_TXT_ID, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	HexVMSize_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	HexVMSize_LH->Add( HexVMSize_TXT, 1, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );
	
	HexVMSize_SPB = new wxSpinButton( HexVal_P, HexVMSize_SPB_ID, wxDefaultPosition, wxDefaultSize, 0 );
	HexVMSize_SPB->SetMinSize( wxSize( 15,-1 ) );
	
	HexVMSize_LH->Add( HexVMSize_SPB, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxTOP, 5 );
	
	HexVInfo_LF->Add( HexVMSize_LH, 1, wxEXPAND, 5 );
	
	HexVal_LFV->Add( HexVInfo_LF, 0, wxEXPAND, 5 );
	
	HexVal_P->SetSizer( HexVal_LFV );
	HexVal_P->Layout();
	HexVal_LFV->Fit( HexVal_P );
	HexBody_LV->Add( HexVal_P, 0, wxEXPAND | wxALL, 5 );
	
	HexBody_SW->SetSizer( HexBody_LV );
	HexBody_SW->Layout();
	HexBody_LV->Fit( HexBody_SW );
	HexList_P = new wxPanel( HexGUI_SP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* HexList_LV;
	HexList_LV = new wxBoxSizer( wxVERTICAL );
	
	HexList_LB = new wxListBox( HexList_P, HexList_LB_ID, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxNO_BORDER|wxSUNKEN_BORDER ); 
	HexList_LB->SetMinSize( wxSize( 300,100 ) );
	
	HexList_LV->Add( HexList_LB, 1, wxEXPAND|wxLEFT, 5 );
	
	HexGrid_G = new wxGrid( HexList_P, HexGrid_G_ID, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	HexGrid_G->CreateGrid( 0, 18 );
	HexGrid_G->EnableEditing( true );
	HexGrid_G->EnableGridLines( true );
	HexGrid_G->EnableDragGridSize( false );
	HexGrid_G->SetMargins( 0, 0 );
	
	// Columns
	HexGrid_G->EnableDragColMove( false );
	HexGrid_G->EnableDragColSize( true );
	HexGrid_G->SetColLabelSize( 15 );
	HexGrid_G->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	HexGrid_G->EnableDragRowSize( true );
	HexGrid_G->SetRowLabelSize( 150 );
	HexGrid_G->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	HexGrid_G->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	HexGrid_G->Hide();
	HexGrid_G->SetMinSize( wxSize( 300,-1 ) );
	
	HexList_LV->Add( HexGrid_G, 1, wxEXPAND, 5 );
	
	HexTree_P = new wxPanel( HexList_P, wxID_ANY, wxDefaultPosition, wxSize( -1,200 ), wxTAB_TRAVERSAL );
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
	HexList_LV->Add( HexTree_P, 1, wxEXPAND | wxALL, 5 );
	
	HexList_P->SetSizer( HexList_LV );
	HexList_P->Layout();
	HexList_LV->Fit( HexList_P );
	HexGUI_SP->SplitVertically( HexBody_SW, HexList_P, 200 );
	HexGUI_LV->Add( HexGUI_SP, 1, wxEXPAND, 5 );
	
	this->SetSizer( HexGUI_LV );
	this->Layout();
	HexGUI_ST = this->CreateStatusBar( 1, wxST_SIZEGRIP, HexGUI_ST_ID );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::G_OnIdle ) );
	HexNew_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	HexDel_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	HexGet_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	hexFont_sc->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( HexGUI::HexFont_SPC_OnSpin ), NULL, this );
	hexFont_sc->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexFont_SPC_OnChange ), NULL, this );
	HexState_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexState_B_OnClick ), NULL, this );
	HexBinExec_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinExec_B_OnClick ), NULL, this );
	HexBinKill_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinKill_B_OnClick ), NULL, this );
	HexFAdd_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexFAdd_B_OnClick ), NULL, this );
	HexConvert_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexConvert_B_OnClick ), NULL, this );
	HexMerge_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexMerge_B_OnClick ), NULL, this );
	HexLoop_SPB->Connect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexLoop_SBC ), NULL, this );
	HexBinHack_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinHack_B_OnClick ), NULL, this );
	HexVal_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexVal_SPB->Connect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexVal_OnSpin ), NULL, this );
	HexInc_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexList_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HexGUI::HexList_LB_OnSelect ), NULL, this );
	HexHack_TC->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexHack_TC_OnSelect ), NULL, this );
	HexCode_TC->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexCode_TC_OnSelect ), NULL, this );
}

HexGUI::~HexGUI()
{
	// Disconnect Events
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::G_OnIdle ) );
	HexNew_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	HexDel_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	HexGet_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexGUI_TB_OnToolExec ), NULL, this );
	hexFont_sc->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( HexGUI::HexFont_SPC_OnSpin ), NULL, this );
	hexFont_sc->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexFont_SPC_OnChange ), NULL, this );
	HexState_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexState_B_OnClick ), NULL, this );
	HexBinExec_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinExec_B_OnClick ), NULL, this );
	HexBinKill_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinKill_B_OnClick ), NULL, this );
	HexFAdd_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexFAdd_B_OnClick ), NULL, this );
	HexConvert_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexConvert_B_OnClick ), NULL, this );
	HexMerge_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexMerge_B_OnClick ), NULL, this );
	HexLoop_SPB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexLoop_SBC ), NULL, this );
	HexBinHack_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HexGUI::HexBinHack_B_OnClick ), NULL, this );
	HexVal_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexVal_SPB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxSpinEventHandler( HexGUI::HexVal_OnSpin ), NULL, this );
	HexInc_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HexGUI::HexVal_OnChange ), NULL, this );
	HexList_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( HexGUI::HexList_LB_OnSelect ), NULL, this );
	HexHack_TC->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexHack_TC_OnSelect ), NULL, this );
	HexCode_TC->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HexGUI::HexCode_TC_OnSelect ), NULL, this );
	
}