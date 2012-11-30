#include "hexGUI_G.hpp"

bool G::ListOrgs( void )
{
	Org* aOrg = NULL;
	ui08 aSize = 0u;
	if ( !LoadDatB( aOrg, aSize, HEX_LIST_ORG ) || aSize == 0u )
		return false;
	ui16 a = 0u;
	TxtA aTxt;
	aTxt.SetCount( aSize );
	HexList_LB->Clear();
	for ( ; a < aSize; ++a )
		aTxt[ a ] = aOrg[ a ].nameOld;
	/*
	Text text, msg = wxT("test");
	text.Printf( wxT( "%u" ), aSize );
	if ( wxMessageBox( msg, text, wxOK | wxCANCEL ) == wxCANCEL )
		return false;//*/
	HexList_LB->Append( aTxt );
	return true;
}
