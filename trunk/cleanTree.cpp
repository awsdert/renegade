#include "G.h"
/*
void G::CheckByte( void )
{
	u8 mode = codeType_D->GetSelection();
	u8 loop = codeLoop_SN->GetValue();
	if ( loop > 0 || mode == CT_LIST )
	{
		s8 size = codeSize_D->GetSelection();
		xStr text;
		switch ( size )
		{
			case 1: text = wxT( "x 2 to Address" ); break;
			case 2: text = wxT( "x 4 to Address" ); break;
			case 3: text = wxT( "x 8 to Address" ); break;
			default: text = wxT( "x 1 to Address" ); break;
		}
		codeByteInc_S2->SetLabel( text );
		codeByteInc_P->Show();
		if ( mode != CT_LIST )
		{
			codeSum_P->Show();
		}
		else
		{
			codeSum_P->Hide();
		}
	}
	else
	{
		if ( mode != CT_LIST )
		{
			codeByteInc_P->Hide();
		}
		codeSum_P->Hide();
	}
	code_P->Layout();
}
//*/
void G::tree_TOnSelect( wxTreeEvent& event )
{
	xTreeID id = tree_T->GetSelection();
	gSetHack( mGetHack( id ) );
	mShowHack();
}
void G::tree_TOnKeyUp( wxKeyEvent& event )
{
	bool doEvent = true;
	s32 key = event.GetKeyCode();
	switch ( key )
	{
		case WXK_UP:
		case WXK_LEFT:
		case WXK_RIGHT:
		case WXK_DOWN:
		case WXK_SPACE:
			doEvent = false;
	}
	if ( !doEvent )
	{
		xTreeID tid = GetHackID();
		if ( key == WXK_SPACE )
		{
			HACK* hack = mGetHack( tid );
			hack->use  = !mUseHack_CB->GetValue();
			mUseHack_CB->SetValue( hack->use );
		}
		else
		{
			if ( event.ControlDown() )
			{
				mMoveHack( tid, key );
			}
			else
			{
				doEvent = true;
			}
		}
	}
	event.Skip( doEvent );
}
void G::tree_TOnKeyDown( wxKeyEvent& event )
{
	bool doEvent = true;
	s32 key = event.GetKeyCode();
	xTreeID tid = GetHackID();
	xTreeID id;
	switch ( key )
	{
		case WXK_DOWN:
			if ( tid.IsOk() )
			{
				id = tree_T->GetNextSibling( tid );
			}
			if ( id.IsOk() )
			{
				doEvent = false;
				break;
			}
		case WXK_RIGHT:
			if ( tid.IsOk() && tree_T->HasChildren( tid ) )
			{
				xTreeIDV tidv;
				id = tree_T->GetFirstChild( tid, tidv );
			}
			if ( !id.IsOk() )
			{
				id = tid;
			}
			doEvent = false;
			break;
		case WXK_UP:
			if ( tid.IsOk() )
			{
				id = tree_T->GetPrevSibling( tid );
			}
			if ( id.IsOk() )
			{
				doEvent = false;
				break;
			}
		case WXK_LEFT:
			id = GetHackRoot( tid );
			doEvent = false;
	}
	if ( !doEvent )
	{
		if ( !event.ControlDown() ) tree_T->SelectItem( id );
		else doEvent = true;
	}
	event.Skip( doEvent );
}
void G::tree_TOnBeginDrag( wxTreeEvent& event )
{
	treePrev = event.GetItem();
	event.Allow();
}
void G::tree_TOnEndDrag( wxTreeEvent& event )
{
	xTreeID id   = event.GetItem();
	xTreeID root = GetHackRoot( id );
	xTreeID idf  = treePrev;
	xStr    name = tree_T->GetItemText( idf );
	HACK*   hack = mGetHack( idf );
	xTreeID idt  = mNewHack( root, name, hack, id, ADD_NEXT );
	mMoveHack( idf, idt );
	tree_T->Expand( idt );
	tree_T->SelectItem( idt );
}
