#include "hex2_global.h"
#include "hex2_db.h"
#include "hexDB_hack.h"
#include "hexDB_app.h"
#ifndef HACKEREX_GLOBAL_DB
#define HACKEREX_GLOBAL_DB
enum
{
	HEX_LOAD_SAVE2FILE = 0,
	HEX_LOAD_SAVE2TEMP,
	HEX_LOAD_LIST,
	HEX_LOAD_COUNT
};
class hexGui;
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
	// Editor
	wxGrid		*m_eGrid;
	wxButton	*m_eJump, *m_eGet, *m_eSet;
	wxChoice	*m_eHook;
	wxSpinButton *m_eSpin;
	wxTextCtrl	*m_eGridTB, *m_eValue, *m_eAddr;
	ui64	m_eGridAddr;
	// Hacks / Codes
	void	m_getCode( Code& obj, ui08* data );
	void	m_saveCodes( ui08* data, Text& path, TxtA& block, TxtF& file, ui32& hEnd, ui32 p );
	bool	m_checkDir( Text& path, Text& leaf );
	bool	m_checkFiles( Text& path, Text& leaf, Text& ext, Text& subP );
public:
	hexDB();
	void	SetGui( hexGui* gui );
	int		nowL, oldL;
	int		eXVH, eYVH;
	bool	eGridActive; // Thread needs this to allow editing bytes
	Text	m_binNameE, m_binNameH;
	void	m_eGridJump( bool fromThread = false );
	void	eGrid_Connect( wxGrid* grid, wxChoice* hook, wxSpinButton* bytes, wxTextCtrl* gridTB, wxTextCtrl* addr, wxTextCtrl* value, wxButton* jump, wxButton* read, wxButton* write );
	void	eGrid_Disconnect( void );
	void	eGrid_OnScroll( bool isVertical, int move );
	void	eJump_OnClick( wxCommandEvent& event );
	void	eGet_OnClick( wxCommandEvent& event );
	void	eSet_OnClick( wxCommandEvent& event );
	void	eGrid_OnEditExit( wxGridEvent* event );
	void	eJump_OnMouseWheel( wxMouseEvent& event );
	void	eGrid_OnMouseWheel( wxMouseEvent& event );
	void	eGrid_OnScrollHome( wxScrollWinEvent& event );
	void	eGrid_OnScrollLast( wxScrollWinEvent& event );
	void	m_getCodes( Codes& obj, ui32 h, bool insideCall );
	wxStandardPaths stdPaths;
	Text	cwd;
	ui64	eAddr, oAddr;
	wxGauge* pb;
	void	eGrid( ui08 rows );
	void	eGrid( ui08 rows, ui64 addr, ui08* data, ui16 bytes );
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
	bool	tmpCwd;
	int		tmpMode;
};
class xsDLL codeThread : public wxThread
{
protected:
	hexGui*		m_gui;
	hexDB*		m_db;
	int*		m_add;
public:
	codeThread( hexGui* gui, hexDB& db, int& timeCTAdd );
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
	hexDB*	m_db;
	int*	m_add;
public:
	editThread( hexGui* gui, hexDB& db, int& timeETAdd );
	~editThread();
protected:
	virtual ExitCode Entry( void );
};
class xsDLL hexGui
{
public:
	hexGui();
	bool	m_hackOn, m_editOn;
	hexDB	m_db;
	int		m_hackAdd, m_editAdd;
	codeThread* m_cThread;
	editThread* m_eThread;
	wxCriticalSection m_cThreadCS, m_eThreadCS;
	void NewCodeThread();
	void NewEditThread();
	int SetGTime( int i );
};
#endif // HACKEREX_GLOBAL_DB
