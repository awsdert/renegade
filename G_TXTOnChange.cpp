#include "G.h"
void G::out_TXTOnChange( wxCommandEvent& event )
{
	s8 mode = outMode_D->GetSelection();
	s8 size = outSize_D->GetSelection();
	doChange( event, mode, size );
}
void G::edit_TXTOnChange( wxCommandEvent& event )
{
	s8 mode = editMode_D->GetSelection();
	s8 size = editSize_D->GetSelection();
	doChange( event, mode, size );
}
