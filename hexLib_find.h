#include "hexLib_bin.h"

#ifndef hexLib_find_h
#define hexLib_find_h

enum hexA_TYPE
{
	hexA_MT = 0,
	hexA_ME,
	hexA_LT,
	hexA_LE,
	hexA_COUNT
};

enum hexQ_TYPE
{
	hexQ_NOACT = 0,
	hexQ_DC, hexQ_NC,
	hexQ_DE, hexQ_NE,
	hexQ_MT, hexQ_ME,
	hexQ_LT, hexQ_LE,
	hexQ_COUNT
};

enum hexT_TYPE
{
	// DO NOT MODIFY ORDER
	hexT_DC = 0u,
	hexT_NC,
	hexT_DE,
	hexT_NE,
	hexT_MT,
	hexT_ME,
	hexT_LT,
	hexT_LE,
	hexT_COUNT
};

class hexLibDLL M_FIND : public wxEvtHandler // Query & Results
{
private:
	void cmp__txt_onchange(	wxCommandEvent	&event );
	void cmp__spb_onspinH(	wxSpinEvent		&event );
	void cmp__spb_onspinE(	wxSpinEvent		&event );
	void max__txt_onchange(	wxCommandEvent	&event );
	void max__spb_onspinH(	wxSpinEvent		&event );
	void max__spb_onspinE(	wxSpinEvent		&event );
	void min__txt_onchange(	wxCommandEvent	&event );
	void min__spb_onspinH(	wxSpinEvent		&event );
	void min__spb_onspinE(	wxSpinEvent		&event );
	void find_dd__onchange( wxCommandEvent	&event );
	void max_check( bool fromMinCheck = false );
	void min_check( bool fromMaxCheck = false );
	void sync_m_connect( void );
	void sync_m_disconnect( void );
public:
	M_FIND( void );
	enum
	{
		HEX_QM = 0, // Must be true
		HEX_QA, // Any be true
		HEX_QN, // None be true
		HEX_QCOUNT
	};
	M_ADDR addrGuiE, addrGuiO;
	hexLang
		*m_lang;
	hexLib
		*m_lib;
	hexGui
		*m_gui;
	wxPanel	
		*find_p, *out__p;
	wxGrid
		*edit_g, *out__g;
	wxCheckListBox
		*sync_rl;
	wxSpinButton
		*cmp__spb, *min__spb, *max__spb, *size_spb;
	wxButton
		*eJump_b, *eGet_b, *eSet_b,
		*oJump_b;
	wxChoice
		*type_dd, *find_dd, *ram__dd, *hook_dd;
	// Search
	wxGauge	
		*find_pb;
	wxCheckBox
		*a_cb[ HEX_QCOUNT ][ hexA_COUNT ], *v_cb[ HEX_QCOUNT ][ hexT_COUNT ];
	wxTextCtrl
		*addr_txt, *val__txt,
		*cmp__txt, *min__txt, *max__txt,
		*a_txt[ HEX_QCOUNT ][ hexT_COUNT ], *v_txt[ HEX_QCOUNT ][ hexT_COUNT ];
	ui08	m_max, m_min, m_find,
		m_eRows, m_eSize, m_eType,
		m_oRows, m_oSize, m_oType,
		m_v[ HEX_QCOUNT ][ hexT_COUNT ][ 16 ];
	bool
		m_ab[ HEX_QCOUNT ][ hexA_COUNT ],
		m_vb[ HEX_QCOUNT ][ hexT_COUNT ];
	ui64
		eAddr, oAddr,
		m_a[ HEX_QCOUNT ][ hexA_COUNT ];
	si16	m_cmp, m_cmpMax;
	void	find( void );
	void	find_create( void );
	// Results
	// - Shared Events
	void	out( ui64 addr, ui08 rows );
	// Editor
	bool	isAuto, isActive, isUpLast, isEShown;
	int		wait, iXVH, iYVH;
	// - Shared Events
	bool	eJump( void );
	void	eJump2( ui64 addr );
	void	eUpdate( ui08* data, ui16 size );
	void	eScroll( int dir = 0, bool isGridSrc = false, bool isWheelSrc = false );
	// - Individual Events
	void	sync_connect( void );
	void	sync_disconnect( void );
	void	sync_onshow( wxShowEvent& event );
	void	sync_onclick( wxCommandEvent& event );
	void	eGet_onclick( wxCommandEvent& event );
	void	eSet_onclick( wxCommandEvent& event );
	void	hook_onchoice( wxCommandEvent& event );
	void	eGrid_onmwheel( wxMouseEvent& event );
	void	edit_onmwheel( wxMouseEvent& event );
	void	eJump_onclick( wxCommandEvent& event );
	void	oneScrollB( wxScrollWinEvent& event );
	void	oneScrollE( wxScrollWinEvent& event );
};

#endif