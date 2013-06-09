#include "hexLib_M_NAME.h"

#ifndef hexLib_state_h
#define hexLib_state_h

class hexLibDLL M_STATE : public M_NAME
{
private:
	void m_load( Text &line, State &now, Text &source );
	void m_save( Text &line, State &now, Text &source );
	State m_load( TxtF *file, State &now, Text &name, Text &source );
public:
	M_STATE( void );
	State m_now, m_old, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	TxtA
		listMain;
	btnArray
		btn_main;
	wxStaticBox
		*lbl__org,
		*lbl__pfm,
		*lbl__bin,
		*lbl__pfl,
		*lbl__fmt;
	void lib_load( M_LOAD &load );
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif