#include "hexLib_main.h"
void M_CODE::m_listCodes( TrCO* tree, Codes& data, Code& obj, TrId& parent, int i, int iEnd )
{
	Code now;
	Text txt;
	TrId item;
	for ( ; i < iEnd; ++i )
	{
		now = data[ i ];
		switch ( now.type )
		{
		case CODE_WRITE:txt = _("Write");	break;
		case CODE_COPY:	txt = _("Copy");	break;
		case CODE_INC:	txt = _("Plus");	break;
		case CODE_DEC:	txt = _("Minus");	break;
		case CODE_LIST:	txt = _("List");	break;
		case CODE_TEST:	txt = _("Test");	break;
		default:		txt = _("Unknown");
		}
		item = tree->AppendItem( parent, txt );
		tree->SetItemData( item, new TrID( i ) );
		data[ i ] = now;
		if ( now.type == CODE_TEST )
		{
			m_listCodes( tree, data, now, item, i + 1, ( ( i + now.loop ) < iEnd ) ? ( i + now.loop ) : iEnd );
			i += now.loop;
		}
	}
}
void M_CODE::m_listCodes( TrCO* tree, LBox* lbox, Codes& data, int format, int listCode )
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
		m_listCodes( tree, data, obj, rItem, c, cEnd );
		tree->Expand( rItem );
	}
	lbox->Clear();
	if ( c < cEnd )
	{
		TxtA block;
		lbox->Append( block );
	}
}