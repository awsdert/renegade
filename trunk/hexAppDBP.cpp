#include "cleanAll.h"
DBP  gDBP;
void gGetDBPFile( xStr &path, xStr &file )
{
	PFM pfm = gGetPFM();
	BIN bin = gGetBin();
	gGetBinFile( path, file );
	path   += pfm.oldFile + gGetSlash();
	if ( !wxDirExists( path ) ) wxMkdir( path );
	file    = path + wxT( "default.hexdb" );
	if ( !wxFileExists( file ) )
	{
		wxTextFile tmp_TF;
		tmp_TF.Create( file );
	}
}
void gSetDBP( DBP  dbp ) { gDBP = dbp;  }
DBP  gGetDBP( void     ) { return gDBP; }
