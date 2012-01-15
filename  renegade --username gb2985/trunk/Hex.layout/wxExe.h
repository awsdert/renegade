#ifndef WXEXE_H
#define WXEXE_H
#include <wx/string.h>
#ifdef WIN32
#include <windows.h>
#include <tlhelp32.h>
#endif
class wxExe {
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
