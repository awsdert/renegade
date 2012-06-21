#include "G.h"
void G::byte_TXTOnChange( wxCommandEvent& event )
{
	doChange( event, VAL_HEX, 3 );
	if ( event.GetId() == editGet_ID ) FillEditor();
}
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
void G::name_TXTOnChange( wxCommandEvent& event ) { doChange( event, VAL_NAME ); }
void G::path_TXTOnChange( wxCommandEvent& event ) { doChange( event, VAL_PATH ); }
void G::file_TXTOnChange( wxCommandEvent& event ) { doChange( event, VAL_FILE ); }
