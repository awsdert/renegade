#include "hexLib_bin.h"

#ifndef hexLib_pfl_h
#define hexLib_pfl_h

class hexLibDLL M__PFL : public M_FILE
{
private:
	void m_show( ui32 region );
	Pfl  m_load( TxtF *file, Pfl &save, Text &name, Text &source );
	void m_load( TxtF *file, Pfl &obj, Text &source );
	void m_save( TxtF *file, Pfl &obj, Text &source );
	void ta___notes_onchange( wxCommandEvent& event );
	void tbox_sid_onchange( wxCommandEvent& event );
	void tbox_pid_onchange( wxCommandEvent& event );
public:
	M__PFL( void );
	Pfl
		m_now, m_src, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	wxTextCtrl
		*ta___notes,
		*tbox_sid,
		*tbox_pid;
	wxCheckListBox
		*clb__region;
	wxChoice
		*dd___region;
	ui08 getEndian( Text txt );
	Text getEndian( ui08 val );
	void lib_load( M_LOAD load );
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif