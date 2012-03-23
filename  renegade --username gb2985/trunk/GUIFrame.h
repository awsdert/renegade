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
#include <wx/panel.h>
#include <wx/filepicker.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gauge.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
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
		wxPanel* hookPlatform;
		wxChoice* group_D;
		wxChoice* hookType_D;
		wxButton* loadGroup_B;
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
		wxPanel* hookRAM_P;
		wxButton* addRAM_B;
		wxGrid* RAMG;
		wxButton* APPLIST;
		wxButton* APPUSE;
		wxGrid* APPG;
		wxPanel* search_P;
		wxStaticText* good_S;
		wxStaticText* bad_S;
		wxGauge* byte_PB;
		wxScrolledWindow* good_SCROLL;
		wxCheckBox* goodAGT_CB;
		wxTextCtrl* goodAGT_TXT;
		wxCheckBox* goodAGTE_CB;
		wxTextCtrl* goodAGTE_TXT;
		wxCheckBox* goodALT_CB;
		wxTextCtrl* goodALT_TXT;
		wxCheckBox* goodALTE_CB;
		wxTextCtrl* goodALTE_TXT;
		wxCheckBox* goodVEqual_CB;
		wxTextCtrl* goodVEqual_TXT;
		wxCheckBox* goodVNOTE_CB;
		wxTextCtrl* goodVNOTE_TXT;
		wxCheckBox* goodVGT_CB;
		wxTextCtrl* goodVGT_TXT;
		wxCheckBox* goodVGTE_CB;
		wxTextCtrl* goodVGTE_TXT;
		wxCheckBox* goodVLT_CB;
		wxTextCtrl* goodVLT_TXT;
		wxCheckBox* goodVLTE_CB;
		wxTextCtrl* goodVLTE_TXT;
		wxScrolledWindow* bad_SCROLL;
		wxCheckBox* badAGT_CB;
		wxTextCtrl* badAGT_TXT;
		wxCheckBox* badAGTE_CB;
		wxTextCtrl* badAGTE_TXT;
		wxCheckBox* badALT_CB;
		wxTextCtrl* badALT_TXT;
		wxCheckBox* badALTE_CB;
		wxTextCtrl* badALTE_TXT;
		wxCheckBox* badVEqual_CB;
		wxTextCtrl* badVEqual_TXT;
		wxCheckBox* badVNOTE_CB;
		wxTextCtrl* badVNOTE_TXT;
		wxCheckBox* badVGT_CB;
		wxTextCtrl* badVGT_TXT;
		wxCheckBox* badVGTE_CB;
		wxTextCtrl* badVGTE_TXT;
		wxCheckBox* badVLT_CB;
		wxTextCtrl* badVLT_TXT;
		wxCheckBox* badVLTE_CB;
		wxTextCtrl* badVLTE_TXT;
		wxPanel* searchOptions_P;
		wxStaticText* total_S;
		wxStaticLine* searchOptions_LINE1;
		wxStaticText* compare_S;
		wxChoice* compare_D;
		wxStaticText* searchRAM_S;
		wxChoice* searchRAM_D;
		wxStaticText* searchType_S;
		wxChoice* searchType_D;
		wxStaticText* searchSize_S;
		wxChoice* searchSize_D;
		wxStaticText* searchValueType_S;
		wxChoice* searchValueType_D;
		wxCheckBox* searchIsSigned_CB;
		wxStaticText* searchIsSigned_S;
		wxCheckBox* searchIsBinary_CB;
		wxStaticText* searchIsBinary_S;
		wxStaticLine* searchOptions_LINE2;
		wxButton* dump_B;
		wxButton* search_B;
		wxButton* searchUndo_B;
		wxButton* searchLT_B;
		wxButton* searchLTE_B;
		wxButton* searchEqual_B;
		wxButton* searchNOTE_B;
		wxButton* searchGTE_B;
		wxButton* searchGT_B;
		wxPanel* RP;
		wxGrid* RG;
		wxPanel* RHP;
		wxCheckBox* useEdit_CB;
		wxGrid* resultHack_G;
		wxButton* resultHackAdd_B;
		wxButton* resultHackDel_B;
		wxStaticText* resultHackRAM_S;
		wxChoice* resultHackRAM_D;
		wxStaticText* resultHackSize_S;
		wxChoice* resultHackSize_D;
		wxStaticText* resultHackAddress_S;
		wxTextCtrl* resultHackAddress_TXT;
		wxStaticText* resultHackMode_S;
		wxChoice* resultHackMode_D;
		wxStaticText* resultHackValue_S;
		wxTextCtrl* resultHackValue_TXT;
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
		wxStaticText* codeType_S;
		wxChoice* codeType_D;
		wxStaticText* codeRepeat_S;
		wxStaticText* codeRAM_S;
		wxChoice* codeRAM_D;
		wxSpinCtrl* codeRepeat_SN;
		wxStaticText* codeAddress_S;
		wxTextCtrl* codeAddress_TXT;
		wxChoice* codeFixed_D;
		wxChoice* codeSize_D;
		wxTextCtrl* codeValue_TXT;
		wxChoice* codeMode_D;
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
		virtual void appName_TXTOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void mWaitOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINDOnEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void BINBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void addRAM_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ram_GOnChange( wxGridEvent& event ) { event.Skip(); }
		virtual void APPLISTOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void APPUSEOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void byte_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void byte_TXTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void search_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void search_TXTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void compare_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchValueType_DOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void dump_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void search_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchUndo_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchLT_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchLTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchEqual_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchNOTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchGTE_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void searchGT_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void result_GOnSelect( wxGridEvent& event ) { event.Skip(); }
		virtual void resultHack_GOnSelectCell( wxGridEvent& event ) { event.Skip(); }
		virtual void resultHackAdd_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void resultHackDel_BOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void address_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void address_TXTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
		virtual void resultValue_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void resultValue_TXTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
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
		virtual void codeValue_TXTOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void codeValue_TXTOnKeyUp( wxKeyEvent& event ) { event.Skip(); }
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
