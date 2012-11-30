#include "hexGUI_G.hpp"
bool G::ListHacks( void )
{
	ui08  aSize = 0u;
	Hack* hacks = NULL;
	if ( LoadDatB( hacks, aSize, HEX_LIST_HCK ) )
		return ListHacks( hacks, aSize );
	return false;
}

bool G::ListHacks( Hack* hacks, ui08& aSize )
{
	HexTree_P->Show();
	HexHack_TC->DeleteAllItems();
	TrId hckItem, rootItem = HexHack_TC->GetRootItem(), tpid = rootItem;
	Hack hack, phck = hacks[ 0u ];
	for ( ui16 i = 1u; i < aSize; ++i )
	{
		hack = hacks[ i ];
		if ( hack.hckParent >= i )
			hack.hckParent = 0u;
		phck			= hacks[ hack.hckParent ];
		hckItem			= HexHack_TC->AppendItem( phck.hckItem, hack.hckName );
		hack.hckItem	= hckItem;
		hacks[ i ]		= hack;
	}
	return false;
}
bool G::ShowHack( Hack* hacks, ui08& aSize, Hack& hack, ui16 i )
{
	if ( hack.hckParent >= i )
	{
		hack.hckParent = 0u;
	}
	hack.hckItem = HexHack_TC->AppendItem( hacks[ hack.hckParent ].hckItem, hack.hckName );
	return hack.hckItem.IsOk();
}

