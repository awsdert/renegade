#include "hex2_global.h"
#include "hex2_db.h"
#include "hexDB_hack.h"
#ifndef HACKEREX_GLOBAL_DB
#define HACKEREX_GLOBAL_DB

class xsDLL hexRow	: public Vect< wxTextCtrl* > {};
class xsDLL hexGrid	: public Vect< hexRow > {};
class xsDLL hexDB
{
	Text	getDir( void );
	Text	getPath( ui32 c );
	static void	setCode( Code& obj, ui08* data );
	void	setCodes( void );
	static void	getCode( Code& obj, ui08* data );
	void	m_saveCodes( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p );
public:
	hexDB();
	hexGrid	grid;
	static Text	getDefN( int inMode = -1, bool forRoot = true );
	void	loadCodes( bool getCodeData = true );
	void	saveCodes( bool addObj = false );
	void	getCodes( ui32 c, bool internBool = false );
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
	bool	showHacks;
	bool	showAllApps;
	LBox*	tmpLB;
	bool	tmpCfg;
	int		tmpMode;
};

#endif // HACKEREX_GLOBAL_DB
