#include "G.h"
// - List Apps
void G::AddApp( wxString id, wxString exe, wxString title )
{
	s16 length = ListApps_LC->GetItemCount();
	wxListItem item;
	item.SetId( length );
	s16 index = ListApps_LC->InsertItem( item );
	ListApps_LC->SetItem( index, 0, id );
	ListApps_LC->SetItem( index, 1, exe );
	ListApps_LC->SetItem( index, 2, title );
}
void G::ListApps( void )
{
	xStr id, exe, title;
	const wxChar* idText = wxT( "%08X" );
	const wxChar* exeText = wxT( "%s" );
	SetTime();
	ListApps_LC->DeleteAllItems();
#ifdef WIN32
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	HANDLE snapShot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	Process32First( snapShot, &pe32 );
	do {
		id.Printf( idText, pe32.th32ProcessID );
		exe.Printf( exeText, pe32.szExeFile );
		AddApp( id, exe, title );
	} while ( Process32Next( snapShot, &pe32 ) );
#endif
}
void G::ListWindows( void )
{
	SetTime();
	ListApps_LC->DeleteAllItems();
#ifdef WIN32
	EnumWindows( EnumWindowsMSW, 0u );
#endif
}
s32 G::GetListLength( void )
{
	return ListApps_LC->GetItemCount();
}
void G::ListApps_BOnClick( wxCommandEvent& event )
{
	if ( ListApps_RB->GetValue() )
	{
		ListApps();
	}
	else
	{
		ListWindows();
	}
}
void G::ListApps_DOnChoice( wxCommandEvent& event )
{
	hookAdd  = 0u;
	editAdd  = 0u;
	UseHook_D->Select( 0 );
	editUpdate_D->Select( 0 );
	s32 mode = ListApps_D->GetSelection();
	SetTime( listAdd, mode );
	if ( mode > 0 )
	{
		if ( ListApps_RB->GetValue() )
		{
			ListApps();
		}
		else
		{
			ListWindows();
		}
	}
}
void G::UseApp_BOnClick( wxCommandEvent& event )
{
	s32 index = 0;
	s32 count = ListApps_LC->GetItemCount();
	u32 state = 0;
	wxListItem item;
	for ( ; index < count; ++index )
	{
		item.SetId( index );
		item.SetColumn( 1 );
		ListApps_LC->GetItem( item );
		state = item.GetState();
		if ( state > 0u )
		{
			break;
		}
	}
	binBind_TXT->SetValue( item.GetText() );
}
