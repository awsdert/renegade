#include "hexDB_app.h"
#ifdef xsMSW
PROCESSENTRY32 xsDLL mswGetPE32( DWORD appID )
{
	PROCESSENTRY32 pe32, temp;
	bool got = false;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	temp.dwSize = 0;
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do got = ( pe32.th32ProcessID == appID );
	while ( !got && Process32Next( shot, &pe32 ) );
	return got ? pe32 : temp;
}
#endif
Text xsDLL GetAppExe( DWORD appID )
{
	Text txt;
#ifdef xsMSW
	PROCESSENTRY32 pe32 = mswGetPE32( appID );
	if ( pe32.dwSize > 0 )
		txt.Printf( wxT( "%s" ), pe32.szExeFile );
#endif
	return txt;
}
