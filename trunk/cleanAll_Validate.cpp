#include "G.h"
xStr lGetName( xStr &text )
{
	xStr txt;
	xStr safe = wxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ+- _()" );
	text.UpperCase();
	wxChar c;
	s32 i = 0;
	while ( ( c = text[ i ] ) )
	{
		if ( safe.Contains( c ) ) txt += text[ i ];
		++i;
	}
	return txt;
}
xStr lGetFile( xStr &text )
{
	xStr txt;
	xStr safe = wxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ+- _()[]." );
	text.UpperCase();
	wxChar c;
	s32 i = 0;
	while ( ( c = text[ i ] ) )
	{
		if ( safe.Contains( c ) ) txt += text[ i ];
		++i;
	}
	return txt;
}
xStr lGetPath( xStr &text )
{
	xStr txt;
	xStr safe = wxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ+- _()[]/\\" );
	text.UpperCase();
	wxChar c;
	s32 i = 0;
	while ( ( c = text[ i ] ) )
	{
		if ( safe.Contains( c ) ) txt += text[ i ];
		++i;
	}
	return txt;
}
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
			if
			(
				tmp.EndsWith( wxT( "." ) ) ||
				tmp.EndsWith( wxT( "e" ) ) ||
				tmp.EndsWith( wxT( "E" ) )
			)
			return;
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
		case VAL_NAME: text = lGetName( tmp ); break;
		case VAL_PATH: text = lGetPath( tmp ); break;
		case VAL_FILE: text = lGetFile( tmp ); break;
		default: text = tmp;
	}
	obj->ChangeValue( text );
	pos = ( pos > text.length() ) ? text.length() : pos;
	obj->SetInsertionPoint( pos );
}
