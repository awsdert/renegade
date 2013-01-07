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
