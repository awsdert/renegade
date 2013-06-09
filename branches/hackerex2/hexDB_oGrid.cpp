#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
/* *
bool M_FIND::find_m_check( void )
{
	int i, j;
	bool isNull = ( new__b == NULL || dump_b == NULL || must_p == NULL || any__p == NULL || none_p == NULL );
	if ( !isNull && !m_madeMAN )
	{
		m_MeqA = ( must_p == any__p );
		m_MeqN = ( must_p == none_p );
		for ( i = HEX_QDC; ( i < HEX_QCOUNT && !isNull ); ++i )
		{
			for ( j = 0; j < 16; ++j )
			{
				vm[ i ][ j ] = 0u;
				va[ i ][ j ] = 0u;
				vn[ i ][ j ] = 0u;
			}
			isNull = ( q_b[ i ] == NULL );
			vm__cb[ i ] = new wxCheckBox( must_p, 5000 + i, m_vtxt[ i ] );
			vm_txt[ i ] = new wxTextCtrl( must_p, 5010 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
			vm_lfg->Add( vm__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
			vm_lfg->Add( vm_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			if ( !m_MeqA )
			{
				va__cb[ i ] = new wxCheckBox( must_p, 5020 + i, m_vtxt[ i ] );
				va_txt[ i ] = new wxTextCtrl( must_p, 5030 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
				va_lfg->Add( vm__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
				va_lfg->Add( vm_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			}
			if ( !m_MeqN )
			{
				vn__cb[ i ] = new wxCheckBox( must_p, 5040 + i, m_vtxt[ i ] );
				vn_txt[ i ] = new wxTextCtrl( must_p, 5050 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
				vn_lfg->Add( vm__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
				vn_lfg->Add( vm_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			}
		}
		for ( i = 0; ( i < HEX_ACOUNT && !isNull ); ++i )
		{
			am[ i ] = 0uLL; aa[ i ] = 0uLL; an[ i ] = 0uLL;
			am__cb[ i ] = new wxCheckBox( must_p, 5100 + i, m_atxt[ i ] );
			am_txt[ i ] = new wxTextCtrl( must_p, 5110 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
			am_lfg->Add( am__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
			am_lfg->Add( am_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			if ( !m_MeqA )
			{
				aa__cb[ i ] = new wxCheckBox( must_p, 5120 + i, m_atxt[ i ] );
				aa_txt[ i ] = new wxTextCtrl( must_p, 5130 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
				aa_lfg->Add( am__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
				aa_lfg->Add( am_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			}
			if ( !m_MeqN )
			{
				an__cb[ i ] = new wxCheckBox( must_p, 5140 + i, m_atxt[ i ] );
				an_txt[ i ] = new wxTextCtrl( must_p, 5150 + i, wxT("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
				an_lfg->Add( am__cb[ i ], 0, wxALL | wxALIGN_CENTER_VERTICAL, 5 );
				an_lfg->Add( am_txt[ i ], 0, wxALL | wxEXPAND, 5 );
			}
		}
	}
	else
	{
		for ( i = HEX_QDC; ( i < HEX_QCOUNT && !isNull ); ++i )
			isNull = ( q_b[ i ] == NULL );
	}
	if ( isNull )
		wxMessageBox( wxT("Pointer/s not set, Events not connected"), wxT("Error") );
	return !isNull;
}
void M_OGRID::find_connect( void )
{
	if ( !find_m_check() )
		return;
	wxButton* btn = new__b;
	wxTextCtrl *vmt, *vat, *vnt;
	btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
	btn = dump_b;
	btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
	for ( int i = HEX_QDC; i < HEX_QCOUNT; ++i )
	{
		btn = q_b[ i ];
		btn->Connect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
		vmt = vm_txt[ i ]; vat = va_txt[ i ]; vnt = vn_txt[ i ];
		vmt->Connect( vmt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
		if ( !m_MeqA )
			vat->Connect( vat->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
		if ( !m_MeqN )
			vnt->Connect( vnt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
	}
}
void M_OGRID::find_disconnect( void )
{
	if ( !find_m_check() )
		return;
	wxButton* btn = new__b;
	wxTextCtrl *vmt, *vat, *vnt;
	btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
	btn = dump_b;
	btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
	for ( int i = HEX_QDC; i < HEX_QCOUNT; ++i )
	{
		btn = q_b[ i ];
		btn->Disconnect( btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( M_OGRID::find_onclick ), NULL, this );
		vmt = vm_txt[ i ]; vat = va_txt[ i ]; vnt = vn_txt[ i ];
		vmt->Disconnect( vmt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
		if ( !m_MeqA )
			vat->Disconnect( vat->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
		if ( !m_MeqN )
			vnt->Disconnect( vnt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexDB::val__onchange ), NULL, db );
	}
}
void M_OGRID::find_fillcmp( void )
{
	Text txt;
	qCmpA_dd->Clear();
	qCmpA_dd->Append( _("Dump") );
	for ( si16 i = 1; i <= qNo; ++i )
	{
		txt.Printf( wxT("Cmp to % 2i"), i );
		qCmpA_dd->Append( txt );
	}
	qCmpA_dd->Select( ( qNo < 0 ) ? 0 : qNo + 1 );
}
void M_OGRID::find_onclick( wxCommandEvent& event )
{
	//qNo = (qCmpA_dd->GetSelection() - 1);
	wxButton* btn = (wxButton*)event.GetEventObject();
	if ( btn == new__b )
	{
		qNo = -1;
		find_fillcmp();
		qType_dd->SetSelection( 0 );
		qType = -1;
	}
	else if ( btn == dump_b )
	{
		qType_dd->SetSelection( 0 );
		qType = -1;
	}
	else
	{
		for ( int i = HEX_QDC; i < HEX_QCOUNT; ++i )
		{
			if ( btn == q_b[ i ] )
			{
				qType_dd->SetSelection( i + 1 );
				qType = i;
			}
		}
	}
	find();
	event.Skip();
}
void M_OGRID::undo_onclick( wxCommandEvent& event )
{
	--qNo;
	find_fillcmp();
}
void M_OGRID::qType_onclick( wxCommandEvent& event )
{
	qType = event.GetSelection();
	if ( qType < 0 )
	{
		qType = 0;
		qType_dd->Select( 0 );
	}
	--qType;
}
void M_OGRID::valS_onshow( wxShowEvent& event )
{
#define LE_TOGGLE( m_o, m_h ) m_o->GetId(), wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( m_h ), NULL, this
#define LE_SELECT( m_o, m_h ) m_o->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( m_h ), NULL, this
	if ( event.GetShow() )
	{
		vType_dd->Connect( LE_SELECT( vType_dd, hexDB::valT_onchange ) );
		valS_clb->Connect( LE_TOGGLE( valS_clb, M_OGRID::valS_oncheck ) );
	}
	else
	{
		vType_dd->Disconnect( LE_SELECT( vType_dd, hexDB::valT_onchange ) );
		valS_clb->Disconnect( LE_TOGGLE( valS_clb, M_OGRID::valS_oncheck ) );
	}
}
void M_OGRID::valS_oncheck( wxCommandEvent& event )
{
	ui08 vs = 0u, i = event.GetInt();
	GetHex( &vs, valS_clb->GetString( i ) );
	qvSize[ vs - 1 ] = valS_clb->IsChecked( i );
	event.Skip();
}
/* */