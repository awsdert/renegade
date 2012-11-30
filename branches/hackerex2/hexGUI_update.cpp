#include "hexGUI_G.hpp"
void G::UpdatePanels( void )
{
// TODO(awsdert) 0: Refine G::UpdatePanels()
	int i, iCount = m_List_Ps.size();
	for ( i = 0; i < iCount; ++i )
	{
		m_List_Ps[ i ]->Hide();
	}
	if ( m_ListCfg )
	{
		HexSession_P->Show();
		HexName_P->Show();
		HexFile_P->Show();
	}
	else
	{
		switch ( m_ListNow )
		{
		case HEX_LIST_ORG:
			HexName_P->Show();
			HexFile_P->Show();
			ListOrgs();
			break;
		case HEX_LIST_PFM:
			HexName_P->Show();
			HexFile_P->Show();
			HexEndian_P->Show();
			break;
		}
	}
	HexBody_SW->FitInside();
}
void G::UpdateTheme( Text name )
{
	if ( name.IsEmpty() )
	{
		return;
	}
	int i, iCount = 12;
	Text theme = ( wxGetCwd() + wxT("/../themes/") + name + wxT("/") );
	wxImage img;
	img.AddHandler( new wxICOHandler );
	TxtA tha;
	tha.SetCount( iCount );
	Vect< int > tia( iCount );
	tha[  0 ] = wxT("config.ico");	tia[  0 ] = HexMain_TT_ID;
	tha[  1 ] = wxT("list.ico");	tia[  1 ] = HexList_TT_ID;
	tha[  2 ] = wxT("load.ico");	tia[  2 ] = HexLoad_TT_ID;
	tha[  3 ] = wxT("save.ico");	tia[  3 ] = HexSave_TT_ID;
	tha[  4 ] = wxT("first.ico");	tia[  4 ] = HexFirst_TT_ID;
	tha[  5 ] = wxT("next.ico");	tia[  5 ] = HexNext_TT_ID;
	tha[  6 ] = wxT("prev.ico");	tia[  6 ] = HexPrev_TT_ID;
	tha[  7 ] = wxT("last.ico");	tia[  7 ] = HexLast_TT_ID;
	tha[  8 ] = wxT("add.ico");		tia[  8 ] = HexNew_TT_ID;
	tha[  9 ] = wxT("del.ico");		tia[  9 ] = HexDel_TT_ID;
	tha[ 10 ] = wxT("tick.ico");	tia[ 10 ] = HexGet_TT_ID;
	tha[ 11 ] = wxT("cross.ico");	tia[ 11 ] = HexSet_TT_ID;
	for ( i = 0; i < iCount; ++i )
	{
		img.LoadFile( theme + tha[ i ], wxBITMAP_TYPE_ICO );
		HexGUI_TB->SetToolNormalBitmap( tia[ i ], img );
	}
}
