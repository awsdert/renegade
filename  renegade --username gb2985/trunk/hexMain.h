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
// DB = Database List, HT = Hack Tree
enum TESTM { TM_EQUAL = 0x00, TM_LT, TM_GT, TM_LTEQUAL, TM_GTEQUAL, TM_NOTEQUAL, TM_INSIDE, TM_OUTSITE };
class ME: public HEXFRM {
    public:
        ME(wxFrame *frame);
        ~ME();
    private:
        virtual void HEXFORMCLOSE(wxCloseEvent& event);
	public:
		// Globals
		u8 HDTI; // Hook Time Index
		xAInt HDT; // Hook Time Value List
		HACK* getIH(xTID& i);
		void delI(xTID& i, xTID& ni);
		void setIH(xTID& i, HACK* h);
		int endian;
		xAStr DBFA, PFEA;
		DWORD AI;
		xStr AE;
		wxLongLong AW, AWU, EW, EWU, HW, HWU;
		int appLen, AWB, EWB, HWB;
		u16 HTJ;
		xStr treeFile, ht1, ht2, ht3, ht4;
		xTID rti, ti, pti; // Root Item, Current Item, Previous Item
		int dl; // List Count
		xTID rdi, di, pdi; // Root Item, Current Item, Previous Item
		// - App Selection
		xAInt appNum, appEnd;
		xAStr appName, ramName, ramFixed, ramStart, ramSize;
		// - File stuff
		u8 getPF(xStr s);
		wxChar myDiv; //bool HTFT;
		wxStandardPaths myPaths;
		wxTextFile pff, dbf, htf; // Platform File, DataBase, Hack Tree
		wxDir dir;
		// - Search File
		wxFile qbf, qbt;
		// hexMain.cpp
		HANDLE GAP(void);
		xStr GARAM(u8 r, u8 c);
		xStr GARN(u8 r);
		bool GART(u8 r);
		void ClearGrid(wxGrid*& grid);
		u32 GARS(u8 r);
		u32 GARM(u8 r);
		u64 getHEX(xStr s);
		int getAppLen(void);
        void addApp(int row, xStr id, xStr app, xStr title);
		// hexVar.cpp
		HACK* newH(void);
		// hexEvents.cpp
		// - Main Window
		void HEXFRMOnFocus(wxActivateEvent& event);
		void HEXFORMIDLE(wxIdleEvent& event);
		// - - Hook Tab
		void HCHookOnClick(wxCommandEvent& event);
		void APPLISTOnClick(wxCommandEvent& event);
		void APPUSEOnClick(wxCommandEvent& event);
		void mWaitOnChange(wxCommandEvent& event);
		// - - - Platform
		void PFOnBlur(wxFocusEvent& event);
		void PFOnClick(wxCommandEvent& event);
		void PFOnChange(wxCommandEvent& event);
		// - - - App
		void APPDOnChange(wxCommandEvent& event);
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
		//void HTOnDel(wxTreeEvent& event);
		void bHTSaveOnClick(wxCommandEvent& event);
		void bHTLoadOnClick(wxCommandEvent& event);
		void bAddHackOnClick(wxCommandEvent& event);
		void bDelHackOnClick(wxCommandEvent& event);
		void HTOnKeyDown(wxKeyEvent& event);
		void HTOnChangeSelT(wxTreeEvent& event);
		void HTOnKeyUp(wxKeyEvent& event);
		// - - - Hack Codelist
		void HCDelBOnClick(wxCommandEvent& event);
		void HCChangeC(wxGridEvent& event); // Load hack codeline
		void HCChangeR(wxGridEvent& event); // Load first hack codeline in range
		void HCChangeD(wxGridEvent& event); // Change hack codeline
		void HCRCOnChange(wxCommandEvent& event); // Does codeline repeat?
		void HCCDOnChange(wxCommandEvent& event); // Set type of codeline
		void HCUOnChange(wxCommandEvent& event); // Use / Don't use hack
		// HCC.cpp
		CL HCSet(HACK* hack, int row);
		void HCAddBOnClick(wxCommandEvent& event);
		// qTab.cpp
		bool Test(int mode, u64 value, u64 against);
		bool Test(int mode, u64 value, u64 from, u64 to);
		void QSet(int q, int size);
		u64* OldA(int sn);
		u8* OldV8(int sn);
		void Dump8(void);
		void Dump16(void);
		void Dump32(void);
		void Dump64(void);
		void Find8(u8 mode = 0);
		void Find16(u8 mode = 0);
		void Find32(u8 mode = 0);
		void Find64(u8 mode = 0);
		void bQActSOnClick(wxCommandEvent& event);
		// hTab.cpp
		void setAWait(int i);
		void setApps(void);
		// - Platform
		void PFSet(void);
		void PFLoad(void);
		// eTab.cpp
		void EA(void); // Fill editor from Address
		void EV(void); // Change value at address
		// DB.cpp
		void DBSet(void); // Get database file ready for loading / saving
		void DBLoad(void);
		void DBSave(void);
		void DBDel(void);
		void DBDel(xTID& i);
		void DBAdd(void);
		void DBAdd(xStr s, DBI* cv);
		DBI* DBCopy(DBI* from, DBI* to);
		void DBSelect(void);
		xTID DBRoot(void);
		xTID DBRoot(xTID& i); // Get Parent or if invalid return the root
		// HT.cpp
		// - Hack Tab
		// - - Hack Tree
		void HTLoad(void);
		xStr HTLoad(xTID& r, xStr s);
		void HTSave(void);
		u16 HTSave(xTID& r, u16 j, u16 l);
		xTID HTRoot(void);
		xTID HTRoot(xTID& i); // Get Parent or if invalid return the root
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i, HACK d);
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i, HACK* d);
		xTID HTAdd(xTID& r, xStr l, int where, xTID& i);
		xTID HTAdd(xTID& r, xStr l, int where, HACK d);
		xTID HTAdd(xTID& r, xStr l, int where);
		xTID HTFind(xTID& r, xStr l);
		int HTCount(xTID& r);
		void HTSet(void);
		void HCTest(CL code);
		xTID HTFind(u16 j);
		xTID HTFind(u16 j, xTID& r);
		void HTDel(xTID& i);
		void HTDelAll(void);
		void HTMove(int direction);
		xTID HTMove(xTID& root, xTID& new_root);
		void HTChange(void);
		void HTChange(xTID& i);
		int HCRow, HCRows;
		void HCLoad(void);
		void HCWrite(HANDLE p, DWORD x, int s, DWORD v);
		xStr HCRead(HANDLE p, DWORD x, int s);
		DWORD HCReadH(HANDLE p, DWORD x, int s);
		u8* HCReadM8(HANDLE p, DWORD x, u64 s);
		u16* HCReadM16(HANDLE p, DWORD x, u64 s);
		u32* HCReadM32(HANDLE p, DWORD x, u64 s);
		u64* HCReadM64(HANDLE p, DWORD x, u64 s);
		// HC.cpp
		// - Hack Tab
		// - - Hack Codelist
		void HCUChange(void);
		void HCUse(xTID& r, HANDLE pid, int j = 0, int stop = 0);
		void HCHook(void);
		void HCChange(int r);
};
#endif
