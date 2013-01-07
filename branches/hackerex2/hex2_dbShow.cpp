#include "wx_pch.h"
#include "hex2_G.h"
void G::ShowPanels()
{
	int i = 0, iEnd = g_iPanelCount, inMode = m_siListNow;
	if ( m_bListCfg )
	{
		for ( i = 0; i < iEnd; ++i )
			m_aPanels[ i ]->Show( false );
		HexList_LB->Show();
	}
	else if ( inMode != m_siListOld )
	{
		for ( i = 0; i < iEnd; ++i )
			m_aPanels[ i ]->Show( false );
		HexList_LB->Show( false );
		HexInc_DD->Show( false );
		HexInc_TXT->Show( false );
		i = HEX_LIST_FORMAT;
		if ( inMode < HEX_LIST_CODE )
		{
			HexName_P->Show();
			HexList_LB->Show();
			if ( inMode >= HEX_LIST_ORG && inMode < HEX_LIST_HACK )
				HexFile_P->Show();
		}
		if ( inMode == HEX_LIST_HACK || inMode == HEX_LIST_CODE )
			HexTree_P->Show();
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
		case HEX_LIST_RAM:
			HexFile_P->Show( false );
			HexRam_P->Show();
			HexRamData_P->Show();
			HexAddr_P->Show();
			break;
		case HEX_LIST_PFL:
			HexPfl_P->Show();
			break;
		case HEX_LIST_HACK:
			HexHck_P->Show();
			break;
		case HEX_LIST_CODE:
			HexList_LB->Show();
			HexCode_P->Show();
			HexAddr_P->Show();
			HexVal_P->Show();
			break;
		}
		m_siListOld = inMode;
	}
	HexBody_SW->FitInside();
	HexList_SW->FitInside();
	bool en = ( m_db.getNowN( inMode ) != m_db.getDefN( inMode ) );
	switch ( inMode )
	{
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
	case HEX_LIST_RAM:
	case HEX_LIST_HACK:
		en = true;
		break;
	case HEX_LIST_CODE:
		en = ( m_db.codeNo >= 0 );
		break;
	}
	iEnd = g_iPanelCount - 2;
	for ( int i = 0; i < iEnd; ++i )
		m_aPanels[ i ]->Enable( en );
}
void G::ShowData( hexDB& db )
{
	ShowPanels();
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
		case HEX_LIST_PFL:
			ShowPflD( db.pfl );
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
void G::ShowHack( Hacks& data, int hackNo )
{
	if ( hackNo < 0 )
		return;
	Hack& obj = data[ hackNo ];
	bool show = ( obj.info & HACK_USE );
	bool isRB = ( hackNo > 0 && data[ obj.parent ].info & HACK_RL );
	HexName_TXT->ChangeValue( obj.name );
	HexName_TXT->Enable( ( hackNo > 0 ) );
	HexUse_CB->SetValue( show );
	HexUse_RB->SetValue( show );
	HexUse_CB->Show( !isRB );
	HexUse_RB->Show( isRB );
	HexHackKids_DD->SetSelection( ( (ui08)( obj.info & HACK_RL ) > 0u ) ? 0 : 1 );
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
	switch ( obj.bytes )
	{
		case 8u: v64 = *( reinterpret_cast< ui64* >( &( obj[ v ] ) ) ); break;
		case 4u: v64 = *( reinterpret_cast< ui32* >( &( obj[ v ] ) ) ); break;
		case 2u: v64 = *( reinterpret_cast< ui16* >( &( obj[ v ] ) ) ); break;
		default: v64 = obj[ v ];
	}
	switch ( obj.hex )
	{
	case HEX_TYPE_HEX:	txt.Printf( wxT("%01llX"), v64 ); break;
	case HEX_TYPE_UI:	txt.Printf( wxT("%01llu"), v64 ); break;
	case HEX_TYPE_SI:	txt.Printf( wxT("%01lli"), v64 ); break;
	case HEX_TYPE_TEXT:	txt.Printf( wxT("%s"), v64 ); break;
	case HEX_TYPE_WTEXT:txt.Printf( wxT("%ls"), v64 ); break;
	default: txt = wxT('0');
	}
	tbox->ChangeValue( txt );
}
