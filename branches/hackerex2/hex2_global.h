#include "wx_pch.h"
#include "hexDLL_global.hpp"

#ifndef HEXGUI_GLOBAL_H
#define HEXGUI_GLOBAL_H

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

