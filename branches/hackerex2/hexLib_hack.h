#include "hexLib_code.h"

#ifndef hexLib_hack_h
#define hexLib_hack_h

class hexLibDLL M_HACK : public M_NAME
{
private:
	void m_listHacks( si32 i, si32& iEnd, TrId pItem );
	void m_listHacks( void );
	void m_connect( void );
	void m_disconnect( void );
public:
	M_HACK( void );
	Hacks
		m_now, m_src, m_tmp;
	Hack
		m_obj;
	void p____main_onfocus(	wxFocusEvent& event );
	void p____main_onblur(	wxFocusEvent& event );
	void tree_main_onselect( wxTreeEvent& event );
	M_CODE
		*codeGui;
	TrCO
		*tree_main;
	wxCheckBox
		*cb___active;
	wxRadioButton
		*rb___active;
	wxChoice
		*dd___kids;
	btnArray
		btn_main;
	si32 m_id;
	void lib_show( void );
	void lib_connect( void );
	void lib_disconnect( void );
	void main_connect( void );
	void main_disconnect( void );
};

class hexLibDLL M_TREE : public wxEvtHandler // Hacks & Codes
{
private:
	bool	m_hacks_check( void );
	void	m_hacks_connect( void );
	void	m_hacks_disconnect( void );
	void	m_codes_connect( void );
	void	m_codes_disconnect( void );
	// Tree Events
	void	hack_t_onselect( wxTreeEvent&	event );
	void	hack_t_onshow(	 wxShowEvent&	event );
	void	code_t_onselect( wxTreeEvent&	event );
	void	code_t_onshow(	 wxShowEvent&	event );
	// Button Clicks
	void	hNew_b_onclick( wxCommandEvent& event );
	void	hDel_b_onclick( wxCommandEvent& event );
	void	hSet_b_onclick( wxCommandEvent& event );
	void	hGet_b_onclick( wxCommandEvent& event );
	void	cNew_b_onclick( wxCommandEvent& event );
	void	cDel_b_onclick( wxCommandEvent& event );
	void	cSet_b_onclick( wxCommandEvent& event );
	void	cGet_b_onclick( wxCommandEvent& event );
	void	cType_dd_onchange( wxCommandEvent& event );
	bool	m_isHacksConnected, m_isCodesConnected, m_isShared;
public:
	M_TREE( void );
	hexLib* m_lib;
	Fmt		m_fNow, m_fOld, m_fTmp;
	Hack	m_hNow, m_hOld, m_hTmp;
	dName	m_dNow, m_dOld, m_dTmp;
	Code	m_cNow, m_cOld, m_cTmp;
	Hacks	m_hacks;
	Codes	m_codes;
	wxPanel
		*hack_p, *code_p, *fmt__p;
	wxTreeCtrl
		*hack_t, *code_t;
	wxChoice
		*cType_dd;
	wxTextCtrl
		*name_txt, *addr_txt, *val__txt, *size_txt;
	wxButton
		*hNew_b, *hDel_b, *hSet_b, *hGet_b,
		*cNew_b, *cDel_b, *cSet_b, *cGet_b;
	void	hacks_connect( void );
	void	hacks_disconnect( void );
	void	codes_connect( void );
	void	codes_disconnect( void );
	ui08	m_cType, m_vType;
	si32	m_hackNow, m_codeNow;
	bool	isAuto, isActive;
	int	wait;
};

hexLibDLL void Maketxt_Hex1( Code& obj, TxtA& block );
#endif