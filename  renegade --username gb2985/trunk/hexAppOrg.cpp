#include "cleanAll.h"
ORG  gOrg;
void gGetOrgFile( xStr &path, xStr &file )
{
	path = wxGetCwd() + gGetSlash();
	file = path + wxT( "hex.ini" );
	if ( !wxFileExists( file ) )
	{
		wxTextFile tmp_TF;
		tmp_TF.Create( file );
	}
}
void gSetOrg( ORG  org ) { gOrg = org;  }
ORG  gGetOrg( void     ) { return gOrg; }
void gGetOrg( ORG* org, ORG* now )
{
	now->isDefault = org->isDefault;
	now->nowName   = org->nowName;
	now->oldName   = org->oldName;
	now->nowFile   = org->nowFile;
	now->oldFile   = org->oldFile;
}
