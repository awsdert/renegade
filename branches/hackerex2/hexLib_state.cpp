#include "hexLib_main.h"

M_STATE::M_STATE( void ) :
	M_NAME()
{
	//
}
void M_STATE::lib_show( void )
{
	tbox_name->ChangeValue(	m_tmp.name );
	lbl__org->SetLabel(		m_tmp.orgName );
	lbl__pfm->SetLabel(		m_tmp.pfmName );
	lbl__bin->SetLabel(		m_tmp.binName );
	lbl__pfl->SetLabel(		m_tmp.pflName );
	lbl__fmt->SetLabel(		m_tmp.fmtName );
}
// Connection of events
void M_STATE::lib_connect( void )
{
	if ( m_libC )
		return;
	name_connect();
	wxButton *btn;
	btn = btn_main[ BTN_LOAD ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__load_onclick ), null, m_lib );
	btn = btn_main[ BTN_SAVE ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__save_onclick ), null, m_lib );
	btn = btn_main[ BTN_NEW ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__new__onclick ), null, m_lib );
	btn = btn_main[ BTN_DEL ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__del__onclick ), null, m_lib );
	btn = btn_main[ BTN_SET ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__set__onclick ), null, m_lib );
	btn = btn_main[ BTN_GET ];
	if ( btn != null )
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__get__onclick ), null, m_lib );
	m_libC = true;
}
void M_STATE::lib_disconnect( void )
{
	if ( !m_libC )
		return;
	name_disconnect();
	wxButton *btn;
	btn = btn_main[ BTN_LOAD ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__load_onclick ), null, m_lib );
	btn = btn_main[ BTN_SAVE ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__save_onclick ), null, m_lib );
	btn = btn_main[ BTN_NEW ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__new__onclick ), null, m_lib );
	btn = btn_main[ BTN_DEL ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__del__onclick ), null, m_lib );
	btn = btn_main[ BTN_SET ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__set__onclick ), null, m_lib );
	btn = btn_main[ BTN_GET ];
	if ( btn != null )
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__get__onclick ), null, m_lib );
	m_libC = false;
}
void M_STATE::main_connect( void )
{
	if ( m_mainC )
		return;
	if ( p____main != null && p____name == null )
	{
		p____main->Connect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M_STATE::p____main_onfocus ), null, this );
		p____main->Connect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M_STATE::p____main_onblur ), null, this );
		lib_connect();
		m_mainC = true;
	}
}
void M_STATE::main_disconnect( void )
{
	lib_disconnect();
	if ( !m_mainC )
		return;
	p____main->Disconnect( p____main->GetId(), wxEVT_SET_FOCUS, wxFocusEventHandler( M_STATE::p____main_onfocus ), null, this );
	p____main->Disconnect( p____main->GetId(), wxEVT_KILL_FOCUS, wxFocusEventHandler( M_STATE::p____main_onblur ), null, this );
	m_mainC = false;
}
// Events
void M_STATE::p____main_onfocus( wxFocusEvent& event )
{
	m_lib->setGuiMode( HEX_LIST_STATE );
}
void M_STATE::p____main_onblur( wxFocusEvent &event )
{
	m_lib->setGuiMode( -1 );
}