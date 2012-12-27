#include "hexDB_hack.h"
void Listhacks( TrCO* tree, Hacks& data, int i )
{
	Hack hObj = data[ i ], pObj = data[ hObj.parent ];
	if ( !pObj.item.IsOk() )
		Listhacks( tree, data, hObj.parent );
	pObj = data[ hObj.parent ];
	hObj.item	= tree->AppendItem( pObj.item, hObj.name );
	data[ i ]	= hObj;
}
void xsDLL ListHacks( TrCO* tree, Hacks& data )
{
	tree->DeleteAllItems();
	data[ 0 ].item = tree->AppendItem( tree->GetRootItem(), wxT("(m)") );
	int iEnd = data.size();
	for ( int i = 1; i < iEnd; ++i )
	{
		if ( !data[i].item.IsOk() )
			Listhacks( tree, data, i );
	}
}
