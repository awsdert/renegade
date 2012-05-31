#include "GetDBP_DLG.h"

GetDBP_DLG::GetDBP_DLG( wxWindow* parent )
:
cleanGetDBP_DLG( parent )
{
	s32 index;
	dAreaGet_CB.resize( AREA_COUNT );
	dAreaSet_CB.resize( AREA_COUNT );
	xAStr fArea = gGetArea();
	for ( index = 0; index < AREA_COUNT; ++index )
	{
		dAreaGet_CB[ index ] = new wxCheckBox( dGetAreaCB_P, wxID_ANY, fArea[ index ] );
		dAreaSet_CB[ index ] = new wxCheckBox( dSetAreaCB_P, wxID_ANY, fArea[ index ] );
		dGetAreaCB_LG->Add( dAreaGet_CB[ index ], 0, wxBORDER | wxALL, 5 );
		dSetAreaCB_LG->Add( dAreaSet_CB[ index ], 0, wxBORDER | wxALL, 5 );
		dAreaGet_CB[ index ]->SetValue( true );
		dAreaSet_CB[ index ]->SetValue( true );
	}
	dSetDBP_P->Fit();
	dLoadDBP();
}
void GetDBP_DLG::dUseDBP_OnClick(    wxCommandEvent& event ) { gClose( this ); }
void GetDBP_DLG::dNewDBP_OnClick(    wxCommandEvent& event )
{
	DBI* dbi   = new DBI;
	DBP  dbp   = dGetDBP();
	dbi->index = dNewDBP( dbp );
	dNewDBI( dbi );
	delete dbi;
	dLoadDBI();
	isModified = true;
}
void GetDBP_DLG::dSetDBP_OnClick(     wxCommandEvent& event )
{
	s32  i   = dDBPName_LB->GetSelection();
	DBI* dbi = dGetDBI( i );
	DBP  dbp = dGetDBP( dbi->index );
	if ( dbp.isDefault ) return;
	dbp      = dGetDBP();
	dLoadDBI();
	isModified = true;
}
void GetDBP_DLG::dGetDBP_OnClick(     wxCommandEvent& event ) { dShowDBP(); }
void GetDBP_DLG::dDelDBP_OnClick(     wxCommandEvent& event )
{
	s32  i   = dDBPName_LB->GetSelection();
	dDelDBI( i );
}
void GetDBP_DLG::dLoadDBP_OnClick(    wxCommandEvent& event ) { dLoadDBP(); }
void GetDBP_DLG::dSaveDBP_OnClick(    wxCommandEvent& event ) { dSaveDBP(); }
void GetDBP_DLG::dSetArea_RBOnClick(  wxCommandEvent& event )
	{ gEnable( dSetAreaSel_RB->GetValue(), dSetAreaCB_P ); }
void GetDBP_DLG::dDBPName_LBOnSelect( wxCommandEvent& event ) { dShowDBP(); }
void GetDBP_DLG::GetDBP_DLGOnClose(   wxCloseEvent&   event )
{
	if ( isModified )
	{
		switch ( MB( wxT( "Do you wish to save changes?" ), wxT("List is Modified"), wxYES_NO | wxCANCEL ) )
		{
			case wxYES: dSaveDBP(); break;
			case wxCANCEL: return;
		}
	}
	s32 index = dDBPName_LB->GetSelection();
	if ( index < 0 ) index = 0;
	s32 count = dDBPName_LB->GetCount();
	if ( count > 0 )
	{
		DBI*  dbi = dGetDBI( index );
		DBP   dbp = dGetDBP( dbi->index );
		gSetDBP( dbp );
		for ( index = count; index >= 0; index-- )
		{
			dDBPName_LB->Delete( index );
		}
	}
	dDBPList.clear();
	 dIdList.clear();
	dAreaGet_CB.clear();
	dAreaSet_CB.clear();
	event.Skip();
}
