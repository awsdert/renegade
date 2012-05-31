#include "G.h"
void doChange( wxCommandEvent& event, s32 mode, s32 theSize )
{
	wxTextCtrl* obj = ( wxTextCtrl* )event.GetEventObject();
	u64 pos = obj->GetInsertionPoint();
	u64 value;
	u8 size;
	switch ( theSize )
	{
		case 1: size = 2u; break;
		case 2: size = 4u; break;
		case 3: size = 8u; break;
		default: size = 1u;
	}
	xStr text, tmp = obj->GetValue();
	switch ( mode )
	{
		case VAL_HEX:
			value = GetHex( tmp, size );
			text.Printf( hexVLL, value );
			break;
		case VAL_UINT:
			value = GetHexFromU64( tmp, size );
			text.Printf( wxT( "%01llu" ), value );
			break;
		case VAL_SINT:
			value = GetHexFromS64( tmp, size );
			text.Printf( wxT( "%01lli" ), value );
			break;
		case VAL_SFLT:
			if ( tmp.EndsWith( wxT( "." ) ) ) return;
			value = GetHexFromF64( tmp, size );
			if ( size == 4u )
			{
				f32 v32 = gHexToF32( value );
				text.Printf( wxT("%01g"), v32 );
			}
			else if ( size == 8u )
			{
				text.Printf( wxT("%01lg"), value );
			}
			break;
		default: text = tmp;
	}
	obj->ChangeValue( text );
	pos = ( pos > text.length() ) ? text.length() : pos;
	obj->SetInsertionPoint( pos );
}
void doKeyDown( wxKeyEvent& event, s32 mode )
{
	bool doEvent = false;
	s32 key = event.GetKeyCode();
	if ( key > WXK_START )
	{
		doEvent = true;
	}
	else
	{
		wxChar c = key;
		xStr text = c;
		text.Upper();
		c = text[ 0 ];
		switch ( key )
		{
			case WXK_RETURN:
			case WXK_TAB:
			case WXK_BACK:
			case WXK_DELETE:
			case WXK_INSERT:
			case WXK_UP:
			case WXK_LEFT:
			case WXK_RIGHT:
			case WXK_DOWN:
				doEvent = true;
		}
		if ( !doEvent )
		{
			wxTextCtrl* obj = ( wxTextCtrl* )event.GetEventObject();
			xStr text = obj->GetValue();
			u64 pos = obj->GetInsertionPoint();
			switch ( mode )
			{
				case VAL_HEX:
					doEvent = ( IsBetween( c, c0, c9 ) || IsBetween( c, cA, cF ) );
					break;
				case VAL_UINT:
					doEvent = IsBetween( c, c0, c9 );
					break;
				case VAL_SINT:
					if ( c == cNeg && !text.Contains( cNeg ) && pos == 0 )
					{
						doEvent = true;
					}
					else if ( IsBetween( c, c0, c9 ) )
					{
						doEvent = true;
					}
					break;
				case VAL_SFLT:
					if ( c == cNeg && !text.Contains( cNeg ) && pos == 0 )
					{
						doEvent = true;
					}
					else if ( c == cDot && !text.Contains( cDot ) )
					{
						doEvent = true;
					}
					else if ( IsBetween( c, c0, c9 ) )
					{
						doEvent = true;
					}
					break;
				case VAL_COUNT:
					doEvent = true;
			}
		}
	}
	event.Skip( doEvent );
}
