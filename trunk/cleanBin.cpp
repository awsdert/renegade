#include "G.h"
#include "GetBin_DLG.h"
BIN G::mGetBin( void )
{
	xStr text;
	BIN  bin;
	text       = binName_TXT->GetValue();
	if ( !text.IsEmpty() ) bin.nowName = text;
	text       = binFile_TXT->GetValue();
	if ( !text.IsEmpty() ) bin.nowFile = text;
	bin.bind   = binBind_TXT->GetValue();
	bin.path   = binPath_TXT->GetValue();
	bin.isFile = isFile_RB->GetValue();
	return bin;
}
void G::mShowBin( void )
{
	BIN bin = gGetBin();
	hookApp = !bin.isFile;
	binName_TXT->ChangeValue( bin.nowName );
	binFile_TXT->ChangeValue( bin.nowFile );
	binPath_TXT->ChangeValue( bin.path );
	binBind_TXT->ChangeValue( bin.bind );
	isApp_RB->SetValue(    !bin.isFile );
	isFile_RB->SetValue(    bin.isFile );
	ramName_D->Clear();
	findRam_D->Clear();
	 outRAM_D->Clear();
	editRam_D->Clear();
	RAM  ram;
	xStr text;
	s8   index = 0;
	s8   count = bin.GetCount();
	for ( ; index < count; ++index )
	{
		ram  = bin.p_data[ index ];
		text = ram.name;
		ramName_D->Append( text );
		findRam_D->Append( text );
		 outRAM_D->Append( text );
		editRam_D->Append( text );
	}
	gEnable( !bin.isDefault, bin_P );
	gEnable( !bin.isDefault, ram_P );
	if ( count > 0 )
	{
		ramName_D->Select( 0 );
		findRam_D->Select( 0 );
		 outRAM_D->Select( 0 );
		editRam_D->Select( 0 );
		mShowRam();
	}
}
void G::mSaveBin( void )
{
	RAM  ram;
	BIN  bin = gGetBin();
	if ( bin.isDefault ) return;
	xStr key, text, path, file;
	gGetBinFile( path, file );
	wxFileConfig cfgBin( gGetTitle(), gGetVendor(), file );
	cfgBin.DeleteGroup( bin.oldName );
	cfgBin.SetPath(     bin.nowName );
	key  = wxT( "data" );
	if ( bin.isFile ) text = wxT( ";file" );
	else text = wxT( ";app" );
	cfgBin.Write( key, text + bin.nowFile + wxT( ";" ) +
				bin.bind + wxT( ";" ) + bin.path );
	u8 j, jCount = bin.GetCount();
	for ( j = 0u; j < jCount; ++j )
	{
		ram = bin[ j ];
		key.Printf( wxT( "%X" ), j );
		text.Printf( wxT( ";%X;%llX;%llX" ),
					ram.ptrDepth, ram.byte, ram.size );
		cfgBin.Write( key, ram.name + text );
	}
}
void G::mLoadBin( void )
{
	GetBin_DLG d( this );
	d.ShowModal();
	mShowBin();
}
void G::mListBin_OnClick( wxCommandEvent& event )
{
	mLoadBin();
}
void G::mLoadBin_OnClick( wxCommandEvent& event )
{
	mLoadBin();
}
void G::mSaveBin_OnClick( wxCommandEvent& event )
{
	mSaveBin();
	xStr text = wxFileSelector();
}
void G::mSetBin_OnClick( wxCommandEvent& event )
{
	gSetBin( mGetBin() );
}
void G::HookBin_BOnClick(  wxCommandEvent& event )
{
	listUntil = 0u;
	ListApps_D->Select( 0 );
	UseHook_D->Select( 1 );
	SetTime( hookAdd, 1 );
	UseHook();
}
void G::UseHook_DOnChoice( wxCommandEvent& event )
{
	listUntil = 0u;
	ListApps_D->Select( 0 );
	s32 mode  = UseHook_D->GetSelection();
	SetTime( hookAdd, mode );
	if ( mode > 0 )
	{
		UseHook();
	}
}
void G::binPath_BOnClick( wxCommandEvent& event ) {}
void G::binBind_BOnClick( wxCommandEvent& event ) {}
void G::LaunchBin_BOnClick( wxCommandEvent& event ) {}
