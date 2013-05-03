#include "wx_pch.h"
#include "hexDLL_global.hpp"
#include "hex2_db.h"
#include "hexDB_hack.h"
#include "hexDB_hexIO.h"
#ifndef hexDB_hexLib_h
#define hexDB_hexLib_h

class hexThread;
struct xsDLL HEX_LANG
{
	HEX_LANG( void );
	enum
	{
		en = 0,
		enGb, enUs, // Great Britain, United States
		de, // German
		jp,
		/** Japanese (Also name of sub language):
			Ainu, Amami-Oshima (Nothern, Sothern),
			Kikai, Korean, Kunigami, Miyako,
			Okinawan (Central), Oki-No-Erabu,
			Japanese Sign Language, Toku-No-Shima,
			Yeayama, Yonaguni, Yoron
		**/
		jpAi, jpAN, jpAS, jpKi, jpKo, jpKu, jpMi, jpOC, jpOk, jpSL, jpTo, jpYa, jpYn, jpYr,
		langCount
	};
	enum
	{
		txt_load = 0,
		txt_save,
		txt_new,
		txt_del,
		txt_set,
		txt_get,
		txt_error,
		txt_failedtocreatethreadpointer,
		txt_failedtocreatethread,
		txt_failedtorunthread,
		txt_thefollowingarestillnull,
		txt_text,
		txt_address,
		txt_value,
		txt_shoudisavechanges,
		txt_modified,
		txt_count
	};
	Text DNM[ txt_count ];
	Text text[ txt_count ], mode[ HEX_LIST_COUNT ];
};
class xsDLL M_FIND : public wxEvtHandler // Query & Results
{
private:
	void cmp__txt_onchange(	wxCommandEvent	&event );
	void cmp__spb_onspinH(	wxSpinEvent		&event );
	void cmp__spb_onspinE(	wxSpinEvent		&event );
	void max__txt_onchange(	wxCommandEvent	&event );
	void max__spb_onspinH(	wxSpinEvent		&event );
	void max__spb_onspinE(	wxSpinEvent		&event );
	void min__txt_onchange(	wxCommandEvent	&event );
	void min__spb_onspinH(	wxSpinEvent		&event );
	void min__spb_onspinE(	wxSpinEvent		&event );
	void find_dd__onchange( wxCommandEvent	&event );
	void max_check( bool fromMinCheck = false );
	void min_check( bool fromMaxCheck = false );
public:
	M_FIND( void );
	enum
	{
		HEX_QM = 0, // Must be true
		HEX_QA, // Any be true
		HEX_QN, // None be true
		HEX_QCOUNT
	};
	HEX_LANG
		*m_lang;
	hexLib
		*m_lib;
	wxPanel	
		*find_p, *out__p;
	wxGrid
		*edit_g;
	wxSpinButton
		*cmp__spb, *min__spb, *max__spb;
	wxChoice
		*type_dd, *find_dd, *ram__dd;
	// Search
	wxGauge	
		*find_pb;
	wxCheckBox
		*a_cb[ HEX_QCOUNT ][ hexA_COUNT ], *v_cb[ HEX_QCOUNT ][ hexT_COUNT ];
	wxTextCtrl
		*cmp__txt, *min__txt, *max__txt,
		*a_txt[ HEX_QCOUNT ][ hexT_COUNT ], *v_txt[ HEX_QCOUNT ][ hexT_COUNT ];
	ui08	m_max, m_min, m_find, m_eRows,
		m_v[ HEX_QCOUNT ][ hexT_COUNT ][ 16 ];
	bool
		m_ab[ HEX_QCOUNT ][ hexA_COUNT ],
		m_vb[ HEX_QCOUNT ][ hexT_COUNT ];
	ui64
		m_a[ HEX_QCOUNT ][ hexA_COUNT ];
	si16	m_cmp, m_cmpMax;
	void	find( void );
	void	find_create( void );
	// Editor
	bool	isAuto, isActive;
	int	wait;
	bool	jump( void );
};
class xsDLL M_TREE : public wxEvtHandler // Hacks & Codes
{
private:
	bool	m_hacks_check( void );
	void	m_hacks_connect( void );
	void	m_hacks_disconnect( void );
	void	m_codes_connect( void );
	void	m_codes_disconnect( void );
	// Tree Events
	void	hack_t_onselect( wxTreeEvent&	event );
	void	hack_t_onshow(	 wxShowEvent&	event );
	void	code_t_onselect( wxTreeEvent&	event );
	void	code_t_onshow(	 wxShowEvent&	event );
	// Button Clicks
	void	hNew_b_onclick( wxCommandEvent& event );
	void	hDel_b_onclick( wxCommandEvent& event );
	void	hSet_b_onclick( wxCommandEvent& event );
	void	hGet_b_onclick( wxCommandEvent& event );
	void	cNew_b_onclick( wxCommandEvent& event );
	void	cDel_b_onclick( wxCommandEvent& event );
	void	cSet_b_onclick( wxCommandEvent& event );
	void	cGet_b_onclick( wxCommandEvent& event );
	void	cType_dd_onchange( wxCommandEvent& event );
	bool	m_isHacksConnected, m_isCodesConnected, m_isShared;
public:
	M_TREE( void );
	hexLib* m_lib;
	Fmt		m_fNow, m_fOld, m_fTmp;
	Hack	m_hNow, m_hOld, m_hTmp;
	Code	m_cNow, m_cOld, m_cTmp;
	Hacks	m_hacks;
	Codes	m_codes;
	wxPanel
		*hack_p, *code_p, *fmt__p;
	wxTreeCtrl
		*hack_t, *code_t;
	wxChoice
		*cType_dd;
	wxTextCtrl
		*name_txt, *addr_txt, *val__txt, *size_txt;
	wxButton
		*hNew_b, *hDel_b, *hSet_b, *hGet_b,
		*cNew_b, *cDel_b, *cSet_b, *cGet_b;
	void	hacks_connect( void );
	void	hacks_disconnect( void );
	void	codes_connect( void );
	void	codes_disconnect( void );
	ui08	m_cType, m_vType;
	si32	m_hackNow, m_codeNow;
	bool	isAuto, isActive;
	int	wait;
};
class xsDLL hexLib : public wxEvtHandler
{
public:
	class xsDLL M_LOAD
	{
	public:
		Text name;
		HEX_LANG *m_lang;
		TxtF *des, *src;
		bool desIsTmp, saveChanges;
		M_LOAD( void );
		bool check( void );
	};
	class xsDLL M_BASE : public wxEvtHandler
	{
	public:
		HEX_LANG *m_lang;
		bool m_main_connect( dBase *now = NULL, dBase *old = NULL, dBase *tmp = NULL );
		bool m_main_disconnect( void );
		hexLib* m_lib;
		Text m_prevPath;
		bool m_isMainConnected;
		wxTextCtrl	*name_txt;
		TxtA		m_mainList;
		wxPanel		*main_p;
		wxButton	*load_b, *save_b, *new_b, *del_b, *set_b, *get_b;
	};
	class xsDLL M_STATE : public M_BASE
	{
	private:
		void name_dd_onchange( wxCommandEvent& event );
	public:
		M_STATE( void );
		State m_now, m_old, m_tmp;
		wxChoice *name_dd;
		wxStaticText
			*org_s, *pfm_s, *bin_s, *pfl_s, *fmt_s;
		void getState( Text name = wxEmptyString );
		void main_connect( void );
		void main_disconnect( void );
	};
	class xsDLL M__ORG : public M_BASE
	{
	public:
		M__ORG( void );
		const Text m_header;
		Org m_now, m_old, m_tmp;
		wxTextCtrl	*file_txt;
		void main_m_load( Text &line, Org &src, Org &tmp );
		void main_m_save( Text &line, Org &obj, bool asTemp = false );
		void main_load( M_LOAD load );
		void main_connect( void );
		void main_disconnect( void );
	};
	class xsDLL M__PFM : public M_BASE
	{
	public:
		M__PFM( void );
		Pfm m_now, m_old, m_tmp;
		wxTextCtrl	*file_txt;
		wxChoice	*endian_dd;
		void main_load( M_LOAD load );
		void main_m_load( Text &line, Pfm &src, Pfm &tmp );
		void main_m_save( Text &line, Pfm &obj, bool asTemp = false );
		void getPfm( Text name = wxEmptyString );
		ui08 getEndian( Text name = wxEmptyString );
		Text getEndian( ui08 endian );
		void endian_dd_onchange( wxCommandEvent& event );
		void main_connect( void );
		void main_disconnect( void );
	};
	class xsDLL M__BIN : public M_BASE
	{
	private:
		void bin__lb_onclick( wxCommandEvent& event );
		void ram__lb_onclick( wxCommandEvent& event );
		void bind_b__onclick( wxCommandEvent& event );
		void path_b__onclick( wxCommandEvent& event );
		void main_m_load( TxtT &tknr, Bin *obj );
		void main_m_load( TxtT &tknr, Ram *obj );
		void main_m_save( Text &line, Bin *obj );
		void main_m_save( Text &line, Ram *obj );
	public:
		M__BIN( void );
		const Text m_keyData, m_keyTemp, m_valApp, m_valWin, m_valFile;
		enum { HEX_BIN_FILE = 0, HEX_BIN_APP, HEX_BIN_WIN, HEX_BIN_COUNT };
		Bin m_bNow, m_bOld, m_bTmp;
		Ram m_rNow, m_rOld, m_rTmp;
		wxListBox *bin__lb, *ram__lb;
		wxTextCtrl *file_txt, *addr_txt, *bytes_txt, *bind_txt, *path_txt;
		wxButton
			*bind_b, *path_b;
		void main_load( M_LOAD load );
		void main_m_save( TxtF *file, Bin *old, Bin *now = NULL );
		void getBin( Text name = wxEmptyString );
		void getRam( Text name = wxEmptyString );
		void main_connect( void );
		void main_disconnect( void );
	};
	class xsDLL M__PFL : public M_BASE
	{
	private:
		void notes_ta_onchange( wxCommandEvent& event );
		void sid__txt_onchange( wxCommandEvent& event );
		void pid__txt_onchange( wxCommandEvent& event );
	public:
		enum 
		{
			HEX_REGION_AUS = 0u,
			HEX_REGION_CA,
			HEX_REGION_DE,
			HEX_REGION_JP,
			HEX_REGION_UK,
			HEX_REGION_US,
			HEX_REGION_COUNT
		};
	private:
		Text m_rTxt[ HEX_REGION_COUNT ];
		ui32 m_rHex[ HEX_REGION_COUNT ];
	public:
		M__PFL( void );
		Pfl m_now, m_old, m_tmp;
		wxTextCtrl	*file_txt, *notes_ta, *sid__txt, *pid__txt;
		ui32 getRegions( Text name = wxEmptyString );
		void main_load( M_LOAD load );
		void main_m_load( TxtF *src, Pfl &obj );
		void main_m_save( TxtF *des, Pfl &obj );
		void main_connect( void );
		void main_disconnect( void );
	};
private:
	ui08 m_guiNow, m_guiOld;
	bool m_guiDlg, m_isCwd;
	Text m_dirCwd, m_dirDoc, m_dirTmp;
public:
	hexLib( void );
	hexThread* thread;
	M_BASE *m_base;
	HEX_LANG m_lang;
	M_STATE m_state;
	M__ORG m__org, m_dorg;
	M__PFM m__pfm, m_dpfm;
	M__BIN m__bin, m_dbin;
	M__PFL m__pfl, m_dpfl;
	M_FIND m_find;
	M_TREE m_tree, m_dtre;
	wxChoice
		*guiMode_dd;
	dBase *m_now, *m_old, *m_tmp;
	ui64 *m_addr, *m_cVal;
	ui08
		**m__val, *m_size, *m__hex;
	void name_txt_onchange();
	void setGuiMode( int mode, bool isDlg = false );
	ui08 getGuiMode( void );
	Text getWd( void );
	Text getTmpWd( void );
	void setWd( bool isCwd = false );
	bool isDlgShown( void );
	void new_b_onclick( wxCommandEvent& event );
	void del_b_onclick( wxCommandEvent& event );
	void set_b_onclick( wxCommandEvent& event );
	void get_b_onclick( wxCommandEvent& event );
	void anyobj_onfocus( wxFocusEvent& event );
	void guiMode_dd_onchange( wxCommandEvent& event );
	void name_txt_onchange( wxCommandEvent& event );
	void file_txt_onchange( wxCommandEvent& event );
	void addr_txt_onchange( wxCommandEvent& event );
	void val__txt_onchange( wxCommandEvent& event );
	void hex___dd_onchange( wxCommandEvent& event );
};

#endif