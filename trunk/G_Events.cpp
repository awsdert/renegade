#include "G.h"
void G::NewHook( void )
{
	++isHooked;
	if ( isHooked > 1 ) return;
	xStr binFile = binBind_TXT->GetValue();
	if ( hookApp )
	{
		appHandle = GetAppHandle( binFile );
	}
	else
	{
		xStr binPath = binPath_TXT->GetValue();
		xStr text = binPath + gGetSlash() + binFile;
		if ( !bin_BF.Exists( text ) )
		{
			bin_BF.Create( text );
		}
		bin_BF.Open( text );
	}
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
void G::DelHook( void )
{
	--isHooked;
	if ( isHooked > 0 ) return;
	if ( hookApp )
	{
#ifdef __WXMSW__
		CloseHandle( appHandle );
#else
		appHandle = NULL;
#endif
	}
	else
	{
		bin_BF.Close();
	}
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
void G::GOnIdle( wxIdleEvent& event )
{
	bool doEvent = false;
	s32 panelIndex = cleanFRM_NB->GetSelection();
	xLL now = wxGetLocalTimeMillis();
	if ( hookAdd > 0u )
	{
		doEvent = true;
		if ( now >= hookUntil )
		{
			UseHook();
		}
	}
	if ( listAdd > 0u && panelIndex == 0 )
	{
		doEvent = true;
		if ( now >= listUntil )
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
	if ( editAdd > 0u && panelIndex == 3 )
	{
		doEvent = true;
		if ( now >= editUntil )
		{
			FillEditor();
		}
	}
	event.Skip();
	event.RequestMore( doEvent );
}
void G::name_TXTOnChange( wxCommandEvent& event ){}
void G::path_TXTOnChange( wxCommandEvent& event ){}
void G::file_TXTOnChange( wxCommandEvent& event ){}
