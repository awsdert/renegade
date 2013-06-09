#include "wx_pch.h"
#include "hexLib_main.h"
void M__ORG::lib_load( M_LOAD &load )
{
	Org tmp, def;
	listMain.clear();
	if ( load.loadDef )
	{
		m_src = def;
		m_now = def;	
		m_tmp = def;
		return;
	}
	Text source;
	tmp = m_load( load.des,
		load.loadNow ? def : m_now,
		load.name, source );
	m_src = m_load( load.src, def, source, source );
	m_now = tmp;
	m_tmp = tmp;
}
void M__ORG::m_load( Text &line, Org &obj, Text& source )
{
	TxtT tknr;
	tknr.SetString( line, wxT('=') );
	obj.name = tknr.GetNextToken();
	obj.name.Replace( wxT("\\\\"), wxT("\\"), true );
	tknr.SetString( tknr.GetNextToken(), wxT(";") );
	obj.file = tknr.GetNextToken();
	if ( tknr.HasMoreTokens() )
		source = tknr.GetNextToken();
	else
		source = obj.name;
}
void M__ORG::m_save( Text &line, Org& obj, Text &source )
{
	line = obj.name;
	line.Replace( wxT("\\"), wxT("\\\\"), true );
	line.Replace( wxT(" "), wxT("\\ "), true );
	line += wxT("=") + obj.file;
	if ( source != obj.name )
		line += wxT(";") + source;
}
Org  M__ORG::m_load( TxtF *file, Org &save, Text &name, Text &source )
{
	Text line, temp, srcName;
	const Text header = wxT("[Organisation]");
	Org  tmp, load;
	bool dSave = false, dLoad = false, fill = source.empty();
	for
	(
		line = file->GetFirstLine();
		!file->Eof();
		line = file->GetNextLine()
	)
	{
		if ( line == header )
			break;
	}
	for
	(
		line = file->GetNextLine();
		!file->Eof();
		line = file->GetNextLine()
	)
	{
		if ( line.empty() || line[ 0 ] == wxT('[') )
			break;
		m_load( line, tmp, temp );
		if ( !dSave && temp == source )
		{
			tmp = save;
			m_save( line, save, source );
			file->RemoveLine( file->GetCurrentLine() );
			file->InsertLine( line, file->GetCurrentLine() - 1, wxTextFileType_Dos );
			dSave = true;
		}
		if ( !dLoad && tmp.name == name )
		{
			load = tmp;
			source = temp;
			dLoad = true;
		}
		if ( fill )
			listMain.Add( tmp.name );
	}
	if ( !dLoad )
		source = getGlobalName();
	if ( !dSave && save.name != getGlobalName() )
	{
		m_save( line, save, source );
		file->InsertLine( line, file->GetCurrentLine() - 1, wxTextFileType_Dos );
	}
	file->Write( wxTextFileType_Dos );
	if ( dLoad )
		source = srcName;
	return load;
}