/***************************************************************
 * Name:      hexApp.cpp
 * Purpose:   Code for Application Class
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "hexApp.h"
#include "hexMain.h"
#include "hexM.h"
IMPLEMENT_APP(hexApp);
hexWin* frame;
bool hexApp::OnInit()
{
	frame = new hexWin(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    return true;
}
#ifdef WIN32
PROCESSENTRY32 getApp(DWORD appID) {
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	HANDLE ah = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(NULL, &pe32);
	do {
		if (pe32.th32ProcessID == appID) { break; }
	} while (Process32Next(ah, &pe32));
	CloseHandle(ah);
	return pe32;
}
wxString getAppExe(DWORD appID) {
	PROCESSENTRY32 pe32;
	wxString s;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	pe32 = getApp(appID);
	s.Printf(wxT("%s"), pe32.szExeFile);
	return s;
}
/*DWORD getAppId(const wxString appName) {
	PROCESSENTRY32 appInfo;
	appInfo.dwSize = sizeof(appInfo);
	wxString exe;
	Process32First(NULL, &appInfo);
	exe.Printf(wxT("%s"), appInfo.szExeFile);
	if (!exe.CmpNoCase(appName)) {
		return appInfo.th32ProcessID;
	}

	while ( Process32Next(NULL, &appInfo) )
	{
		if ( !appName.compare(appInfo.szExeFile) )
		{
			return appInfo.th32ProcessID;
		}
	}

//	CloseHandle(appShot);///
	return 0;
}//*/
BOOL CALLBACK appList3(HWND hwnd, LPARAM AL) {
	if (IsWindowVisible(hwnd)) {
		/*TCHAR t[MAXCHAR]; DWORD pid;
		GetWindowThreadProcessId(hwnd, &pid);
		s1.Printf(wxT("%i"), pid);
		s2 = getAppExe(pid);
		// This is in case have a problem with MAXBYTE as value
		// sizeof(t)/sizeof(TCHAR)
		SendMessage(hwnd, WM_GETTEXT, MAXBYTE, (LPARAM)(void*)t);
		s3.Printf(wxT("%s"), t);
		frame->addApp(a, s1, s2, s3);*/
		int a = frame->appLen++;
		wxString s1, s2, s3;
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
