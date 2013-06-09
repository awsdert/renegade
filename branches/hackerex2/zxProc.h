#include "zxText.h"

#ifdef zxMSW
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#endif

#ifndef zxProc_h
#define zxProc_h

#ifdef zxMSW

typedef HANDLE
	zxPHandle;
typedef PROCESSENTRY32
	zxPE32;
typedef DWORD
	zxPID;
const zxText zxProcExt = zxT(".exe");

#else

typedef void*
	zxOSHandle;
typedef ui32
	zxPID;
struct zxPE32_MISC
{
	zxText path;
};
typedef zxPE32_MISC
	zxPE32;
const zxText zxProcExt;

#endif

const int zxProcExtLen = zxText(zxProcExt).length();

struct zxDLL zxProc
{
	zxText m_name;
	zxPHandle m_ph;
	zxPID	m_pid;
	zxPE32	m_pe32;
	// Handles m_pid / m_name ( uses zxGetPE32 )
	bool zxGetProc( zxText name );
	bool zxGetProc( zxPID id );
	// Handles m_pe32
	bool zxGetPE32( void );
	bool zxGetPE32( zxText name );
	bool zxGetPE32( zxPID pid );
	// Handles m_ph
	bool zxNewHandle( void );
	bool zxNewHandle( zxPID pid );
	bool zxNewHandle( zxText name );
	bool zxDelHandle( void );
	// Above should be used first
	size_t zxGetMemory( ui64 address, void* des, size_t size );
	size_t zxSetMemory( ui64 address, void* src, size_t size );
};

#endif