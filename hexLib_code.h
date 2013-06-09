#include "hexLib_fmt.h"

#ifndef hexLib_code_h
#define hexLib_code_h

class hexLibDLL M_CODE : public M_NAME
{
	void m_listCodes( TrCO* tree, Codes& data, Code& obj, TrId& parent, int i, int iEnd );
	void m_listCodes( TrCO* tree, LBox* lbox, Codes& data, int format, int listCode );
	void m_show( wxTextCtrl* tbox, si32 id );
public:
	M_CODE( void );
	Codes
		m_now, m_src, m_tmp;
	Code
		m_obj;
	M_ADDR
		addrGui;
	M__VAL
		valGui;
	TrCO
		*tree_main;
	LBox
		*lbox_main;
	wxTextCtrl
		*tbox_inc,
		*tbox_loop;
	wxStaticBox
		*lbl__loop;
	wxSpinButton
		*spb__val;
	wxChoice
		*dd___type,
		*dd___inc,
		*dd___test;
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif