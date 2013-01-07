#include "wx_pch.h"
#include "hex2_G.h"
void G::UpdatePanels( void )
{
// TODO(awsdert) Search, Results and Editor still needed
	int inMode = m_siListNow, atMode = m_db.mode[ inMode ];
	bool act = false;
	if ( !m_bListCfg && inMode != m_siListOld )
		act = true;
	else if ( m_bListCfg )
		act = true;
	if ( !act )
		return;
	m_db.tmpCfg		= m_bListCfg;
	m_db.tmpLB		= HexList_LB;
	m_db.showAllApps= ( inMode == HEX_LIST_APP );
	m_db.tmpMode	= inMode;
	UpdateList( m_db, HexList_LB, m_db.getNowN( inMode ) );
	if ( !m_bListCfg )
		m_db.oldP[ atMode ] = m_db.nowP[ atMode ];
	bool doRam = false;
	switch ( inMode )
	{
	case HEX_LIST_RAM:
	case HEX_LIST_FIND:
	case HEX_LIST_EDIT:
	case HEX_LIST_OUT:
		doRam = true;
		break;
	}
	ShowData( m_db );
	if ( doRam )
	{
		m_db.tmpCfg		= false;
		m_db.tmpMode	= HEX_LIST_RAM;
		UpdateList( m_db, HexRam_LB );
	}
}
void G::UpdateList( hexDB& db, LBox* lb, Text name )
{
	/**
		@param lb
		Where the list is being sent
		@param isCfg
		Should the list be of the mode selection type or the data selection / manipulation type
		@param inMode
		Ignored if isCfg is true
	**/
	int i = 0;
	bool listSel = false;
	LoadData( db, lb, HEX_LOAD_LIST, name );
	if ( db.tmpCfg )
	{
		listSel = true;
		i = db.tmpMode;
	}
	else
	{
		listSel = ( db.tmpMode < HEX_LIST_HACK );
		if ( listSel )
			i = lb->FindString( name );
	}
	if ( listSel )
		lb->SetSelection( ( i < 0 ) ? 0 : i );
}
void G::UpdateTheme( Text name, int size )
{
	if ( name.IsEmpty() )
		return;
	if ( size < 0 || size > 48 )
		size = 22;
	int i;
	const int iCount = 7;
	Text ico, theme = ( wxGetCwd() + xsDirUp + xsDirSep + wxT("themes") + xsDirSep + name + xsDirSep );
	wxImage img;
	//img.AddHandler( new wxICOHandler );
	img.AddHandler( new wxXPMHandler );
	Text tha[ iCount ], ext = wxT(".xpm");
	int  tia[ iCount ];
	tha[  0 ] = wxT("manager");	tia[  0 ] = HexMain_TT_ID;
	tha[  1 ] = wxT("db");		tia[  1 ] = HexList_TT_ID;
	tha[  2 ] = wxT("save");	tia[  2 ] = HexSave_TT_ID;
	/*/
	tha[  4 ] = wxT("2uarrow");	tia[  4 ] = HexFirst_TT_ID;
	tha[  5 ] = wxT("1darrow");	tia[  5 ] = HexNext_TT_ID;
	tha[  6 ] = wxT("1uarrow");	tia[  6 ] = HexPrev_TT_ID;
	tha[  7 ] = wxT("2darrow");	tia[  7 ] = HexLast_TT_ID;
	tha[  8 ] = wxT("db_add");	tia[  8 ] = HexNew_TT_ID;
	tha[  9 ] = wxT("db_del");	tia[  9 ] = HexDel_TT_ID;
	tha[ 10 ] = wxT("db_get");	tia[ 10 ] = HexGet_TT_ID;
	tha[ 11 ] = wxT("db_set");	tia[ 11 ] = HexSet_TT_ID;
	* */
	tha[  3 ] = wxT("db_add");	tia[  3 ] = HexNew_TT_ID;
	tha[  4 ] = wxT("db_del");	tia[  4 ] = HexDel_TT_ID;
	tha[  5 ] = wxT("db_get");	tia[  5 ] = HexGet_TT_ID;
	tha[  6 ] = wxT("db_set");	tia[  6 ] = HexSet_TT_ID;
	//*/
	for ( i = 0; i < iCount; ++i )
	{
		ico = theme + tha[ i ] + ext;
		if ( !wxFileExists( ico ) )
			continue;
		img.LoadFile( ico, wxBITMAP_TYPE_XPM );
		if ( !img.IsOk() )
			break;
		HexGUI_TB->SetToolNormalBitmap( tia[ i ], img.Scale( size, size ) );
	}
}
