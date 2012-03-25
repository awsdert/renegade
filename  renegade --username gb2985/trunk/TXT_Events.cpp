#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::validateValue( wxKeyEvent& event, u32 valMode )
{
	u32 key = event.GetKeyCode();
	bool doEvent = false;
	wxChar txt = key;
	xStr text = txt;
	text = text.Upper();
	const xStr checkHex = wxT( "0123456789ABCDEF" );
	const xStr checkInt = wxT( "-0123456789" );
	const xStr checkFloat = wxT( "-0123456789." );
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
					case 1u:
						if ( checkInt.Contains( text ) )
						{
							doEvent = true;
						}
						break;
					case 2u:
						if ( checkFloat.Contains( text ) )
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
	event.Skip( doEvent );
}
void ME::validateValue( wxKeyEvent& event, u32 valueMode, s32 valueSize )
{
	u64 uSize;
	switch ( valueSize )
	{
		case 1:
			uSize = 0xFFFF;
			break;
		case 2:
			uSize = 0xFFFFFFFF;
			break;
		case 3:
			uSize = 0u;
			break;
		default:
			uSize = 0xFF;
	}
	u64 value;
	xStr text;
	wxTextCtrl* valueVar_TXT = ( wxTextCtrl* ) event.GetEventObject();
	text = valueVar_TXT->GetValue();
	switch ( valueMode )
	{
		case 1u:
			value = getHEXFromDecimal( text, uSize );
			text.Printf( wxT("%llu"), value );
			break;
		case 3u:
			if ( text != wxT("-") && text != wxT("-0") )
			{
				value = getHEXFromSignedDecimal( text, uSize );
				if ( uSize == 0xFF )
				{
					text.Printf( wxT("%i"), static_cast<s8>(value) );
				}
				else if ( uSize == 0xFFFF )
				{
					text.Printf( wxT("%i"), static_cast<s16>(value) );
				}
				else if ( uSize == 0xFFFFFFFF )
				{
					text.Printf( wxT("%i"), static_cast<s32>(value) );
				}
				else
				{
					text.Printf( wxT("%lli"), value );
				}
			}
			break;
		case 2u:
			value = getHEXFromFloat( text, uSize );
			if ( uSize == 0u )
			{
				text.Printf( wxT("%llf"), value );
			}
			else
			{
				text.Printf( wxT("%f"), static_cast<f32>(value) );
			}
			break;
		default:
			value = getHEX( text, uSize );
			text.Printf( wxT("%llX"), value );
	}
	valueVar_TXT->SetValue( text );
}
void ME::byte_TXTOnKeyDown( wxKeyEvent& event )
{
	validateValue( event, 0u );
}
void ME::byte_TXTOnKeyUp( wxKeyEvent& event )
{
	validateValue( event, 0u, 3 );
}
void ME::search_TXTOnKeyDown( wxKeyEvent& event )
{
	u32 valueMode = searchValueType_D->GetSelection();
	valueMode = ( valueMode == 1u && searchIsSigned_CB->GetValue() ) ? 3u : valueMode;
	validateValue( event, valueMode );
}
void ME::search_TXTOnKeyUp( wxKeyEvent& event )
{
	u32 valueMode = searchValueType_D->GetSelection();
	valueMode = ( valueMode == 1u && searchIsSigned_CB->GetValue() ) ? 3u : valueMode;
	validateValue( event, valueMode, searchSize_D->GetSelection() );
}
void ME::result_TXTOnKeyDown( wxKeyEvent& event )
{
	u32 valueMode = resultHackMode_D->GetSelection();
	validateValue( event, valueMode, findValueLength );
}
void ME::result_TXTOnKeyUp( wxKeyEvent& event )
{
	s32 valueMode = resultHackMode_D->GetSelection();
	s32 valueSize = resultHackSize_D->GetSelection();
	//valueMode = ( valueMode == 1u && isSigned_CB->GetValue() ) ? 3u : valueMode;
	validateValue( event, valueMode, valueSize );
}
void ME::code_TXTOnKeyDown( wxKeyEvent& event )
{
	u32 valueMode = codeMode_D->GetSelection();
	validateValue( event, valueMode, findValueLength );
}
void ME::code_TXTOnKeyUp( wxKeyEvent& event )
{
	s32 valueMode = codeMode_D->GetSelection();
	s32 valueSize = codeSize_D->GetSelection();
	//valueMode = ( valueMode == 1u && isSigned_CB->GetValue() ) ? 3u : valueMode;
	validateValue( event, valueMode, valueSize );
}
