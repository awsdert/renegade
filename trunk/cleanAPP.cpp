#include "cleanAPP.h"
#if WIN32
PROCESSENTRY32 GetAppMSW( DWORD appID )
{
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do {
		if ( pe32.th32ProcessID == appID )
		{
			break;
		}
	} while ( Process32Next( shot, &pe32 ) );
	return pe32;
}
#endif
void GetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize )
{
#ifdef WIN32
	ReadProcessMemory( fHandle, ( void* )fAddress, fBuffer, fSize, NULL );
#endif
}
void SetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize )
{
#ifdef WIN32
	WriteProcessMemory( fHandle, ( void* )fAddress, fBuffer, fSize, NULL );
#endif
}
uHandle GetAppHandle( const xStr appExe )
{
	uHandle ah = 0u;
#ifdef WIN32
	xStr exe;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( pe32 );
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do {
		exe.Printf( wxT( "%s" ), pe32.szExeFile );
		if ( exe.CmpNoCase( appExe ) == 0 ) {
			ah = OpenProcess( PROCESS_ALL_ACCESS,
								FALSE, pe32.th32ProcessID );
			break;
		}
	} while ( Process32Next( shot, &pe32 ) );
#endif
	return ah;
}
xStr GetAppExe( DWORD appID )
{
	xStr text;
#if WIN32
	PROCESSENTRY32 pe32 = GetAppMSW( appID );
	text.Printf( wxT( "%s" ), pe32.szExeFile );
#endif
	return text;
}
bool GetAppSize( uHandle ah, u64 &size )
{
	bool worked = false;
	size = 0u;
#ifdef WIN32
	PROCESS_MEMORY_COUNTERS* pmc = new PROCESS_MEMORY_COUNTERS;
	if ( GetProcessMemoryInfo( ah, pmc, ( DWORD )sizeof( PROCESS_MEMORY_COUNTERS ) ) )
	{
		size = pmc->PagefileUsage;
		worked = true;
	}
#endif
	return worked;
}
