#include "cleanAll.h"
HACK* gHack;
void gGetHackFile( xStr &path, xStr &file )
{
	DBP dbp = gGetDBP();
	gGetDBPFile( path, file );
	file    = path + dbp.oldFile + wxT( ".hexcl" );
	if ( !wxFileExists( file ) )
	{
		wxTextFile tmp_TF;
		tmp_TF.Create( file );
	}
}
HACK* gGetHack( void )       { return gHack; }
void  gSetHack( HACK* hack ) { gHack = hack; }
