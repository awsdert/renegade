#include "G.h"
#include "GetOrg_DLG.h"
ORG  G::mGetOrg(     void )
{
	ORG org;
	org.nowName = orgName_TXT->GetValue();
	org.nowFile = orgFile_TXT->GetValue();
	return org;
}
xStr G::mGetOrgFile( void )
{
	return gGetOrg().nowFile;
}
void G::mShowOrg( void )
{
	ORG org = gGetOrg();
	orgName_TXT->ChangeValue( org.nowName );
	orgFile_TXT->ChangeValue( org.nowFile );
	gEnable( !org.isDefault, SetOrg_P );
}
void G::mSaveOrg( void )
{
	ORG org = gGetOrg();
	if ( !org.isDefault )
	{
		xStr path, file;
		gGetOrgFile( path, file );
		wxFileConfig cfgIni( wxT( "HackerEX" ), wxT( "Shadow Flare Industries" ), file );
		cfgIni.SetPath( wxT( "Organisation" ) );
		cfgIni.DeleteEntry( org.oldName, false );
		path      += wxT( "org" ) + gGetSlash();
		file       = path + org.oldFile + wxT( ".hexp" );
		if ( !wxDirExists( path ) )
		{
			wxMkdir( path );
		}
		if ( wxFileExists( file ) )
		{
			wxRenameFile( file, org.nowFile + wxT( ".hexp" ) );
		}
		cfgIni.Write( org.nowName, org.nowFile );
	}
}
void G::mLoadOrg( void )
{
	GetOrg_DLG d( this );
	if ( d.ShowModal() == wxID_OK )
	{
		mShowOrg();
		mLoadPFM();
	}
}
void G::mListOrg_OnClick( wxCommandEvent& event )
{
	mLoadOrg();
}
void G::mLoadOrg_OnClick( wxCommandEvent& event )
{
	mLoadOrg();
}
void G::mSaveOrg_OnClick( wxCommandEvent& event )
{
	mSaveOrg();
}
void G::mSetOrg_OnClick( wxCommandEvent& event )
{
	gSetOrg( mGetOrg() );
}
