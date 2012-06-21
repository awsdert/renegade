#include "cleanAPP.h"
void GetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize )
{
#ifdef __WXMSW__
	ReadProcessMemory( fHandle, ( void* )fAddress, fBuffer, fSize, NULL );
#endif
}
void SetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize )
{
#ifdef __WXMSW__
	WriteProcessMemory( fHandle, ( void* )fAddress, fBuffer, fSize, NULL );
#endif
}
#ifdef __WXMSW__
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
bool LaunchExe( xStr path )
{
	xStr text = wxT( '"' ) + path + wxT( '"' );
#ifdef __WXMSW__
	return ( WinExec( text.mb_str().data(), SW_HIDE ) );
#else
	return false;
#endif
}
uHandle GetAppHandle( const xStr appExe )
{
	uHandle ah = NULL;
#ifdef __WXMSW__
	xStr exe;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do {
		exe.Printf( wxT( "%s" ), pe32.szExeFile );
		if ( exe.CmpNoCase( appExe ) == 0 )
		{
			ah = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );
			break;
		}
	} while ( Process32Next( shot, &pe32 ) );
#endif
	return ah;
}
void  DelAppHandle( uHandle &fHandle )
{
#ifdef __WXMSW__
	CloseHandle( fHandle );
#else
	fHandle = NULL;
#endif
}
xStr GetAppExe( DWORD appID )
{
	xStr text;
#ifdef __WXMSW__
	PROCESSENTRY32 pe32 = GetAppMSW( appID );
	text.Printf( wxT( "%s" ), pe32.szExeFile );
#endif
	return text;
}
bool GetAppSize( uHandle ah, u64 &size )
{
	bool worked = false;
	size = 0u;
#ifdef __WXMSW__
	PROCESS_MEMORY_COUNTERS* pmc = new PROCESS_MEMORY_COUNTERS;
	if ( GetProcessMemoryInfo( ah, pmc, ( DWORD )sizeof( PROCESS_MEMORY_COUNTERS ) ) )
	{
		size = pmc->PagefileUsage;
		worked = true;
	}
#endif
	return worked;
}
