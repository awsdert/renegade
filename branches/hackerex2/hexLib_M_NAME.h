#include "hexLib_M_LOAD.h"

#ifndef hexLib_M_NAME_h
#define hexLib_M_NAME_h

class hexLibDLL M_NAME : public wxEvtHandler
{
private:
	bool m_nameC;
public:
	M_NAME( void );
	bool m_mainC, m_libC;
	hexLib
		*m_lib;
	hexLang
		*m_lang;
	wxPanel
		*p____main,
		*p____name;
	wxStaticBox
		*lbl__name;
	wxTextCtrl
		*tbox_name;
	void name_connect( void );
	void name_disconnect( void );
};

#endif