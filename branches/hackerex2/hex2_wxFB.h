///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __HEX2_WXFB_H__
#define __HEX2_WXFB_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/toolbar.h>
#include <wx/gauge.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/statline.h>
#include <wx/spinbutt.h>
#include <wx/gbsizer.h>
#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/slider.h>
#include <wx/scrolwin.h>
#include <wx/grid.h>
#include <wx/treectrl.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class HexGUI
///////////////////////////////////////////////////////////////////////////////
class HexGUI : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			HexGUI_ID = 1000,
			hexGui_tbar_id,
			HexLoad_B_ID,
			HexSave_B_ID,
			HexNew_B_ID,
			HexDel_B_ID,
			HexSet_B_ID,
			HexGet_B_ID,
			hexFont_sc_id,
			HexQNew__B_ID,
			HexQFind_B_ID,
			HexQUndo_B_ID,
			HexQDump_B_ID,
			HexQDC_B_ID,
			HexQNC_B_ID,
			HexQEQ_B_ID,
			HexQNE_B_ID,
			HexQMT_B_ID,
			HexQME_B_ID,
			HexQLT_B_ID,
			HexQLE_B_ID,
			HexGUI_SP_ID,
			HexName_TXT_ID,
			HexState_B_ID,
			HexFile_TXT_ID,
			HexHook_DD_ID,
			HexBinBind_B_ID,
			HexBinBind_TXT_ID,
			HexPath_B_ID,
			HexBinPath_TXT_ID,
			HexBinExec_B_ID,
			HexBinKill_B_ID,
			HexRam_LB_ID,
			HexRamSize_TXT_ID,
			HexPID_TXT_ID,
			HexSID_TXT_ID,
			HexNotes_TA_ID,
			HexRegion_DD_ID,
			HexRegion_CLB_ID,
			HexRegionAll_RB_ID,
			HexRegionSel_RB_ID,
			HexExt_TXT_ID,
			HexFAdd_B_ID,
			HexConvert_B_ID,
			HexMerge_B_ID,
			HexCType_DD_ID,
			HexLoop_TXT_ID,
			HexUse_RB_ID,
			HexUse_CB_ID,
			HexHackKids_DD_ID,
			HexBinHack_B_ID,
			HexQInfo_DD_ID,
			HeJump_B_ID,
			HexAddr_TXT_ID,
			HexEGet_B_iD,
			HexESet_B_ID,
			HexVal_ID,
			HexInc_DD_ID,
			HexVType_DD_ID,
			HexVSize_TXT_ID,
			HexVSize_SPB_ID,
			HexVMSize_TXT_ID,
			HexVMSize_SPB_ID,
			HexList_LB_ID,
			HexGrid_G_ID,
			HexHack_TC_ID,
			HexCode_TC_ID,
			HexGUI_ST_ID,
		};
		
		wxToolBar* hexGui_tbar;
		wxButton* HexLoad_B;
		wxButton* HexSave_B;
		wxButton* HexNew_B;
		wxButton* HexDel_B;
		wxButton* HexSet_B;
		wxButton* HexGet_B;
		wxStaticText* hexFont_s;
		wxSpinCtrl* hexFont_sc;
		wxToolBar* HexQ_TB;
		wxButton* HexQNew__B;
		wxButton* HexQFind_B;
		wxButton* HexQUndo_B;
		wxButton* HexQDump_B;
		wxButton* HexQDC_B;
		wxButton* HexQNC_B;
		wxButton* HexQEQ_B;
		wxButton* HexQNE_B;
		wxButton* HexQMT_B;
		wxButton* HexQME_B;
		wxButton* HexQLT_B;
		wxButton* HexQLE_B;
		wxGauge* HexProgress_PB;
		wxSplitterWindow* HexGUI_SP;
		wxScrolledWindow* HexBody_SW;
		wxPanel* hexMode_p;
		wxChoice* hexMode_dd;
		wxPanel* HexName_P;
		wxTextCtrl* HexName_TXT;
		wxPanel* HexState_P;
		wxStaticText* HexOrgName_S;
		wxStaticText* HexPfmName_S;
		wxStaticText* HexBinName_S;
		wxStaticText* HexPflName_S;
		wxStaticText* HexHackFormat_S;
		wxButton* HexState_B;
		wxPanel* HexFile_P;
		wxTextCtrl* HexFile_TXT;
		wxPanel* HexEndian_P;
		wxChoice* HexEndian_DD;
		wxPanel* HexHook_P;
		wxChoice* HexHook_DD;
		wxPanel* HexBin_P;
		wxButton* HexBinBind_B;
		wxTextCtrl* HexBinBind_TXT;
		wxButton* HexBinPath_B;
		wxTextCtrl* HexBinPath_TXT;
		wxRadioButton* HexBinApp_RB;
		wxRadioButton* HexBinWin_RB;
		wxRadioButton* HexBinFSO_RB;
		wxButton* HexBinExec_B;
		wxButton* HexBinKill_B;
		wxPanel* HexRam_P;
		wxListBox* HexRam_LB;
		wxPanel* HexRamData_P;
		wxStaticText* HexRamSize_S1;
		wxStaticText* HexRamSize_S2;
		wxTextCtrl* HexRamSize_TXT;
		wxPanel* HexPfl_P;
		wxStaticText* HexPID_S;
		wxTextCtrl* HexPID_TXT;
		wxStaticText* HexSID_S;
		wxTextCtrl* HexSID_TXT;
		wxStaticText* HexNotes_S;
		wxTextCtrl* HexNotes_TA;
		wxChoice* HexRegion_DD;
		wxCheckListBox* HexRegion_CLB;
		wxRadioButton* HexRegionAll_RB;
		wxRadioButton* HexRegionSel_RB;
		wxPanel* HexFormat_P;
		wxStaticText* HexExt_S;
		wxTextCtrl* HexExt_TXT;
		wxButton* HexFAdd_B;
		wxStaticLine* HexFLine_HR;
		wxButton* HexConvert_B;
		wxButton* HexMerge_B;
		wxListBox* HexFormat_LB;
		wxPanel* HexCode_P;
		wxStaticText* HexCType_S;
		wxChoice* HexCType_DD;
		wxStaticText* HexLoop_S;
		wxTextCtrl* HexLoop_TXT;
		wxSpinButton* HexLoop_SPB;
		wxPanel* HexHck_P;
		wxRadioButton* HexUse_RB;
		wxCheckBox* HexUse_CB;
		wxStaticText* HexHackKids_S;
		wxChoice* HexHackKids_DD;
		wxButton* HexBinHack_B;
		wxPanel* HexQ_P;
		wxStaticText* HexQOut_S;
		wxChoice* HexQInfo_DD;
		wxPanel* HexOut_P;
		wxPanel* HexAddr_P;
		wxButton* HexJump_B;
		wxTextCtrl* HexAddr_TXT;
		wxRadioBox* HexEdit_RL;
		wxPanel* HexEAddr_P;
		wxButton* HexEGet_B;
		wxButton* HexESet_B;
		wxPanel* HexDepth_P;
		wxSlider* HexDepth_SL;
		wxPanel* HexVal_P;
		wxChoice* HexTest_DD;
		wxTextCtrl* HexVal_TXT;
		wxSpinButton* HexVal_SPB;
		wxChoice* HexInc_DD;
		wxTextCtrl* HexInc_TXT;
		wxStaticText* HexVType_S;
		wxChoice* HexVType_DD;
		wxStaticText* HexVSize_S;
		wxTextCtrl* HexVSize_TXT;
		wxSpinButton* HexVSize_SPB;
		wxStaticText* HexVMSize_S;
		wxTextCtrl* HexVMSize_TXT;
		wxSpinButton* HexVMSize_SPB;
		wxPanel* HexList_P;
		wxListBox* HexList_LB;
		wxGrid* HexGrid_G;
		wxPanel* HexTree_P;
		wxTreeCtrl* HexHack_TC;
		wxStaticLine* HexTree_SL;
		wxTreeCtrl* HexCode_TC;
		wxStatusBar* HexGUI_ST;
		
		// Virtual event handlers, overide them in your derived class
		virtual void G_OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void HexGUI_TB_OnToolExec( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexFont_SPC_OnSpin( wxSpinEvent& event ) { event.Skip(); }
		virtual void HexFont_SPC_OnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexState_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexBinExec_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexBinKill_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexFAdd_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexConvert_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexMerge_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexLoop_SBC( wxSpinEvent& event ) { event.Skip(); }
		virtual void HexBinHack_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexVal_OnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexVal_OnSpin( wxSpinEvent& event ) { event.Skip(); }
		virtual void HexList_LB_OnSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexHack_TC_OnSelect( wxTreeEvent& event ) { event.Skip(); }
		virtual void HexCode_TC_OnSelect( wxTreeEvent& event ) { event.Skip(); }
		
	
	public:
		
		HexGUI( wxWindow* parent, wxWindowID id = HexGUI_ID, const wxString& title = _("HackerEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 740,613 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		
		~HexGUI();
		
		void HexGUI_SPOnIdle( wxIdleEvent& )
		{
			HexGUI_SP->SetSashPosition( 200 );
			HexGUI_SP->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::HexGUI_SPOnIdle ), NULL, this );
		}
	
};

#endif //__HEX2_WXFB_H__
