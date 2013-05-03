#include "hexDB_hexLib.h"
void hexLib::M__PFL::main_connect( void )
{
	if ( !m_main_connect( &m_now, &m_old, &m_tmp ) )
		return;
	file_txt->Connect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
	notes_ta->Connect( notes_ta->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::notes_ta_onchange ), NULL, this );
	sid__txt->Connect( sid__txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::sid__txt_onchange ), NULL, this );
	pid__txt->Connect( pid__txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::pid__txt_onchange ), NULL, this );
}
void hexLib::M__PFL::main_disconnect( void )
{
	if ( !m_main_disconnect() )
		return;
	file_txt->Disconnect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
	notes_ta->Disconnect( notes_ta->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::notes_ta_onchange ), NULL, this );
	sid__txt->Disconnect( sid__txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::sid__txt_onchange ), NULL, this );
	pid__txt->Disconnect( pid__txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::M__PFL::pid__txt_onchange ), NULL, this );
}
void hexLib::M__PFL::main_load( M_LOAD load )
{
	if ( !load.check() )
	{
		m_old = Pfl();
		m_now = m_old;
		m_tmp = m_old;
		return;
	}
	TxtF *desF = load.des, *srcF = load.src;
	Text line;
	Pfl s1, s2, t1, t2;
	bool dNow = false, dOld = false;
	for ( line = srcF->GetFirstLine(); !srcF->Eof(); line = srcF->GetNextLine() )
	{
		if ( line.empty() || line[0] != wxT('[') )
		{
			desF->AddLine( line );
			continue;
		}
		s1.name = line.substr( 1, line.length() - 2 );
		main_m_load( srcF, s1 );
		line = srcF->GetNextLine();
		if ( line.empty() || line[ 0 ] != wxT('¬') || ( dNow && dOld ) )
		{
			srcF->GetPrevLine();
			t1 = s1;
		}
		else
		{
			t1.name = line.substr( 1u, line.length() );
			main_m_load( srcF, t1 );
		}
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
			s2 = s1; t2 = t1;
			dNow = true;
		}
		main_m_save( desF, s1 );
		if ( load.desIsTmp )
		{
			desF->AddLine( wxT("¬") + t1.name );
			main_m_save( desF, t1 );
		}
	}
	m_tmp = t2;
	m_now = t2;
	m_old = s2;
}
void hexLib::M__PFL::main_m_load( TxtF *src, Pfl &obj )
{
	TxtT tknr;
	Text line = src->GetNextLine(), txt;
	tknr.SetString( line, wxT(';') );
	tknr.GetNextToken();
	obj.file = tknr.GetNextToken();
	obj.region = getRegions( tknr.GetNextToken() );
	obj.serial = tknr.GetNextToken();
	GetHex( &obj.profile, tknr.GetNextToken(), 4u );
	for ( line = src->GetNextLine(); !src->Eof(); line = src->GetNextLine() )
	{
		if ( line.empty() || line[ 0 ] == wxT('[') || line[ 0 ] == wxT('¬') )
			break;
	}
	src->GetPrevLine();
}