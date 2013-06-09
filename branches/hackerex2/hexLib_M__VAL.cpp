#include "hexLib_main.h"

M__VAL::M__VAL( void )
{
	m_type = 0u;

	p____main	= null;
	lbl__main	= null;
	tbox_main	= null;

	lbl__type	= null;
	dd___type	= null;

	lbl__size	= null;
	tbox_size	= null;
	spb__size	= null;
}
void M__VAL::lib_show( void )
{
	Text txt;
	switch ( m_type )
	{
	case VAL_SI:
	case VAL_UI:
		txt = m_val.toString().data();
		break;
	case VAL_SF_IEEE754:
		txt = m_getFloat( m_val.m_data, m_val.m_size );
	case VAL_TEXT:
		txt = txt.FromAscii( (char*)m_val.m_data );
		break;
	case VAL_WTEXT:
		txt.Printf( wxT("ls"), (wchar_t*)m_val.m_data );
		break;
	case VAL_UTF8:
		txt = txt.FromUTF8( (char*)m_val.m_data );
		break;
	case VAL_BIN:
		txt = m_val.toString( 2u ).data();
		break;
	default:
		txt = m_val.toString( 16u ).data();
		m_type = VAL_HEX;
	}
	tbox_main->ChangeValue( txt );
	txt.Printf( wxT("%u"), m_val.m_size );
	tbox_size->ChangeValue( txt );
	dd___type->Select( m_type );
}
Text M__VAL::m_getFloat( void* fpn, ui08 size )
{
	Text txt = wxT("0.0");
	switch ( size )
	{
	case sizeof( float ):
	case sizeof( double ):
		txt.Printf( wxT("%G"), *( (float*)fpn ) );
		break;
	}
	return txt;
}