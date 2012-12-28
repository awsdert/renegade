#include "hexDB_main.h"
#ifndef HACKEREX_GLOBAL_DB
#define HACKEREX_GLOBAL_DB

#include "hex2_db.h"
#ifdef xsMSW
BOOL CALLBACK mswEnumWin( HWND hWin, LPARAM bShowAll );
#endif // xsMSW

class xsDLL hexDB
{
public:
	hexDB();
	int		mode[ HEX_LIST_COUNT ];
	LBox*	appsLB;
	LBox*	codesLB;
	TrCO*	hacksTree;
	TrCO*	codesTree;
	State	state;
	Org		org;
	Pfm		pfm;
	Bin		bin;
	si08	ramNo;
	si16	codeNo;
	Pfl		pfl;
	Format	format;
	Hacks	hacks;
	Codes	codes;
	Text	getNowN( int inMode );
	Text	getFormat( int fNo );
	TxtA	nowP;
	TxtA	oldP;
	bool	nowM[ HEX_LIST_COUNT ];
	LBox*	tmpLB;
	bool	tmpCfg;
	int		tmpMode;
	bool	tmpRelist;
};

#endif // HACKEREX_GLOBAL_DB
