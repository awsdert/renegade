#include "hexDB_hack.h"
void xsDLL ListHacks( TrCO* tree, Hacks& hacks )
{
	tree->DeleteAllItems();
	TrId rItem = tree->AppendItem( tree->GetRootItem(), wxT("(m)") );
	Hack hObj, pObj;
	hacks[ 0 ].item = rItem;
	int iEnd = hacks.size();
	for ( int i = 1; i < iEnd; ++i )
	{
		hObj = hacks[ i ];
		pObj = hacks[ hObj.parent ];
		hObj.item	= tree->AppendItem( pObj.item, hObj.name );
		hacks[ i ]	= hObj;
	}
}
