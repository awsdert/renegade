/***************************************************************
 * Name:      hexMain.h
 * Purpose:   Defines Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifndef HEXMAIN_H
#define HEXMAIN_H
#include <wx/filefn.h>
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/stdpaths.h>
#include "hexApp.h"
#include "GUIFrame.h"
enum HPF {
	PC32 = 0, PC64,
	PS1, PS2,
	N64, NGB, NDS, NWII,
	HPFL
}; // Hack Platform
class DBI: public wxTreeItemData {
	public:
		DBI(void);
		DBI(wxTreeItemData*);
		~DBI(void);
	public:
		CHAR afr;
		WORD afi;
		wxString afn, afs, afp;
};
class HACK: public wxTreeItemData {
	public:
		HACK();
		HACK(wxTreeItemData*);
		~HACK();
	public:
		bool use;
		WORD hid;
		unsigned int length;
		wxArrayString cPart1;
		wxArrayString cPart2;
		int GetLen();
		void SetLen(int l);
};
class hexWin: public HEXFRM {
    public:
        hexWin(wxFrame *frame);
        ~hexWin();
    private:
        virtual void HEXFORMCLOSE(wxCloseEvent& event);
	public:
		wxString myExe;
		wxChar myDiv;
		wxStandardPaths myPaths;
		wxTextFile db, ht; // DataBase, Hack Tree
		wxDir dir;
		wxArrayString dbFile, osName;
		wxArrayString* pfName;
		// Hook Tab
		void groupOnBlur(wxFocusEvent& event);
		void groupOnClick(wxCommandEvent& event);
		// DB List
		int dl; // List Count
		wxTreeItemId rdi, di, pdi; // Root Item, Current Item, Previous Item
		void DBSet(void);
		void DBLoad(void);
		void DBLoadBOnClick(wxCommandEvent& event);
		void DBSave(void);
		void DBSaveBOnClick(wxCommandEvent& event);
		void dbListAdd(void);
		void dbListAdd(wxString s, DBI* cv);
		void dbListAddBClick(wxCommandEvent& event);
		void dbListSelect(void);
		void dbListSelectC(wxTreeEvent& event);
		// Hack Tree
		wxString treeFile, ht1, ht2, ht3, ht4;
		wxTreeItemId ti, pti; // Current Item, Previous Item
		wxTreeItemId treeHackRoot(void);
		wxTreeItemId treeHackRoot(wxTreeItemId& i);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK* d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, HACK d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where);
		wxTreeItemId treeHackFind(wxTreeItemId& r, wxString l);
		int treeHackCount(wxTreeItemId& r);
		void HTSet(void);
		void HTSave(void);
		WORD HTSave(wxTreeItemId& r, WORD j, WORD l);
		void HTLoad(void);
		wxTreeItemId HTFind(WORD j);
		wxTreeItemId HTFind(WORD j, wxTreeItemId& r);
		wxString HTLoad(wxTreeItemId& r, WORD j, wxString s, int m);
		void bHTSaveOnClick(wxCommandEvent& event);
		void bHTLoadOnClick(wxCommandEvent& event);
		void treeHackDel(void);
		void treeHackDel(wxTreeItemId i);
		void treeHackMove(int direction);
		void treeHackMove(wxTreeItemId& root, wxTreeItemId& new_root);
		void treeHackChange(void);
		void treeHackOnChangeSelT(wxTreeEvent& event);
		void treeHackOnChangeSelM(wxMouseEvent& event);
		void treeHackOnChangeSel(wxCommandEvent& event);
		// Other
		DWORD32 getHEX(wxString s);
		void HEXFORMIDLE(wxIdleEvent& event);
		void afHook(void);
		void afHookBClick(wxCommandEvent& event);
		void bAppListOnClick(wxCommandEvent& event);
		void bAppUseOnClick(wxCommandEvent& event);
		void mWaitOnChange(wxCommandEvent& event);
		void bAddHackOnClick(wxCommandEvent& event);
		void bDelHackOnClick(wxCommandEvent& event);
		void bHackCAddOnClick(wxCommandEvent& event);
		void bHackCDelOnClick(wxCommandEvent& event);
		void treeHackOnKeyDown(wxKeyEvent& event);
		void setWait(int i);
		int getAppLen(void);
		void setApps(void);
        void addApp(int row, wxString id, wxString app, wxString title);
        // Variables
		DWORD AI;
		wxString AE;
		wxLongLong appWait, appWaitU;
		int appWaitB, appLen;
};
#endif
