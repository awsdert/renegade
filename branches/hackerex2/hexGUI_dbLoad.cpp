#include "hexGUI_G.hpp"
bool G::CheckPaths( bool& isCfg, Text& path, Text& hckP, TxtA& dirA )
{
// TODO(awsdert) 0: Refine G::CheckPaths();
	// 1st Checks
	isCfg	= true;
	bool b	= true;
	Text now, old;
	path = m_ListCwd ? wxGetCwd() + wxT("/..") : wxGetDataDir();
	if ( !wxDirExists( path ) )
		b = wxMkdir( path );
	if ( !b )
		return b;
	// 2nd Checks
	const wxChar sep	= wxT('/');
	const Text orgDir	= sep + m_org.fileNow;
	const Text pfmDir	= sep + m_pfm.fileNow;
	const Text binDir	= sep + m_bin.fileNow;
	const Text pflDir	= sep + m_pfl.fileNow;
	switch ( m_ListNow )
	{
	case HEX_LIST_ORG:
		now = wxT( "/hex.ini" );
		break;
	case HEX_LIST_PFM:
		dirA.Add( m_orgPath );
		now = ( orgDir + wxT(".hexp") );
		break;
	case HEX_LIST_BIN:
		dirA.Add( m_orgPath );
		dirA.Add( orgDir );
		now = ( pfmDir + wxT(".hexb") );
		break;
	case HEX_LIST_PFL:
		dirA.Add( m_orgPath );
		dirA.Add( orgDir );
		dirA.Add( pfmDir );
		old = ( binDir + wxT(".hexdb") );
		now = ( binDir + wxT(".hexh") );
		isCfg = false;
		break;
	case HEX_LIST_HCK:
		dirA.Add( m_orgPath );
		dirA.Add( orgDir );
		dirA.Add( pfmDir );
		dirA.Add( binDir );
		old = ( pflDir + wxT(".hexcl") );
		now = ( pflDir + wxT(".hexc") );
		break;
	}
	int i, iCount = dirA.GetCount();
	for ( i = 0; ( b && i < iCount ); ++i )
	{
		path += dirA[ i ];
		if ( !wxDirExists( path ) )
			b = wxMkdir( path );
	}
	if ( !b )
		return b;
	// 3rd Checks
	TxtF file;
	Text nowP = path + now, oldP = path + old;
	if ( !wxFileExists( nowP ) )
		b = file.Create( nowP );
	if ( b )
	{
		hckP = path + pflDir;
		if ( m_ListNow == HEX_LIST_HCK && !wxDirExists( hckP ) )
			b = wxMkdir( hckP );
		if ( b && !old.IsEmpty() && wxFileExists( path + old ) )
		{
			Text temp( path + old );
			switch ( m_ListNow )
			{
			case HEX_LIST_PFL:
				b = wxRenameFile( oldP, nowP, true );
				break;
			case HEX_LIST_HCK:
				b = wxRenameFile( oldP, hckP + pflDir + wxT(".hex00000001"), true );
			}
			wxRemoveFile( oldP );
		}
	}
	path = nowP;
	return b;
}
bool G::LoadDatT( void )
{
// TODO(awsdert) 0: Refine G::LoadDatT()
	TxtA dirA;
	Text path, hckP, tmp;
	bool b = true, isCfg = true;
	if ( CheckPaths( isCfg, path, hckP, dirA ) )
	{
		tmp = path + wxT("~");
		if ( isCfg )
		{
			CfgF cfg( wxT("HackerEX"), wxT("Awsdert"), path, wxT(""), wxCONFIG_USE_LOCAL_FILE );
			switch ( m_ListNow )
			{
			case HEX_LIST_ORG: b = LoadOrgT( cfg, tmp ); break;
			case HEX_LIST_PFM: b = LoadPfmT( cfg, tmp ); break;
			case HEX_LIST_BIN: b = LoadBinT( cfg, tmp ); break;
			default: b = false;
			}
		}
		else
		{
			TxtF file( path );
			Text e, ext = wxT("hexc"), leafExt = path.AfterLast( wxT('.') );
			ui32 i = 1;
			ui08 iCount = 1;
			switch ( m_ListNow )
			{
			case HEX_LIST_PFL: b = LoadPflT( file, tmp ); break;
			case HEX_LIST_HCK:
				for ( ; i < iCount; ++i )
				{
					GetTxtFromUI( e, &i, 4u );
					e = ext + e;
					if ( leafExt == e )
						b = LoadHckT_Hex( file, i );
				}
				b = b ? ListHacks() : false;
				break;
			default: b = false;
			}
			file.Close();
		}
	}
	return b;
}

bool G::LoadOrgT( CfgF& file, Text& path )
{
	Text key, value;
	bool b;
	long i;
	file.SetPath( m_iniOrgPath );
	ui08 aSize = 1u;
	Org org;
	OrgV vOrg;
	vOrg.resize( 1u );
	for
	(
		b = file.GetFirstEntry( key, i );
		( b && aSize < 255u );
		b = file.GetNextEntry( key, i )
	)
	{
		if ( key.IsEmpty() ) continue;
		if ( !file.Read( key, &value, wxT("default") ) ) break;
		org.fileNow = value;
		org.fileOld = value;
		org.nameNow = key;
		org.nameOld = key;
		vOrg.push_back( org );
		++aSize;
	}
	m_org = vOrg[ 0 ];
	return SaveDatB( &vOrg[0u], aSize, HEX_LIST_ORG );
}
bool G::LoadDatB( void* vDat, ui08& aSize, int inMode )
{
	Size bSize = 0u;
	Text path, text;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
			bSize	= sizeof( Org );
			break;
		case HEX_LIST_PFM:
			bSize	= sizeof( Pfm );
			break;
		case HEX_LIST_BIN:
			bSize	= sizeof( Bin );
			break;
		case HEX_LIST_PFL:
			bSize	= sizeof( Pfl );
			break;
		case HEX_LIST_HCK:
			bSize	= sizeof( Hack );
			break;
		default: return false;
	}
	if ( !CheckTmpBin( path, inMode ) )
		return false;
	path += wxT(".bin~");
	wxFile file( path );
	Size fSize = file.Length();
	aSize = fSize / bSize;/*
	text.Printf( wxT( "%u" ), aSize );
	if ( wxMessageBox( path, text, wxOK | wxCANCEL ) == wxCANCEL )
		return false;//*/
	switch ( inMode )
	{
		case HEX_LIST_ORG:
		{
			Org a[ aSize ];
			vDat = &a;
			file.Read( vDat, fSize );
			break;
		}
		default: return false;
	}
	return file.Close();
}

bool G::LoadPfmT( CfgF& file, Text& path )
{
// TODO: Implement G::LoadPfmT()
	return false;
}
bool G::LoadBinT( CfgF& file, Text& path )
{
// TODO: Implement G::LoadBinT()
	return false;
}
bool G::LoadPflT( TxtF& file, Text& path )
{
// TODO: Implement G::LoadPflT()
	return false;
}
