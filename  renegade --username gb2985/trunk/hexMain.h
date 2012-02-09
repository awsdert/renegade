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
class ME: public HEXFRM {
    public:
        ME(wxFrame *frame);
        ~ME();
    private:
        virtual void HEXFORMCLOSE(wxCloseEvent& event);
	public:
		// Globals
		u8 HDTL, HDTI;
		wxArrayInt HDT;
		wxArrayString HSTR;
		HACK* getIH(xTID& i);
		void delI(xTID& i, xTID& ni);
		void setIH(xTID& i, HACK* h);
		int endian;
		wxArrayString DBFA, OSNA, PFEA;
		DWORD AI;
		xStr AE;
		wxLongLong AW, AWU, EW, EWU, HW, HWU;
		int appLen, AWB, EWB, HWB;
		// - File stuff
		u8 getPF(xStr s);
		wxChar myDiv; bool HTFT;
		wxStandardPaths myPaths;
		wxTextFile pff, dbf, htf; // Platform File, DataBase, Hack Tree
		wxDir dir;
		// hexMain.cpp
		HANDLE GAP(void);
		u32 GAR(void);
		u32 GAR(u8 i = 0);
		void PFSet(void);
		// hexEvents.cpp
		// - Main Window
		void HEXFRMOnFocus(wxActivateEvent& event);
		void HEXFORMIDLE(wxIdleEvent& event);
		// - - Hook Tab
		void HCHookOnClick(wxCommandEvent& event);
		void bAppListOnClick(wxCommandEvent& event);
		void bAppUseOnClick(wxCommandEvent& event);
		void mWaitOnChange(wxCommandEvent& event);
		// - - - Group
		void groupOnBlur(wxFocusEvent& event);
		void groupOnClick(wxCommandEvent& event);
		// - - - Profile
		void PFOnChange(wxCommandEvent& event);
		// - - Editor Tab
		void EAOnClick(wxCommandEvent& event);
		void EVOnClick(wxCommandEvent& event);
		void EUOnChange(wxCommandEvent& event);
		void EGOnChange(wxGridEvent& event);
		// - - Database Tab
		void DBLoadBOnClick(wxCommandEvent& event);
		void DBSaveBOnClick(wxCommandEvent& event);
		void DBFileTOnKeyD(wxKeyEvent& event);
		void DBDelBOnClick(wxCommandEvent& event);
		void DBAddBClick(wxCommandEvent& event);
		void DBSelectC(wxTreeEvent& event);
		// - - Hack Tree Tab
		void bHTSaveOnClick(wxCommandEvent& event);
		void bHTLoadOnClick(wxCommandEvent& event);
		void bAddHackOnClick(wxCommandEvent& event);
		void bDelHackOnClick(wxCommandEvent& event);
		void HTOnKeyDown(wxKeyEvent& event);
		void HTOnChangeSelT(wxTreeEvent& event);
		void HTOnKeyUp(wxKeyEvent& event);
		// - - - Hack Codelist
		void HCAddBOnClick(wxCommandEvent& event);
		void HCDelBOnClick(wxCommandEvent& event);
		void HCChangeC(wxGridEvent& event);
		void HCChangeR(wxGridEvent& event);
		void HCChangeD(wxGridEvent& event);
		void HCRCOnChange(wxCommandEvent& event);
		void HCCDOnChange(wxCommandEvent& event);
		// hTab.cpp
		void groupLoad(void);
		// eTab.cpp
		void EA(void);
		void EV(void);
		// DB.cpp
		int dl; // List Count
		xTID rdi, di, pdi; // Root Item, Current Item, Previous Item
		void DBSet(void);
		void DBLoad(void);
		void DBSave(void);
		void DBDel(void);
		void DBDel(xTID& i);
		void DBAdd(void);
		void DBAdd(xStr s, DBI* cv);
		DBI* DBCopy(DBI* from, DBI* to);
		void DBSelect(void);
		xTID DBRoot(void);
		xTID DBRoot(xTID& i);
		// HT.cpp
		u16 HTJ;
		xStr treeFile, ht1, ht2, ht3, ht4;
		xTID rti, ti, pti; // Root Item, Current Item, Previous Item
		xTID HTRoot(void);
		xTID HTRoot(xTID& i);
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i, HACK d);
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i, HACK* d);
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i);
		xTID HTAdd(xTID& r, xStr l, int where, HACK d);
		xTID HTAdd(xTID& r, xStr l, int where);
		xTID HTFind(xTID& r, xStr l);
		int HTCount(xTID& r);
		void HTSet(void);
		void HCTest(CL code);
		CL HCSet(HACK* hack, int row);
		void HTSave(void);
		u16 HTSave(xTID& r, u16 j, u16 l);
		void HTLoad(void);
		xStr HTLoad(xTID& r, xStr s);
		xTID HTFind(u16 j);
		xTID HTFind(u16 j, xTID& r);
		HACK* newH(void);
		void HCUOnChange(wxCommandEvent& event);
		void HTDel(xTID& i);
		void HTDelAll(void);
		void HTMove(int direction);
		xTID HTMove(xTID& root, xTID& new_root);
		void HTChange(void);
		void HTChange(xTID& i);
		int HCRow, HCRows;
		void HCLoad(void);
		void HCWrite(HANDLE p, DWORD x, int s, u32 v);
		xStr HCRead(HANDLE p, DWORD x, int s);
		// HC.cpp
		void HCUChange(void);
		void HCUse(xTID& r, HANDLE pid, int j = 0, int stop = 0);
		void HCHook(void);
		void HCChange(int r);
		// Common
		u32 getHEX(xStr s);
		void setWait(int i);
		int getAppLen(void);
		void setApps(void);
        void addApp(int row, xStr id, xStr app, xStr title);
};
#endif
