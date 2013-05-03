#include "hexDB_hexLib.h"
void hexLib::M__PFM::main_connect( void )
{
	if ( !m_main_connect( &m_now, &m_old, &m_tmp ) )
		return;
	file_txt->Connect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
	endian_dd->Connect( endian_dd->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( hexLib::M__PFM::endian_dd_onchange ), NULL, this );
}
void hexLib::M__PFM::main_disconnect( void )
{
	if ( !m_main_disconnect() )
		return;
	file_txt->Disconnect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
	endian_dd->Disconnect( endian_dd->GetId(), wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( hexLib::M__PFM::endian_dd_onchange ), NULL, this );
}
void hexLib::M__PFM::endian_dd_onchange( wxCommandEvent& event ) { m_tmp.endian = endian_dd->GetSelection(); }
void hexLib::M__PFM::getPfm( Text name )
{
	const Text path = m_lib->m__org.m_prevPath + xsDirSep + m_lib->m__org.m_old.file;
	bool same = ( path == m_prevPath ), comit = ( m_now != m_old && wxMessageBox(
			m_lang->text[ m_lang->txt_shoudisavechanges ],
			m_lang->text[ m_lang->txt_modified ], wxYES_NO ) == wxYES );
}
void hexLib::M__PFM::main_load( M_LOAD load )
{
	if ( !load.check() )
	{
		m_old = Pfm();
		m_now = m_old;
		m_tmp = m_old;
		return;
	}
	TxtF *desF = load.des, *srcF = load.src;
	Text line;
	Pfm s1, s2, t1, t2;
	bool dNow = false, dOld = false;
	for ( line = srcF->GetFirstLine(); !srcF->Eof(); line = srcF->GetNextLine() )
	{
		if ( line.empty() )
			continue;
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
			t2 = t1;
			dNow = true;
		}
		main_m_save( line, s1 );
		if ( load.desIsTmp )
			main_m_save( line, t1, true );
		desF->AddLine( line );
	}
	m_tmp = t2;
	m_now = t2;
	m_old = s2;
}
void hexLib::M__PFM::main_m_load( Text &line, Pfm &src, Pfm &tmp )
{
	TxtT tknr;
	tknr.SetString( line, wxT('=') );
	src.name = tknr.GetNextToken();
	tknr.SetString( tknr.GetNextToken(), wxT(';') );
	src.file = tknr.GetNextToken();
	src.endian = getEndian( tknr.GetNextToken() );
	if ( !tknr.HasMoreTokens() )
	{
		tmp = src;
		return;
	}
	tmp.name = tknr.GetNextToken();
	tmp.file = tknr.GetNextToken();
	tmp.endian = getEndian( tknr.GetNextToken() );
}
void hexLib::M__PFM::main_m_save( Text &line, Pfm &obj, bool asTemp )
{
	wxChar sc= wxT(';');
	if ( asTemp )
		line += sc + obj.name + sc;
	else
		line = obj.name + wxT('=');
	line += obj.file + sc + getEndian( obj.endian );
}
ui08 hexLib::M__PFM::getEndian( Text name )
{
	name.UpperCase();
	if ( name == Text( wxT("BIG") ) )
		return HEX_ENDIAN_BIG;
	else if ( name = Text( wxT("LBIG") ) )
		return HEX_ENDIAN_LBIG;
	else
		return HEX_ENDIAN_LITTLE;
}
Text hexLib::M__PFM::getEndian( ui08 endian )
{
	switch ( endian )
	{
	case HEX_ENDIAN_BIG:
		return Text( wxT("BIG") );
	case HEX_ENDIAN_LBIG:
		return Text( wxT("LBIG") );
	default:
		return Text( wxT("LITTLE") );
	}
}