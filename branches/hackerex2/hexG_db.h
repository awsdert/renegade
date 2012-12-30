#include "hexDB_main.h"
#ifndef HACKEREX_GLOBAL_DB
#define HACKEREX_GLOBAL_DB

#include "hex2_db.h"
#ifdef xsMSW
BOOL CALLBACK mswEnumWin( HWND hWin, LPARAM bShowAll );
#endif // xsMSW

class xsDLL hexDB
{
	Text	getDir( void );
	Text	getPath( ui32 c );
	void	setCode( Code& obj, ui08* data );
	void	setCodes( void );
	void	getCode( Code& obj, ui08* data );
	void	saveCodesIntern( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p );
public:
	hexDB();
	void	loadCodes( void );
	void	saveCodes( bool addObj = false );
	void	getCodes( ui32 c );
	int		mode[ HEX_LIST_COUNT ];
	LBox*	appsLB;
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
