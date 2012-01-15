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
#include <wx/app.h>
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
PROCESSENTRY32 getApp(DWORD id);
wxString getAppExe(DWORD appID);
BOOL CALLBACK appList3(HWND hwnd, LPARAM AL);
#endif
class hexApp : public wxApp
{
    public:
        virtual bool OnInit();
};
#endif // REXAPP_H
