#include "GetPFM_DLG.h"

GetPFM_DLG::GetPFM_DLG( wxWindow* parent )
:
cleanGetPFM_DLG( parent )
{
	PFM* pfm = new PFM;
	dNewPFM( pfm );
	delete pfm;
	dLoadPFM();
}
void GetPFM_DLG::GetPFM_DLGOnClose(     wxCloseEvent&   event )
{
	dShowPFM();
	event.Skip();
}
void GetPFM_DLG::dPFMName_LBOnSelect( wxCommandEvent& event ) { dShowPFM(); }
void GetPFM_DLG::dLoadPFM_OnClick(   wxCommandEvent& event ) { dLoadPFM(); }
void GetPFM_DLG::dSavePFM_OnClick(   wxCommandEvent& event ) { dSavePFM(); }
void GetPFM_DLG::dNewPFM_OnClick(    wxCommandEvent& event )
{
	PFM* pfm = dGetPFM();
	dNewPFM( pfm );
	delete pfm;
	dShowPFM();
}

void GetPFM_DLG::dSetPFM_OnClick(    wxCommandEvent& event )
{
	s8 index = dPFMName_LB->GetSelection();
	PFM* pfm = dGetPFM( index );
	if ( !pfm->isDefault )
	{
		pfm = dGetPFM();
		dSetPFM( index, pfm );
		delete pfm;
	}
}

void GetPFM_DLG::dUsePFM_OnClick(    wxCommandEvent& event ) { gClose( this ); }
void GetPFM_DLG::dDelPFM_OnClick(    wxCommandEvent& event )
{
	s8 index = dPFMName_LB->GetSelection();
	PFM* pfm = dGetPFM( index );
	if ( !pfm->isDefault )
	{
		dPFMName_LB->Delete( index );
		index = ( index > 0 ) ? index - 1 : 0;
		dPFMName_LB->Select( index );
		dShowPFM();
	}
}
