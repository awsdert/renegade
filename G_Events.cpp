#include "G.h"
void G::NewHook( void )
{
	++isHooked;
	if ( isHooked > 1 ) return;
	xStr binPath = binPath_TXT->GetValue();
	xStr binFile = binBind_TXT->GetValue();
	xStr text = binPath + gGetSlash() + binFile;
	if ( hookApp )
	{
		appHandle = GetAppHandle( binFile );
		if ( appHandle == NULL )
		{
			if ( LaunchExe( text ) )
				appHandle = GetAppHandle( binFile );
		}
		if ( appHandle == NULL ) --isHooked;
	}
	else
	{
		if ( !wxFileExists( text ) ) --isHooked;
		else bin_BF.Open( text );
	}
}
void G::DelHook( void )
{
	--isHooked;
	if ( isHooked > 0 ) return;
	if ( isHooked < 0 ) isHooked = 0;
	if ( hookApp ) DelAppHandle( appHandle );
	else bin_BF.Close();
}
u32  G::mGetRam( u64 &ramStart, u64 &ramEnd, s8 ramNo )
{
	if ( ramNo < 0 ) ramNo = 0;
		ramStart = mGetRamByte( ramNo );
		ramEnd   = mGetRamSize( ramNo );
	u64 appSize  = 0u;
	if ( hookApp )
	{
		if ( !GetAppSize( appHandle, appSize ) )
			return 0u;
	}
	else appSize = bin_BF.Length();
	u32 useSize = ( ramEnd < readSize ) ? ramEnd : readSize;
	if ( ramEnd > appSize ) ramEnd = appSize;
	return useSize;
}
void G::SetTime( void )
{
	xLL now = wxGetLocalTimeMillis();
	hookUntil = now + hookAdd;
	listUntil = now + listAdd;
	editUntil = now + editAdd;
}
void G::SetTime( u32 &value, s32 mode )
{
	u32 sec  = 1000u;
	u32 min  = 60000u;
	switch ( mode )
	{
		case  1: value = 500u;      break;
		case  2: value = sec;       break;
		case  3: value = sec *  5u; break;
		case  4: value = sec * 30u; break;
		case  5: value = min;       break;
		case  6: value = min *  5u; break;
		case  7: value = min * 30u; break;
		case  8: value = min * 60u; break;
		default: value = 0u;
	}
}
bool lDoHook = false;
bool lDoEdit = false;
bool lDoList = false;
void G::GOnIdle( wxIdleEvent& event )
{
	bool doEvent = false;
	s32 panelIndex = cleanFRM_NB->GetSelection();
	xLL now = wxGetLocalTimeMillis();
	lDoHook = ( hookAdd > 0u );
	lDoList = ( listAdd > 0u && panelIndex == 0 );
	lDoEdit = ( editAdd > 0u && panelIndex == 3 );
	if ( lDoHook )
	{
		doEvent = true;
		if ( now >= hookUntil ) UseHook();
	}
	if ( lDoList )
	{
		doEvent = true;
		if ( now >= listUntil )
		{
			if ( ListApps_RB->GetValue() ) ListApps();
			else ListWindows();
		}
	}
	if ( lDoEdit )
	{
		doEvent = true;
		if ( now >= editUntil ) FillEditor();
	}
	event.Skip();
	event.RequestMore( doEvent );
}
