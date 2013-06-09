#include "wx_pch.h"
#include "hexObjs_main.h"
#include "hexDll_main.h"

#ifndef hexLib_base_h
#define hexLib_base_h

#ifdef hexLib_BUILD
#define hexLibDLL zxDLL_EXP
#else
#define hexLibDLL zxDLL_IMP
#endif

class hexThread;
class hexLib;
class hexGui;

enum
{
	HEX_LIST_THEME = 0,
	HEX_LIST_STATE,
	HEX_LIST_ORG,
	HEX_LIST_PFM,
	HEX_LIST_BIN,
	HEX_LIST_APP,
	HEX_LIST_WIN,
	HEX_LIST_RAM,
	HEX_LIST_PFL,
	HEX_LIST_FORMAT,
	HEX_LIST_HACK,
	HEX_LIST_CODE,
	HEX_LIST_FIND,
	HEX_LIST_OUT,
	HEX_LIST_EDIT,
	HEX_LIST_COUNT
};

struct hexLibDLL hexLang
{
	hexLang( void );
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
		txt_failedtoreadmemory,
		txt_failedtoloadappfile,
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

enum
{
	BTN_LOAD = 0,
	BTN_SAVE,
	BTN_NEW,
	BTN_DEL,
	BTN_SET,
	BTN_GET,
	BTN_COUNT
};

class hexLibDLL btnArray : public zxArray< wxButton*, BTN_COUNT >
{
public:
	btnArray( void );
};

class hexLibDLL M_ADDR : public wxEvtHandler
{
public:
	M_ADDR( void );
	wxStaticBox
		*lbl__main;
	wxTextCtrl
		*tbox_main;
	wxSlider
		*sl___depth;
	void addr_connect( void );
	void addr_disconnect( void );
};
class hexLibDLL M__VAL : public wxEvtHandler
{
private:
	bool m_libC;
	Text m_getFloat( void* fpn, ui08 size );
public:
	M__VAL( void );
	void main_onchange( wxCommandEvent& event );
	void type_onselect( wxCommandEvent& event );
	void size_onspinup( wxSpinEvent& event );
	void size_onspindown( wxSpinEvent& event );
	M_ADDR
		addrGui;
	zxInt
		m_val;
	ui08
		m_type;
	wxPanel
		*p____main;
	wxStaticBox
		*lbl__main,
		*lbl__size,
		*lbl__type;
	wxTextCtrl
		*tbox_main,
		*tbox_size;
	wxChoice
		*dd___type;
	wxSpinButton
		*spb__size;
	wxButton
		*btn__read,
		*btn__write;
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
};

#endif