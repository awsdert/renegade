
#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexApp.h"
#if WIN32
PROCESSENTRY32 getApp(DWORD appID) {
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	HANDLE ah = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(ah, &pe32);
	do {
		if (pe32.th32ProcessID == appID) { break; }
	} while (Process32Next(ah, &pe32));
	return pe32;
}
HANDLE getAppId(const wxString appName) {
	PROCESSENTRY32 ai; wxString exe;
	ai.dwSize = sizeof(ai);
	HANDLE ah = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	Process32First(ah, &ai);
	do {
		exe.Printf(wxT("%s"), ai.szExeFile);
		if ( exe.CmpNoCase(appName) == 0 ) {
			return OpenProcess(PROCESS_ALL_ACCESS, FALSE, ai.th32ProcessID);
		}
	} while ( Process32Next(ah, &ai) );
	return NULL;
}
wxString getAppExe(DWORD appID) {
	PROCESSENTRY32 pe32;
	wxString s;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	pe32 = getApp(appID);
	s.Printf(wxT("%s"), pe32.szExeFile);
	return s;
}
#endif