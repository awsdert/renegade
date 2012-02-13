/***************************************************************
 * Name:      hexApp.cpp
 * Purpose:   Code for Application Class
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/


#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "hexApp.h"
#include "hexMain.h"
IMPLEMENT_APP(hexApp);
ME* frame;
void MB(xStr text, xStr title) { wxMessageBox(text, title); }
bool hexApp::OnInit() {
	frame = new ME(0L);
    frame->SetIcon(wxICON(NULL)); // To Set App Icon
    frame->Show();
    //frame->Maximize();
    return true;
}
#ifdef WIN32
BOOL CALLBACK listApps(HWND hwnd, LPARAM AL) {
	if (IsWindowVisible(hwnd)) {
		int a = frame->appLen++;
		xStr s1, s2, s3;
		TCHAR t[MAXCHAR];
		DWORD pid;
		GetWindowThreadProcessId(hwnd, &pid);
		s1.Printf(wxT("%x"), pid);
		s2 = getAppExe(pid); a++;
		// This is in case have a problem with MAXBYTE as value
		// sizeof(t)/sizeof(TCHAR)
		SendMessage(hwnd, WM_GETTEXT, MAXBYTE, (LPARAM)(void*)t);
		s3.Printf(wxT("%s"), t);
		frame->addApp(a, s1, s2, s3);
	} return TRUE;
}
#endif
