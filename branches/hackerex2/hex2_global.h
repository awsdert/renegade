#ifndef HEXGUI_GLOBAL_H
#define HEXGUI_GLOBAL_H

// Global Includes
#include "hexDLL_global.hpp"
#include "wx_pch.h"

// Global defines
#define wxOK_CANCEL wxOK | wxCANCEL

// Types

typedef wxString			Text;
typedef wxStringTokenizer	TxtT;
typedef wxArrayString		TxtA;
typedef wxTextFile			TxtF;
typedef wxFile				BinF;
typedef wxFileConfig		CfgF;
typedef wxTreeCtrl			TrCO;
typedef wxTreeItemId		TrId;
typedef wxTreeItemIdValue	TrIV;
typedef wxListBox			LBox;

// Common Characters

const wxChar c0		= wxT('0');
const wxChar c9		= wxT('9');
const wxChar cA		= wxT('A'); // Base 16 and 36 usage
const wxChar cE		= wxT('E'); // For Exponent capturing
const wxChar cF		= wxT('F'); // Base 16 End
const wxChar cZ		= wxT('Z'); // Base 36 End
const wxChar cDot	= wxT('.'); // For FPN capturing
const wxChar cNeg	= wxT('-');
const wxChar cPos	= wxT('+');
const wxChar cQuot	= wxT('"');
const wxChar cEqual	= wxT('=');
const wxChar cSemC	= wxT(';');
const wxChar cBrS	= wxT('[');
const wxChar cFS	= wxT('/');
const wxChar cBS	= wxT('\\');
const wxChar cTild	= wxT('~');
const Text xsDirSep = ( wxGetOSDirectory().Contains( cBS ) ) ? cBS : cFS;
const Text xsDirUp  = xsDirSep + wxT("..");

#endif

