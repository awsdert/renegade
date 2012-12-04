#include "hexGUI_G.hpp"
void G::LoadData( int inMode )
{
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		inMode = m_ListNow;
	TxtF file, temp;
	const wxChar tild = wxT('~');
	Text path, leaf, subP, nowP, tmpP;
	if ( !CheckFilesT( path, leaf, subP ) )
		return;
	nowP = path + m_sep + leaf;
	tmpP = nowP + tild;
	if ( !wxFileExists( tmpP ) )
		temp.Create( tmpP );
	if ( !file.Open( nowP ) || !temp.Open( tmpP ) )
		return;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
		{
			OrgV dat1;
			LoadOrgs( dat1, file, false );
			m_org = dat1[ 0 ];
			m_Org = 0;
			SaveOrgs( dat1, file, temp );
			break;
		}
		case HEX_LIST_PFM:
		{
			PfmV dat2;
			LoadPfms( dat2, file, false );
			m_pfm = dat2[ 0 ];
			m_Pfm = 0;
			SavePfms( dat2, temp );
			break;
		}
	}
	file.Close();
	temp.Close();
}
void G::LoadOrgs( OrgV& dat, TxtF& file, bool isTmpFile )
{
	dat.resize( 1 );
	bool  inOrg = false;
	Text  lineTxt, oldN, val, oldF, nowN, nowF;
	const Text orgHead = wxT("[Organisation]");
	const Text del = wxT('=');
	const Text sc = wxT(';');
	TxtT  txtT;
	Org   obj;
	for
	(
		lineTxt = file.GetFirstLine();
		!file.Eof();
		lineTxt = file.GetNextLine()
	)
	{
		if ( lineTxt.IsEmpty() )
			continue;
		if ( !inOrg )
		{
			inOrg = ( lineTxt == orgHead );
			continue;
		}
		else if ( !lineTxt.Contains( del ) )
			break;
		txtT.SetString( lineTxt, del );
		oldN = txtT.GetNextToken();
		val = txtT.GetNextToken();
		if ( isTmpFile )
		{
			txtT.SetString( val, sc );
			oldF = txtT.GetNextToken();
			nowN = txtT.GetNextToken();
			nowF = txtT.GetNextToken();
		}
		else
		{
			oldF = val;
			nowN = oldN;
			nowF = val;
		}
		obj.fileNow = nowF;
		obj.fileOld = oldF;
		obj.nameNow = nowN;
		obj.nameOld = oldN;
		dat.push_back( obj );
	}
	dat[ m_Org ] = m_org;
}
void G::LoadPfms( PfmV& dat, TxtF& file, bool isTmpFile )
{
	Pfm obj;
	dat.resize( 1 );
	Text lineTxt, val, nowN, nowF, oldN, oldF;
	TxtT txtT;
	ui08 edn = 0u;
	const Text del = wxT('=');
	const Text sc = wxT(';');
	for
	(
		lineTxt = file.GetFirstLine();
		!file.Eof();
		lineTxt = file.GetNextLine()
	)
	{
		if ( lineTxt.IsEmpty() )
			continue;
		txtT.SetString( lineTxt, del );
		oldN = txtT.GetNextToken();
		val  = txtT.GetNextToken();
		txtT.SetString( val, sc );
		oldF = txtT.GetNextToken();
		GetHex( &edn, txtT.GetNextToken() );
		if ( isTmpFile )
		{
			nowN = txtT.GetNextToken();
			nowF = txtT.GetNextToken();
		}
		else
		{
			nowN = oldN;
			nowF = oldF;
		}
		obj.fileNow = nowF;
		obj.fileOld = oldF;
		obj.nameNow = nowN;
		obj.nameOld = oldN;
		obj.endian	= edn;
		dat.push_back( obj );
	}
	dat[ m_Pfm ] = m_pfm;
}
