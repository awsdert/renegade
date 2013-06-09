#include "hexLib_main.h"

M_FILE::M_FILE( void )
	: M_NAME()
{
	m_fileC = false;
	lbl__file = null;
	tbox_file = null;
}

void M_FILE::file_connect( void )
{
	if ( m_fileC )
		return;
	name_connect();
	if ( tbox_file != null )
		tbox_file->Connect( tbox_file->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::tbox_file_onchange ), null, m_lib );
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
	btn = btn_main[ BTN_DEL ];\
	if ( btn != null )\
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__del__onclick ), null, m_lib );
	btn = btn_main[ BTN_SET ];\
	if ( btn != null )\
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__set__onclick ), null, m_lib );
	btn = btn_main[ BTN_GET ];\
	if ( btn != null )\
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__get__onclick ), null, m_lib );
}

void M_FILE::file_disconnect( void )
{
	if ( !m_fileC )
		return;
	name_connect();
	if ( tbox_file != null )
		tbox_file->Disconnect( tbox_file->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::tbox_file_onchange ), null, m_lib );
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
	btn = btn_main[ BTN_DEL ];\
	if ( btn != null )\
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__del__onclick ), null, m_lib );
	btn = btn_main[ BTN_SET ];\
	if ( btn != null )\
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__set__onclick ), null, m_lib );
	btn = btn_main[ BTN_GET ];\
	if ( btn != null )\
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( hexLib::btn__get__onclick ), null, m_lib );
}