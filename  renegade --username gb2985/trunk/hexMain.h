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
#include <wx/tokenzr.h>
#include "hexApp.h"
#include "GUIFrame.h"
#include "hexVar.h"
class ME: public HEXFRM {
    public:
        ME(wxFrame *frame);
        ~ME();
    private:
        virtual void HEXFORMCLOSE(wxCloseEvent& event);
	public:
		// Hooking Time
		u8 HDTL, HDTI;
		wxArrayInt HDT;
		wxArrayString HSTR;
		void PFOnChange(wxCommandEvent& event);
		// File stuff
		u8 getPF(wxString s);
		wxChar myDiv; bool HTFT;
		wxStandardPaths myPaths;
		wxTextFile pff, dbf, htf; // Platform File, DataBase, Hack Tree
		wxDir dir;
		void PFSet(void);
		// ???
		HACK* getIH(wxTreeItemId& i);
		void delI(wxTreeItemId& i, wxTreeItemId& ni);
		void setIH(wxTreeItemId& i, HACK* h);
		int endian;
		wxArrayString DBFA, OSNA, PFEA;
		void HEXFRMOnFocus(wxActivateEvent& event);
		void HEXFORMIDLE(wxIdleEvent& event);
		// Hook Tab
		HANDLE GAP(void);
		u32 GAR(void);
		void groupOnBlur(wxFocusEvent& event);
		void groupOnClick(wxCommandEvent& event);
		void HCHookOnClick(wxCommandEvent& event);
		// Editor Tab
		void EA(void);
		void EV(void);
		void EAOnClick(wxCommandEvent& event);
		void EVOnClick(wxCommandEvent& event);
		void EUOnChange(wxCommandEvent& event);
		void EGOnChange(wxGridEvent& event);
		// Database Tab
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
		DBI* DBCopy(DBI* from, DBI* to);
		void DBAddBClick(wxCommandEvent& event);
		void DBSelect(void);
		void DBSelectC(wxTreeEvent& event);
		wxTreeItemId DBRoot(void);
		wxTreeItemId DBRoot(wxTreeItemId& i);
		// Hack Tab
		u16 HTJ;
		wxString treeFile, ht1, ht2, ht3, ht4;
		wxTreeItemId rti, ti, pti; // Root Item, Current Item, Previous Item
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
		void HCTest(CL code);
		CL HCSet(HACK* hack, int row);
		void HTSave(void);
		u16 HTSave(wxTreeItemId& r, u16 j, u16 l);
		void HTLoad(void);
		wxString HTLoad(wxTreeItemId& r, wxString s);
		wxTreeItemId HTFind(u16 j);
		wxTreeItemId HTFind(u16 j, wxTreeItemId& r);
		void bHTSaveOnClick(wxCommandEvent& event);
		void bHTLoadOnClick(wxCommandEvent& event);
		HACK* newH(void);
		void HCUOnChange(wxCommandEvent& event);
		void HTDel(wxTreeItemId& i);
		void HTDelAll(void);
		void HTMove(int direction);
		wxTreeItemId HTMove(wxTreeItemId& root, wxTreeItemId& new_root);
		void HTChange(void);
		void HTChange(wxTreeItemId& i);
		void HTOnChangeSelT(wxTreeEvent& event);
		void HTOnKeyUp(wxKeyEvent& event);
		int HCRow, HCRows;
		void HCLoad(void);
		void HCWrite(HANDLE p, DWORD x, int s, u32 v);
		wxString HCRead(HANDLE p, DWORD x, int s);
		// HC
		void HCUChange(void);
		void HCUse(wxTreeItemId& r, HANDLE pid, int j = 0, int stop = 0);
		void HCHook(void);
		void HCRCOnChange(wxCommandEvent& event);
		void HCCDOnChange(wxCommandEvent& event);
		void HCChange(int r);
		void HCChangeC(wxGridEvent& event);
		void HCChangeR(wxGridEvent& event);
		void HCChangeD(wxGridEvent& event);
		// Events
		u32 getHEX(wxString s);
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
		wxLongLong AW, AWU, EW, EWU, HW, HWU;
		int appLen, AWB, EWB, HWB;
};
#endif
