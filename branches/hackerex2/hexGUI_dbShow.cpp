#include "hexGUI_G.hpp"
void G::ShowOrgD( int s )
{
	//ui16 index = 0u;
	ui08 aSize = 0u;
	Org* data = NULL;
	if ( !LoadDatB( data, aSize, HEX_LIST_ORG ) )
		return;
}
void G::ShowPfmD( int s )
{
	//ui16 index = 0u;
	ui08 aSize = 0u;
	Pfm* data = NULL;
	if ( !LoadDatB( data, aSize, HEX_LIST_PFM ) )
		return;
}
void G::ShowBinD( int s )
{
	//ui16 index = 0u;
	ui08 aSize = 0u;
	Bin* data = NULL;
	if ( !LoadDatB( data, aSize, HEX_LIST_BIN ) )
		return;
}
void G::ShowPflD( int s )
{
	//ui16 index = 0u;
	ui08 aSize = 0u;
	Pfl* data = NULL;
	if ( !LoadDatB( data, aSize, HEX_LIST_PFL ) )
		return;
}
