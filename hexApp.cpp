/***************************************************************
 * Name:      hexApp.cpp
 * Purpose:   Code for Application Class
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/


#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "cleanAll.h"
#include "G.h"
IMPLEMENT_APP( hexApp );
s32 MB( xStr text, xStr title, s32 mode )
{
	return wxMessageBox( text, title, mode );
}
G*    rootWindow;
xStr  gTitle  = wxT( "HackerEX" );
xStr  gVendor = wxT( "Shadow Flare Industries" );
xStr  gSlash;
xAStr gArea;
xAStr gSizes;
xAStr gTests;
bool hexApp::OnInit() {
	gArea.SetCount( AREA_COUNT );
	gArea[ AREA_UK_CB  ] = wxT( "UK"  );
	gArea[ AREA_US_CB  ] = wxT( "US"  );
	gArea[ AREA_JP_CB  ] = wxT( "JP"  );
	gArea[ AREA_DE_CB  ] = wxT( "DE"  );
	gArea[ AREA_AUS_CB ] = wxT( "AUS" );
	gSizes.SetCount( SIZE_COUNT );
	gSizes[ SIZE_8  ] = wxT( "8bit"  );
	gSizes[ SIZE_16 ] = wxT( "16bit" );
	gSizes[ SIZE_32 ] = wxT( "32bit" );
	gSizes[ SIZE_64 ] = wxT( "64bit" );
	gTests.SetCount( FIND_COUNT );
	gTests[ FIND_EQUAL ] = wxT( "Equal to"              );
	gTests[ FIND_NOTE  ] = wxT( "Not Equal to"          );
	gTests[ FIND_GT    ] = wxT( "More Than"             );
	gTests[ FIND_GTE   ] = wxT( "More Than or Equal to" );
	gTests[ FIND_LT    ] = wxT( "Less Than"             );
	gTests[ FIND_LTE   ] = wxT( "Less Than or Equal to" );
	gTests[ FIND_BIN   ] = wxT( "Contains"              );
	gSetQTests();
	gSlash     = wxGetCwd().Contains( wxT( "\\" ) ) ? wxT( "\\" ) : wxT( "/" );
	rootWindow = new G( 0 );
	rootWindow->SetIcon( wxICON( NULL ) );
	rootWindow->Show();
	return true;
}
xStr  gGetTitle(  void ) { return gTitle;  }
xStr  gGetVendor( void ) { return gVendor; }
xStr  gGetSlash(  void ) { return gSlash;  }
xAStr gGetArea(   void ) { return gArea;   }
void  gEnable( bool enable, wxWindow* obj )
{
	if ( !enable )
	{
		obj->Disable();
		obj->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	}
	else
	{
		obj->Enable();
		obj->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	}
}
xAStr gGetSizes( void ) { return gSizes; }
xAStr gGetTests( void ) { return gTests; }
u8   gGetUSize( s8 size )
{
	u8 value = 0u;
	switch ( size )
	{
		case SIZE_16: value = 2u; break;
		case SIZE_32: value = 4u; break;
		case SIZE_64: value = 8u; break;
		default: value = 1u;
	}
	return value;
}
s8   gGetSSize( u8 size )
{
	s8 value = -1;
	switch ( size )
	{
		case 2u: value = SIZE_16; break;
		case 4u: value = SIZE_32; break;
		case 8u: value = SIZE_64; break;
		default: value = SIZE_8;
	}
	return value;
}
void gClose( wxDialog* d )
{
	if ( !d->IsModal() ) d->Close();
	else  d->EndModal( wxID_OK );
}
void ValidateFileName( wxKeyEvent& event )
{
	s32    key     = event.GetKeyCode();
	bool   doEvent = false;
	wxChar c       = key;
	xStr   text    = c;
	xStr   safe    = wxT( "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ (-)" );
	text.UpperCase();
	switch ( key )
	{
		default:
			if ( key <= 255 && !safe.Contains( text ) ) break;
		case WXK_BACK:
		case WXK_DELETE:
		case WXK_INSERT:
		case WXK_LEFT:
		case WXK_RIGHT:
		case WXK_UP:
		case WXK_DOWN:
			doEvent = true;
	}
	event.Skip(doEvent);
}
#ifdef WIN32
BOOL CALLBACK EnumWindowsMSW( HWND winHandle, LPARAM winLength )
{
	if ( IsWindowVisible( winHandle ) )
	{
		wxString xAppID, xAppExe, xTitle;
		// Process ID
		DWORD appID;
		GetWindowThreadProcessId( winHandle, &appID );
		xAppID.Printf( wxT( "%08X" ), appID );
		// Executable
		xAppExe = GetAppExe( appID );
		// Window Caption
		TCHAR title[ MAXCHAR ];
		SendMessage( winHandle, WM_GETTEXT, MAXBYTE, (LPARAM)(void*)title );
		xTitle.Printf( wxT( "%s" ), title );
		// Finish up
		if ( xTitle != wxT("") )
		{
			rootWindow->AddApp( xAppID, xAppExe, xTitle );
		}
	}
	return TRUE;
}
#endif
