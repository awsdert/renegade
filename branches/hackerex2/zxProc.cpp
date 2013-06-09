#include "zxProc.h"
bool zxProc::zxGetProc( zxText name ) /* DO NOT USE EXT */
{
	if ( zxGetPE32( name ) )
	{
		m_name = name;
#ifdef zxMSW
		m_pid = m_pe32.th32ProcessID;
		return true;
#endif
	}
	m_name.clear();
	m_pid = NULL;
	return false;
}
bool zxProc::zxGetProc( zxPID pid )
{
	zxText name;
	if ( zxGetPE32( pid ) )
	{
		m_pid = pid;
#ifdef zxMSW
		name = m_pe32.szExeFile;
		name = name.substr( 0, name.length() - 4 );
		m_name = name;
		return true;
#endif
	}
	pid = NULL;
	m_name.clear();
	return false;
}
/* Get Process Entry Data */
bool zxProc::zxGetPE32( void )
{
	if ( m_pid != NULL )
		return zxGetPE32( m_pid );
	else if ( m_name.empty() )
		return false;
	else
		return zxGetPE32( m_name );
}
bool zxProc::zxGetPE32( zxPID pid )
{
	bool got = false;
	zxPE32 pe32, temp;
#ifdef zxMSW
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	temp.dwSize = 0;
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do got = ( pe32.th32ProcessID == pid );
	while ( !got && Process32Next( shot, &pe32 ) );
#endif
	m_pe32 = got ? pe32 : temp;
	return got;
}
bool zxProc::zxGetPE32( zxText name ) /* DO NOT USE EXT */
{
	zxText tmp;
	if ( name.empty() )
		return false;
	bool got = false;
	zxPE32 pe32, temp;
#ifdef zxMSW
	name += zxProcExt;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	temp.dwSize = 0;
	HANDLE shot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( shot, &pe32 );
	do
	{
		tmp = pe32.szExeFile;
		got = ( tmp == name );
	}
	while ( !got && Process32Next( shot, &pe32 ) );
#endif
	m_pe32 = got ? pe32 : temp;
	return got;
}
/* Get Handle */
bool zxProc::zxNewHandle( zxText name ) /* DO NOT USE EXT */
{
	if ( !zxDelHandle() )
		return false;
	if ( zxGetPE32( name ) )
	{
#ifdef zxMSW
		m_pid = m_pe32.th32ProcessID;
		m_ph = OpenProcess(
				PROCESS_SUSPEND_RESUME | PROCESS_VM_OPERATION |
				PROCESS_VM_READ | PROCESS_VM_WRITE,
				FALSE, m_pid );
		if ( m_ph != NULL )
			return true;
#endif
	}
	return false;
}
bool zxProc::zxDelHandle( void )
{
	if ( m_ph == NULL )
		return true;
#ifdef zxMSW
	if ( CloseHandle( m_ph ) )
		return true;
#endif
	return false;
}
/* Ram Handling */
size_t zxProc::zxGetMemory( ui64 address, void* des, size_t size )
{
	if ( m_ph == NULL )
		return 0;
	size_t bytes = 0;
#ifdef zxMSW
	DWORD BYTES = 0;
	ReadProcessMemory( m_ph, (void*)address, des, size, &BYTES );
	bytes = BYTES;
#endif
	return bytes;
}
size_t zxProc::zxSetMemory( ui64 address, void* src, size_t size )
{
	if ( m_ph == NULL )
		return 0;
	size_t bytes = 0;
#ifdef zxMSW
	DWORD BYTES = 0;
	WriteProcessMemory( m_ph, (void*)address, src, size, &BYTES );
	bytes = BYTES;
#endif
	return bytes;
}