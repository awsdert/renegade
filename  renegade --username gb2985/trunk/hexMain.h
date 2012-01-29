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
#include "hexVar.h"
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
		wxTextFile dbf, htf; // DataBase, Hack Tree
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
		void DBFileTOnKeyD(wxKeyEvent& event);
		void DBDel(void);
		void DBDel(wxTreeItemId& i);
		void DBDelBOnClick(wxCommandEvent& event);
		void DBAdd(void);
		void DBAdd(wxString s, DBI* cv);
		void DBAddBClick(wxCommandEvent& event);
		void DBSelect(void);
		void DBSelectC(wxTreeEvent& event);
		wxTreeItemId DBRoot(void);
		wxTreeItemId DBRoot(wxTreeItemId& i);
		// Hack Tree
		wxString treeFile, ht1, ht2, ht3, ht4;
		wxTreeItemId ti, pti; // Current Item, Previous Item
		wxTreeItemId HTRoot(void);
		wxTreeItemId HTRoot(wxTreeItemId& i);
		wxTreeItemId HTAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK d);
		wxTreeItemId HTAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK* d);
		wxTreeItemId HTAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i);
		wxTreeItemId HTAdd(wxTreeItemId& r, wxString l, int where, HACK d);
		wxTreeItemId HTAdd(wxTreeItemId& r, wxString l, int where);
		wxTreeItemId HTFind(wxTreeItemId& r, wxString l);
		int HTCount(wxTreeItemId& r);
		void HTSet(void);
		void HTSave(void);
		WORD HTSave(wxTreeItemId& r, WORD j, WORD l);
		void HTLoad(void);
		wxTreeItemId HTFind(WORD j);
		wxTreeItemId HTFind(WORD j, wxTreeItemId& r);
		wxString HTLoad(wxTreeItemId& r, wxString s, int m);
		void bHTSaveOnClick(wxCommandEvent& event);
		void bHTLoadOnClick(wxCommandEvent& event);
		void HTDel(void);
		void HTDel(wxTreeItemId i);
		void HTMove(int direction);
		void HTMove(wxTreeItemId& root, wxTreeItemId& new_root);
		void HTChange(void);
		void HTChange(wxTreeItemId& i);
		void HTOnChangeSelT(wxTreeEvent& event);
		int HCRow, HCRows;
		void HCLoad(void);
		void HCChange(int r);
		void HCChangeC(wxGridEvent& event);
		void HCChangeR(wxGridEvent& event);
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
		void HCAddBOnClick(wxCommandEvent& event);
		void bHackCDelOnClick(wxCommandEvent& event);
		void HTOnKeyDown(wxKeyEvent& event);
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
