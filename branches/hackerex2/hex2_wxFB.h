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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/scrolwin.h>
#include <wx/treectrl.h>
#include <wx/statline.h>
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
			HexGUI_TB_ID,
			HexMain_TT_ID,
			HexList_TT_ID,
			HexSave_TT_ID,
			HexNew_TT_ID,
			HexDel_TT_ID,
			HexSet_TT_ID,
			HexGet_TT_ID,
			HexQDump_TT_ID,
			HexQFind_TT_ID,
			HexQUndo_TT_ID,
			HexQCT_TT_ID,
			HexQCF_TTID,
			HexQEQ_TT_ID,
			HexQNE_TT_ID,
			HexQMT_TT_ID,
			HexQME_TT_ID,
			HexQLT_TT_ID,
			HexQLE_TT_ID,
			HexGUI_SP_ID,
			HexName_TXT_ID,
			HexState_B_ID,
			HexFile_TXT_ID,
			HexBinBind_TXT_ID,
			HexBinPath_TXT_ID,
			HexBinExec_B_ID,
			HexBinHack_B_ID,
			HexRam_LB_ID,
			HexRamSize_TXT_ID,
			HexPID_TXT_ID,
			HexSID_TXT_ID,
			HexNotes_TA_ID,
			HexRegion_DD_ID,
			HexRegionAll_RB_ID,
			HexRegionSel_RB_ID,
			HexRegion_CLB_ID,
			HexUse_RB_ID,
			HexUse_CB_ID,
			HexAddr_TXT_ID,
			HexVal_TXT_ID,
			HexValF_DD_ID,
			HexValB_SP_ID,
			HexQType_DD_ID,
			HexQForm_DD_ID,
			HexQInfo_DD_ID,
			HexList_LB_ID,
			HexHack_TC_ID,
			HexCode_TC_ID,
			HexGUI_ST_ID,
		};
		
		wxToolBar* HexGUI_TB;
		wxToolBar* HexQ_TB;
		wxSplitterWindow* HexGUI_SP;
		wxScrolledWindow* HexBody_SW;
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
		wxPanel* HexBin_P;
		wxStaticText* HexBinBind_S;
		wxTextCtrl* HexBinBind_TXT;
		wxStaticText* HexBinPath_S;
		wxTextCtrl* HexBinPath_TXT;
		wxRadioButton* HexBinApp_RB;
		wxRadioButton* HexBinWin_RB;
		wxRadioButton* HexBinFSO_RB;
		wxButton* HexBinExec_B;
		wxButton* HexBinHack_B;
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
		wxRadioButton* HexRegionAll_RB;
		wxRadioButton* HexRegionSel_RB;
		wxCheckListBox* HexRegion_CLB;
		wxPanel* HexHck_P;
		wxRadioButton* HexUse_RB;
		wxCheckBox* HexUse_CB;
		wxPanel* HexAddr_P;
		wxTextCtrl* HexAddr_TXT;
		wxStaticText* HexDepth_S;
		wxSlider* HexDepth_SL;
		wxPanel* HexVal_P;
		wxTextCtrl* HexVal_TXT;
		wxStaticText* HexValF_S;
		wxChoice* HexValF_DD;
		wxStaticText* HexValB_S;
		wxSpinCtrl* HexValB_SP;
		wxPanel* HexQ_P;
		wxStaticText* HexQOut_S;
		wxStaticText* HexQType_S;
		wxChoice* HexQType_DD;
		wxStaticText* HexQForm_S;
		wxChoice* HexQForm_DD;
		wxCheckListBox* HexQSize_LBCB;
		wxChoice* HexQInfo_DD;
		wxStaticText* HexQVal_S;
		wxCheckBox* HexQAddrMT_CB;
		wxTextCtrl* HexQAddrMT_TXT;
		wxCheckBox* HexQAddrME_CB;
		wxTextCtrl* HexQAddrME_TXT;
		wxCheckBox* HexQAddrLT_CB;
		wxTextCtrl* HexQAddrLT_TXT;
		wxCheckBox* HexQAddrLE_CB;
		wxTextCtrl* HexQAddrLE_TXT;
		wxCheckBox* HexQCT_CB;
		wxTextCtrl* HexQCT_TXT;
		wxCheckBox* HexQCF_CB;
		wxTextCtrl* HexQCF_TXT;
		wxCheckBox* HexQEQ_CB;
		wxTextCtrl* HexQEQ_TXT;
		wxCheckBox* HexQNE_CB;
		wxTextCtrl* HexQNE_TXT;
		wxCheckBox* HexQMT_CB;
		wxTextCtrl* HexQMT_TXT;
		wxCheckBox* HexQME_CB;
		wxTextCtrl* HexQME_TXT;
		wxCheckBox* HexQLT_CB;
		wxTextCtrl* HexQLT_TXT;
		wxCheckBox* HexQLE_CB;
		wxTextCtrl* HexQLE_TXT;
		wxPanel* HexOut_P;
		wxScrolledWindow* m_scrolledWindow7;
		wxListBox* HexList_LB;
		wxPanel* HexTree_P;
		wxTreeCtrl* HexHack_TC;
		wxStaticLine* HexTree_SL;
		wxTreeCtrl* HexCode_TC;
		wxStatusBar* HexGUI_ST;
		
		// Virtual event handlers, overide them in your derived class
		virtual void HexGUI_TB_OnToolExec( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexState_B_OnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HexList_LB_OnSelect( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HexGUI( wxWindow* parent, wxWindowID id = HexGUI_ID, const wxString& title = _("HackerEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 678,613 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		
		~HexGUI();
		
		void HexGUI_SPOnIdle( wxIdleEvent& )
		{
			HexGUI_SP->SetSashPosition( 200 );
			HexGUI_SP->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HexGUI::HexGUI_SPOnIdle ), NULL, this );
		}
	
};

#endif //__HEX2_WXFB_H__