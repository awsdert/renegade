#include "hexDB_main.h"
void Listhacks( TrCO* tree, Hacks& data, int i )
{
	Hack hObj = data[ i ], pObj = data[ hObj.parent ];
	if ( !pObj.item.IsOk() )
		Listhacks( tree, data, hObj.parent );
	pObj = data[ hObj.parent ];
	hObj.item	= tree->AppendItem( pObj.item, hObj.name );
	tree->SetItemData( hObj.item, new TrID( i ) );
	data[ i ]	= hObj;
}
void xsDLL ListHacks( TrCO* tree, Hacks& data )
{
	tree->DeleteAllItems();
	TrId rItem = tree->AppendItem( tree->GetRootItem(), wxT("(m)") );
	data[ 0 ].item = rItem;
	tree->SetItemData( rItem, new TrID( 0 ) );
	int iEnd = data.size();
	for ( int i = 1; i < iEnd; ++i )
	{
		if ( !data[i].item.IsOk() )
			Listhacks( tree, data, i );
	}
	tree->Expand( rItem );
}
void Listcodes( TrCO* tree, Codes& data, Code& obj, int& i, int iEnd )
{
	Code now;
	Text txt;
	for ( ++i; i < iEnd; ++i )
	{
		now = data[ i ];
		switch ( now.type )
		{
		case HEX_CT_WRITE:	txt = _("Write");	break;
		case HEX_CT_COPY:	txt = _("Copy");	break;
		case HEX_CT_INC:	txt = _("Plus");	break;
		case HEX_CT_DEC:	txt = _("Minus");	break;
		case HEX_CT_LIST:	txt = _("List");	break;
		case HEX_CT_TEST:	txt = _("Test");	break;
		default:			txt = _("Unknown");
		}
		now.item = tree->AppendItem( obj.item, txt );
		tree->SetItemData( now.item, new TrID( i ) );
		data[ i ] = now;
		if ( now.type == HEX_CT_TEST )
			Listcodes( tree, data, now, i, i + now.loop );
	}
	--i;
}
void xsDLL ListCodes( TrCO* tree, LBox* lbox, Codes& data, int format, int listCode, bool relist )
{
	int i = -1;
	Code obj;
	if ( relist )
	{
		tree->DeleteAllItems();
		TrId rItem = tree->AppendItem( tree->GetRootItem(), _("(Codes)") );
		tree->SetItemData( rItem, new TrID( i ) );
		obj.item = rItem;
		Listcodes( tree, data, obj, i, data.size() );
		tree->Expand( rItem );
	}
	lbox->Clear();
	int cEnd = data.size();
	if ( listCode >= 0 && listCode < cEnd )
	{
		TxtA block;
		switch ( format )
		{
			case HL_HEX1: Maketxt_Hex1( data[ listCode ], block ); break;
		}
		lbox->Append( block );
	}
}
