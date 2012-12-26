#include "hex2_G.h"
void G::ShowData( hexDB& db )
{
	Text name;
	int inMode = db.tmpMode;
	switch ( inMode )
	{
		case HEX_LIST_SESSION:
			name = db.state.nameNow;
			ShowStateD( db.state );
			break;
		case HEX_LIST_ORG:
			name = db.org.nameNow;
			ShowOrgD( &(db.org) );
			break;
		case HEX_LIST_PFM:
			name = db.pfm.nameNow;
			ShowPfmD( db.pfm );
			break;
		case HEX_LIST_BIN:
		case HEX_LIST_APP:
		case HEX_LIST_WIN:
		{
			Bin& obj3 = db.bin;
			name = ( inMode == HEX_LIST_BIN ) ? obj3.nameNow : obj3.name;
			ShowBinD( obj3 );
			break;
		}
		case HEX_LIST_PFL:
			name = db.pfl.nameNow;
			ShowPflD( db.pfl );
			break;
		default:
			name = getGlobalName();
	}
	bool en = ( name != getGlobalName() );
	switch ( inMode )
	{
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
	case HEX_LIST_RAM:
		en = true;
		break;
	}
	for ( int i = 0; i < g_iPanelCount; ++i )
		m_aPanels[ i ]->Enable( en );
}
void G::ShowStateD( State& obj )
{
	HexName_TXT->ChangeValue(	obj.nameNow );
	HexOrgName_S->SetLabel(		obj.orgName );
	HexPfmName_S->SetLabel(		obj.pfmName );
	HexBinName_S->SetLabel(		obj.binName );
	HexPflName_S->SetLabel(		obj.pflName );
}
void G::ShowOrgD( Org* obj )
{
	HexName_TXT->ChangeValue( obj->nameNow );
	HexFile_TXT->ChangeValue( obj->fileNow );
}
void G::ShowPfmD( Pfm& obj )
{
	ShowOrgD( &obj );
	HexEndian_DD->Select( obj.endian );
}
void G::ShowBinD( Bin& obj )
{
	// TODO(awsdert) Refine G::ShowBinD();
	ShowOrgD( &obj );
	HexBinBind_TXT->ChangeValue( obj.name );
	HexBinPath_TXT->ChangeValue( obj.path );
	HexBinFSO_RB->SetValue( obj.type == 0u );
	HexBinApp_RB->SetValue( obj.type == 1u );
	HexBinWin_RB->SetValue( obj.type == 2u );
}
void G::ShowRamD( Ram& obj )
{
	Text txt;
	txt.Printf( wxT("%0llu"), obj.addr );
	HexAddr_TXT->ChangeValue( txt );
	txt.Printf( wxT("%0llu"), obj.bytes );
	HexRamSize_TXT->ChangeValue( txt );
}
void G::ShowPflD( Pfl& obj )
{
	// TODO: Implement G::ShowPflD();
	ShowOrgD( &obj );
}
void G::ShowHack( Hack& obj )
{
	// TODO: Implement G::ShowHack();
}
void G::ShowCode( Code& obj )
{
	// TODO: Implement G::ShowCode();
}
