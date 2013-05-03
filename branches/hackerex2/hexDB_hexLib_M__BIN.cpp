#include "hexDB_hexLib.h"
#include "hexDB_hexIO.h"
hexLib::M__BIN::M__BIN( void ) :
	M_BASE(),
	m_keyData(	wxT( "data" ) ),
	m_keyTemp(	wxT( "temp" ) ),
	m_valApp(	wxT( "app"  ) ),
	m_valWin(	wxT( "win"  ) ),
	m_valFile(	wxT( "file" ) )
{
	//
}
void hexLib::M__BIN::main_connect( void )
{
	if ( !m_main_connect( &m_bNow, &m_bOld, &m_bTmp ) )
		return;
	file_txt->Connect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
}
void hexLib::M__BIN::main_disconnect( void )
{
	if ( !m_main_disconnect() )
		return;
	file_txt->Disconnect( file_txt->GetId(), wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( hexLib::file_txt_onchange ), NULL, m_lib );
}
void hexLib::M__BIN::bind_b__onclick( wxCommandEvent& event )
{
	wxFileDialog dlg( main_p );
	if ( dlg.ShowModal() )
	{
		Text txt = dlg.GetDirectory();
		txt.Replace( wxT("\\"), wxT("/"), true );
		bind_txt->ChangeValue( dlg.GetFilename() );
		path_txt->ChangeValue( txt );
	}
	event.Skip();
}
void hexLib::M__BIN::path_b__onclick( wxCommandEvent& event )
{
	wxDirDialog dlg( main_p );
	if ( dlg.ShowModal() )
	{
		Text txt = dlg.GetPath();
		txt.Replace( wxT("\\"), wxT("/"), true );
		path_txt->ChangeValue( txt );
	}
	event.Skip();
}
void hexLib::M__BIN::bin__lb_onclick( wxCommandEvent& event )
{
	Text txt = bin__lb->GetString( bin__lb->GetSelection() );
	switch ( m_lib->getGuiMode() )
	{
	case HEX_LIST_BIN:
	{
		getBin( txt );
		break;
	}
	case HEX_LIST_RAM:
		getRam( txt );
		break;
	case HEX_LIST_APP:
		bind_txt->ChangeValue( txt );
		break;
	}
	event.Skip();
}
void hexLib::M__BIN::ram__lb_onclick( wxCommandEvent& event )
{
	getRam( ram__lb->GetString( ram__lb->GetSelection() ) );
	event.Skip();
}
void hexLib::M__BIN::getBin( Text name )
{
	TxtF des, src;
	const Text path = m_lib->m__pfm.m_prevPath + xsDirSep + m_lib->m__pfm.m_old.file;
	Text srcP = path + wxT(".hexb"), desP = srcP + wxT('~');
	bool same = ( path == m_prevPath ), comit = ( m_bNow != m_bOld && wxMessageBox(
			m_lang->text[ m_lang->txt_shoudisavechanges ],
			m_lang->text[ m_lang->txt_modified ], wxYES_NO ) == wxYES );
	if ( same )
	{
		srcP += wxT('~');
		desP += wxT('~');
	}
	else
	{
		src.Open( desP );
		des.Open( srcP );
		if ( comit )
			load( des, src, wxEmptyString, false, true );
	}
	if ( !wxFileExists( srcP ) )
		src.Create( srcP );
	src.Open( srcP );
	des.Create( desP );
	des.Open( desP );
	load( des, src, name, true,
		( same && comit ) );
	src.Close();
	des.Close();
}
void hexLib::M__BIN::getRam( Text name )
{
	int i = m_bNow.ramNo;
	m_bNow[ i ] = m_rNow;
	m_bTmp[ i ] = m_rTmp;
	for ( i = 0; i < 16; ++i )
	{
		if ( m_bNow[ i ].name == name )
		{
			m_rNow = m_bNow[ i ];
			m_rOld = m_bOld[ i ];
			m_rTmp = m_bTmp[ i ];
			break;
		}
	}
	if ( i > 15 )
	{
		i = 0x10;
		m_rNow = Ram();
		m_rOld = Ram();
		m_rTmp = Ram();
	}
	m_bNow.ramNo = i;
	m_bOld.ramNo = i;
	m_bTmp.ramNo = i;
}
void hexLib::M__BIN::main_load( M_LOAD load )
{
	if ( !load.check() )
	{
		m_bOld = Bin();
		m_bNow = m_bOld;
		m_bTmp = m_bOld;
		m_rOld = Ram();
		m_rNow = m_rOld;
		m_rTmp = m_rOld;
		return;
	}
	TxtT tknr;
	TxtF *desF = load.des, *srcF = load.src;
	Text text, line, key, val;
	ui08 r, rCount = 0u;
	Bin s1, s2, t1, t2;
	bool dNow = false, dOld = false, dTemp = false;
	m_mainList.Clear();
	ui32 done = 0u;
	for ( line = srcF->GetFirstLine(); !srcF->Eof(); )
	{
		if ( line.IsEmpty() || line[ 0 ] != wxT('[') )
		{
			desF->AddLine( line );
			continue;
		}
		text = line.substr( 1u, line.Len() - 2 );
		m_mainList.Add( text );
		s1.name = text;
		t1.name = text;
		done = dNow ? done : 0u;
		for ( line = srcF->GetNextLine(); !srcF->Eof(); line = srcF->GetNextLine() )
		{
			if ( line.empty() || line[ 0 ] == wxT('[') )
				break;
			if ( line[0] == wxT(';') )
			{
				t1.name = line.substr( 1u, line.length() );
				continue;
			}
			tknr.SetString( line, wxT( '=' ) );
			key = tknr.GetNextToken();
			val = tknr.GetNextToken();
			tknr.SetString( val, wxT( ';' ) );
			key.LowerCase();
			if ( key == m_keyData )
				main_m_load( tknr, &s1 );
			else if ( key == m_keyTemp )
			{
				main_m_load( tknr, &t1 );
				dTemp = true;
			}
			else
			{
				r = 0u;
				GetHexFromUI( &r, key );
				if ( r >= rCount )
				{
					rCount = r + 1;
					s1.resize( rCount );
					t1.resize( rCount );
				}
				if ( key[ 0 ] == wxT('t') )
				{
					main_m_load( tknr, &t1[ r ] );
					done |= ( 1u << r );
				}
				else
					main_m_load( tknr, &s1[ r ] );
			}
		}
		if ( !dOld && text == m_bOld.name )
		{
			if ( load.saveChanges )
			{
				s1 = m_bOld;
				t1 = m_bNow;
			}
			dOld = true;
		}
		if ( !dNow && text == load.name )
		{
			s2 = s1; t2 = t1;
			dNow = true;
		}
		main_m_save( desF, &s1, load.desIsTmp ? &t1 : NULL );
	}
	if ( load.saveChanges && !dOld )
		main_m_save( desF, &m_bOld, &m_bNow );
	if ( !dTemp )
	{
		t2.file = s2.file;
		t2.bind = s2.bind;
		t2.path = s2.path;
	}
	for ( r = 0u; r < 16u; ++r )
	{
		if ( ( done & ( 1u << r ) ) == 0u )
			t1[ r ] = s2[ r ];
	}
	m_bOld = s2;
	m_bNow = t2;
	m_bTmp = t2;
}
void hexLib::M__BIN::main_m_load( TxtT &tknr, Ram *obj )
{
	obj->name = tknr.GetNextToken();
	GetHexFromUI( &obj->depth, tknr.GetNextToken() );
	GetHex( &obj->addr, tknr.GetNextToken(), 8u );
	GetHex( &obj->bytes, tknr.GetNextToken(), 8u );
}
void hexLib::M__BIN::main_m_load( TxtT &tknr, Bin *obj )
{
	Text txt = tknr.GetNextToken();
	if ( txt == m_valApp )
		obj->type = HEX_BIN_APP;
	else if ( txt == m_valWin )
		obj->type = HEX_BIN_WIN;
	else
		obj->type = HEX_BIN_FILE;
	obj->file = tknr.GetNextToken();
	obj->bind = tknr.GetNextToken();
	obj->path = tknr.GetNextToken();
	obj->path.Replace( wxT("\\\\"), wxT("/") );
}
void hexLib::M__BIN::main_m_save( TxtF *file, Bin *old, Bin *now )
{
	file->AddLine( wxT('[') + old->name + wxT(']') );
	wxChar sc = wxT(';'), eq = wxT('=');
	Text line = m_keyData + eq;
	main_m_save( line, old );
	file->AddLine( line );
	ui08 r, roCount = old->size(), rnCount = 0u;
	if ( now != NULL )
	{
		rnCount = now->size();
		line = m_keyTemp + eq;
		main_m_save( line, now );
		file->AddLine( line );
	}
	TxtA lines;
	lines.SetCount( 16 );
	for ( r = 0u; r < roCount; ++r )
	{
		lines[ r ].Printf( wxT("%u="), r );
		main_m_save( lines[ r ], &old[ r ] );
	}
	for ( r = 0u ; r < rnCount; ++r )
	{
		if ( r < roCount )
			file->AddLine( lines[ r ] );
		lines[ r ].Printf( wxT("t%u="), r );
		main_m_save( lines[ r ], &now->at( r ) );
		file->AddLine( lines[ r ] );
	}
}
void hexLib::M__BIN::main_m_save( Text &line, Bin *obj )
{
	wxChar sc = wxT(';');
	switch ( obj->type )
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
	line += sc + obj->file + sc + obj->bind + sc + obj->path;
}
void hexLib::M__BIN::main_m_save( Text &line, Ram *obj )
{
	wxChar sc = wxT(';');
	Text d, a, b;
	d.Printf( wxT("%01u"), obj->depth );
	a.Printf( wxT("%01llX"), obj->addr );
	b.Printf( wxT("%01llX"), obj->bytes );
	line += obj->name + sc + d + sc + a + b;
}