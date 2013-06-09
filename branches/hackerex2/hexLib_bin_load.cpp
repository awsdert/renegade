#include "wx_pch.h"
#include "hexLib_main.h"

void M__BIN::lib_load( M_LOAD load )
{
	Bin tmp, def;
	if ( load.loadDef )
	{
		m_src = def;
		m_now = def;
		m_tmp = def;
	}
	Text source;
	tmp = m_load( load.des, load.loadNow ? m_now : def, load.name, source );
	m_src = m_load( load.src, def, source, source );
	m_now = tmp;
	m_tmp = tmp;
}
Bin M__BIN::m_load( TxtF *file, Bin &save, Text &name, Text &source )
{
	Text line, temp, srcName;
	Bin tmp, load;
	size_t i = 0, end = 0;
	bool dLoad = false, dSave = false;
	for ( line = file->GetFirstLine(); !file->Eof(); )
	{
		if ( line.empty() || line[ 0 ] != wxT('[') )
			continue;
		end = file->GetCurrentLine();
		m_load( file, tmp, temp );
		if ( !dSave && temp == source )
		{
			i = file->GetCurrentLine();
			for ( --i; i > end; --i )
				file->RemoveLine( i );
			file->RemoveLine( i );
			tmp = save;
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
void M__BIN::m_load( TxtF *file, Bin &obj, Text &source )
{
	TxtT tknr;
	Text
		text, key, val,
		line = file->GetLine( file->GetCurrentLine() );
	obj.name = line.substr( 1, line.length() - 2 );
	Ram kid;
	ui08 r, rEnd = 0u;
	for ( line = file->GetNextLine(); !file->Eof(); line = file->GetNextLine() )
	{
		if ( line.empty() || line[ 0 ] == wxT('[') )
			break;
		if ( line[0] == wxT(';') )
		{
			text = line.substr( 1u, line.length() );
			continue;
		}
		tknr.SetString( line, wxT( '=' ) );
		key = tknr.GetNextToken();
		val = tknr.GetNextToken();
		tknr.SetString( val, wxT( ';' ) );
		key.LowerCase();
		if ( key == m_keyData )
		{
			val = tknr.GetNextToken();
			if ( val == m_valApp )
				obj.type = HEX_BIN_APP;
			else if ( val == m_valWin )
				obj.type = HEX_BIN_WIN;
			else
				obj.type = HEX_BIN_FILE;
			obj.file = tknr.GetNextToken();
			obj.bind = tknr.GetNextToken();
			obj.path = tknr.GetNextToken();
			if ( tknr.HasMoreTokens() )
				source = tknr.GetNextToken();
			else
				source = obj.name;
			obj.path.Replace( wxT("\\\\"), wxT("/") );
		}
		else
		{
			r = 0u;
			r = ( zxGetUI( key.data() ) & 0xFF );
			kid.name	= tknr.GetNextToken();
			kid.depth	= ( zxGetUI( tknr.GetNextToken().data() ) & 0xFF );
			kid.addr	= zxGetHex( tknr.GetNextToken().data() );
			kid.bytes	= zxGetHex( tknr.GetNextToken().data() );
			if ( r > 15u )
				continue;
			if ( r >= rEnd )
			{
				rEnd = r + 1;
				obj.resize( rEnd );
			}
			obj[ r ] = kid;
		}
	}
}
void M__BIN::m_save( TxtF *file, Bin &obj, Text &source )
{
	file->AddLine( wxT('[') + obj.name + wxT(']') );
	wxChar sc = wxT(';'), eq = wxT('=');
	Ram kid;
	Text line = m_keyData + eq, depth, addr, size;
	switch ( obj.type )
	{
	case HEX_BIN_APP:
		line += m_valApp;
		break;
	case HEX_BIN_WIN:
		line += m_valWin;
		break;
	case HEX_BIN_FILE:
		line += m_valFile;
		break;
	}
	line += sc + obj.file + sc + obj.bind + sc + obj.path;
	file->AddLine( line );
	ui08 r, rEnd = obj.size();
	for ( r = 0u; r < rEnd; ++r )
	{
		line.Printf( wxT("%u="), r );
		kid = obj[ r ];
		depth.Printf( wxT("%01u"), kid.depth );
		addr.Printf( wxT("%01llX"), kid.addr );
		size.Printf( wxT("%01llX"), kid.bytes );
		line += kid.name + sc + depth + sc + addr + size;
		file->AddLine( line );
	}
}