#include "wx_pch.h"
#include "hexLib_main.h"
void M_HACK::m_listHacks( si32 i, si32& iEnd, TrId pItem )
{
	Hack hObj = m_tmp[ i ], pObj = m_tmp[ hObj.parent ];
	pObj = m_tmp[ hObj.parent ];
	TrId cItem = tree_main->AppendItem( pItem, hObj.name );
	tree_main->SetItemData( cItem, new TrID( i ) );
	m_tmp[ i ] = hObj;
	for ( i = hObj.first; i < iEnd; i = m_tmp[ i ].next )
		m_listHacks( i, iEnd, cItem );
}
void M_HACK::m_listHacks( void )
{
	si32
		i = 0,
		iEnd = m_tmp.size();
	tree_main->DeleteAllItems();
	Hack
		root = m_tmp[ 0 ];
	TrId rItem = tree_main->AppendItem( tree_main->GetRootItem(), wxT("(m)") );
	tree_main->SetItemData( rItem, new TrID( 0 ) );
	for ( i = root.first; i >= 0; i = m_tmp[ i ].next )
		m_listHacks( i, iEnd, rItem );
	tree_main->Expand( rItem );
}
