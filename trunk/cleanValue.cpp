#include "G.h"
void G::byte_TXTOnChange( wxCommandEvent& event )
{
	doChange( event, VAL_HEX, 3 );
}
void G::byte_TXTOnKeyDown( wxKeyEvent& event )
{
	doKeyDown( event, VAL_HEX );
}
