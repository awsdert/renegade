#include "wx_pch.h"
#include "hex2_G.h"
void G::UpdatePanels( void )
{
// TODO(awsdert) Search, Results and Editor still needed
	hexDB& db = m_gui.m_db;
	int inMode = db.nowL, atMode = db.mode[ inMode ];
	bool act = false;
	if ( !m_bListCfg && inMode != db.oldL )
		act = true;
	else if ( m_bListCfg )
		act = true;
	if ( !act )
		return;
	db.tmpCfg		= m_bListCfg;
	db.tmpLB		= HexList_LB;
	db.showAllApps	= ( inMode == HEX_LIST_APP );
	db.tmpMode		= inMode;
	UpdateList( db, db.getNowN( inMode ) );
	if ( !m_bListCfg )
		db.oldP[ atMode ] = db.nowP[ atMode ];
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
	ShowData( db );
	if ( doRam )
	{
		db.tmpCfg	= false;
		db.tmpMode	= HEX_LIST_RAM;
		db.tmpLB	= HexRam_LB;
		UpdateList( db );
	}
}
void G::UpdateList( hexDB& db, Text name )
{
	int i = 0;
	bool listSel = false;
	db.loadData( HEX_LOAD_LIST, name );
	if ( db.tmpCfg )
	{
		listSel = true;
		i = db.tmpMode;
	}
	else
	{
		listSel = ( db.tmpMode < HEX_LIST_HACK );
		if ( listSel )
			i = db.tmpLB->FindString( name );
	}
	if ( listSel )
		db.tmpLB->SetSelection( ( i < 0 ) ? 0 : i );
}
void G::UpdateTheme( Text name, int size )
{
	if ( name.IsEmpty() )
		return;
	if ( size < 0 || size > 48 )
		size = 22;
	int i = 0;
	const int iCount = 7;
	Text ico, theme = ( wxGetCwd() + xsDirSep + wxT("themes") + xsDirSep + name + xsDirSep );
	wxImage img;
	img.AddHandler( new wxXPMHandler );
	Text tha[ iCount ], ext = wxT(".xpm");
	int  tia[ iCount ];
	tia[   i ] = HexMain_TT_ID;	tha[ i ] = wxT("manager");
	tia[ ++i ] = HexList_TT_ID;	tha[ i ] = wxT("db");
	tia[ ++i ] = HexSave_TT_ID;	tha[ i ] = wxT("save");
	/*
	tia[ ++i ] = HexFirst_TT_ID;tha[ i ] = wxT("2uarrow");
	tia[ ++i ] = HexNext_TT_ID;	tha[ i ] = wxT("1darrow");
	tia[ ++i ] = HexPrev_TT_ID;	tha[ i ] = wxT("1uarrow");
	tia[ ++i ] = HexLast_TT_ID;	tha[ i ] = wxT("2darrow");
	//*/
	tia[ ++i ] = HexNew_TT_ID;	tha[ i ] = wxT("db_add");
	tia[ ++i ] = HexDel_TT_ID;	tha[ i ] = wxT("db_del");
	tia[ ++i ] = HexGet_TT_ID;	tha[ i ] = wxT("db_get");
	tia[ ++i ] = HexSet_TT_ID;	tha[ i ] = wxT("db_set");
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
