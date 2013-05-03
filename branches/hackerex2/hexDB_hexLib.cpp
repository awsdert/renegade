#include "hexDB_hexLib.h"
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
Text hexLib::getWd( void ) { return m_isCwd ? m_dirCwd : m_dirDoc; }
void hexLib::setWd( bool isCwd ) { m_isCwd = isCwd; }
HEX_LANG::HEX_LANG( void )
{
	// DNM is the default value set for text, ./lang/*.txt files will be used to allow multi-language support
	DNM[ txt_error ]						= wxT("Error!");
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
	case HEX_LIST_SESSION:
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
	case HEX_LIST_SESSION:
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
void hexLib::anyobj_onfocus( wxFocusEvent& event )
{
	wxWindow* obj = event.GetWindow();
	if ( !m_guiDlg )
	{
		if ( obj == NULL || !obj->HasCapture() )
			setGuiMode( -1 );
		else
		{
			if ( obj == m__org.main_p )
				setGuiMode( HEX_LIST_ORG );
			else if ( obj == m__pfm.endian_dd || obj == m__pfm.main_p )
				setGuiMode( HEX_LIST_PFM );
			else if ( obj == m__bin.main_p )
				setGuiMode( HEX_LIST_BIN );
			else if ( obj == m__pfl.main_p )
				setGuiMode( HEX_LIST_PFL );
			else if ( obj == m_tree.fmt__p )
				setGuiMode( HEX_LIST_FORMAT );
			else if ( obj == m_tree.hack_t || obj == m_tree.hack_p )
				setGuiMode( HEX_LIST_HACK );
			else if ( obj == m_tree.code_t || obj == m_tree.code_p )
				setGuiMode( HEX_LIST_CODE );
			else if ( obj == m_find.find_p )
				setGuiMode( HEX_LIST_FIND );
			else if ( obj == m_find.out__p )
				setGuiMode( HEX_LIST_OUT );
			else
				setGuiMode( -1 );
		}
	}
	event.Skip( true );
}
void hexLib::guiMode_dd_onchange( wxCommandEvent& event ) { setGuiMode( guiMode_dd->GetSelection() ); }
void hexLib::set_b_onclick( wxCommandEvent& event ) { *m_now = *m_tmp; }
void hexLib::get_b_onclick( wxCommandEvent& event ) { *m_tmp = *m_now; }
void hexLib::name_txt_onchange( wxCommandEvent& event )
{
	if ( m_tmp != NULL )
	{
		wxTextCtrl* obj = ( wxTextCtrl* )( event.GetEventObject() );
		m_tmp->name = obj->GetValue();
	}
	event.Skip();
}
void hexLib::file_txt_onchange( wxCommandEvent &event )
{
	if ( m_tmp != NULL )
	{
		wxTextCtrl* obj = ( wxTextCtrl* )( event.GetEventObject() );
		Org* tmp = ( Org* )m_tmp;
		tmp->file = obj->GetValue();
	}
	event.Skip();
}
void hexLib::addr_txt_onchange( wxCommandEvent &event )
{
	if ( m_addr != NULL )
	{
		wxTextCtrl* obj = (wxTextCtrl*)(event.GetEventObject());
		GetHex( m_addr, obj->GetValue(), 8u );
		obj->ChangeValue( GetTxt( m_addr, 8u ) );
	}
	event.Skip();
}
void hexLib::val__txt_onchange( wxCommandEvent &event )
{
	wxTextCtrl* obj = (wxTextCtrl*)( event.GetEventObject() );
	if ( m__val != NULL )
	{
		GetHex( *m__val, obj->GetValue(), *m_size );
		obj->ChangeValue( GetTxt( *m__val, *m_size ) );
	}
	else
	{
		*m_cVal = 0u;
		GetHex( m_cVal, obj->GetValue(), *m_size );
		obj->ChangeValue( GetTxt( m_cVal, *m_size ) );
	}
	event.Skip();
}
// Other Stuff
bool hexLib::M_BASE::m_main_connect( dBase *now, dBase *old, dBase *tmp )
{
	if ( m_isMainConnected )
		return false;
	bool fail = false;
	Text msg = m_lang->text[ m_lang->txt_thefollowingarestillnull ];
	if ( new_b == NULL )
	{
		msg += wxT("\nnew_b");
		fail = true;
	}
	if ( del_b == NULL )
	{
		msg += wxT("\ndel_b");
		fail = true;
	}
	if ( set_b == NULL )
	{
		msg += wxT("\nset_b");
		fail = true;
	}
	if ( get_b == NULL )
	{
		msg += wxT("\nget_b");
		fail = true;
	}
	if ( fail )
	{
		wxMessageBox( msg, m_lang->text[ m_lang->txt_error ] );
		return false;
	}
	m_lib->m_base = this;
	m_lib->m_now = now;
	m_lib->m_old = old;
	m_lib->m_tmp = tmp;
	name_txt->Connect( name_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::name_txt_onchange ), NULL, m_lib );
	new_b->Connect( new_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::new_b_onclick ), NULL, m_lib );
	del_b->Connect( del_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::del_b_onclick ), NULL, m_lib );
	set_b->Connect( set_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::set_b_onclick ), NULL, m_lib );
	get_b->Connect( get_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::get_b_onclick ), NULL, m_lib );
	return true;
}
bool hexLib::M_BASE::m_main_disconnect( void )
{
	if ( !m_isMainConnected )
		return false;
	m_lib->m_base = NULL;
	m_lib->m_now = NULL;
	m_lib->m_old = NULL;
	m_lib->m_tmp = NULL;
	name_txt->Disconnect( name_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::name_txt_onchange ), NULL, m_lib );
	new_b->Disconnect( new_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::new_b_onclick ), NULL, m_lib );
	del_b->Disconnect( del_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::del_b_onclick ), NULL, m_lib );
	set_b->Disconnect( set_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::set_b_onclick ), NULL, m_lib );
	get_b->Disconnect( get_b->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::get_b_onclick ), NULL, m_lib );
	return true;
}
hexLib::M_LOAD::M_LOAD( void )
{
	desIsTmp	= false;
	saveChanges	= false;
	des = NULL;
	src = NULL;
	m_lang = NULL;
}
bool hexLib::M_LOAD::check( void )
{
	Text msg;
	if ( des == NULL )
		msg += wxT("\ndes");
	if ( src == NULL )
		msg += wxT("\nsrc");
	if ( !msg.empty() )
	{
		if ( m_lang == NULL )
		{
			wxMessageBox( wxT("m_lang cannot be NULL"), m_lang->text[ m_lang->txt_error ] );
			return false;
		}
		wxMessageBox( m_lang->text[ m_lang->txt_thefollowingarestillnull ] + msg,
			m_lang->text[ m_lang->txt_error ] );
		return false;
	}
	return true;
}
// State
void hexLib::M_STATE::main_connect( void )
{
	if ( !m_main_connect( &m_now, &m_old, &m_tmp ) )
		return;
}
void hexLib::M_STATE::main_disconnect( void )
{
	if ( !m_main_disconnect() )
		return;
}
void hexLib::M_STATE::name_dd_onchange( wxCommandEvent& event )
{
	getState( name_dd->GetString( name_dd->GetSelection() ) );
}