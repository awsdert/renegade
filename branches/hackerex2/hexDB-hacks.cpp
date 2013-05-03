#include "hexDB_hack.h"
void Hacks::open( Text path )
{
	if ( m_isOpen )
	{
		m_names.Close();
		m_hacks.Close();
		m_isOpen = false;
	}
	m_path = path;
	if ( path.empty() )
		return;
	m_names.Open( path + xsDirSep + wxT("hacks.txt") );
	m_hacks.Open( path + xsDirSep + wxT("hacks.bin") );
}