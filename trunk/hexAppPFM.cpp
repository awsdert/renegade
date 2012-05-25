#include "cleanAll.h"
PFM  gPFM;
void gGetPFMFile( xStr &path, xStr &file )
{
	ORG  org   = gGetOrg();
	xStr slash = gGetSlash();
	path       = wxGetCwd()  + slash + wxT( "org" ) + slash;
	if ( !wxDirExists( path ) ) wxMkdir( path );
	file       = path + org.oldFile + wxT( ".hexp" );
	if ( !wxFileExists( file ) )
	{
		wxTextFile tmp_TF;
		tmp_TF.Create( file );
	}
}
void gSetPFM( PFM  pfm ) { gPFM = pfm;  }
PFM  gGetPFM( void     ) { return gPFM; }
