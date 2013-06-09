#include "hexLib_ram.h"

#ifndef hexLib_bin_h
#define hexLib_bin_h


class hexLibDLL M__BIN : public M_FILE
{
private:
	Bin  m_load( TxtF *file, Bin &save, Text &name, Text &source );
	void m_load( TxtF *file, Bin &obj, Text &source );
	void m_save( TxtF *file, Bin &obj, Text &source );
public:
	M__BIN( void );
	Bin m_now, m_src, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	void dd___main_onclick(	wxCommandEvent& event );
	void btn__bind_onclick(	wxCommandEvent& event );
	void btn__path_onclick(	wxCommandEvent& event );
	M__RAM *ramGui;
	const Text m_keyData, m_keyTemp, m_valApp, m_valWin, m_valFile;
	enum { HEX_BIN_FILE = 0, HEX_BIN_APP, HEX_BIN_WIN, HEX_BIN_COUNT };
	enum
	{
		RB_FSO = 0u,
		RB_APP = 1u,
		RB_WIN = 2u,
		RB_COUNT
	};
	wxListBox
		*lbox_main;
	wxTextCtrl
		*tbox_bind, *tbox_path;
	wxButton
		*btn__bind, *btn__path;
	wxChoice
		*dd___type;
	void lib_show( void );
	void lib_load( M_LOAD load );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif