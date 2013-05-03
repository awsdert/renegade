#include "wx_pch.h"
#include "hex2_G.h"
void G::ShowPanels( int inMode, bool inCfg )
{
	int i = 0, iEnd = NO_OF_PANELS;
	hexDB& db = m_gui.m_db;
	bool en = ( db.getNowN( inMode ) != db.getDefN( inMode ) );
	for ( i = 0; i < iEnd; ++i )
		m_aPanels[ i ]->Show( false );
	if ( inCfg )
		HexList_LB->Show();
	else
	{
		HexJump_B->Show( false );
		HexEdit_RL->Show( false );
		HexInc_DD->Show( false );
		HexInc_TXT->Show( false );
		i = HEX_LIST_FORMAT;
		switch ( inMode )
		{
		case HEX_LIST_FIND:
		case HEX_LIST_OUT:
		case HEX_LIST_EDIT:
			HexList_LB->Show( false );
			HexHack_TC->Show( false );
			break;
		default:
			HexHack_TC->Show();
			HexList_LB->Show();
		}
		switch ( inMode )
		{
		case HEX_LIST_ORG:
		case HEX_LIST_PFM:
		case HEX_LIST_BIN:
		case HEX_LIST_APP:
		case HEX_LIST_WIN:
		case HEX_LIST_PFL:
			HexName_P->Show();
			HexFile_P->Show();
			break;
		case HEX_LIST_RAM:
			HexName_P->Show();
			HexRam_P->Show();
			HexRamData_P->Show();
			HexAddr_P->Show();
			break;
		case HEX_LIST_HACK:
		case HEX_LIST_CODE:
		case HEX_LIST_OUT:
			HexTree_P->Show();
			break;
		}
		switch ( inMode )
		{
		case HEX_LIST_SESSION:
			HexState_P->Show();
			break;
		case HEX_LIST_PFM:
			HexEndian_P->Show();
			break;
		case HEX_LIST_BIN:
		case HEX_LIST_APP:
		case HEX_LIST_WIN:
			HexBin_P->Show();
			break;
		case HEX_LIST_PFL:
			HexPfl_P->Show();
			break;
		case HEX_LIST_FORMAT:
			HexFormat_P->Show();
			break;
		case HEX_LIST_HACK:
			HexHook_P->Show();
			HexHck_P->Show();
			break;
		case HEX_LIST_CODE:
		case HEX_LIST_OUT:
			HexCode_P->Show();
			HexAddr_P->Show();
			HexDepth_P->Show();
			HexInc_DD->Show();
			HexInc_TXT->Show();
			HexVal_P->Show();
			break;
		case HEX_LIST_EDIT:
			db.eAddr = 0u;
			HexAddr_P->Show();
			HexDepth_P->Show( false );
			HexVal_P->Show();
			HexHook_P->Show();
			HexGrid_G->Show();
			HexEdit_RL->Show();
			HexJump_B->Show();
			break;
		}
	}
	HexBody_SW->Layout();
	HexList_P->Layout();
	switch ( inMode )
	{
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
	case HEX_LIST_RAM:
	case HEX_LIST_HACK:
	case HEX_LIST_FIND:
	case HEX_LIST_OUT:
	case HEX_LIST_EDIT:
		en = true;
		break;
	case HEX_LIST_CODE:
		en = ( m_gui.m_db.codeNo >= 0 );
		break;
	}
	iEnd = NO_OF_PANELS - 2;
	for ( i = 0; i < iEnd; ++i )
		m_aPanels[ i ]->Enable( en );
}
void G::ShowData( hexDB& db )
{
	ShowPanels( db.nowL, m_bListCfg );
	int inMode = db.tmpMode;
	switch ( inMode )
	{
		case HEX_LIST_SESSION:
			ShowStateD( db.state );
			break;
		case HEX_LIST_ORG:
			ShowOrgD( &(db.org) );
			break;
		case HEX_LIST_PFM:
			ShowPfmD( db.pfm );
			break;
		case HEX_LIST_BIN:
		case HEX_LIST_APP:
		case HEX_LIST_WIN:
			ShowBinD( db.bin );
			break;
		case HEX_LIST_RAM:
			ShowRamD( db.bin[ db.bin.ramNo ] );
			break;
		case HEX_LIST_PFL:
			ShowPflD( db.pfl );
			break;
		case HEX_LIST_FORMAT:
			ShowFormat( db.format );
			break;
		case HEX_LIST_HACK:
		{
			int hn = db.hacks.hackNow;
			ShowHack( db.hacks, hn );
			break;
		}
		case HEX_LIST_CODE:
		{
			int cn = db.codeNo, cc = db.codes.size();
			Code obj6;
			if ( cn < 0 || cn >= cc )
				ShowCode( obj6 );
			else
				ShowCode( db.codes[ cn ] );
		}
	}
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
	HexName_TXT->ChangeValue( obj.name );
	txt.Printf( wxT("%llX"), obj.addr );
	HexAddr_TXT->ChangeValue( txt );
	HexDepth_SL->SetValue( obj.depth );
	txt.Printf( wxT("%llX"), obj.bytes );
	HexRamSize_TXT->ChangeValue( txt );
}
void G::ShowPflD( Pfl& obj )
{
	ShowOrgD( &obj );
	Text txt;
	txt.Printf( wxT("%04X"), obj.profile );
	HexPID_TXT->ChangeValue( txt );
	HexSID_TXT->ChangeValue( obj.serial );
	HexNotes_TA->ChangeValue( obj.notes );
	ShowRegion( obj.region );
}
void G::ShowRegion( ui32 region )
{
	TxtA data;
	int i, iEnd = getRegionCount();
	ui32* regions = new ui32[ iEnd ];
	getRegionData( data );
	getRegions( regions );
	HexRegion_CLB->Clear();
	HexRegion_CLB->Append( data );
	bool all = ( region == 0u );
	for ( i = 0; i < iEnd; ++i )
		HexRegion_CLB->Check( i, ( all || ( region & regions[ i ] ) > 0u ) ? true : false );
	delete [] regions;
	HexRegionAll_RB->SetValue( all );
	HexRegionSel_RB->SetValue( !all );
	HexRegion_CLB->Enable( !all );
}
void G::ShowFormat( Fmt& obj )
{
	HexExt_TXT->ChangeValue( obj.ext );
}
void G::ShowHack( Hacks& data, int hackNo )
{
	if ( hackNo < 0 )
		return;
	Hack& obj = data[ hackNo ];
	bool show = obj.isActive();
	bool isRB = ( hackNo > 0 && data[ obj.getParent() ].isRadio() );
	HexName_TXT->ChangeValue( obj.name );
	HexName_TXT->Enable( ( hackNo > 0 ) );
	HexUse_CB->SetValue( show );
	HexUse_RB->SetValue( show );
	HexUse_CB->Show( !isRB );
	HexUse_RB->Show( isRB );
	HexHackKids_DD->SetSelection( obj.isRadio() ? 0 : 1 );
}
void G::ShowCode( Code& obj )
{
// TODO(awsdert) Finish ShowCode()
	Text txt;
	const bool isTest = ( obj.type == HEX_CT_TEST );
	const bool isList = ( obj.type == HEX_CT_LIST );
	const bool isCopy = ( obj.type == HEX_CT_COPY );
	const bool isInc  = ( !isTest && !isCopy && !isList );
	// Show / Hide Objects
	HexInc_DD->Show( isInc );
	HexInc_TXT->Show( isInc );
	HexTest_DD->Show( isTest );
	HexVType_S->Show( !isCopy );
	HexVSize_S->Show( !isCopy );
	HexVType_DD->Show( !isCopy );
	HexVSize_SB->Show( !isCopy );
	// Show Data
	HexCType_DD->SetSelection( obj.type );
	txt.Printf( wxT("%01llX"), obj.addr[ 0 ] );
	HexAddr_TXT->ChangeValue( txt );
	HexDepth_SL->SetValue( obj.depth );
	if ( isTest )
	{
		int t = -1;
		switch ( obj.info )
		{
			case HEX_IS_DC: t = 0; break;
			case HEX_IS_NC: t = 1; break;
			case HEX_IS_EQ: t = 2; break;
			case HEX_IS_NE: t = 3; break;
			case HEX_IS_GT: t = 4; break;
			case HEX_IS_GE: t = 5; break;
			case HEX_IS_LT: t = 6; break;
			case HEX_IS_LE: t = 7; break;
		}
		HexTest_DD->SetSelection( t );
	}
	else if ( isInc )
	{
		int i;
		switch ( obj.info & 0xF )
		{
			case HEX_CT_DEC: i = 1; break;
			default: i = 0;
		}
		HexInc_DD->SetSelection( i );
		ShowCodeValue( HexInc_TXT, obj, 1 );
	}
	else if ( isCopy )
		obj.hex = HEX_TYPE_HEX;
	if ( isTest )
		txt = _("Codes");
	else
		txt = _("Loop");
	HexLoop_S->SetLabel( txt );
	txt.Printf( wxT("%01u"), obj.loop );
	HexLoop_TXT->ChangeValue( txt );
	ShowCodeValue( HexVal_TXT, obj, 0 );
	HexVType_DD->SetSelection( obj.hex );
	HexVSize_SB->SetValue( obj.bytes );
	HexVal_P->Layout();
}
void G::ShowCodeValue( wxTextCtrl* tbox, Code& obj, int v )
{
	Text txt;
	ui64 v64 = 0u;
	if ( obj.type == HEX_CT_LIST )
	{
		int j = 0, b = 0, k = (obj.bytes * 8), move = 0;
		for ( int i = 0; i < 256; ++j )
		{
			if ( obj.bytes < 8u )
			{
				for ( b = 0; b < 8; ++i, b += obj.bytes )
				{
					if ( i == v )
					{
						v64 = obj[ j ];
						break;
					}
				}
			}
			if ( i == v )
				break;
			else if ( obj.bytes == 8u )
				++i;
		}
		if ( obj.bytes < 8u )
		{
			ui64 tmp = 0u;
			switch ( obj.bytes )
			{
			case 4u: move = 32; tmp = 0xFFFFFFFFLL; break;
			case 2u: move = 48; tmp = 0xFFFFLL; break;
			case 1u: move = 56; tmp = 0xFFLL; break;
			}
			for ( j = 0; j < b; ++j )
				move -= k;
			v64 = GETHEX( v64, tmp, move );
		}
	}
	else
		v64 = obj[ v ];
	zxUInt val = v64;
	switch ( obj.hex )
	{
	case HEX_TYPE_HEX:
		txt = val.toString( 16u );
		break;
	case HEX_TYPE_SI:
		val.m_signed = true;
	case HEX_TYPE_UI:
		txt = val.toString();
		break;
	case HEX_TYPE_TEXT:
		txt.Printf( wxT("%s"), (char*)val.m_data );
		break;
	case HEX_TYPE_WTEXT:
		txt.Printf( wxT("%ls"), (wchar_t*)val.m_data );
		break;
	default: txt = wxT('0');
	}
	tbox->ChangeValue( txt );
}
