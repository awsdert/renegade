#include "hex2_global.h"
#include "hex2_db.h"
#include "hexDB_hack.h"
#include "hexDB_app.h"
#include "hexDB_hexLib.h"
#ifndef HEXG_DB_H
#define HEXG_DB_H
class hexGui;
class hexDB;
/* *
class xsDLL M_EGRID : public wxEvtHandler
{
private:
	void m_connect( void );
	void m_disconnect( void );
	void sync_m_connect( void );
	void sync_m_disconnect( void );
	void sync_onshow(	wxShowEvent&	event );
	void jump_onclick(	wxCommandEvent&	event );
	void get_onclick(	wxCommandEvent&	event );
	void set_onclick(	wxCommandEvent&	event );
	void grid_onmwheel( wxMouseEvent&	event );
	void misc_onmwheel( wxMouseEvent&	event );
	void hook_onchoice( wxCommandEvent&	event );
	void onscrollb(	wxScrollWinEvent&	event ); // Towards Beginning
	void onscrolle(	wxScrollWinEvent&	event ); // Towards End
public:
	M_EGRID( void );
	wxGrid
		*grid_g;
	wxButton	
		*jump_b, *get_b, *set_b;
	wxChoice	
		*hook_dd;
	wxSpinButton
		*size_sb;
	wxTextCtrl
		*a_txt, *v_txt;
	wxRadioBox
		*sync_rl;
	ui64 nAddr;
	ui08 rows;
	hexDB* db;
	hexGui* gui;
	int	 iXVH, iYVH, iYVP, wait, vType;
	bool isUpLast, isActive, isAuto, isShown;
	bool jump( void );
	void jump2( ui64 addr );
	void scroll( int dir, bool isGridSrc = false, bool isWheelSrc = true );
	void update( ui08* data, size_t bytes );
	void sync_connect( void );
	void sync_disconnect( void );
};
#define HEX_VS008 0x1
#define HEX_VS016 0x2
#define HEX_VS024 0x4
#define HEX_VS032 0x8
#define HEX_VS040 0x10
#define HEX_VS048 0x20
#define HEX_VS056 0x40
#define HEX_VS064 0x80
#define HEX_VS072 0x100
#define HEX_VS080 0x200
#define HEX_VS088 0x400
#define HEX_VS096 0x800
#define HEX_VS104 0x1000
#define HEX_VS112 0x2000
#define HEX_VS120 0x4000
#define HEX_VS128 0x8000

class xsDLL M_OGRID : public wxEvtHandler
{
private:
	void find_onclick(	wxCommandEvent& event );
	void undo_onclick(	wxCommandEvent& event );
	void qType_onclick(	wxCommandEvent& event );
	void valS_onshow(	wxShowEvent&	event );
	void valS_oncheck(	wxCommandEvent& event );
	bool find_m_check( void );
	wxString
		m_atxt[ HEX_ACOUNT ], m_vtxt[ HEX_QCOUNT ];
	wxCheckBox
		*am__cb[ HEX_ACOUNT ], *aa__cb[ HEX_ACOUNT ], *an__cb[ HEX_ACOUNT ],
		*vm__cb[ HEX_QCOUNT ], *va__cb[ HEX_QCOUNT ], *vn__cb[ HEX_QCOUNT ];
	wxTextCtrl // m = Must, a = Any, n = None
		*am_txt[ HEX_ACOUNT ], *aa_txt[ HEX_ACOUNT ], *an_txt[ HEX_ACOUNT ],
		*vm_txt[ HEX_QCOUNT ], *va_txt[ HEX_QCOUNT ], *vn_txt[ HEX_QCOUNT ];
public:
	M_OGRID();
	wxGrid	*grid_g;
	hexDB	*db;
	hexGui	*gui;
	bool m_MeqA, m_MeqN, m_madeMAN;
	wxButton
		*find_b, *new__b, *dump_b, *undo_b, *q_b[ HEX_QCOUNT ];
	wxChoice
		*qCmpA_dd, *qType_dd, *vType_dd;
	wxCheckListBox
		*valS_clb;
	wxPanel
		*must_p, *any__p, *none_p;
	wxFlexGridSizer
		*am_lfg, *aa_lfg, *an_lfg, *vm_lfg, *va_lfg, *vn_lfg;
	ui64
		am[ HEX_ACOUNT ], aa[ HEX_ACOUNT ], an[ HEX_ACOUNT ];
	ui08 
		vm[ HEX_QCOUNT ][ 16 ], va[ HEX_QCOUNT ][ 16 ], vn[ HEX_QCOUNT ][ 16 ];
	si16 valb[ 16 ], qNo;
	int qType, vType, vSize;
	ui32 vsUse;
	bool isM, isA, isN, qvSize[ 16 ], vmb[ HEX_QCOUNT ], vab[ HEX_QCOUNT ], vnb[ HEX_QCOUNT ];
	void find( void );
	void find_fillcmp( void );
	void find_connect( void );
	void find_disconnect( void );
	void out( ui64 addr, ui08 rows );
};
class xsDLL M_HTREE : public wxEvtHandler
{
public:
	wxTreeCtrl
		*htree, *ctree;
	wxTextCtrl
		*addr_txt, *val__txt;
	hexDB* db;
	hexGui* gui;
	bool isAuto;
	int wait;
	Hack hack;
	Code code;
};
/*
class xsDLL hexDB : public wxEvtHandler
{
	hexGui* m_gui;
	Text	m_getDir( void );
	Text	m_getPath( ui32 c );
	void	m_setCode( Code& obj, ui08* data );
	void	m_setCodes( void );
	bool	m_hooked;
	size_t	m_addrSize;
	const size_t m_codeBytes;
	ui08	m_moveAddr;
	// Hacks / Codes
	int     m_nowL;
	void	m_getCode( Code& obj, ui08* data );
	void	m_saveCodes( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p );
	bool	m_checkDir( Text& path, Text& leaf );
	bool	m_checkFiles( Text& path, Text& leaf, Text& ext, Text& subP );
public:
	hexDB();
	M_EGRID m_eGrid;
	M_OGRID m_oGrid;
	M_HTREE m_hTree;
	void	addr_onchange(	wxCommandEvent& event );
	void	val__onchange(	wxCommandEvent& event );
	void	valT_onchange(	wxCommandEvent& event );
	void	val__onshow(	wxShowEvent& event );
	void	valS_onselect(	wxCommandEvent& event );
	void	SetGui( hexGui* gui );
	int		nowL, oldL;
	bool	eGridActive; // Thread needs this to allow editing bytes
	Text	m_binNameE, m_binNameH;
	void	eGrid_OnEditExit( wxGridEvent* event );
	void	m_getCodes( Codes& obj, ui32 h, bool insideCall );
	wxStandardPaths stdPaths;
	Text	cwd, wd;
	ui64	eAddr, oAddr;
	wxGauge* pb;
	bool	uGrid( wxGrid* grid, ui64 addr, ui08 rows );
	void	eGrid( ui08 rows, ui64 addr, ui08* data = NULL, ui16 bytes = 0u );
	void	oGrid( BinF& file, ui64 addr, ui08 rows, int c, size_t sizeofvalues );
	bool	killThreads;
	void	useCodes( void );
	static Text	getDefN( int inMode = -1, bool forRoot = true );
	// Load data
	void	loadData( int doAct = HEX_LOAD_SAVE2TEMP, Text name = getGlobalName() );
	void	loadCodes( Text path, Hacks& hData, Codes& cData );
	// Save data
	void	saveCodes( bool addObj = false );
	void	getCodes( ui32 hackIndex );
	void	convertF2F( int toFormat );
	int		mode[ HEX_LIST_COUNT ];
	LBox*	appsLB;
	TrCO*	hacksTree;
	TrCO*	codesTree;
	State	state;
	Org		org;
	Pfm		pfm;
	Bin		bin;
	CfgF*	ini;
	si16	codeNo;
	Pfl		pfl;
	Fmt		format;
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
	bool	tmpCwd;
	int		tmpMode;
};
/* */
class xsDLL codeThread : public wxThread
{
protected:
	hexGui*		m_gui;
	hexLib*		m_lib;
	int*		m_add;
public:
	codeThread( hexGui* gui, hexLib& lib, int& timeCTAdd );
	~codeThread();
protected:
	virtual ExitCode Entry( void );
private:
	Codes		codes;
	bool		m_hooked;
	ui64		m_ram[ 0x10 ];
	size_t		m_addrSize;
	void		m_useCodes( osHdl hApp, ui32& h, ui32& hEnd, ui16 c, ui16 cEnd, bool doHacks );
};
class xsDLL editThread : public wxThread
{
private:
	hexGui*	m_gui;
	hexLib*	m_lib;
	int*	m_add;
public:
	editThread( hexGui* gui, hexLib& lib, int& timeETAdd );
	~editThread();
protected:
	virtual ExitCode Entry( void );
};
class xsDLL hexGui
{
public:
	hexGui();
	M_FIND* m_find;
	M_TREE* m_tree;
	HEX_LANG* m_lang;
	hexLib	m_lib;
	osHdl	hApp;
	codeThread* m_cThread;
	editThread* m_eThread;
	wxCriticalSection m_cThreadCS, m_eThreadCS;
	void NewCodeThread();
	void NewEditThread();
	int	SetGTime( int i );
};
/* */
#endif
