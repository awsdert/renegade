#include "wx_pch.h"
#include "hexDB_main.h"
void Listhacks( TrCO* tree, Hacks& data, ui32 i, ui32& iEnd )
{
	Hack hObj = data[ i ], pObj = data[ hObj.parent ];
	pObj = data[ hObj.parent ];
	hObj.item	= tree->AppendItem( pObj.item, hObj.name );
	tree->SetItemData( hObj.item, new TrID( i ) );
	data[ i ]	= hObj;
	for ( i = hObj.first; i < iEnd; i = data[ i ].next )
		Listhacks( tree, data, i, iEnd );
}
void xsDLL ListHacks( TrCO* tree, Hacks& data )
{
	ui32 i = 0u, iEnd = data.size();
	tree->DeleteAllItems(); Hack pObj = data[ i ];
	pObj.item = tree->AppendItem( tree->GetRootItem(), wxT("(m)") );
	data[ i ] = pObj;
	tree->SetItemData( pObj.item, new TrID( 0 ) );
	for ( ui32 i = pObj.first; i < iEnd; i = data[ i ].next )
		Listhacks( tree, data, i, iEnd );
	tree->Expand( pObj.item );
}
void Listcodes( TrCO* tree, Codes& data, Code& obj, int i, int iEnd )
{
	Code now;
	Text txt;
	for ( ; i < iEnd; ++i )
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
		{
			Listcodes( tree, data, now, i + 1, ( ( i + now.loop ) < iEnd ) ? ( i + now.loop ) : iEnd );
			i += now.loop;
		}
	}
}
void xsDLL ListCodes( TrCO* tree, LBox* lbox, Codes& data, int format, int listCode )
{
	int c = listCode;
	Code obj;
	int cEnd = data.size();
	if ( c < 0 )
	{
		c = 0;
		tree->DeleteAllItems();
		TrId rItem = tree->AppendItem( tree->GetRootItem(), _("(Codes)") );
		tree->SetItemData( rItem, new TrID( c ) );
		obj.item = rItem;
		Listcodes( tree, data, obj, c, cEnd );
		tree->Expand( rItem );
	}
	lbox->Clear();
	if ( c < cEnd )
	{
		TxtA block;
		switch ( format )
		{
			case HL_HEX1: Maketxt_Hex1( data[ c ], block ); break;
		}
		lbox->Append( block );
	}
}
