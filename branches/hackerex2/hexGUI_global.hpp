#ifndef HEXGUI_GLOBAL_H
#define HEXGUI_GLOBAL_H

// Global Includes
#include "hexDLL_global.hpp"
#include "wx_pch.h"

// Types

typedef wxString			Text;
typedef wxStringTokenizer	TxtT;
typedef wxArrayString		TxtA;
typedef wxTextFile			TxtF;
typedef wxFileConfig		CfgF;
typedef wxTreeItemId		TrId;
typedef wxTreeItemIdValue	TrIV;

// Common Characters

const wxChar c0	= wxT('0');
const wxChar c9	= wxT('9');
const wxChar cA	= wxT('A'); // Numbers of base 16 and 36
const wxChar cE	= wxT('E'); // Exponent starter
const wxChar cF	= wxT('F'); // Base 16
const wxChar cZ	= wxT('Z'); // Base 36
const wxChar cDot	= wxT('.'); // For floating point numbers
const wxChar cNeg	= wxT('-'); // Also minus character
const wxChar cQuot	= wxT('"');
const wxChar cSemC	= wxT(';');
const Text xsDirSep = ( wxGetOSDirectory().Contains( wxT("\\") ) ) ? wxT("\\") : wxT("/");

#endif

