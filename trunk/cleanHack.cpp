#include "G.h"
#include "SetHack_DLG.h"
xTreeID G::mSetHack( xTreeID id, HACK* hack )
{
	xTreeID kid;
	HACK* data = mGetHack( hack );
	try
	{
		tree_T->SetItemData( id, data );
		kid = id;
	}
	catch ( s64 error )
	{
		delete  data;
	}
	return kid;
}
HACK*   G::mGetHack( HACK* hack )
{
	HACK* data  = new HACK;
	s8    index = 0;
	s8    count = hack->GetCount();
	data->id    = hack->id;
	data->use   = hack->use;
	data->SetCount( count );
	for ( ; index < count; ++index )
	{
		( *data )[ index ] = ( *hack )[ index ];
	}
	return data;
}
HACK*   G::mGetHack( xTreeID id )
{
	HACK* data;
	if ( !id.IsOk() )
		std::invalid_argument( "There is no Hack with this ID" );
	data = ( HACK* )tree_T->GetItemData( id );
	return data;
}
xTreeID G::GetHackID( void )
{
	return tree_T->GetSelection();
}
xTreeID G::GetHackRoot( void )
{
	return tree_T->GetRootItem();
}
xTreeID G::GetHackRoot( xTreeID id )
{
	xTreeID kid;
	if ( id.IsOk() )
	{
		kid = tree_T->GetItemParent( id );
	}
	if ( !kid.IsOk() )
	{
		kid = GetHackRoot();
	}
	return kid;
}
void G::mDelHack( xTreeID id )
{
	tree_T->Delete( id );
}
void G::mMoveHack( xTreeID from, xTreeID to )
{
	xStr  name;
	HACK* hack;
	xTreeID  idf;
	xTreeID  idt;
	xTreeIDV tiv;
	while ( tree_T->HasChildren( from ) )
	{
		idf  = tree_T->GetFirstChild( from, tiv );
		name = tree_T->GetItemText( idf );
		hack = mGetHack( idf );
		idt  = mNewHack( to, name, hack, idt, ADD_BOTTOM );
		mMoveHack( idf, idt );
	}
	mDelHack( from );
}
void G::mMoveHack( xTreeID tid, s32 direction )
{
	if ( tid.IsOk() )
	{
		xTreeID id;
		xTreeID root = GetHackRoot( tid );
		xStr name = tree_T->GetItemText( tid );
		HACK* hack = mGetHack( tid );
		switch ( direction )
		{
			case WXK_UP:
				id = tree_T->GetPrevSibling( tid );
				id = mNewHack( root, name, hack, id, ADD_PREV );
				break;
			case WXK_LEFT:
				id = mNewHack( GetHackRoot( root ), name, hack, root, ADD_PREV );
				break;
			case WXK_DOWN:
				id = tree_T->GetNextSibling( tid );
				id = mNewHack( root, name, hack, id, ADD_NEXT );
				break;
			case WXK_RIGHT:
				xStr  text;
				HACK* data = new HACK;
				text.Printf( wxT( "New Hack %i" ), tree_T->GetCount() );
				id   = tree_T->GetNextSibling( tid );
				if ( !id.IsOk() )
					root = mNewHack( root, text, data, tid, ADD_TOP );
				else root = id;
				id   = mNewHack( root, name, hack, id,  ADD_TOP  );
				delete data;
		}
		mMoveHack( tid, id );
		tree_T->Expand( id );
		tree_T->SelectItem( id );
	}
}
void G::NewHack_BOnClick( wxCommandEvent& event )
{
	s8      mode = NewHack_D->GetSelection();
	HACK*   hack = new HACK;
	xStr    name;
	xTreeID root;
	xTreeID id;
	if ( NewHack_CB->GetValue() )
	{
		root = GetHackID();
	}
	else
	{
		id   = GetHackID();
		root = GetHackRoot( id );
	}
	name.Printf( wxT( "New Hack %i" ), tree_T->GetCount() );
	mNewHack( root, name, hack, id, mode );
	delete hack;
}
void G::UseHack_BOnClick( wxCommandEvent& event )
{
	xTreeID now  = GetHackID();
	if ( !now.IsOk() ) return;
	HACK*   hack = mGetHack( now );
	if ( hack->id > 0u )
	{
		xTreeID root = GetHackRoot( now );
		HACK*   tmp  = mGetHack( root );
		if ( tmp->useRB )
		{
			xTreeID  kid;
			xTreeIDV cookie;
			for
			(
				kid = tree_T->GetFirstChild( root, cookie );
				kid.IsOk();
				kid = tree_T->GetNextChild( root, cookie )
			)
			{
				tmp      = mGetHack( kid );
				tmp->use = false;
			}
		}
	}
	hack->use = mUseHack_CB->GetValue();
}
void G::DelHack_BOnClick( wxCommandEvent& event )
{
	xTreeID id = tree_T->GetSelection();
	if ( !id.IsOk() ) return;
	HACK* hack = mGetHack( id );
	if ( hack->id == 0u )
	{
		hack->Clear();
		return;
	}
	tree_T->Delete( id );
}
void G::MoveHack_BOnClick( wxCommandEvent& event )
{
	s32 dir;
	switch ( MoveHack_D->GetSelection() )
	{
		case 0: dir = WXK_UP; break;
		case 2: dir = WXK_LEFT; break;
		case 3: dir = WXK_RIGHT; break;
		default: dir = WXK_DOWN;
	}
	mMoveHack( GetHackID(), dir );
}
void G::GetHacks_BOnClick( wxCommandEvent& event )
{
	mLoadHack();
}
void G::SetHacks_BOnClick( wxCommandEvent& event )
{
	mSaveHack();
}
void G::mShowHack_OnClick( wxCommandEvent& event )
{
	xTreeID id = tree_T->GetSelection();
	gSetHack( mGetHack( id ) );
	SetHack_DLG dlg( this );
	if ( dlg.ShowModal() == wxID_OK )
		mShowHack();
}
