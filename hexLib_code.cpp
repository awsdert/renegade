#include "wx_pch.h"
#include "hexLib_main.h"

void M_CODE::lib_show( void )
{
// TODO(awsdert) Finish ShowCode()
	Text txt;
	Code obj;
	const bool isTest = ( obj.type == CODE_TEST );
	const bool isList = ( obj.type == CODE_LIST );
	const bool isCopy = ( obj.type == CODE_COPY );
	const bool isInc  = ( !isTest && !isCopy && !isList );
	// Show / Hide Objects
	dd___inc->Show( isInc );
	tbox_inc->Show( isInc );
	dd___test->Show( isTest );
	valGui.lbl__type->Show( !isCopy );
	valGui.lbl__size->Show( !isCopy );
	valGui.dd___type->Show( !isCopy );
	valGui.spb__size->Show( !isCopy );
	// Show Data
	dd___type->SetSelection( obj.type );
	txt.Printf( wxT("%01llX"), obj.addr[ 0 ] );
	addrGui.tbox_main->ChangeValue( txt );
	addrGui.sl___depth->SetValue( obj.depth );
	if ( isTest )
	{
		int t = -1;
		switch ( obj.info )
		{
			case HEX_IS_DC: t = 0; break;
			case HEX_IS_NC: t = 1; break;
			case HEX_IS_EQ: t = 2; break;
			case HEX_IS_NE: t = 3; break;
			case HEX_IS_GT: t = 4; break;
			case HEX_IS_GE: t = 5; break;
			case HEX_IS_LT: t = 6; break;
			case HEX_IS_LE: t = 7; break;
		}
		dd___test->SetSelection( t );
	}
	else if ( isInc )
	{
		int i;
		switch ( obj.info & 0xF )
		{
			case CODE_DEC: i = 1; break;
			default: i = 0;
		}
		dd___inc->SetSelection( i );
		m_show( tbox_inc, 1 );
	}
	else if ( isCopy )
		obj.hex = VAL_HEX;
	if ( isTest )
		txt = _("Codes");
	else
		txt = _("Loop");
	lbl__loop->SetLabel( txt );
	txt.Printf( wxT("%01u"), obj.loop );
	tbox_loop->ChangeValue( txt );
	m_show( valGui.tbox_main, 0 );
	valGui.dd___type->SetSelection( obj.hex );
	valGui.spb__size->SetValue( obj.bytes );
	valGui.p____main->Layout();
}
void M_CODE::m_show( wxTextCtrl* tbox, si32 id )
{
	Text txt;
	zxUInt val;
	val.setPtr( &m_obj[ id * m_obj.bytes ], m_obj.bytes );
	switch ( m_obj.hex )
	{
	case VAL_HEX:
		txt = val.toString( 16u ).data();
		break;
	case VAL_SI:
		val.m_signed = true;
	case VAL_UI:
		txt = val.toString().data();
		break;
	case VAL_TEXT:
		txt.Printf( wxT("%s"), (char*)val.m_data );
		break;
	case VAL_WTEXT:
		txt.Printf( wxT("%ls"), (wchar_t*)val.m_data );
		break;
	default: txt = wxT('0');
	}
	tbox->ChangeValue( txt );
}