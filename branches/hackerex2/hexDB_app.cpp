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
xsDLL bool NewAppHandle( osHdl& hApp, Text exe )
{
	Text tmp;
	hApp = NULL;
#ifdef xsMSW
	PROCESSENTRY32 pe32;
	bool got = false;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do
	{
		tmp.Printf( wxT("%s"), pe32.szExeFile );
		got = ( tmp == exe );
		if ( got )
		{
			hApp = OpenProcess(
				PROCESS_SUSPEND_RESUME | PROCESS_VM_OPERATION |
				PROCESS_VM_READ | PROCESS_VM_WRITE,
				TRUE, pe32.th32ProcessID );
			return true;
		}
	}
	while ( !got && Process32Next( shot, &pe32 ) );
#endif
	return false;
}
xsDLL void DelAppHandle( osHdl& hApp )
{
#ifdef xsMSW
	CloseHandle( hApp );
#endif
	hApp = NULL;
}
xsDLL size_t GetAppRam( osHdl& hApp, void* address, void* value, size_t bytes )
{
	size_t rbytes = 0;
#ifdef xsMSW
	ReadProcessMemory( hApp, address, value, bytes, (SIZE_T*)(&rbytes) );
#endif
	return rbytes;
}
xsDLL size_t SetAppRam( osHdl& hApp, void* address, void* value, size_t bytes )
{
	size_t wbytes = 0;
#ifdef xsMSW
	WriteProcessMemory( hApp, address, value, bytes, (SIZE_T*)(&wbytes) );
#endif
	return wbytes;
}