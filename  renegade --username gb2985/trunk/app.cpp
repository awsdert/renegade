
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
HANDLE getAppId(const xStr appName) {
	PROCESSENTRY32 ai; xStr exe;
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
xStr getAppExe(DWORD appID) {
	PROCESSENTRY32 pe32;
	xStr s;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	pe32 = getApp(appID);
	s.Printf(wxT("%s"), pe32.szExeFile);
	return s;
}
u64 getAppSize( HANDLE appHandle )
{
	PROCESS_MEMORY_COUNTERS* appRAM = new PROCESS_MEMORY_COUNTERS;
	GetProcessMemoryInfo( appHandle, appRAM, (DWORD)sizeof( appRAM ) );
	u64 r = (u64)appRAM->WorkingSetSize;
	delete appRAM;
	return r;
}
#endif
