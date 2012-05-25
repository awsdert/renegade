#include "GetOrg_DLG.h"
void GetOrg_DLG::dLoadOrg( void )
{
	bool  atKey    = false;
	long  i        = 0;
	ORG*  org;
	xStr  text, path, file, name;
	gGetOrgFile( path, file );
	s8    index    = dOrgName_LB->GetCount();
	for ( --index; index >= 0; --index )
	{
		org = dGetOrg( index );
		if ( !org->isDefault ) dOrgName_LB->Delete( index );
	}
	org            = new ORG;
	org->isDefault = false;
	wxFileConfig cfgIni( gGetTitle(), gGetVendor(), file );
	cfgIni.SetPath( orgIni );
	for
	(
		atKey = cfgIni.GetFirstEntry( name, i );
		atKey;
		atKey = cfgIni.GetNextEntry(  name, i )
	)
	{
		org->oldName = name;
		org->nowName = name;
		text         = cfgIni.Read( name, name );
		org->oldFile = text;
		org->nowFile = text;
		dNewOrg( org );
	}
	delete org;
	dOrgName_LB->Select( 0 );
	dShowOrg();
}
void GetOrg_DLG::dSaveOrg( void )
{
	ORG*  org;
	xStr  text, path, file, name;
	gGetOrgFile( path, file );
	s8    i      = 1;
	s8    iCount = dOrgName_LB->GetCount();
	wxFileConfig cfgIni( gGetTitle(), gGetVendor(), file );
	cfgIni.DeleteGroup( orgIni );
	cfgIni.SetPath(     orgIni );
	for ( ; i < iCount; ++i )
	{
		org  = dGetOrg( i );
		if ( !org->isDefault )
		{
			file = path + org->oldFile + wxT( ".hexp" );
			if ( wxFileExists( file ) )
			{
				wxRenameFile( file, path + org->nowFile + wxT( ".hexp" ) );
			}
			org->oldFile = org->nowFile;
			cfgIni.Write( org->nowName, org->nowFile );
		}
	}
}
