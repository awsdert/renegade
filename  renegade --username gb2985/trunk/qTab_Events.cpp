/***************************************************************
 * Name:      qTab_Events.cpp
 * Purpose:   Code for Search Tab
 * Author:    awsdert ()
 * Created:   2012-02-13
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::compare_DOnChoice( wxCommandEvent& event )
{
	s32 findNo = compare_D->GetSelection();
	if ( findNo > 0 )
	{
		searchRAM_D->Disable();
	}
	else
	{
		searchRAM_D->Enable();
	}
}
void ME::searchValueType_DOnChoice( wxCommandEvent& event )
{
	s32 value = searchValueType_D->GetSelection();
	if ( value > 0 )
	{
		searchIsSigned_CB->Enable();
	}
	else
	{
		searchIsSigned_CB->SetValue( false );
		searchIsSigned_CB->Disable();
	}
}
void ME::search_OnClick( s32 searchType )
{
	if ( searchType > -1 )
	{
		searchType_D->Select( searchType );
	}
	Seek( compare_D->GetSelection() );
}
void ME::search_BOnClick( wxCommandEvent& event )
{
	search_OnClick( -1 );
}
void ME::dump_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_DUMP );
}
void ME::searchGT_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_GT );
}
void ME::searchGTE_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_GTE );
}
void ME::searchEqual_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_EQUAL );
}
void ME::searchNOTE_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_NOTE );
}
void ME::searchLTE_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_LTE );
}
void ME::searchLT_BOnClick( wxCommandEvent& event )
{
	search_OnClick( TMU_LT );
}
void ME::searchUndo_BOnClick( wxCommandEvent& event )
{
	s32 findNo = compare_D->GetSelection();
	findNo--;
	if ( findNo > 0 )
	{
		compare_D->Clear();
		u64 xLength = findNo - 1;
		u64 xIndex;
		xStr text;
		const wxChar* searchText = wxT("Search %1");
		compare_D->Append( wxT("Dump") );
		for (xIndex = 1; xIndex < ( xLength + 1 ); xIndex++)
		{
			text.Printf( searchText, xIndex );
			compare_D->Append( text );
		}
		compare_D->Select( xLength );
	}
}
