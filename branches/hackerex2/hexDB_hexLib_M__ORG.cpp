#include "hexDB_hexLib.h"
void hexLib::M__ORG::main_connect( void )
{
	if ( !m_main_connect( &m_now, &m_old, &m_tmp ) )
		return;
	file_txt->Connect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
}
void hexLib::M__ORG::main_disconnect( void )
{
	if ( !m_main_disconnect() )
		return;
	file_txt->Disconnect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
}
void hexLib::M__ORG::main_load( M_LOAD load )
{
	Text line;
	if ( !load.check() )
	{
		m_tmp = Org();
		m_now = m_tmp;
		m_old = m_tmp;
		return;
	}
	TxtF *srcF = load.src, *desF = load.des;
	for ( line = srcF->GetFirstLine(); !srcF->Eof(); line = srcF->GetNextLine() )
	{
		if ( line == m_header )
			break;
	}
	Org s1, s2, t1, t2;
	m_mainList.clear();
	bool dNow = false, dOld = false;
	for ( line = srcF->GetNextLine(); !srcF->Eof(); line = srcF->GetNextLine() )
	{
		if ( line.empty() || line[ 0 ] == wxT('[') )
			break;
		main_m_load( line, s1, t1 );
		if ( !dOld && s1.name == m_old.name )
		{
			if ( load.saveChanges )
			{
				s1 = m_old;
				t1 = m_now;
			}
			dOld = true;
		}
		if ( !dNow && s1.name == load.name )
		{
			s2 = s1;
			t2 = t2;
			dNow = true;
		}
		m_mainList.Add( s1.name );
		main_m_save( line, s1 );
		if ( load.desIsTmp )
			main_m_save( line, t1, true );
		desF->AddLine( line );
	}
	if ( !dOld && load.saveChanges )
	{
		main_m_save( line, m_old );
		if ( load.desIsTmp )
			main_m_save( line, m_now );
		desF->AddLine( line );
	}
	if ( !srcF->Eof() )
	{
		line = srcF->GetLine( srcF->GetCurrentLine() );
		do
		{
			desF->AddLine( line );
			line = srcF->GetNextLine();
		} while ( !srcF->Eof() );
	}
	m_old = s2;
	m_now = t1;
	m_tmp = t1;
}
void hexLib::M__ORG::main_m_load( Text &line, Org &src, Org &tmp )
{
	TxtT tknr;
	tknr.SetString( line, wxT('=') );
	src.name = tknr.GetNextToken();
	src.name.Replace( wxT("\\\\"), wxT("\\"), true );
	tknr.SetString( tknr.GetNextToken(), wxT(';') );
	src.file = tknr.GetNextToken();
	if ( !tknr.HasMoreTokens() )
	{
		tmp = src;
		return;
	}
	tmp.name = tknr.GetNextToken();
	tmp.file = tknr.GetNextToken();
}
void hexLib::M__ORG::main_m_save( Text &line, Org &obj, bool asTemp )
{
	if ( asTemp )
	{
		line += wxT(';') + obj.name + wxT(';') + obj.file );
		return;
	}
	line = obj.name;
	line.Replace( wxT(" "), wxT("\\ ") );
	line += wxT("=") + obj.file;
}