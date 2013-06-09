#include "wx_pch.h"
#include "zxs.h"

#ifndef hexObjs_org_h
#define hexObjs_org_h

#ifdef hexObjs_BUILD
#define hexObjs zxDLL_EXP
#else
#define hexObjs zxDLL_IMP
#endif

const wxChar cDot	= wxT('.'); // For FPN capturing
const wxChar cNeg	= wxT('-');
const wxChar cPos	= wxT('+');
const wxChar cQuot	= wxT('"');
const wxChar cEqual	= wxT('=');
const wxChar cSemCn	= wxT(';');
const wxChar cBrS	= wxT('[');
const wxChar cBrE	= wxT(']');
const wxChar cFS	= wxT('/');
const wxChar cBS	= wxT('\\');
const wxChar cTild	= wxT('~');
const Text xsDirSep = ( wxGetOSDirectory().Contains( cBS ) ) ? cBS : cFS;
const Text xsDirUp  = xsDirSep + wxT("..");

hexObjs Text getGlobalName( void );
struct hexObjs dName
{
	dName( void );
	Text name;
};
struct hexObjs dFile : dName
{
	dFile( void );
	Text file;
};

struct hexObjs State : dName
{
	State();
	void clear();
	Text orgName;
	Text pfmName;
	Text binName;
	Text pflName;
	Text fmtName;
};

struct hexObjs Org : public dFile
{
	Org( void );
	bool operator!= ( Org &obj );
	bool operator== ( Org &obj );
};

struct hexObjs Pfm : public dFile
{
	Pfm( void );
	ui08 endian;
	bool operator!= ( Pfm &obj );
	bool operator== ( Pfm &obj );
};

struct hexObjs Ram : dName
{
	Ram( void );
	void clear( void );
	ui64 addr, bytes;
	ui08 depth;
	bool operator!= ( Ram &obj );
	bool operator== ( Ram &obj );
};

struct hexObjs Bin : dFile, zxArray< Ram, 0x10 >
{
	Bin( void );
	Text bind, path;
	ui08 type, ramNo;
	ui16 done;
	bool operator!= ( Bin& obj );
	bool operator== ( Bin& obj );
};

struct hexObjs Pfl : dFile
{
	Pfl( void );
	ui32 region;
	ui16 profile;
	Text serial, notes;
	bool operator!= ( Pfl& obj );
	bool operator== ( Pfl& obj );
};

struct Fmt;
struct Code;
struct Hack;
struct Codes;
struct Hacks;

class hexObjs TrID : public wxTreeItemData
{
public:
	TrID( int i );
	int index;
};
#endif