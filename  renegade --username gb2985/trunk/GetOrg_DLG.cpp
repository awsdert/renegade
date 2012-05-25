#include "GetOrg_DLG.h"

GetOrg_DLG::GetOrg_DLG( wxWindow* parent )
:
cleanGetOrg_DLG( parent )
{
	orgIni   = wxT( "Organisation" );
	ORG* org = new ORG;
	dNewOrg( org );
	delete org;
	dLoadOrg();
}
void GetOrg_DLG::GetOrg_DLGOnClose(     wxCloseEvent&   event )
{
	dShowOrg();
	event.Skip();
}
void GetOrg_DLG::dOrgName_LBOnSelect( wxCommandEvent& event )
{
	dShowOrg();
}
void GetOrg_DLG::dLoadOrg_OnClick(   wxCommandEvent& event )
{
	dLoadOrg();
}
void GetOrg_DLG::dSaveOrg_OnClick(   wxCommandEvent& event )
{
	dSaveOrg();
}
void GetOrg_DLG::dNewOrg_OnClick(    wxCommandEvent& event )
{
	ORG* org = dGetOrg();
	s8 index = dNewOrg( org );
	delete org;
	dOrgName_LB->Select( index );
	dShowOrg();
}
void GetOrg_DLG::dSetOrg_OnClick(    wxCommandEvent& event )
{
	s8 index = dOrgName_LB->GetSelection();
	ORG* org = dGetOrg( index );
	if ( !org->isDefault )
	{
		org = dGetOrg();
		dSetOrg( index, org );
		delete org;
		dShowOrg();
	}
}
void GetOrg_DLG::dUseOrg_OnClick(    wxCommandEvent& event )
{
	gClose( this );
}
void GetOrg_DLG::dDelOrg_OnClick(    wxCommandEvent& event )
{
	s8 index = dOrgName_LB->GetSelection();
	ORG* org = dGetOrg( index );
	if ( !org->isDefault )
	{
		dOrgName_LB->Delete( index );
		index = ( index > 0 ) ? index - 1 : 0;
		dOrgName_LB->Select( index );
		dShowOrg();
	}
}
