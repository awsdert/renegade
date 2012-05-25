#ifndef CLEANAPP_H_
#define CLEANAPP_H_
#include "cleanType.h"
#ifdef WIN32
typedef HANDLE uHandle;
PROCESSENTRY32 GetAppMSW( DWORD appID );
BOOL CALLBACK EnumWindowsMSW( HWND, LPARAM );
#else
typedef u32    uHandle;
#endif
void GetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize );
void SetRamX( uHandle fHandle, u64 fAddress, void* fBuffer, u32 fSize );
xStr    GetAppExe(    DWORD appID );
uHandle GetAppHandle( const xStr    appExe );
bool    GetAppSize(   const uHandle ah, u64 &size );
#endif
