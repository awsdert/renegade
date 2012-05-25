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
	FillEditor();
	DelHook();
}
void G::editSetItem( wxGridEvent& event )
{
	isFocus = true;
	editRow = event.GetRow();
	editCol = event.GetCol();
}
void G::editSet_BOnClick( wxCommandEvent& event )
{
	u8  size    = gGetUSize( editSize_D->GetSelection() );
	u64 address = GetHex( editSet_TXT->GetValue() );
	u64 value   = GetHex( editValue_TXT->GetValue(), size );
	editSetRam( address, value, size );
}
void G::edit_GOnSelect(    wxGridEvent& event )
{
	editSetItem( event );
}
void G::edit_GOnEdit( wxGridEvent& event )
{
	isEdit = false;
	s32 col = event.GetCol();
	if ( col >= 0 && col < 16 )
	{
		isEdit = true;
	}
	event.Skip( isEdit );
}
void G::edit_GOnMouseWheel( wxMouseEvent& event )
{
	event.Skip();
	// FIXME: Get rid of In/Decrement at Top/Bottom after 1st MouseWheel in opposite direction
	// When move to 2.9.4 onwards this will replace current detection.
//	if ( event.GetWheelAxis() != wxMOUSE_WHEEL_VERTICAL ) return;
	wxWindowDC dc( edit_G );
	s32 x  = 0, y  = 0;
	s32 xS = 0, yS = 0;
	s32 xP = 0, yP = 0;
	s32 xE = 0, yE = 0;
	edit_G->GetViewStart(   &xS, &yS );
	edit_G->GetVirtualSize( &xP, &yP );
	s32 d  = event.GetWheelDelta();
	s32 d2 = floor( d / 2 );
	xE = dc.DeviceToLogicalX( xP ) + d + d2;
	yE = dc.DeviceToLogicalY( yP ) + d + d2;
	edit_G->CalcUnscrolledPosition( xS, yS, &x, &y );
	bool isXScrolling = ( x > 0 && x < xE );
	bool isYScrolling = ( y > 0 && y < yE );
	if ( !isXScrolling && !isYScrolling )
	{
		u64 byte = GetHex( editGet_TXT->GetValue() );
		if ( byte > 0u )
		{
			while ( ( byte % 0x10  ) > 0 ) byte--;
			while ( ( byte % 0x100 ) > 0 ) byte -= 0x10;
		}
		if ( event.GetWheelRotation() < 0 ) byte += 0x100;
		else if ( byte > 0u ) byte -= 0x100;
		xStr text;
		text.Printf( hexVLL, byte );
		editGet_TXT->ChangeValue( text );
		FillEditor();
		edit_G->Scroll( xS, yS );
	}
}
