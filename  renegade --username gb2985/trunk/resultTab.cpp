#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::resultHack_GOnSelectCell( wxGridEvent& event )
{
	resultHackRow = event.GetRow();
}
void ME::resultHackAdd_BOnClick( wxCommandEvent& event )
{
	xStr resultHackRAM = wxT( "0" );
	u64 resultHackAddress = getHEX( resultHackAddress_TXT->GetValue() );
	xStr value = resultHackValue_TXT->GetValue();
	xStr valueSize;
	switch ( resultHackSize_D->GetSelection() )
	{
		case 1: valueSize = wxT( '2' ); break;
		case 2: valueSize = wxT( '4' ); break;
		case 3: valueSize = wxT( '8' ); break;
		default: valueSize = wxT( '1' );
	}
	s32 resultHack = -1, i;
	s32 resultHackLength = resultHack_G->GetRows();
	u64 address;
	for ( i = 0; i < resultHackLength; i++ )
	{
		address = getHEX( resultHack_G->GetCellValue(i, 1) );
		if ( address == resultHackAddress )
		{
			if ( resultHackRAM == resultHack_G->GetCellValue( i, 0 ) )
			{
				resultHack = i;
				break;
			}
		}
	}
	if ( resultHack < 0 )
	{
		resultHack = resultHackLength;
		resultHack_G->AppendRows( 1, false );
	}
	xStr text;
	text.Printf( wxT("%01X"), resultHackAddress );
	resultHack_G->SetCellValue( resultHack, 0, resultHackRAM );
	resultHack_G->SetCellValue( resultHack, 1, text );
	resultHack_G->SetCellValue( resultHack, 2, value );
	resultHack_G->SetCellValue( resultHack, 3, valueSize );
}
void ME::resultHackDel_BOnClick( wxCommandEvent& event )
{
	if ( resultHackRow >= 0 )
	{
		resultHack_G->DeleteRows( resultHackRow );
		resultHackRow = -1;
	}
}
