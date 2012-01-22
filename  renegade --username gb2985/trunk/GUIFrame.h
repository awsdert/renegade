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
#include <wx/combobox.h>
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
#include <wx/choice.h>
#include <wx/scrolwin.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobut.h>
#include <wx/listbox.h>
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
		wxComboBox* cbGroup;
		wxButton* bGroup;
		wxRadioBox* rbHook;
		wxButton* bHook;
		wxButton* bLaunch;
		wxDirPickerCtrl* URL;
		wxBitmapComboBox* cbApp;
		wxButton* bApp;
		wxTextCtrl* tApp;
		wxStaticText* sWait;
		wxChoice* mWait;
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
		wxPanel* nbEdit;
		wxButton* m_button9;
		wxTextCtrl* m_textCtrl10;
		wxButton* m_button10;
		wxTextCtrl* m_textCtrl11;
		wxGrid* m_grid4;
		wxPanel* nbDB;
		wxScrolledWindow* m_scrolledWindow3;
		wxRadioButton* m_radioBtn1;
		wxRadioButton* m_radioBtn11;
		wxRadioButton* m_radioBtn5;
		wxRadioButton* m_radioBtn6;
		wxRadioButton* m_radioBtn7;
		wxListBox* m_listBox1;
		wxPanel* m_panel9;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_textCtrl7;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textCtrl8;
		wxTextCtrl* m_textCtrl9;
		wxPanel* nbHack;
		wxChoice* cbAddHack;
		wxCheckBox* cAddHack;
		wxButton* bAddHack;
		wxButton* bDelHack;
		wxTreeCtrl* treeHack;
		wxButton* m_button15;
		wxChoice* m_choice4;
		wxScrolledWindow* m_scrolledWindow31;
		wxRadioButton* m_radioBtn9;
		wxRadioButton* m_radioBtn10;
		wxRadioButton* m_radioBtn111;
		wxRadioButton* m_radioBtn151;
		wxRadioButton* m_radioBtn16;
		wxRadioButton* m_radioBtn12;
		wxRadioButton* m_radioBtn13;
		wxRadioButton* m_radioBtn14;
		wxRadioButton* m_radioBtn15;
		wxRadioButton* m_radioBtn131;
		wxRadioButton* m_radioBtn141;
		wxCheckBox* m_checkBox1;
		wxSpinCtrl* m_spinCtrl2;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrl12;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl13;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_textCtrl14;
		wxButton* m_button13;
		wxButton* m_button14;
		wxGrid* m_grid5;
		wxPanel* nbAbout;
		wxStaticText* m_staticText10;
		wxHyperlinkCtrl* m_hyperlink2;
		wxStaticText* m_staticText9;
		wxHyperlinkCtrl* m_hyperlink1;
		wxStatusBar* SB;
		
		// Virtual event handlers, overide them in your derived class
		virtual void HEXFORMCLOSE( wxCloseEvent& event ) { event.Skip(); }
		virtual void HEXFORMIDLE( wxIdleEvent& event ) { event.Skip(); }
		virtual void groupOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void groupOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void appOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void appOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mWaitOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppListOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppUseOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAddHackOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bDelHackOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void treeHackOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		
	
	public:
		
		HEXFRM( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~HEXFRM();
	
};

#endif //__GUIFRAME_H__
