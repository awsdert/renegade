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
#include <wx/statusbr.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
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
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class HEXFRM
///////////////////////////////////////////////////////////////////////////////
class HEXFRM : public wxFrame 
{
	private:
	
	protected:
		wxStatusBar* SB;
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
		wxPanel* nbEdit;
		wxPanel* nbDB;
		wxPanel* nbHack;
		wxPanel* nbAbout;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void HEXFORMIDLE( wxIdleEvent& event ) { event.Skip(); }
		virtual void groupOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void groupOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void appOnBlur( wxFocusEvent& event ) { event.Skip(); }
		virtual void appOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mWaitOnChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppListOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bAppUseOnClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HEXFRM( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HEX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~HEXFRM();
	
};

#endif //__GUIFRAME_H__
