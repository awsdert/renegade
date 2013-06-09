#include "wx_pch.h"
#include "hexLib_hack.h"
M__FMT::M__FMT( void )
	: M_FILE()
{
	lbox_convert = null;
}
void M__FMT::lib_show( void )
{
	tbox_name->ChangeValue( m_tmp.name );
	tbox_name->Enable( false );
	tbox_file->ChangeValue( m_tmp.file );
}