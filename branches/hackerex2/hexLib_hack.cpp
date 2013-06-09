#include "wx_pch.h"
#include "hexLib_main.h"

void M_HACK::lib_show( void )
{
	if ( m_id < 0 )
		return;
	bool show = m_obj.isActive;
	bool isRB = ( m_id > 0 && m_tmp[ m_obj.parent ].isRadio );
	tbox_name->ChangeValue( m_obj.name );
	tbox_name->Enable( m_id > 0 );
	cb___active->SetValue( show );
	rb___active->SetValue( show );
	cb___active->Show( !isRB );
	rb___active->Show( isRB );
	dd___kids->SetSelection( m_obj.isRadio ? 0 : 1 );
}

void M_HACK::lib_connect( void )
{
	if ( m_libC )
		return;
	codeGui->lib_disconnect();
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
void M_HACK::lib_disconnect( void )
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

void M_HACK::tree_main_onselect( wxTreeEvent& event )
{
	m_tmp[ m_id ] = m_obj;
	TrID* data = (TrID*)tree_main->GetItemData( event.GetItem() );
	m_obj = m_tmp[ data->index ];
	m_id = data->index;
	m_lib->setGuiMode( HEX_LIST_HACK );
}