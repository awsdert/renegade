#ifndef WXAPP_H
#define WXAPP_H
#include <wx/string.h>
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif
class xApp {
    public:
        bool last;
        DWORD id;
        wxString exe;
        wxString name;
        wxString user;
#ifdef WIN32
        HWND hwnd;
#endif
};
#endif
