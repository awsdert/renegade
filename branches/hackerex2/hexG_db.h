#include "hex2_global.h"
#include "hex2_db.h"
#include "hexDB_hack.h"
#include "hexDB_app.h"
#ifndef HACKEREX_GLOBAL_DB
#define HACKEREX_GLOBAL_DB

class xsDLL hexRow	: public Vect< wxTextCtrl* > {};
class xsDLL hexGrid	: public Vect< hexRow > {};
class xsDLL hexDB
{
	Text	m_getDir( void );
	Text	m_getPath( ui32 c );
	void	m_setCode( Code& obj, ui08* data );
	void	m_getCodes( Codes& obj, ui32 h, bool insideCall );
	void	m_setCodes( void );
	bool	m_hooked;
	size_t	m_addrSize;
	ui08	m_moveAddr;
	ui64	m_ram[ 0xF ];
	void	m_getCode( Code& obj, ui08* data );
	void	m_useCodes( Codes& data, osHdl& hApp, ui32& h, ui32& hEnd, ui16 c, ui16 cEnd, bool doHacks );
	void	m_saveCodes( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p );
public:
	hexDB();
	hexGrid	grid;
	wxGauge* pb;
	bool	killThreads;
	void	useCodes( void );
	static Text	getDefN( int inMode = -1, bool forRoot = true );
	void	loadCodes( void );
	void	saveCodes( bool addObj = false );
	void	getCodes( ui32 hackIndex );
	int		mode[ HEX_LIST_COUNT ];
	LBox*	appsLB;
	TrCO*	hacksTree;
	TrCO*	codesTree;
	State	state;
	Org		org;
	Pfm		pfm;
	Bin		bin;
	CfgF*	ini;
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
