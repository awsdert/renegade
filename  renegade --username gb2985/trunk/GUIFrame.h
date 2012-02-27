///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/cshelp.h>
#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gauge.h>
#include <wx/checkbox.h>
#include <wx/treectrl.h>
#include <wx/spinctrl.h>
#include <wx/hyperlink.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class HEXFRM
///////////////////////////////////////////////////////////////////////////////
class HEXFRM : public wxFrame 
{
	private:
	
	protected:
		wxNotebook* NB;
		wxPanel* nbHook;
		wxScrolledWindow* wHookScroll;
		wxChoice* group_D;
		wxButton* loadGroup_B;
		wxChoice* hookType_D;
		wxButton* saveGroup_B;
		wxButton* PFGetB;
		wxButton* PFStartB;
		wxDirPickerCtrl* URL;
		wxPanel* hookApp_P;
		wxComboBox* appTitle_D;
		wxButton* appUpdate_B;
		wxTextCtrl* appName_TXT;
		wxStaticText* APPS;
		wxChoice* APPCheck;
		wxPanel* hookFile_P;
		wxComboBox* fileTitle_D;
		wxTextCtrl* fileName_TXT;
		wxButton* BINB;
		wxButton* addRAM_B;
		wxGrid* RAMG;
		wxButton* APPLIST;
		wxButton* APPUSE;
		wxGrid* APPG;
		wxPanel* QP;
		wxStaticText* QSizeS;
		wxChoice* searchSize_D;
		wxStaticText* QCompareS;
		wxChoice* QCompareD;
		wxButton* bQActD;
		wxButton* bQActS;
		wxButton* bQActUS;
		wxGauge* pbQAct;
		wxButton* bQActLT;
		wxButton* bQActLTE;
		wxButton* bQActE;
		wxButton* bQActNE;
		wxButton* bQActGTE;
		wxButton* bQActGT;
		wxChoice* useTest_D;
		wxCheckBox* isSigned_CB;
		wxStaticText* result_S;
		wxStaticText* value1_S;
		wxTextCtrl* value1_TXT;
		wxStaticText* value2_S;
		wxTextCtrl* value2_TXT;
		wxStaticText* ignore_S;
		wxScrolledWindow* ignore_SW;
		wxCheckBox* ignore0_CB;
		wxCheckBox* ignoreF_CB;
		wxCheckBox* ignoreValue_CB;
		wxTextCtrl* ignoreValue_TXT;
		wxCheckBox* ignoreInside_CB;
		wxTextCtrl* ignoreInsideFrom_TXT;
		wxStaticText* ignoreInside_S;
		wxTextCtrl* ignoreInsideTo_TXT;
		wxCheckBox* ignoreOutside_CB;
		wxTextCtrl* ignoreOutsideFrom_TXT;
		wxStaticText* ignoreOutside_S;
		wxTextCtrl* ignoreOutsideTo_TXT;
		wxCheckBox* ignorePart8_CB;
		wxTextCtrl* ignorePart8_TXT;
		wxCheckBox* ignorePart16_CB;
		wxTextCtrl* ignorePart16_TXT;
		wxCheckBox* ignorePart32_CB;
		wxTextCtrl* ignorePart32_TXT;
		wxCheckBox* ignorePart64_CB;
		wxTextCtrl* ignorePart64_TXT;
		wxCheckBox* ignorePart8Range_CB;
		wxTextCtrl* ignorePart8RangeFrom_TXT;
		wxStaticText* ignorePart8Range_S;
		wxTextCtrl* ignorePart8RangeTo_TXT;
		wxCheckBox* ignorePart16Range_CB;
		wxTextCtrl* ignorePart16RangeFrom_TXT;
		wxStaticText* ignorePart16Range_S;
		wxTextCtrl* ignorePart16RangeTo_TXT;
		wxCheckBox* ignorePart32Range_CB;
		wxTextCtrl* ignorePart32RangeFrom_TXT;
		wxStaticText* ignorePart32Range_S;
		wxTextCtrl* ignorePart32RangeTo_TXT;
		wxCheckBox* ignorePart64Range_CB;
		wxTextCtrl* ignorePart64RangeFrom_TXT;
		wxStaticText* ignorePart64Range_S;
		wxTextCtrl* ignorePart64RangeTo_TXT;
		wxCheckBox* ignoreAddressOutside_CB;
		wxTextCtrl* ignoreAddressOutsideFrom_TXT;
		wxStaticText* ignoreAddressOutside_S;
		wxTextCtrl* ignoreAddressOutsideTo_TXT;
		wxPanel* RP;
		wxGrid* RG;
		wxPanel* RHP;
		wxCheckBox* useEdit_CB;
		wxGrid* RHG;
		wxStaticText* RHTS;
		wxButton* RHAdd;
		wxChoice* RHTD;
		wxStaticText* RHAS;
		wxTextCtrl* resultAddress_TXT;
		wxStaticText* RHVS;
		wxTextCtrl* resultValue_TXT;
		wxPanel* EP;
		wxButton* EAB;
		wxTextCtrl* editorAddress_TXT;
		wxButton* EVB;
		wxTextCtrl* EVT;
		wxStaticText* EUS;
		wxChoice* EUD;
		wxChoice* EMD;
		wxGrid* EG;
		wxPanel* DBP;
		wxStaticText* DBRS;
		wxChoice* DBRM;
		wxButton* DBAddB;
		wxButton* DBDelB;
		wxTreeCtrl* DB;
		wxButton* DBLoadB;
		wxButton* DBSaveB;
		wxPanel* DBInfoP;
		wxCheckBox* DBRuk;
		wxCheckBox* DBRus;
		wxCheckBox* DBRjp;
		wxCheckBox* DBRde;
		wxStaticText* DBSIDS;
		wxTextCtrl* DBSIDT;
		wxStaticText* DBAFS;
		wxTextCtrl* DBAFT;
		wxStaticText* DBFileS;
		wxTextCtrl* DBFileT;
		wxTextCtrl* DBNotes;
		wxPanel* HTP;
		wxChoice* HTAddD;
		wxCheckBox* HTAddC;
		wxButton* HTAddB;
		wxButton* HTDelB;
		wxButton* bHackMove;
		wxChoice* cbHackMove;
		wxButton* bHTLoad;
		wxButton* bHTSave;
		wxPanel* HCP;
		wxStaticText* HCCS;
		wxChoice* codeType_D;
		wxStaticText* codeRepeat_S;
		wxStaticText* HCRAMS;
		wxChoice* codeRAM_D;
		wxSpinCtrl* codeRepeat_SN;
		wxStaticText* sHackA;
		wxTextCtrl* codeAddress_TXT;
		wxChoice* codeFixed_D;
		wxStaticText* sHackV;
		wxTextCtrl* codeValue_TXT;
		wxChoice* codeSize_D;
		wxPanel* HCTW;
		wxStaticText* HCTS1;
		wxChoice* codeTest_D;
		wxStaticText* HCTS2;
		wxChoice* codeTestLine_D;
		wxPanel* HCAW;
		wxStaticText* HCAS1;
		wxTextCtrl* codeIncAddress_TXT;
		wxStaticText* HCAS2;
		wxPanel* HCVW;
		wxStaticText* HCVS1;
		wxTextCtrl* codeIncValue_TXT;
		wxStaticText* HCVS2;
		wxCheckBox* HCUseC;
		wxButton* HCAddB;
		wxButton* HCLoadB;
		wxButton* HCDelB;
		wxGrid* HCG;
		wxPanel* nbAbout;
		wxStaticText* m_staticText10;
		wxHyperlinkCtrl* m_hyperlink2;
		wxStaticText* m_staticText9;
		wxHyperlinkCtrl* m_hyperlink1;
		wxStatusBar* SB;
		
		// Virtual event handlers, overide them in your derived class
		virtual void HEXFORMCLOSE( wxCloseEvent& event ) { event.Skip(); }
		virtual void HEXFORMIDLE( wxIdleEvent& event ) { event.Skip(); }
		virtual void PFOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void PFOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void saveGroup_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void PFGetOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void PFStartOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void appTitle_DOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void appUpdate_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mWaitOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void addRAM_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ram_GOnChange( wxGridEvent& event ) { event.Skip(); }
		virtual void APPLISTOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void APPUSEOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bQActSOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void value_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void address_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void result_GOnSelect( wxGridEvent& event ) { event.Skip(); }
		virtual void EAOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void EVOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void EUOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void EGOnChange( wxGridEvent& event ) { event.Skip(); }
		virtual void editor_GOnScroll( wxMouseEvent& event ) { event.Skip(); }
		virtual void DBAddBClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DBDelBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DBSelectC( wxTreeEvent& event ) { event.Skip(); }
		virtual void DBLoadBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DBSaveBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DBFileTOnKeyD( wxKeyEvent& event ) { event.Skip(); }
		virtual void bAddHackOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bDelHackOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void HTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void HTOnChangeSelT( wxTreeEvent& event ) { event.Skip(); }
		virtual void bHTLoadOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bHTSaveOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCCDOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void codeRepeat_SNOnSpin( wxSpinEvent& event ) { event.Skip(); }
		virtual void HCUOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCAddBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCLoadOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCDelBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCChangeD( wxGridEvent& event ) { event.Skip(); }
		virtual void HCChangeR( wxGridRangeSelectEvent& event ) { event.Skip(); }
		virtual void HCChangeC( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		wxFlexGridSizer* HTTL;
		wxTreeCtrl* HT;
		
		HEXFRM( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~HEXFRM();
	
};

#endif //__GUIFrame__
