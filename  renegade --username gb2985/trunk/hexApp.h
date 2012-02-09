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
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef wxString xStr;
typedef wxStringTokenizer xStrT;
typedef wxTreeItemId xTID;
typedef wxTreeItemIdValue xTIDV;
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
PROCESSENTRY32 getApp(DWORD appID);
BOOL CALLBACK appList3(HWND hwnd, LPARAM AL);
HANDLE getAppId(const xStr appName);
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
