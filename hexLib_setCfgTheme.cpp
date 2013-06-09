#include "hexLib_main.h"
void hexLib::setCfgTheme( Text name )
{
	M_FILE* now = null;
	btnArray *next = null, *prev = null;
	wxButton *btn = null;
	wxBitmap bmpBtn[ BTN_COUNT ];
	// TODO: finish setCfgTheme
	si32 i = HEX_LIST_THEME, j;
	for ( ; i < HEX_LIST_COUNT; ++i )
	{
		now = m_listFile[ i ];
		if ( now == null )
			continue;
		next = &now->btn_main;
		for ( j = BTN_LOAD; j < BTN_COUNT; ++j )
		{
			btn = next->at( j );
			if ( btn == prev->at( j ) )
				break;
			btn->SetImageLabel( bmpBtn[ j ] );
		}
		prev = next;
	}
}