#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
    // put here all your rarely-changing header files
#endif // WX_PRECOMP

// basic wxWidgets headers
#include <wx/wxprec.h>
#include <wx/thread.h>
#include <wx/stdpaths.h>
#include <wx/tokenzr.h>
#include <wx/dir.h>
#include <wx/fileconf.h>
#include <wx/textfile.h>
#include <wx/event.h>

#include <wx/scrolwin.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/tbarbase.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/stattext.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/scrolwin.h>
#include <wx/listbox.h>
#include <wx/treectrl.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

// Global defines
#define null NULL
#define wxOK_CANCEL wxOK | wxCANCEL

// Types

typedef wxString			Text;
typedef wxStringTokenizer	TxtT;
typedef wxArrayString		TxtA;
typedef wxTextFile			TxtF;
typedef wxFile				BinF;
typedef wxFileConfig		CfgF;
typedef wxTreeCtrl			TrCO;
typedef wxTreeItemId		TrId;
typedef wxTreeItemIdValue	TrIV;
typedef wxListBox			LBox;

#endif // WX_PCH_H_INCLUDED
