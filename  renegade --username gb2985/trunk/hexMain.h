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
#include "hexApp.h"
#include "GUIFrame.h"
WX_DEFINE_ARRAY(DWORD32*, DW32A);
class HACK: public wxTreeItemData {
	public:
		HACK();
		HACK(wxTreeItemData*);
		~HACK();
	public:
		bool use;
		int length;
		DW32A cPart1;
		DW32A cPart2;
		int GetLen();
		void SetLen(int l);
}; //HACK* Hack();
class hexWin: public HEXFRM {
    public:
        hexWin(wxFrame *frame);
        ~hexWin();
    private:
        virtual void HEXFORMCLOSE(wxCloseEvent& event);
	public:
		wxTreeItemId treeHackRoot(void);
		wxTreeItemId treeHackRoot(wxTreeItemId& i);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK* d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where, HACK d);
		wxTreeItemId treeHackAdd(wxTreeItemId& r, wxString l, int where);
		wxTreeItemId treeHackFind(wxTreeItemId& r, wxString l);
		DWORD32 getHEX(wxString s);
		int treeHackCount(wxTreeItemId& r);
		void treeHackDel(void);
		void treeHackDel(wxTreeItemId i);
		void treeHackMove(int direction);
		void treeHackMove(wxTreeItemId& root, wxTreeItemId& new_root);
		void HEXFORMIDLE(wxIdleEvent& event);
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
		int pLen, gLen;
		wxLongLong appWait, appWaitU;
		int appWaitB, appLen;
        wxString* groups;
        int* group;
        wxString* preset;
};
#endif
