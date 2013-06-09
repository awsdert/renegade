#include "hexLib_pfl.h"

#ifndef hexLib_fmt_h
#define hexLib_fmt_h

class M_HACK;
class M_CODE;

class hexLibDLL M__FMT : public M_FILE
{
public:
	M__FMT( void );
	Fmt
		m_now, m_src, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	wxButton
		*btn__convert;
	wxListBox
		*lbox_convert;
	void main_load( M_LOAD load );
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif