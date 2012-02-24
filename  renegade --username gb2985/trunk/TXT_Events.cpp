#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::validateValue(wxKeyEvent& event, u32 valMode)
{
	u32 key = event.GetKeyCode();
	bool doEvent = false;
	wxChar txt = key;
	xStr text = txt;
	text = text.Upper();
	xStr checkHex = wxT( "0123456789ABCDEF" );
	xStr checkInt = wxT( "0123456789" );
	xStr checkDec = wxT( "0123456789." );
	if ( key > 255 )
	{
		doEvent = true;
	}
	else
	{
		switch ( key )
		{
			case WXK_BACK:
			case WXK_DELETE:
			case WXK_INSERT:
			case WXK_LEFT:
			case WXK_RIGHT:
			case WXK_UP:
			case WXK_DOWN:
				doEvent = true;
				break;
			default:
				switch ( valMode )
				{
					case 1:
						if ( checkInt.Contains( text ) )
						{
							doEvent = true;
						}
						break;
					case 2:
						if ( checkDec.Contains( text ) )
						{
							doEvent = true;
						}
						break;
					default:
						if ( checkHex.Contains( text ) )
						{
							doEvent = true;
						}
				}
		}
	}
	event.Skip(doEvent);
}
void ME::address_TXTOnKeyDown(wxKeyEvent& event)
{
	validateValue(event);
}
void ME::value_TXTOnKeyDown(wxKeyEvent& event)
{
	validateValue(event);
}
