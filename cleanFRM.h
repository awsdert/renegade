///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CLEANFRM_H__
#define __CLEANFRM_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/cshelp.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/spinctrl.h>
#include <wx/scrolwin.h>
#include <wx/listctrl.h>
#include <wx/gauge.h>
#include <wx/statline.h>
#include <wx/checkbox.h>
#include <wx/grid.h>
#include <wx/treectrl.h>
#include <wx/hyperlink.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/dialog.h>
#include <wx/slider.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class cleanFRM
///////////////////////////////////////////////////////////////////////////////
class cleanFRM : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			LoadSession_ID = 1000,
			SaveSession_ID,
			NewSession_ID,
			DelSession_ID,
			session_ID,
			mListOrg_ID,
			mLoadOrg_ID,
			mSaveOrg_ID,
			mSetOrg_ID,
			mOrgName_ID,
			mOrgFile_ID,
			mListPFM_ID,
			mLoadPFM_ID,
			mSavePFM_ID,
			mSetPFM_ID,
			mPFMName_ID,
			mPFMFile_ID,
			mPFMEndian_ID,
			mListBin_ID,
			mLoadBin_ID,
			mSaveBin_ID,
			mSetBin_ID,
			mBinName_ID,
			mBinFile_ID,
			mBinPath_ID,
			mBinBind_ID,
			isApp_ID,
			isFile_ID,
			binHook_ID,
			binLaunch_ID,
			mRamName_ID,
			goodA_ID,
			goodV_ID,
			badA_ID,
			badV_ID,
			outByte_ID,
			outValue_ID,
			editGet_ID,
			editSet_ID,
			editValue_ID,
			edit_G_ID,
			dbpName_ID,
			dbpFile_ID,
			dbpSID_ID,
			dbpPID_ID,
			dbpNotes_ID,
			mHackName_ID,
		};
		
		wxNotebook* cleanFRM_NB;
		wxPanel* hook_P;
		wxScrolledWindow* hook_SW;
		wxPanel* session_P;
		wxToolBar* session_TBar;
		wxChoice* session_D;
		wxPanel* org_P;
		wxToolBar* mOrg_TBar;
		wxPanel* SetOrg_P;
		wxStaticText* orgName_S;
		wxTextCtrl* orgName_TXT;
		wxStaticText* orgFile_S;
		wxTextCtrl* orgFile_TXT;
		wxPanel* pfm_P;
		wxToolBar* mPFM_TBar;
		wxStaticText* pfmName_S;
		wxTextCtrl* pfmName_TXT;
		wxStaticText* pfmFile_S;
		wxTextCtrl* pfmFile_TXT;
		wxStaticText* pfmEndian_S;
		wxChoice* pfmEndian_D;
		wxPanel* bin_P;
		wxToolBar* mBin_TBar;
		wxStaticText* binName_S;
		wxTextCtrl* binName_TXT;
		wxStaticText* binFile_S;
		wxTextCtrl* binFile_TXT;
		wxButton* binPath_B;
		wxTextCtrl* binPath_TXT;
		wxButton* binBind_B;
		wxTextCtrl* binBind_TXT;
		wxRadioButton* isApp_RB;
		wxRadioButton* isFile_RB;
		wxButton* binHook_B;
		wxButton* binLaunch_B;
		wxPanel* ram_P;
		wxChoice* ramName_D;
		wxTextCtrl* ramName_TXT;
		wxStaticText* ramPtr_S;
		wxSpinCtrl* ramPtr_SN;
		wxStaticText* ramByte_S;
		wxTextCtrl* ramByte_TXT;
		wxStaticText* ramSize_S;
		wxTextCtrl* ramSize_TXT;
		wxButton* NewRam_B;
		wxButton* SetRam_B;
		wxStaticText* UseHook_S;
		wxChoice* UseHook_D;
		wxStaticText* ListApps_S;
		wxChoice* ListApps_D;
		wxButton* binUse_B;
		wxRadioButton* ListApps_RB;
		wxButton* ListApps_B;
		wxRadioButton* ListWindows_RB;
		wxListCtrl* ListApps_LC;
		wxPanel* find_P;
		wxStaticText* good_S;
		wxStaticText* bad_S;
		wxGauge* byte_PB;
		wxScrolledWindow* good_SCROLL;
		wxScrolledWindow* bad_SCROLL;
		wxPanel* findOptions_P;
		wxStaticText* out_S;
		wxStaticLine* findOptions_LINE1;
		wxButton* dump_B;
		wxButton* find_B;
		wxButton* findUndo_B;
		wxButton* findEqual_B;
		wxButton* findGTE_B;
		wxButton* findGT_B;
		wxButton* findNOTE_B;
		wxButton* findLTE_B;
		wxButton* findLT_B;
		wxStaticLine* findOptions_LINE2;
		wxScrolledWindow* findOptions_SW;
		wxStaticText* findUse_S;
		wxChoice* findUse_D;
		wxStaticText* findRam_S;
		wxChoice* findRam_D;
		wxStaticText* findType_S;
		wxChoice* findType_D;
		wxStaticText* findSize_S;
		wxChoice* findSize_D;
		wxStaticText* findMode_S;
		wxChoice* findMode_D;
		wxPanel* out_P;
		wxListCtrl* out_LC;
		wxPanel* outData_P;
		wxCheckBox* outEdit_CB;
		wxListCtrl* outData_LC;
		wxStaticText* outRAM_S;
		wxChoice* outRAM_D;
		wxStaticText* outSize_S;
		wxChoice* outSize_D;
		wxStaticText* outByte_S;
		wxTextCtrl* outByte_TXT;
		wxStaticText* outMode_S;
		wxChoice* outMode_D;
		wxStaticText* outValue_S;
		wxTextCtrl* outValue_TXT;
		wxButton* SetOut_B;
		wxButton* DelOut_B;
		wxPanel* edit_P;
		wxButton* editShow_B;
		wxStaticText* editUpdate_S;
		wxChoice* editUpdate_D;
		wxPanel* editOptions_P;
		wxStaticText* editRam_S;
		wxChoice* editRam_D;
		wxButton* editGet_B;
		wxTextCtrl* editGet_TXT;
		wxButton* editSet_B;
		wxTextCtrl* editSet_TXT;
		wxTextCtrl* editValue_TXT;
		wxStaticText* editSize_S;
		wxChoice* editSize_D;
		wxStaticText* editMode_S;
		wxChoice* editMode_D;
		wxGrid* edit_G;
		wxPanel* dbp_P;
		wxRadioButton* dbpAreaAll_RB;
		wxRadioButton* dbpAreaCheck_RB;
		wxPanel* dbpAreaCB_P;
		wxStaticText* dbpName_S;
		wxTextCtrl* dbpName_TXT;
		wxStaticText* dbpFile_S;
		wxTextCtrl* dbpFile_TXT;
		wxStaticText* dbpSID_S;
		wxTextCtrl* dbpSID_TXT;
		wxStaticText* dbpPID_S;
		wxTextCtrl* dbpPID_TXT;
		wxStaticText* dbpNotes_S;
		wxTextCtrl* dbpNotes_TA;
		wxButton* NewDBP_B;
		wxButton* SetDBP_B;
		wxButton* LoadDBP_B;
		wxButton* SaveDBP_B;
		wxPanel* tree_P;
		wxButton* NewHack_B;
		wxCheckBox* NewHack_CB;
		wxChoice* NewHack_D;
		wxButton* SetCode_B;
		wxButton* DelHack_B;
		wxStaticText* mHackName_S;
		wxTextCtrl* mHackName_TXT;
		wxCheckBox* mUseHack_CB;
		wxStaticLine* mHackBreak;
		wxButton* mShowHack_B;
		wxListCtrl* code_LC;
		wxButton* GetHacks_B;
		wxButton* SetHacks_B;
		wxButton* MoveHack_B;
		wxChoice* MoveHack_D;
		wxPanel* about_P;
		wxStaticText* m_staticText10;
		wxHyperlinkCtrl* m_hyperlink3;
		wxHyperlinkCtrl* m_hyperlink2;
		wxHyperlinkCtrl* m_hyperlink5;
		wxHyperlinkCtrl* m_hyperlink4;
		wxStaticText* m_staticText9;
		wxHyperlinkCtrl* m_hyperlink1;
		wxStatusBar* SB;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void GOnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void LoadSession_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveSession_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void NewSession_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DelSession_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void session_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void ListOrg_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mLoadOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSaveOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSetOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void name_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void file_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void mListPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mLoadPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSavePFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSetPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mListBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mLoadBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSaveBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mSetBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void binPath_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void path_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void binBind_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void binHook_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void binLaunch_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ramName_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void byte_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void NewRam_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetRam_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void UseHook_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void ListApps_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void binUse_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ListApps_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dump_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void find_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findUndo_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findEqual_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findGTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findGT_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findNOTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findLTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void findLT_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void compare_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void findMode_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void out_LCOnSelect( wxListEvent& event ) { event.Skip(); }
		virtual void outData_LCOnSelect( wxListEvent& event ) { event.Skip(); }
		virtual void out_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetOut_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DelOut_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void editShow_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void editUpdate_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void editGet_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void edit_TXTOnMouseWheel( wxMouseEvent& event ) { event.Skip(); }
		virtual void editSet_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void edit_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void edit_GOnEditEnd( wxGridEvent& event ) { event.Skip(); }
		virtual void edit_GOnEditBegin( wxGridEvent& event ) { event.Skip(); }
		virtual void edit_GOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void edit_GOnMouseWheel( wxMouseEvent& event ) { event.Skip(); }
		virtual void edit_GOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void dbpArea_RBOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void byte16_TXTOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void NewDBP_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetDBP_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void LoadDBP_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveDBP_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void NewHack_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetCode_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DelHack_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void tree_TOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void tree_TOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void tree_TOnBeginDrag( wxTreeEvent& event ) { event.Skip(); }
		virtual void tree_TOnEndDrag( wxTreeEvent& event ) { event.Skip(); }
		virtual void tree_TOnSelect( wxTreeEvent& event ) { event.Skip(); }
		virtual void UseHack_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mShowHack_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void GetHacks_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SetHacks_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void MoveHack_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxFlexGridSizer* goodA_L;
		wxFlexGridSizer* goodV_L;
		wxFlexGridSizer* badA_L;
		wxFlexGridSizer* badV_L;
		wxGridSizer* dbpAreaCB_LG;
		wxTreeCtrl* tree_T;
		
		cleanFRM( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("HEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~cleanFRM();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class cleanGetOrg_DLG
///////////////////////////////////////////////////////////////////////////////
class cleanGetOrg_DLG : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			dGetOrgDLG_ID = 1000,
			dUseOrg_ID,
			dLoadOrg_ID,
			dSaveOrg_ID,
			dNewOrg_ID,
			dSetOrg_ID,
			dGetOrg_ID,
			dDelOrg_ID,
		};
		
		wxToolBar* dGetOrg_TBar;
		wxListBox* dOrgName_LB;
		wxPanel* dSetOrgData_P;
		wxStaticText* dSetOrgName_S;
		wxTextCtrl* dSetOrgName_TXT;
		wxStaticText* dSetOrgFile_S;
		wxTextCtrl* dSetOrgFile_TXT;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetOrg_DLGOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void dUseOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dLoadOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSaveOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dNewOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSetOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dGetOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dDelOrg_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dOrgName_LBOnSelect( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		cleanGetOrg_DLG( wxWindow* parent, wxWindowID id = dGetOrgDLG_ID, const wxString& title = _("Choose / Modify Organisation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~cleanGetOrg_DLG();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class cleanGetPFM_DLG
///////////////////////////////////////////////////////////////////////////////
class cleanGetPFM_DLG : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			dUsePFM_ID = 1000,
			dLoadPFM_ID,
			dSavePFM_ID,
			dNewPFM_ID,
			dSetPFM_ID,
			dGetPFM_ID,
			dDelPFM_ID,
		};
		
		wxToolBar* dGetPFM_TBar;
		wxListBox* dPFMName_LB;
		wxPanel* dSetPFMData_P;
		wxStaticText* dSetPFMName_S;
		wxTextCtrl* dSetPFMName_TXT;
		wxStaticText* dSetPFMFile_S;
		wxTextCtrl* dSetPFMFile_TXT;
		wxStaticText* dSetPFMEndian_S;
		wxChoice* dSetPFMEndian_D;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetPFM_DLGOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void dUsePFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dLoadPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSavePFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dNewPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSetPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dGetPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dDelPFM_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dPFMName_LBOnSelect( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		cleanGetPFM_DLG( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Choose / Modify Platform"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,480 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~cleanGetPFM_DLG();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class cleanGetBin_DLG
///////////////////////////////////////////////////////////////////////////////
class cleanGetBin_DLG : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			dUseBin_ID = 1000,
			dLoadBin_ID,
			dSaveBin_ID,
			dNewBin_ID,
			dSetBin_ID,
			dGetBin_ID,
			dDelBin_ID,
		};
		
		wxToolBar* dGetBin_TBar;
		wxListBox* dBinName_LB;
		wxPanel* dSetBinData_P;
		wxStaticText* dBinName_S;
		wxTextCtrl* dBinName_TXT;
		wxStaticText* dBinFile_S;
		wxTextCtrl* dBinFile_TXT;
		wxButton* dBinPath_B;
		wxTextCtrl* dBinPath_TXT;
		wxButton* dBinBind_B;
		wxTextCtrl* dBinBind_TXT;
		wxRadioButton* dIsApp_RB;
		wxRadioButton* dIsFile_RB;
		wxChoice* dRamName_D;
		wxTextCtrl* dRamName_TXT;
		wxStaticText* dRamDepth_S;
		wxSlider* dRamDepth_SL;
		wxStaticText* dRamBase_S;
		wxTextCtrl* dRamBase_TXT;
		wxStaticText* dRamSize_S;
		wxTextCtrl* dRamSize_TXT;
		wxButton* dNewRam_B;
		wxButton* dSetRam_B;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetBin_DLGOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void dUseBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dLoadBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSaveBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dNewBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSetBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dGetBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dDelBin_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dOrgName_LBOnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void dBinPath_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dBinBind_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dRanName_DOnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void dNewRam_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSetRam_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		cleanGetBin_DLG( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Choose / Modify Binary"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~cleanGetBin_DLG();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class cleanGetDBP_DLG
///////////////////////////////////////////////////////////////////////////////
class cleanGetDBP_DLG : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			dUseDBP_ID = 1000,
			dLoadDBP_ID,
			dSaveDBP_ID,
			dNewDBP_ID,
			dSetDBP_ID,
			dGetDBP_ID,
			dDelDBP_ID,
		};
		
		wxToolBar* dGetDBP_TBar;
		wxRadioButton* dGetAreaAll_RB;
		wxRadioButton* dGetAreaSel_RB;
		wxPanel* dGetAreaCB_P;
		wxListBox* dDBPName_LB;
		wxPanel* dSetDBP_P;
		wxRadioButton* dSetAreaAll_RB;
		wxRadioButton* dSetAreaSel_RB;
		wxPanel* dSetAreaCB_P;
		wxStaticText* dDBPName_S;
		wxTextCtrl* dDBPName_TXT;
		wxStaticText* dDBPFile_S;
		wxTextCtrl* dDBPFile_TXT;
		wxStaticText* dDBPPID_S;
		wxTextCtrl* dDBPPID_TXT;
		wxStaticText* dDBPSID_S;
		wxTextCtrl* dDBPSID_TXT;
		wxStaticText* dDBPNotes_S;
		wxTextCtrl* dDBPNotes_TA;
		
		// Virtual event handlers, overide them in your derived class
		virtual void GetDBP_DLGOnClose( wxCloseEvent& event ) = 0;
		virtual void dUseDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dLoadDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dSaveDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dNewDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dSetDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dGetDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dDelDBP_OnClick( wxCommandEvent& event ) = 0;
		virtual void dDBPName_LBOnSelect( wxCommandEvent& event ) = 0;
		virtual void dSetArea_RBOnClick( wxCommandEvent& event ) = 0;
		
	
	public:
		wxGridSizer* dGetAreaCB_LG;
		wxGridSizer* dSetAreaCB_LG;
		
		cleanGetDBP_DLG( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Choose / Modify Profile"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~cleanGetDBP_DLG();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class cleanSetHack_DLG
///////////////////////////////////////////////////////////////////////////////
class cleanSetHack_DLG : public wxDialog 
{
	private:
	
	protected:
		enum
		{
			dSetHack_ID = 1000,
			dLoadHack_ID,
			dSaveHack_ID,
			dNewCode_ID,
			dSetCode_ID,
			dGetCode_Tool,
			dDelCode_ID,
		};
		
		wxToolBar* dSetHack_TBar;
		wxScrolledWindow* m_scrolledWindow5;
		wxStaticText* dCodeType_S;
		wxChoice* dCodeType_D;
		wxStaticText* dCodeSize_S;
		wxChoice* dCodeSize_D;
		wxStaticText* dCodeRam_S;
		wxChoice* dCodeRam_D;
		wxStaticText* dCodeLoop_S;
		wxSpinCtrl* dCodeLoop_SN;
		wxTextCtrl* dCodeByte_TXT;
		wxStaticText* dCodePtr_S;
		wxSpinCtrl* dCodePtr_SN;
		wxPanel* dCodeInc_P;
		wxStaticText* dCodeInc_S;
		wxTextCtrl* dCodeInc_TXT;
		wxStaticText* dCodeMode_S;
		wxChoice* dCodeMode_D;
		wxTextCtrl* dCodeValue_TXT;
		wxPanel* dCodeSum_P;
		wxStaticText* dCodeSum_S;
		wxTextCtrl* dCodeSum_TXT;
		wxPanel* dCodeTest_P;
		wxStaticText* dCodeTest_S;
		wxChoice* dCodeTest_D;
		wxStaticText* dCodeTestThen_S;
		wxChoice* dCodeTestThen_D;
		wxListCtrl* dCode_LC;
		
		// Virtual event handlers, overide them in your derived class
		virtual void dSetHack_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dLoadHack_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSaveHack_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dNewCode_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dSetCode_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dGetCode_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dDelCode_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void dCode_LCOnSelect( wxListEvent& event ) { event.Skip(); }
		
	
	public:
		
		cleanSetHack_DLG( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Modify Codelist"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,480 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxRESIZE_BORDER ); 
		~cleanSetHack_DLG();
	
};

#endif //__CLEANFRM_H__
