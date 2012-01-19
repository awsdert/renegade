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
class hexWin: public HEXFRM {
    public:
        hexWin(wxFrame *frame);
        ~hexWin();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
	public:
		wxTreeItemId treeHackRoot(void);
		wxTreeItemId treeHackRoot(wxTreeItemId i);
		wxTreeItemId treeHackAdd(wxTreeItemId r, wxString l, int where);
		wxTreeItemId treeHackAdd(wxTreeItemId r, wxString l, int where, wxTreeItemData* d);
		wxTreeItemId treeHackAdd(wxTreeItemId r, wxString l, int where, wxTreeItemId i, wxTreeItemData* d);
		wxTreeItemId treeHackAdd(wxTreeItemId r, wxString l, int where, wxTreeItemId i);
		wxTreeItemId treeHackFind(wxTreeItemId r, wxString l);
		void treeHackDel(void);
		void treeHackMove(int direction);
		void HEXFORMIDLE(wxIdleEvent& event);
		void bAppListOnClick(wxCommandEvent& event);
		void bAppUseOnClick(wxCommandEvent& event);
		void mWaitOnChange(wxCommandEvent& event);
		void bAddHackOnClick(wxCommandEvent& event);
		void bDelHackOnClick(wxCommandEvent& event);
		void treeHackOnKeyDown(wxKeyEvent& event);
		void setWait(int i);
		int getAppLen(void);
		DWORD AI;
		wxString AE;
		void setApps(void);
        void addApp(int row, wxString id, wxString app, wxString title);
		int pLen, gLen;
		wxLongLong appWait, appWaitU;
		int appWaitB, appLen;
        wxString* groups;
        int* group;
        wxString* preset;
};
#endif
