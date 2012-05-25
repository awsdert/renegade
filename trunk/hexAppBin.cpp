#include "cleanAll.h"
BIN  gBin;
void gGetBinFile( xStr &path, xStr &file )
{
	ORG org = gGetOrg();
	PFM pfm = gGetPFM();
	gGetPFMFile( path, file );
	path   += org.oldFile + gGetSlash();
	if ( !wxDirExists( path ) ) wxMkdir( path );
	file    = path + pfm.oldFile + wxT( ".hexb" );
	if ( !wxFileExists( file ) )
	{
		wxTextFile tmp_TF;
		tmp_TF.Create( file );
	}
}
void gSetBin( BIN  bin ) { gBin = bin;  }
BIN  gGetBin( void     ) { return gBin; }
