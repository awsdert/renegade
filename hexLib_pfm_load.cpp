#include "wx_pch.h"
#include "hexLib_main.h"

void M__PFM::main_load( M_LOAD load )
{
	Pfm tmp, def;
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
void M__PFM::m_load( Text &line, Pfm &obj, Text &source )
{
	TxtT tknr;
	tknr.SetString( line, wxT('=') );
	obj.name = tknr.GetNextToken();
	tknr.SetString( tknr.GetNextToken(), wxT(';') );
	obj.file = tknr.GetNextToken();
	obj.endian = m_getEndian( tknr.GetNextToken() );
	if ( !tknr.HasMoreTokens() )
		source = tknr.GetNextToken();
	else
		source = obj.name;
}
void M__PFM::m_save( Text &line, Pfm &obj, Text &source )
{
	wxChar sc= wxT(';');
	line = obj.name + wxT('=');
	line += obj.file + sc + m_getEndian( obj.endian );
	if ( !source.empty() && source != obj.name )
		line += sc + source;
}
Pfm  M__PFM::m_load( TxtF *file, Pfm &save, Text &name, Text &source )
{
	Pfm tmp, load;
	Text line, temp, srcName;
	size_t l;
	bool dSave = false, dLoad = false;
	for ( line = file->GetFirstLine(); !file->Eof(); line = file->GetNextLine() )
	{
		if ( line.empty() )
			continue;
		m_load( line, tmp, temp );
		if ( !dSave && temp == source )
		{
			tmp = save;
			l = file->GetCurrentLine();
			m_save( line, save, source );
			file->RemoveLine( l );
			file->InsertLine( line, l, wxTextFileType_Dos );
			dSave = true;
		}
		if ( !dLoad && temp == name )
		{
			load = tmp;
			srcName = temp;
			dLoad = true;
		}
	}
	if ( !dSave && save.name != getGlobalName() )
	{
		m_save( line, save, source );
		file->AddLine( line, wxTextFileType_Dos );
	}
	file->Write( wxTextFileType_Dos );
	if ( dLoad )
		source = srcName;
	return load;
}