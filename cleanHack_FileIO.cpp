#include "G.h"
void G::mLoadHack( void )
{
	s32   mode = 0, index, count;
	xStr  txt, text, path, file, name;
	xStrT st;
	xAStr array;
	HACK* hack = new HACK;
	CODE  code;
	u32   tmp;
	tree_T->DeleteAllItems();
	xTreeID root, doNotModifyThisTreeId;
	gGetHackFile( path, file );
	wxTextFile file_TF;
	file_TF.Open( file );
	mNewHack( GetHackRoot(), wxT( "(m)" ), hack, doNotModifyThisTreeId );
	for
	(
		text = file_TF.GetFirstLine();
			  !file_TF.Eof();
		text = file_TF.GetNextLine()
	)
	{
		switch ( mode )
		{
			case 0: case 2:
				if ( text.StartsWith( wxT( "\"" ) ) )
				{
					if ( mode == 2 )
					{
						index = 0;
						count = array.GetCount();
						for ( ; index < count; )
						{
							BuildCode( code, index, array );
							hack->NewCode( code );
						}
						if ( hack->id == 0u ) mSetHack( root, hack );
						else mNewHack( root, name, hack, doNotModifyThisTreeId );
					}
					hack->Clear();
					array.Clear();
					st.SetString( text, wxT( '"' ) );
					st.GetNextToken();
					name = st.GetNextToken();
					mode = 1;
				}
				else if ( mode == 2 ) array.Add( text );
				break;
			case 1:
				hack->id    = GetHex( text.Mid( 4, 4 ) );
				tmp         = GetHex( text.Left( 4 )   );
				hack->use   = ( ( tmp & HACK_USE ) > 0u );
				hack->useRB = ( ( tmp & HACK_RB  ) > 0u );
				if ( hack->id != 0u )
				{
					tmp  = GetHex( text.Mid( 13, 4 ), 2u );
					root = mFindHack( tmp );
				}
				else root = GetHackRoot();
				mode = 2;
		}
	}
	if ( mode == 2 )
	{
		index = 0;
		count = array.GetCount();
		for ( ; index < count; )
		{
			BuildCode( code, index, array );
			hack->NewCode( code );
		}
		if ( hack->id == 0u ) mSetHack( root, hack );
		else mNewHack( root, name, hack, doNotModifyThisTreeId );
	}
	delete hack;
	tree_T->SelectItem( GetHackRoot() );
}
void G::mSaveHack( void )
{
	xStr path, file;
	u16  id = 0u;
	gGetHackFile( path, file );
	hack_TF.Open( file );
	hack_TF.Clear();
	mSaveHack( GetHackRoot(), id, 0u );
	hack_TF.Write( wxTextFileType_Dos );
	hack_TF.Close();
}
void G::mSaveHack( xTreeID root, u16 &id, u16 parentID )
{
	HACK*   hack = mGetHack( root );
	xStr    text = tree_T->GetItemText( root );
	u16     head = 0u;
	if ( hack->use   ) head += HACK_USE;
	if ( hack->useRB ) head += HACK_RB;
	hack_TF.AddLine( wxT( '"' ) + text + wxT( '"' ), wxTextFileType_Dos );
	text.Printf( hex16 + hex16 + wxT( " 0000" ) + hex16, head, id, parentID );
	hack_TF.AddLine( text, wxTextFileType_Dos );
	xAStr array;
	s16 iCount = hack->GetCount();
	s16 j, jCount;
	for ( s16 i = 0; i < iCount; ++i )
	{
		array  = BuildCode( ( *hack )[ i ] );
		jCount = array.GetCount();
		for ( j = 0; j < jCount; ++j )
			hack_TF.AddLine( array[ j ], wxTextFileType_Dos );
	}
	// Iterate through children
	parentID = id;
	++id;
	xTreeID  kid;
	xTreeIDV cookie;
	for
	(
		kid = tree_T->GetFirstChild( root, cookie );
		kid.IsOk();
		kid = tree_T->GetNextChild(  root, cookie )
	)
	{
		mSaveHack( kid, id, parentID );
	}
}
