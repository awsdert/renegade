#include "wx_pch.h"
#include "hexDB_app.h"
#ifdef xsMSW
xsDLL PROCESSENTRY32 mswGetPE32( DWORD pid )
{
	PROCESSENTRY32 pe32, temp;
	bool got = false;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	temp.dwSize = 0;
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do got = ( pe32.th32ProcessID == pid );
	while ( !got && Process32Next( shot, &pe32 ) );
	return got ? pe32 : temp;
}
#endif
xsDLL Text GetAppExe( DWORD pid )
{
	Text txt;
#ifdef xsMSW
	PROCESSENTRY32 pe32 = mswGetPE32( pid );
	if ( pe32.dwSize > 0 )
		txt.Printf( wxT( "%s" ), pe32.szExeFile );
#endif
	return txt;
}
xsDLL osHdl NewAppHandle( Text exe )
{
	Text tmp;
	if ( exe.IsNull() )
		return NULL;
	exe.LowerCase();
#ifdef xsMSW
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do
	{
		tmp.Printf( wxT("%s"), pe32.szExeFile );
		if ( tmp.CmpNoCase( exe ) == 0 )
		{
			return OpenProcess(
				PROCESS_SUSPEND_RESUME | PROCESS_VM_OPERATION |
				PROCESS_VM_READ | PROCESS_VM_WRITE,
				FALSE, pe32.th32ProcessID );
		}
	}
	while ( Process32Next( shot, &pe32 ) );
#endif
	return NULL;
}
xsDLL void DelAppHandle( osHdl hApp )
{
#ifdef xsMSW
	CloseHandle( hApp );
#endif
	hApp = NULL;
}
xsDLL bool IsAppAlive( osHdl hApp )
{
#ifdef xsMSW
	DWORD ec;
	if ( GetExitCodeProcess( hApp, &ec ) )
		return ( ec == STILL_ACTIVE );
	else
		return false;
#else
	return false;
#endif
}
xsDLL ui32 GetAppRam( osHdl hApp, ui64 address, void* value, ui32 bytes )
{
	size_t rbytes = 0;
#ifdef xsMSW
	DWORD RBYTES = 0;
	ReadProcessMemory( hApp, (void*)address, value, bytes, &RBYTES );
	rbytes = RBYTES;
#endif
	return rbytes;
}
xsDLL ui32 SetAppRam( osHdl hApp, ui64 address, void* value, ui32 bytes )
{
	size_t wbytes = 0;
#ifdef xsMSW
	DWORD WBYTES = 0;
	WriteProcessMemory( hApp, (void*)address, value, bytes, &WBYTES );
	wbytes = WBYTES;
#endif
	return wbytes;
}