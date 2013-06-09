#include "wx_pch.h"
#include "hexLib_main.h"
hexLib::hexLib( void ) :
	wxEvtHandler()
{
	m_now = NULL;
	m_old = NULL;
	m_tmp = NULL;
	m_tree.m_lib = this;
	m_guiDlg = false;
	m_isCwd	 = true;
	wxStandardPaths std;
	m_dirCwd = wxGetCwd() + xsDirSep;
	m_dirTmp = std.GetTempDir() + xsDirSep + wxT("hackerex") + xsDirSep;
	m_dirDoc = std.GetDocumentsDir() + xsDirSep + wxT("hackerex") + xsDirSep;
}
hexLib::~hexLib( void )
{
	setCfgState( m_state.m_old.name );
	setCfgTheme( wxT("crystal-clear-icons-by-everaldo") );
	wxDir dir;
	TxtA names;
	int i = 0, end = dir.GetAllFiles( getTmpWd(), &names );
	for ( ; i < end; ++i )
		wxRemoveFile( names[ i ] );
}
Text hexLib::getWd( void ) { return m_isCwd ? m_dirCwd : m_dirDoc; }
void hexLib::setWd( bool isCwd ) { m_isCwd = isCwd; }
Text hexLib::getTmpWd( void ) { return m_dirTmp; }
hexLang::hexLang( void )
{
	// DNM is the default value set for text, ./lang/*.txt files will be used to allow multi-language support
	DNM[ txt_error ]						= wxT("Error!");
	DNM[ txt_failedtoreadmemory ]			= wxT("Failed to read Memory!");
	DNM[ txt_failedtoloadappfile ]			= wxT("Failed to load Application / File!");
	DNM[ txt_failedtocreatethreadpointer ]	= wxT("Failed to create thread pointer!");
	DNM[ txt_failedtocreatethread ]			= wxT("Failed to create thread!");
	DNM[ txt_failedtorunthread ]			= wxT("Failed to run thread!");
	DNM[ txt_thefollowingarestillnull ]		= wxT("The following are still NULL:");
	DNM[ txt_shoudisavechanges ]			= wxT("Should I save changes?");
	DNM[ txt_modified ]						= wxT("Modified!");
	for ( int i = 0; i < txt_count; ++i )
		text[ i ] = DNM[ i ];
}
M_TREE::M_TREE( void ) :
	wxEvtHandler()
{
	hack_t = NULL; code_t = NULL;
	hNew_b = NULL; hDel_b = NULL;
	hSet_b = NULL; hGet_b = NULL;
	cNew_b = NULL; cDel_b = NULL;
	cSet_b = NULL; cGet_b = NULL;
}
ui08 hexLib::getGuiMode( void ) { return m_guiNow; }
bool hexLib::isDlgShown( void ) { return m_guiDlg; }
void hexLib::setGuiMode( int mode, bool isDlg )
{
	if ( mode < 0 || mode > HEX_LIST_COUNT )
		mode = isDlg ? m_guiNow : HEX_LIST_COUNT;
	ui08 m = mode;
	if ( m == m_guiNow && isDlg == m_guiDlg )
		return;
	switch ( m_guiNow )
	{
	case HEX_LIST_STATE:
		m_state.main_disconnect();
		break;
	case HEX_LIST_ORG:
		if ( !m_guiDlg )
			m__org.main_disconnect();
		else
			m_dorg.main_disconnect();
		break;
	case HEX_LIST_PFM:
		if ( !m_guiDlg )
			m__pfm.main_disconnect();
		else
			m_dpfm.main_disconnect();
		break;
	case HEX_LIST_BIN:
		if ( !m_guiDlg )
			m__bin.main_disconnect();
		else
			m_dbin.main_disconnect();
		break;
	case HEX_LIST_PFL:
		if ( !m_guiDlg )
			m__pfl.main_disconnect();
		else
			m_dpfl.main_disconnect();
		break;
	case HEX_LIST_HACK:
		m_tree.hacks_disconnect();
		break;
	case HEX_LIST_CODE:
		if ( !m_guiDlg )
			m_tree.codes_disconnect();
		else
			m_dtre.codes_disconnect();
		break;
	}
	switch ( m )
	{
	case HEX_LIST_STATE:
		m_state.main_connect();
		break;
	case HEX_LIST_ORG:
		if ( !m_guiDlg )
			m__org.main_connect();
		break;
	case HEX_LIST_PFM:
		if ( !m_guiDlg )
			m__pfm.main_connect();
		break;
	case HEX_LIST_BIN:
		if ( !m_guiDlg )
			m__bin.main_connect();
		break;
	case HEX_LIST_PFL:
		if ( !m_guiDlg )
			m__pfl.main_connect();
		break;
	case HEX_LIST_HACK:
		m_tree.hacks_connect();
		break;
	case HEX_LIST_CODE:
		if ( !m_guiDlg )
			m_tree.codes_connect();
		break;
	}
	m_guiOld = isDlg ? m_guiNow : m;
	m_guiNow = m;
	m_guiDlg = isDlg;
}
void hexLib::dd___mode_onchange( wxCommandEvent& event ) { setGuiMode( guiMode_dd->GetSelection() ); }
void hexLib::btn__set__onclick( wxCommandEvent& event ) { *m_now = *m_tmp; }
void hexLib::btn__get__onclick( wxCommandEvent& event ) { *m_tmp = *m_now; }
void hexLib::tbox_name_onchange( wxCommandEvent& event )
{
	if ( m_tmp != null )
	{
		wxTextCtrl* obj = ( wxTextCtrl* )( event.GetEventObject() );
		m_tmp->name = obj->GetValue();
	}
	event.Skip();
}
void hexLib::tbox_file_onchange( wxCommandEvent &event )
{
	if ( m_tmp != null )
	{
		wxTextCtrl* obj = ( wxTextCtrl* )( event.GetEventObject() );
		dFile* tmp = ( dFile* )m_tmp;
		tmp->file = obj->GetValue();
	}
	event.Skip();
}
void hexLib::tbox_addr_onchange( wxCommandEvent &event )
{
	if ( m_addr != null )
	{
		wxTextCtrl* obj = (wxTextCtrl*)(event.GetEventObject());
		*m_addr = zxAtou( obj->GetValue().data(), 16u );
		obj->ChangeValue( zxUtoa( *m_addr, 16u ).data() );
	}
	event.Skip();
}
void hexLib::tbox_val__onchange( wxCommandEvent &event )
{
	wxTextCtrl* obj = (wxTextCtrl*)( event.GetEventObject() );
	if ( m__val != null )
	{
		zxInt val, tmp = parseInt( obj->GetValue().data(), 16u );
		val.setPtr( m__val, *m_size );
		val.copy( tmp.m_data, tmp.m_size );
		obj->ChangeValue( val.toString().data() );
	}
	event.Skip();
}