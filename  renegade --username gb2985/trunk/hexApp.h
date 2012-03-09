/***************************************************************
 * Name:      hexApp.h
 * Purpose:   Defines Application Class
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifndef HEXAPP_H
#define HEXAPP_H
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif
#include <wx/tokenzr.h>
#include <wx/app.h>
#include <wx/treectrl.h>
typedef wxInt8 s8;
typedef wxInt16 s16;
typedef wxInt32 s32;
typedef wxInt64 s64;
typedef wxUint8 u8;
typedef wxUint16 u16;
typedef wxUint32 u32;
typedef wxUint64 u64;
typedef wxFloat32 f32;
typedef wxFloat64 f64;
typedef wxString xStr;
typedef wxStringTokenizer xStrT;
typedef wxArrayInt xAInt;
typedef wxArrayString xAStr;
typedef wxTreeItemId xTID;
typedef wxTreeItemIdValue xTIDV;
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
PROCESSENTRY32 getApp( DWORD appID );
BOOL CALLBACK listApps( HWND hwnd, LPARAM AL );
HANDLE getAppId( const xStr appName );
u64 getAppSize( HANDLE appHandle );
#endif
enum ESIZE { SE = 0, LE, LSE };
void MB(xStr text = wxT(""), xStr title = wxT(""));
xStr getAppExe(DWORD appID);
class hexApp : public wxApp
{
    public:
        virtual bool OnInit();
};
#endif // REXAPP_H
