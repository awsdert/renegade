#include "wx_pch.h"
#include "hexLib_main.h"
void M__PFL::lib_load( M_LOAD load )
{
	Pfl tmp, def;
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
void M__PFL::m_load( TxtF *file, Pfl &obj, Text &source )
{
	TxtT tknr;
	// Name
	Text line = file->GetLine( file->GetCurrentLine() );
	obj.name = line.substr( 1, line.length() - 2 );
	// File
	tknr.SetString( file->GetNextLine(), wxT(';') );
	tknr.GetNextToken();
	obj.file = tknr.GetNextToken();
	// Region
	obj.region = oRegion.getValue( tknr.GetNextToken() );
	// Serial ID
	obj.serial = tknr.GetNextToken();
	// Profile / Game ID
	obj.profile = zxAtou( tknr.GetNextToken().data(), 16u );
	// Source name
	if ( tknr.HasMoreTokens() )
		source = tknr.GetNextToken();
}
void M__PFL::m_save( TxtF *file, Pfl &obj, Text &source )
{
	size_t l = file->GetCurrentLine();
	wxChar sc = wxT(';');
	// Name
	file->InsertLine( wxT('[') + obj.name + wxT(']'), l );
	Text line = sc +
		obj.file + sc +
		oRegion.getNames( obj.region ) + sc +
		obj.serial + sc;
	// Profle ID
	line += zxUtoa( obj.profile, 16u ).data();
	// Source name
	if ( !source.empty() && obj.name != source )
		line += sc + source;
	file->InsertLine( line, l + 1 );
}
Pfl  M__PFL::m_load( TxtF *file, Pfl &save, Text &name, Text &source )
{
	Text line, temp, srcName;
	Pfl tmp, load;
	bool dSave = false, dLoad = false;
	size_t l = 0;
	for ( line = file->GetFirstLine(); !file->Eof(); line = file->GetNextLine() )
	{
		if ( line.empty() || line[0] != wxT('[') )
			continue;
		m_load( file, tmp, temp );
		if ( !dSave && temp == source )
		{
			tmp = save;
			l = file->GetCurrentLine() - 1;
			file->RemoveLine( l );
			file->RemoveLine( l );
			m_save( file, save, source );
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
		m_save( file, save, source );
	file->Write( wxTextFileType_Dos );
	if ( dLoad )
		source = srcName;
	return load;
}