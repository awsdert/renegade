#include "GetDBP_DLG.h"
s32  GetDBP_DLG::dNewDBP( DBP dbp )
{
	s32 index = -1;
	s32 count = dGetCount();
	if ( count < 65535 )
	{
		dDBPList.push_back( dbp );
		index = count;
	}
	return index;
}
s32  GetDBP_DLG::dNewDBI( DBI* dbi )
{
	s32 index = -1;
	s32 count = dDBPName_LB->GetCount();
	if ( count < 65535 )
	{
		DBI* now  = dGetDBI( dbi );
		DBP  dbp  = dGetDBP( now->index );
		index     = dDBPName_LB->Append( dbp.nowName, now );
	}
	return index;
}
void GetDBP_DLG::dSetDBP( s32 index, DBP dbp )
{
	if ( index < 0 || index >= dGetCount() )
		throw std::out_of_range( "Tried to set DBP outside range" );
	dDBPList[ index ] = dbp;
}
void GetDBP_DLG::dSetDBI( s32 index, DBI* dbi )
{
	if ( index < 0 || index >= ( s32 )dDBPName_LB->GetCount() )
		throw std::out_of_range( "Tried to set DBI outside range" );
	DBI* now = dGetDBI( dbi );
	DBP  dbp = dGetDBP( dbi->index );
	dDBPName_LB->SetString( index, dbp.nowName );
	dDBPName_LB->SetClientObject( index, now );
}
DBP& GetDBP_DLG::dGetDBP( s32  index )
{
	if ( index < 0 || index >= dGetCount() )
		throw std::out_of_range( "Tried to get DBP outside range" );
	u16 safe_index = index;
	return dDBPList[ safe_index ];
}
DBP  GetDBP_DLG::dGetDBP( void )
{
	xStr text;
	DBP  dbp;
	dbp.isDefault = false;
	text          = dDBPName_TXT->GetValue();
	if ( !text.IsEmpty() )
	{
		dbp.nowName = text;
		dbp.oldName = text;
	}
	text           = dDBPFile_TXT->GetValue();
	if ( !text.IsEmpty() )
	{
		dbp.nowFile = text;
		dbp.oldFile = text;
	}
	dbp.PID         = GetHex( dDBPPID_TXT->GetValue(), 2u );
	dbp.SID         = dDBPSID_TXT->GetValue();
	dbp.notes       = dDBPNotes_TA->GetValue();
	return dbp;
}
DBI* GetDBP_DLG::dGetDBI( DBI* dbi   )
{
	DBI* now   = new DBI;
	now->index = dbi->index;
	return now;
}
DBI* GetDBP_DLG::dGetDBI( s32  index )
{
	if ( index < 0 || index >= ( s32 )dDBPName_LB->GetCount() )
		throw std::out_of_range( "Tried to get DBI outside range" );
	return ( DBI* )dDBPName_LB->GetClientObject( index );
}
void GetDBP_DLG::dDelDBI( s32 index )
{
	DBI* dbi = dGetDBI( index );
	DBP  dbp = dGetDBP( dbi->index );
	if ( dbp.isDefault ) return;
	dDelDBP( dbi->index );
	dLoadDBI();
	if ( index < 1 ) dDBPName_LB->Select( 0 );
	else dDBPName_LB->Select( index - 1 );
	isModified = true;
}
void GetDBP_DLG::dDelDBP( s32 index )
{
	if ( index < 0 || index >= dGetCount() ) return;
	DBP  dbp = dGetDBP( index );
	if ( dbp.isDefault ) return;
	dDBPList.erase( dDBPList.begin() + index );
}
s32  GetDBP_DLG::dGetCount( void )
{
	s32 count = dDBPList.size();
	return count;
}
void GetDBP_DLG::dShowDBP( void )
{
	s32  index = dDBPName_LB->GetSelection();
	if ( index < 0 ) return;
	DBI* dbi   = dGetDBI( index );
	DBP& dbp   = dGetDBP( dbi->index );
	dDBPName_TXT->ChangeValue( dbp.nowName );
	dDBPFile_TXT->ChangeValue( dbp.nowFile );
	xStr text;
	text.Printf( hex16, dbp.PID );
	dDBPPID_TXT->ChangeValue( text );
	dDBPSID_TXT->ChangeValue( dbp.SID );
	dDBPNotes_TA->ChangeValue( dbp.notes );
	gSetDBP( dbp );
	dSetDBP_P->Enable( !dbp.isDefault );
}
