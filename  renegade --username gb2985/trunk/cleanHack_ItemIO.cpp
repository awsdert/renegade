#include "G.h"
void G::mShowHack( void )
{
	xTreeID tid = GetHackID();
	if ( !tid.IsOk() ) return;
	xStr  name = tree_T->GetItemText( tid );
	HACK* hack = mGetHack( tid );
	gSetHack( hack );
	mHackName_TXT->ChangeValue( name );
	gEnable( !( hack->id == 0u ), mHackName_TXT );
	mUseHack_CB->SetValue( hack->use );
	s8  i, iCount = hack->GetCount();
	s16 j, jCount, k = 0;
	xAStr array;
	xStrT st;
	xStr part1, part2;
	wxListItem item;
	code_LC->DeleteAllItems();
	for ( i = 0; i < iCount; ++i )
	{
		array = BuildCode( ( *hack )[ i ] );
		jCount = array.GetCount();
		for ( j = 0; j < jCount; ++j, ++k )
		{
			st.SetString( array[ j ], wxT( " " ) );
			part1 = st.GetNextToken();
			part2 = st.GetNextToken();
			item.SetId( k );
			item.SetColumn( 0 );
			item.SetText( part1 );
			code_LC->InsertItem( item );
			item.SetColumn( 1 );
			item.SetText( part2 );
			code_LC->SetItem( item );
		}
		array.Clear();
	}
}
xTreeID G::mNewHack( xTreeID root, xStr name, HACK* hack, xTreeID id, s8 mode, bool show )
{
	xTreeID kid;
	if ( !root.IsOk() ) root = GetHackRoot();
	switch ( mode )
	{
		case ADD_PREV:
			if ( id.IsOk() )
			{
				id = tree_T->GetPrevSibling( id );
			}
			if ( id.IsOk() )
			{
				kid = tree_T->InsertItem( root, id, name );
				break;
			}
		case ADD_TOP:
			kid = tree_T->PrependItem( root, name );
			break;
		case ADD_NEXT:
			if ( id.IsOk() )
			{
				kid = tree_T->InsertItem( root, id, name );
				break;
			}
		default:
			kid = tree_T->AppendItem( root, name );
	}
	HACK* data = mGetHack( hack );
	mSetHack( kid, data );
	tree_T->Expand( root );
	if ( show ) tree_T->SelectItem( kid );
	return kid;
}
xTreeID G::mFindHack( u16 id )
{
	xTreeID root = GetHackRoot();
	return mFindHack( root, id );
}
xTreeID G::mFindHack( xTreeID root, u16 id )
{
	xTreeID give;
	if ( root.IsOk() )
	{
		HACK*   hack = mGetHack( root );
		if ( hack->id == id ) give = root;
		else
		{
			xTreeIDV cookie;
			xTreeID  kid = tree_T->GetFirstChild( root , cookie );
			while ( kid.IsOk() && !give.IsOk() )
			{
				give = mFindHack( kid, id );
				kid  = tree_T->GetNextChild( root, cookie );
			}
		}
	}
	return give;
}
