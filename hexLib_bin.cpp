#include "wx_pch.h"
#include "hexLib_main.h"


M__BIN::M__BIN( void ) :
	M_FILE(),
	m_keyData(	wxT( "data" ) ),
	m_keyTemp(	wxT( "temp" ) ),
	m_valApp(	wxT( "app"  ) ),
	m_valWin(	wxT( "win"  ) ),
	m_valFile(	wxT( "file" ) )
{
	ramGui = null;
	dd___type = null;
}
void M__BIN::lib_show( void )
{
	tbox_name->ChangeValue( m_tmp.name );
	tbox_file->ChangeValue( m_tmp.file );
	tbox_bind->ChangeValue( m_tmp.bind );
	tbox_path->ChangeValue( m_tmp.path );
	dd___type->Select( m_tmp.type );
}
void M__BIN::main_connect( void )
{
	if ( m_libC )
		return;
	file_connect();
	m_libC = true;
}
void M__BIN::main_disconnect( void )
{
	if ( !m_libC )
		return;
	file_disconnect();
	m_libC = false;
}
void M__BIN::btn__bind_onclick( wxCommandEvent& event )
{
	wxFileDialog dlg( p____main );
	if ( dlg.ShowModal() )
	{
		Text txt = dlg.GetDirectory();
		txt.Replace( wxT("\\"), wxT("/"), true );
		tbox_bind->ChangeValue( dlg.GetFilename() );
		tbox_path->ChangeValue( txt );
	}
	event.Skip();
}
void M__BIN::btn__path_onclick( wxCommandEvent& event )
{
	wxDirDialog dlg( p____main );
	if ( dlg.ShowModal() )
	{
		Text txt = dlg.GetPath();
		txt.Replace( wxT("\\"), wxT("/"), true );
		tbox_path->ChangeValue( txt );
	}
	event.Skip();
}