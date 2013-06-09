#include "hexLib_M_FILE.h"
#include "hexLib_state.h"
#include "hexLib_hack.h"
#include "hexLib_hexIO.h"
#include "hexLib_find.h"
#include "hexLib_codeThread.h"
#include "hexLib_editThread.h"

#ifndef hexDB_hexLib_h
#define hexDB_hexLib_h

class hexLibDLL hexLib : public wxEvtHandler
{
private:
	ui08 m_guiNow, m_guiOld;
	bool m_guiDlg, m_isCwd;
	Text m_dirCwd, m_dirDoc, m_dirTmp;
public:
	hexLib( void );
	~hexLib( void );
	hexThread* thread;
	M_NAME *m_name;
	M_FILE *m_file;
	M_FILE *m_listFile[ HEX_LIST_COUNT ];
	hexLang m_lang;
	M_STATE m_state;
	M__ORG m__org, m_dorg;
	M__PFM m__pfm, m_dpfm;
	M__BIN m__bin, m_dbin;
	M__PFL m__pfl, m_dpfl;
	M_FIND m_find;
	M_TREE m_tree, m_dtre;
	wxChoice
		*guiMode_dd;
	dName *m_now, *m_old, *m_tmp;
	ui64
		*m_addr, *m_cVal;
	ui08
		**m__val, *m_size, *m__hex;
	void setGuiMode( int mode, bool isDlg = false );
	ui08 getGuiMode( void );
	Text getWd( void );
	Text getTmpWd( void );
	void setCfgState( Text name );
	void setCfgTheme( Text name );
	void setWd( bool isCwd = false );
	bool isDlgShown( void );
	void dd___mode_onchange( wxCommandEvent& event );
	void tbox_name_onchange( wxCommandEvent& event );
	void tbox_file_onchange( wxCommandEvent& event );
	void tbox_addr_onchange( wxCommandEvent& event );
	void tbox_val__onchange( wxCommandEvent& event );
	void dd___hex__onchange( wxCommandEvent& event );
	void btn__load_onclick(	wxCommandEvent& event );
	void btn__save_onclick(	wxCommandEvent& event );
	void btn__new__onclick(	wxCommandEvent& event );
	void btn__del__onclick(	wxCommandEvent& event );
	void btn__set__onclick(	wxCommandEvent& event );
	void btn__get__onclick(	wxCommandEvent& event );
};

#endif