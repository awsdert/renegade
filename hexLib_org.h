#include "hexLib_M_FILE.h"

#ifndef hexLib_org_h
#define hexLib_org_h

class hexLibDLL M__ORG : public M_FILE
{
private:
	void m_load( Text &line, Org &now, Text &source );
	void m_save( Text &line, Org &now, Text &source );
	Org  m_load( TxtF *file, Org &now, Text &name, Text &source );
public:
	M__ORG( void );
	Org m_now, m_src, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	void lib_load( M_LOAD &load );
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif