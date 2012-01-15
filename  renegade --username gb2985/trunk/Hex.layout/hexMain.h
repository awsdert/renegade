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
#include "wxExe.h"
class hexWin: public HEXFRM {
    public:
        hexWin(wxFrame *frame);
        ~hexWin();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
	public:
		void HEXFORMIDLE(wxIdleEvent& event);
		void bAppListOnClick(wxCommandEvent& event);
		void bAppUseOnClick(wxCommandEvent& event);
		void mWaitOnChange(wxCommandEvent& event);
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
