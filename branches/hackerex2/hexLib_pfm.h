#include "hexLib_org.h"

#ifndef hexLib_pfm_h
#define hexLib_pfm_h

enum
{
	HEX_ENDIAN_LITTLE = 0,
	HEX_ENDIAN_BIG,
	HEX_ENDIAN_LBIG,
	HEX_ENDIAN_COUNT
};

class hexLibDLL M__PFM : public M_FILE
{
private:
	Pfm  m_load( TxtF *file, Pfm &save, Text &name, Text &source );
	void m_load( Text &line, Pfm &obj, Text &source );
	void m_save( Text &line, Pfm &obj, Text &source );
	ui08 m_getEndian( Text name = wxEmptyString );
	Text m_getEndian( ui08 endian );
public:
	M__PFM( void );
	Pfm m_src, m_now, m_tmp;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	void dd___endian_onchange( wxCommandEvent& event );
	wxStaticBox
		*lbl__endian;
	wxChoice
		*dd___endian;
	void main_load( M_LOAD load );
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

#endif