#include "G.h"
#include <wx/dcclient.h>
void G::editByte_BOnClick( wxCommandEvent& event )
{
	FillEditor();
}
void G::editShow_BOnClick(    wxCommandEvent& event )
{
	if ( !editOptions_P->IsShown() )
	{
		editOptions_P->Show();
		editShow_B->SetLabel( wxT( "-" ) );
	}
	else
	{
		editOptions_P->Hide();
		editShow_B->SetLabel( wxT( "+" ) );
	}
	edit_P->Layout();
}
void G::editUpdate_DOnChoice( wxCommandEvent& event )
{
	hookAdd  = 0u;
	listAdd  = 0u;
	UseHook_D->Select( 0 );
	ListApps_D->Select( 0 );
	s32 mode = editUpdate_D->GetSelection();
	SetTime( editAdd, mode );
	if ( mode > 0 )
	{
		FillEditor();
	}
}
void G::editGet_BOnClick( wxCommandEvent& event )
{
	hookAdd = 0u;
	listAdd = 0u;
	UseHook_D->Select( 0 );
	ListApps_D->Select( 0 );
	FillEditor();
}
void G::editSetRam( u64 address, u64 value, u8 size )
{
	NewHook();
	u8  ramNo = editRam_D->GetSelection();
	address  += mGetRamByte( ramNo );
	if ( hookApp ) SetRamX( appHandle, address, &value, size );
	else
	{
		bin_BF.Seek( address, wxFromStart );
		bin_BF.Write( &value, size );
	}
	DelHook();
}
void G::editSet_BOnClick( wxCommandEvent& event )
{
	u8  size    = gGetUSize( editSize_D->GetSelection() );
	u64 address = GetHex( editSet_TXT->GetValue() );
	u64 value   = GetHex( editValue_TXT->GetValue(), size );
	editSetRam( address, value, size );
	FillEditor();
}
void G::edit_GOnEditBegin( wxGridEvent& event )
{
	s32 col = event.GetCol();
	if ( col >= 16 ) event.Veto();
	else isEdit = true;
	event.Skip();
}
void G::edit_GOnEditEnd(   wxGridEvent& event )
{
	u8   col  = event.GetCol();
	if ( col >= 16u || editIsRecursing > 0 ) return;
	++editIsRecursing;
	u8   row  = event.GetRow();
	xStr text = edit_G->GetCellValue( row, col );
	u64  address = GetHex( edit_G->GetRowLabelValue( row ) );
	address  += col;
	u8   size;
	u8   len = text.length();
	if (      len < 2u ) size = 1u;
	else if ( len < 4u ) size = 2u;
	else if ( len < 8u ) size = 4u;
	else                 size = 8u;
	editSetRam( address, GetHex( text, size ), size );
	FillEditor();
	isEdit    = false;
	--editIsRecursing;
}
bool lFromUser = false;
void G::edit_TXTOnMouseWheel( wxMouseEvent& event )
{
	u64 address = GetHex( editGet_TXT->GetValue() );
	while ( ( address % 0x10  ) > 0u ) --address;
	while ( ( address % 0x100 ) > 0u ) address -= 0x10;
	if ( event.GetWheelRotation() >= 0 )
	{
		if ( address > 0u ) address -= 0x100;
	}
	else
	{
		if ( address < UINT64_MAX ) address += 0x100;
	}
	xStr txt;
	txt.Printf( hexVLL, address );
	editGet_TXT->ChangeValue( txt );
	FillEditor();
}
void G::edit_GOnMouseWheel( wxMouseEvent& event )
{
	event.Skip();
	s32 r = event.GetWheelRotation();
	editScroll( r, true );
}
void G::editScroll( s32 direction, bool fromUser, s32 orient )
{
	if ( orient != wxVERTICAL || !fromUser ) return;
	s32 xS = 0, yS = 0;
	s32 w  = 0, h  = 0;
	s32 xL = 0, yL = 0;
	edit_G->GetViewStart( &xS, &yS );
	edit_G->GetScrollPixelsPerUnit( &xL, &yL );
	s32 x  = xS * xL;
	s32 y  = yS * yL;
	edit_G->GetClientSize( &w, &h );
	lFromUser = false;
	++editIsRecursing;
	if ( ( y <= 0 || y >= h ) && ( x <= 0 || x >= w ) )
	{
		u64 address = GetHex( editGet_TXT->GetValue() );
		while ( ( address % 0x10  ) > 0u ) --address;
		while ( ( address % 0x100 ) > 0u ) address -= 0x10;
		if ( direction >= 0 )
		{
			if ( address > 0u && y <= 0 ) address -= 0x100;
		}
		else
		{
			if ( address < UINT64_MAX && y >= h ) address += 0x100;
		}
		xStr txt;
		txt.Printf( hexVLL, address );
		editGet_TXT->ChangeValue( txt );
		FillEditor();
	}
	--editIsRecursing;
}
void G::edit_GOnKeyDown( wxKeyEvent&   event )
{
	lFromUser = true;
	event.Skip();
}
/*
void G::edit_GOnPaint( wxPaintEvent& event )
{
	if ( !mSetEditor )
	{
		editRow = edit_G->GetGridCursorRow();
		editCol = edit_G->GetGridCursorCol();
		edit_G->GetViewStart( &editX, &editY );
	}
	edit_G->ClearSelection();
	edit_G->SetGridCursor( editRow, editCol );
	edit_G->Scroll( editX, editY );
	mSetEditor = false;
	///
	event.Skip();
}
//*/
/*
void G::edit_GOnUpdate( wxUpdateUIEvent& event )
{
	if ( mSetEditor == 2 ) mSetEditor = 3;
	event.Skip();
}
//*/
