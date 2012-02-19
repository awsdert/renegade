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
#include <wx/ffile.h>
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/stdpaths.h>
#include "hexApp.h"
#include "GUIFrame.h"
#include "hexVar.h"
#define BLANK(blank_argument)
#define ReadWriteApp HANDLE appHandle, DWORD xAddress, u64 size
// DB = Database List, HT = Hack Tree
enum { TMU_EQUAL = 0x00000000, TMU_NOTE, TMU_GT, TMU_GTE, TMU_LT, TMU_LTE,
	TMU_INSIDE, TMU_OUTSIDE, TMU_LENGTH };
const u32 TM_EQUAL = 0x1, TM_GT = 0x2, TM_GTE = 0x4, TM_INSIDE = 0x8,
	TM_NOTE = 0x10, TM_LT = 0x20, TM_LTE = 0x40, TM_OUTSIDE = 0x80,
	TM_00 = 0x100, TM_FF = 0x200;
const xStr TMU_VAL1 = _(" Value 1");
const xStr TMU_VAL2 = _(" Value 2");
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
		s32 endian;
		xAStr DBFA, PFEA;
		DWORD AI;
		xStr AE;
		wxLongLong AW, AWU, EW, EWU, HW, HWU;
		s32 appLen, AWB, EWB, HWB;
		u16 HTJ;
		xStr treeFile, ht1, ht2, ht3, ht4;
		xTID rti, ti, pti; // Root Item, Current Item, Previous Item
		s32 dl; // List Count
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
		xAStr TMU;
		// hexMain.cpp
		HANDLE GAP(void);
		xStr GARAM(s32 r, s32 c);
		xStr GARN(s32 r);
		bool GART(s32 r);
		void ClearGrid(wxGrid*& grid);
		void ClearGridCols(wxGrid*& grid);
		DWORD GARS(s32 r);
		u32 GARM(s32 r);
		u64 getHEX(xStr s);
		s32 getAppLen(void);
        void addApp(s32 row, xStr id, xStr app, xStr title);
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
		CL HCSet(HACK* hack, s32 row);
		void HCAddBOnClick(wxCommandEvent& event);
		// qTab.cpp
		void validateValue(wxKeyEvent& event, u32 valMode = 0);
		void validateFileName(wxKeyEvent& event);
		void value1_TXTOnKeyDown(wxKeyEvent& event);
		u64 value1, value2;
		u32 GetTests(void);
		u32 GetIgnore(void);
		u32 GetIgnoreAddress(void);
		bool Test(u32 mode, u64 value, u64 against, u64 to = 0);
		void QSet(s32 q, s32 size, bool overwrite = true);
		u64* OldV(s32 sn, bool update = true);
		u64 *oldBuff, *newBuff;
		s32 oldSearchNo;
		u64 oldLength;
		void Dump8(void);
		void Dump16(void);
		void Dump32(void);
		void Dump64(void);
		void Find8(u32 mode = 0);
		void Find16(u32 mode = 0);
		void Find32(u32 mode = 0);
		void Find64(u32 mode = 0);
		void bQActSOnClick(wxCommandEvent& event);
		// hTab.cpp
		void setAWait(s32 i);
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
		xTID HTAdd(xTID& r, xStr l, s32 where, xTID& i, HACK d);
		xTID HTAdd(xTID& r, xStr l, s32 where, xTID& i, HACK* d);
		xTID HTAdd(xTID& r, xStr l, s32 where, xTID& i);
		xTID HTAdd(xTID& r, xStr l, s32 where, HACK d);
		xTID HTAdd(xTID& r, xStr l, s32 where);
		xTID HTFind(xTID& r, xStr l);
		s32 HTCount(xTID& r);
		void HTSet(void);
		void HCTest(CL code);
		xTID HTFind(u16 j);
		xTID HTFind(u16 j, xTID& r);
		void HTDel(xTID& i);
		void HTDelAll(void);
		void HTMove(s32 direction);
		xTID HTMove(xTID& root, xTID& new_root);
		void HTChange(void);
		void HTChange(xTID& i);
		s32 HCRow, HCRows;
		void HCLoad(void);
		void HCWrite(ReadWriteApp, DWORD v);
		xStr HCRead(ReadWriteApp);
		DWORD HCReadH(ReadWriteApp);
		u8* HCReadM8(ReadWriteApp);
		u16* HCReadM16(ReadWriteApp);
		u32* HCReadM32(ReadWriteApp);
		u64* HCReadM64(ReadWriteApp);
		// HC.cpp
		// - Hack Tab
		// - - Hack Codelist
		void HCUChange(void);
		void HCUse(xTID& r, HANDLE pid, s32 j = 0, s32 stop = 0);
		void HCHook(void);
		void HCChange(s32 r);
};
#endif
