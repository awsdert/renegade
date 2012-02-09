///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFRAME_H__
#define __GUIFRAME_H__

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
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/filepicker.h>
#include <wx/statbox.h>
#include <wx/bmpcbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/scrolwin.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/treectrl.h>
#include <wx/checkbox.h>
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
		wxChoice* cbGroup;
		wxButton* bGroup;
		wxRadioBox* rbHook;
		wxButton* bHook;
		wxButton* bLaunch;
		wxDirPickerCtrl* URL;
		wxBitmapComboBox* APFD;
		wxButton* bApp;
		wxTextCtrl* tApp;
		wxStaticText* HKWS;
		wxChoice* HKWD;
		wxComboBox* cbFile;
		wxTextCtrl* tFile;
		wxButton* bFile;
		wxRadioBox* rbRAM;
		wxStaticText* sRAMStart;
		wxTextCtrl* tRAMStart;
		wxStaticText* sRAMSize;
		wxTextCtrl* tRAMSize;
		wxButton* bAppList;
		wxButton* bAppUse;
		wxGrid* gApp;
		wxPanel* nbFind;
		wxPanel* nbResults;
		wxGrid* m_grid2;
		wxPanel* m_panel8;
		wxGrid* m_grid3;
		wxStaticText* m_staticText4;
		wxButton* m_button8;
		wxChoice* m_choice2;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrl5;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textCtrl6;
		wxPanel* EP;
		wxButton* EAB;
		wxTextCtrl* EAT;
		wxButton* EVB;
		wxTextCtrl* EVT;
		wxStaticText* EUS;
		wxChoice* EUD;
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
		wxTreeCtrl* HT;
		wxButton* bHackMove;
		wxChoice* cbHackMove;
		wxButton* bHTLoad;
		wxButton* bHTSave;
		wxPanel* HCP;
		wxStaticText* HCCS;
		wxChoice* HCCD;
		wxCheckBox* HCRC;
		wxStaticText* HCRAMS;
		wxChoice* HCRAMD;
		wxSpinCtrl* HCRN;
		wxStaticText* sHackA;
		wxTextCtrl* tHackA;
		wxChoice* mHackA;
		wxStaticText* sHackV;
		wxTextCtrl* tHackV;
		wxChoice* mHackV;
		wxPanel* HCTW;
		wxStaticText* HCTS1;
		wxChoice* HCTD1;
		wxStaticText* HCTS2;
		wxChoice* HCTD2;
		wxPanel* HCAW;
		wxStaticText* HCAS1;
		wxTextCtrl* HCAT;
		wxStaticText* HCAS2;
		wxPanel* HCVW;
		wxStaticText* HCVS1;
		wxTextCtrl* HCVT;
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
		virtual void groupOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void groupOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCHookOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void APFDOnChangeI( wxCommandEvent& event ) { event.Skip(); }
		virtual void appOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void APFDOnChangeT( wxCommandEvent& event ) { event.Skip(); }
		virtual void appOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mWaitOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppListOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppUseOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void EAOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void EVOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void EUOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void EGOnChange( wxGridEvent& event ) { event.Skip(); }
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
		virtual void HCRCOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCUOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCAddBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCDelBOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void HCChangeD( wxGridEvent& event ) { event.Skip(); }
		virtual void HCChangeR( wxGridRangeSelectEvent& event ) { event.Skip(); }
		virtual void HCChangeC( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		HEXFRM( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~HEXFRM();
	
};

#endif //__GUIFRAME_H__
