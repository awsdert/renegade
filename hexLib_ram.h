#include "hexLib_pfm.h"

#ifndef hexLib_ram_h
#define hexLib_ram_h
class M__BIN;
class hexLibDLL M__RAM : public M_NAME
{
private:
	
public:
	M__RAM( void );
	Bin
		*m_now, *m_src, *m_tmp;
	Ram
		m_obj;
	si08
		ramNo;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	void lbox_main_onselect( wxCommandEvent& event );
	void tbox_size_onchange( wxCommandEvent& event );
	M__BIN
		*binGui;
	M_ADDR
		addrGui;
	wxListBox
		*lbox_main;
	wxStaticBox
		*lbl__size;
	wxTextCtrl
		*tbox_size;
	void lib_show( void );
	void lib_getRam( si08 id );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif