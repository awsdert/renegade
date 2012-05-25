#include "cleanCLS.h"
// Hook Tab
ORG::ORG( void )
{
	nowName   = wxT( "(Default)" );
	nowFile   = wxT( "default"   );
	oldName   = nowName;
	oldFile   = nowFile;
	isDefault = true;
}
ORG::~ORG( void )
{
	oldName.Clear();
	oldFile.Clear();
	nowName.Clear();
	nowFile.Clear();
}
PFM::PFM( void ) : ORG()
{
	endian = ENDIAN_LITTLE;
}
PFM::~PFM( void )
{
	endian = 0;
}
RAM::RAM( void )
{
	name     = wxT( "All Memory" );
	byte     = 0u;
	size     = 0u;
	ptrDepth = 0u;
}
RAM::~RAM( void )
{
	byte     = 0u;
	size     = 0u;
	ptrDepth = 0u;
}
// Results
OUTDATA::OUTDATA(    void ) { Clear(); }
OUTDATA::~OUTDATA(   void ) { Clear(); }
void OUTDATA::Clear( void )
{
	address = 0u;
	value   = 0u;
	size    = 0u;
}
// Database Tab
DBI::DBI(  void ) { index = -1; error = 0; }
DBI::~DBI( void ) { index = -1; error = 0; }
DBP::DBP(  void ) : ORG()
{
	area = AREA_ALL;
	PID  = 0u;
}
DBP::~DBP( void )
{
	area = 0u;
	PID  = 0u;
	SID.Clear();
	notes.Clear();
}
