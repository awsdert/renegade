#include "GetBin_DLG.h"

GetBin_DLG::GetBin_DLG( wxWindow* parent )
:
cleanGetBin_DLG( parent )
{
	BIN* bin = new BIN;
	dNewBin( bin );
	delete bin;
	dLoadBin();
}
void GetBin_DLG::GetBin_DLGOnClose( wxCloseEvent& event )
{
	dShowBin();
	event.Skip();
}
void GetBin_DLG::dOrgName_LBOnSelect( wxCommandEvent& event )
{
	dShowBin();
}
void GetBin_DLG::dBinPath_BOnClick( wxCommandEvent& event )
{
	wxDirDialog pathDlg( this );
	if ( pathDlg.ShowModal() == wxID_OK )
		dBinPath_TXT->ChangeValue( pathDlg.GetPath() );
}

void GetBin_DLG::dBinBind_BOnClick( wxCommandEvent& event )
{
	wxFileDialog fileDlg( this );
	if ( fileDlg.ShowModal() == wxID_OK )
	{
		xAStr array;
		fileDlg.GetFilenames( array );
		if ( array.GetCount() > 0 )
			dBinBind_TXT->ChangeValue( array[ 0 ] );
	}
}
void GetBin_DLG::dUseBin_OnClick( wxCommandEvent& event )
{
	gClose( this );
}
void GetBin_DLG::dLoadBin_OnClick( wxCommandEvent& event )
{
	dLoadBin();
}
void GetBin_DLG::dSaveBin_OnClick( wxCommandEvent& event )
{
	dSaveBin();
}
void GetBin_DLG::dNewBin_OnClick( wxCommandEvent& event )
{
	BIN* bin = dGetBin();
	s8 index = dNewBin( bin );
	delete bin;
	dBinName_LB->Select( index );
	dShowBin();
}
void GetBin_DLG::dSetBin_OnClick( wxCommandEvent& event )
{
	s8   index = dBinName_LB->GetSelection();
	if ( index < 0 ) return;
	BIN* bin   = dGetBin( index );
	if ( !bin->isDefault )
	{
		bin = dGetBin();
		dSetBin( index, bin );
		delete bin;
		dShowBin();
	}
}
void GetBin_DLG::dDelBin_OnClick( wxCommandEvent& event )
{
	s8   index = dBinName_LB->GetSelection();
	if ( index < 0 ) return;
	BIN* bin   = dGetBin( index );
	if ( !bin->isDefault )
		dBinName_LB->Delete( index );
}
void GetBin_DLG::dNewRam_BOnClick( wxCommandEvent& event )
{
	s8   index = dBinName_LB->GetSelection();
	BIN* bin   = dGetBin( index );
	if ( !bin->isDefault )
	{
		RAM ram = dGetRam();
		index   = bin->Append( ram );
		dRamName_D->Append( ram.name );
		dRamName_D->Select( index );
		dShowRam();
	}
}
void GetBin_DLG::dSetRam_BOnClick( wxCommandEvent& event )
{
	s8   index = dBinName_LB->GetSelection();
	BIN* bin   = dGetBin( index );
	if ( !bin->isDefault )
	{
		index  = dRamName_D->GetSelection();
		if ( index >= 0 )
		{
			RAM ram                = dGetRam();
			( *bin )[ (u8) index ] = ram;
			dRamName_D->SetString( index, ram.name );
			dRamName_D->Select( index );
			dShowRam();
		}
	}
}
