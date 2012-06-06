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
	if ( col >= 16 ) return;
	isEdit = true;
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
void G::edit_GOnSelect(    wxGridEvent& event )
{
	s32 row = event.GetRow();
	s32 col = event.GetCol();
	if ( row < 0 || col < 0 )
	{
		wxGridCellCoordsArray array = edit_G->GetSelectionBlockTopLeft();
		wxGridCellCoords cell;
		if ( array.GetCount() > 0 )
		{
			cell = array[ 0 ];
			if ( row < 0 ) row = cell.GetRow();
			if ( col < 0 ) col = cell.GetCol();
		}
		if ( row < 0 || col < 0 )
		{
			array = edit_G->GetSelectedCells();
			if ( array.GetCount() > 0 )
			{
				cell = array[ 0 ];
				if ( row < 0 ) row = cell.GetRow();
				if ( col < 0 ) col = cell.GetCol();
			}
			if ( row < 0 || col < 0 )
			{
				wxArrayInt rows, cols;
				rows = edit_G->GetSelectedRows();
				cols = edit_G->GetSelectedCols();
				if ( row < 0 && !( row = rows[ 0 ] ) ) row = 0;
				if ( col < 0 && !( col = cols[ 0 ] ) ) col = 0;
			}
		}
	}
	bool doEvent = ( col < 16 );
	event.Skip( doEvent );
	isFocus = true;
	editRow = row;
	editCol = col;
}
bool isLastUp = false;
void G::edit_GOnMouseWheel( wxMouseEvent& event )
{
	event.Skip();
	// When move to 2.9.4 onwards this will replace current detection.
//	if ( event.GetWheelAxis() != wxMOUSE_WHEEL_VERTICAL ) return;
	s32 x  = 0, y  = 0;
	s32 xS = 0, yS = 0;
	edit_G->GetViewStart( &xS, &yS );
	s32 r = event.GetWheelRotation();
	edit_G->CalcUnscrolledPosition( xS, yS, &x, &y );
	bool isXScrolling = ( x != editX );
	bool isYScrolling = ( y != editY );
	if ( !isXScrolling && !isYScrolling )
	{
		u64 byte = GetHex( editGet_TXT->GetValue() );
		if ( byte > 0u )
		{
			while ( ( byte % 0x10  ) > 0 ) byte--;
			while ( ( byte % 0x100 ) > 0 ) byte -= 0x10;
		}
		if ( r < 0 )
		{
			if ( !isLastUp ) byte += 0x100;
		}
		else if ( byte > 0u )
		{
			if ( isLastUp ) byte -= 0x100;
		}
		xStr text;
		text.Printf( hexVLL, byte );
		editGet_TXT->ChangeValue( text );
		FillEditor();
		edit_G->Scroll( xS, yS );
	}
	editX = x;
	editY = y;
	isLastUp = ( r >= 0 );
}
