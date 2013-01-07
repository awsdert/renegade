#include "wx_pch.h"
#include "hex2_G.h"
bool G::EditHasInvalidName( Text& name )
{
	wxMessageBox( _("You cannot use the name \"") + name + _("\", data will be lost on exiting this mode."), _("Commit") );
	return false;
}
void G::EditData( hexDB& db )
{
	bool use = false;
	int inMode = m_siListNow;
	switch ( inMode )
	{
	case HEX_LIST_ORG:
		use = EditOrgD( &( db.org ) );
		break;
	case HEX_LIST_PFM:
		use = EditPfmD( db.pfm );
		break;
	case HEX_LIST_BIN:
		use = EditBinD( db.bin );
		break;
	case HEX_LIST_RAM:
		use = true;
		EditRamD( db.bin[ db.ramNo ] );
		break;
	case HEX_LIST_PFL:
		use = EditPflD( db.pfl );
		break;
	case HEX_LIST_HACK:
		use = EditHack( db.hacks, db.hacks.hackNow );
		break;
	}
	if ( !use )
		return;
	db.nowM[ inMode ] = true;
}
bool G::EditOrgD( Org* obj )
{
	Text name = HexName_TXT->GetValue();
	if ( name == m_db.getDefN() )
		return EditHasInvalidName( name );
	obj->nameNow = name;
	obj->fileNow = HexFile_TXT->GetValue();
	return true;
}
bool G::EditPfmD( Pfm& obj )
{
	if ( !EditOrgD( &obj ) )
		return false;
	obj.endian = HexEndian_DD->GetSelection();
	return true;
}
bool G::EditBinD( Bin& obj )
{
	if ( !EditOrgD( &obj ) )
		return false;
	obj.name = HexBinBind_TXT->GetValue();
	obj.path = HexBinPath_TXT->GetValue();
	if ( HexBinApp_RB->GetValue() )
		obj.type = 1u;
	else if ( HexBinWin_RB->GetValue() )
		obj.type = 2u;
	else
		obj.type = 0u;
	return true;
}
void G::EditRamD( Ram& obj )
{
	obj.name = HexName_TXT->GetValue();
	GetHex( &( obj.addr ), HexAddr_TXT->GetValue(), 8u );
	obj.depth = HexDepth_SL->GetValue();
	GetHex( &( obj.bytes ), HexRamSize_TXT->GetValue(), 8u );
}
bool G::EditPflD( Pfl& obj )
{
	if ( !EditOrgD( &obj ) )
		return false;
	GetHex( &( obj.profile ), HexPID_TXT->GetValue(), 2u );
	obj.serial	= HexSID_TXT->GetValue();
	obj.notes	= HexNotes_TA->GetValue();
	obj.region	= EditRegion();
	return true;
}
ui32 G::EditRegion( void )
{
	ui32 region = 0u;
	int iEnd = getRegionCount();
	Text txt;
	ui32* regions = new ui32[ iEnd ];
	getRegions( regions );
	for ( int i = 0; i < iEnd; ++i )
	{
		if ( HexRegion_CLB->IsChecked( i ) )
			region |= regions[ i ];
	}
	delete [] regions;
	return region;
}
bool G::EditHack( Hacks& data, int hackNo )
{
	if ( hackNo < 0 )
		return false;
	Hack& obj = data[ hackNo ];
	Text name = HexName_TXT->GetValue();
	if ( hackNo > 0 )
	{
		if ( name == m_db.getDefN( HEX_LIST_HACK ) )
			return EditHasInvalidName( name );
		else
			obj.name = name;
	}
	obj.info = 0u;
	if ( HexUse_CB->GetValue() )
		obj.info |= HACK_USE;
	if ( HexHackKids_DD->GetSelection() == 0 )
		obj.info |= HACK_RL;
	data[ hackNo ] = obj;
	return true;
}
bool G::EditCode( Code& obj )
{
	obj.type = HexCType_DD->GetSelection();
	const bool isTest = ( obj.type == HEX_CT_TEST );
	const bool isList = ( obj.type == HEX_CT_LIST );
	const bool isCopy = ( obj.type == HEX_CT_COPY );
	const bool isInc  = ( !isTest && !isCopy && !isList );
	ui16 v16 = 0u;
	GetHexFromUI( &v16, HexLoop_TXT->GetValue(), 2u );
	if ( isInc )
	{
		obj.info = ( obj.info & 0xFFF0 );
		switch ( HexInc_DD->GetSelection() )
		{
			case 1: obj.info |= HEX_CT_DEC; break;
			case 2: case 3: break; // NOTE: Code value *= and /= not available yet.
		}
		EditCodeValue( HexInc_TXT, obj, 1 );
	}
	EditCodeValue( HexVal_TXT, obj, 0 );
	return true;
}
void G::EditCodeValue( wxTextCtrl* tbox, Code& obj, int v )
{
	Text txt = tbox->GetValue();
	ui64 v64 = 0u;
	switch ( obj.hex )
	{
		case HEX_TYPE_HEX:	GetHex( &v64, txt, obj.bytes ); break;
		case HEX_TYPE_UI:	GetHexFromUI( &v64, txt, obj.bytes );
			txt.Printf( wxT("%01llu"), v64 ); break;
		case HEX_TYPE_SI:	GetHexFromSI( &v64, txt, obj.bytes );
			txt.Printf( wxT("%01lli"), v64 ); break;
	}
	switch ( obj.bytes )
	{
		case 8u: *( reinterpret_cast< ui64* >( &( obj[ v ] ) ) ) = v64; break;
		case 4u: *( reinterpret_cast< ui32* >( &( obj[ v ] ) ) ) = v64; break;
		case 2u: *( reinterpret_cast< ui16* >( &( obj[ v ] ) ) ) = v64; break;
		default: obj[v] = v64;
	}
	tbox->ChangeValue( txt );
}
