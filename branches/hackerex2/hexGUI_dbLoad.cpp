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
		case HEX_LIST_BIN:
		{
			BinV dat3;
			LoadBins( dat3, file, false );
			m_bin= dat3[ 0 ];
			m_Bin = 0;
			SaveBins( dat3, temp );
			break;
		}
		case HEX_LIST_PFL:
		{
			PflV dat4;
			LoadPfls( dat4, file, false );
			m_pfl = dat4[ 0 ];
			m_Pfl = 0;
			SavePfls( dat4, file, temp );
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
void G::LoadBins( BinV& dat, TxtF& file, bool isTmpFile )
{
	Bin obj;
	Ram ram;
	ui08 r, ptr, rEnd = 0u;
	ui64 v64;
	dat.resize( 1 );
	Text lineTxt, val, nowN, nowF, oldN, oldF;
	TxtT txtT;
	const Text del = wxT('=');
	const Text sc = wxT(';');
	const Text app = wxT("app");
	const Text win = wxT("win");
	const Text data = wxT("data");
	const wxChar head = wxT('[');
	bool inBin = false, atRam = false;
	for
	(
		lineTxt = file.GetFirstLine();
		!file.Eof();
		lineTxt = file.GetNextLine()
	)
	{
		if ( lineTxt.IsEmpty() )
			continue;
		if ( lineTxt[ 0 ] == head )
		{
			obj.fileNow = nowF;
			obj.fileOld = oldF;
			obj.nameNow = nowN;
			obj.nameOld = oldN;
			if ( inBin )
				dat.push_back( obj );
			inBin = true;
			atRam = false;
			oldN = lineTxt.SubString( 1, lineTxt.Length() - 2 );
		}
		else if ( inBin )
		{
			txtT.SetString( lineTxt, del );
			val = txtT.GetNextToken();
			if ( !atRam && val == data )
			{
				val = txtT.GetNextToken();
				txtT.SetString( val, sc );
				val  = txtT.GetNextToken();
				if ( val == app )
					obj.type = 1u;
				else if ( val == win )
					obj.type = 2u;
				else
					obj.type = 0u;
				oldF = txtT.GetNextToken();
				obj.name = txtT.GetNextToken();
				obj.path = txtT.GetNextToken();
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
				atRam = true;
			}
			else
			{
				GetHex( &r, val );
				ram.name = txtT.GetNextToken();
				val = txtT.GetNextToken();
				GetHex( &ptr, val );
				ram.depth = ptr;
				val = txtT.GetNextToken();
				GetHex( &v64, val, 8u );
				ram.addr = v64;
				val = txtT.GetNextToken();
				GetHex( &v64, val, 8u );
				ram.bytes = v64;
				if ( r > rEnd )
				{
					obj.resize( r + 1 );
					rEnd = r;
				}
				obj[ r ] = ram;
			}
		}
	}
	dat[ m_Bin ] = m_bin;
}
void G::LoadPfls( PflV& dat, TxtF& file, bool isTmpFile )
{
	Pfl obj;
	dat.resize( 1 );
	Text txt, val, nowN, nowF, oldN, oldF;
	TxtT txtT;
	ui16 pid;
	bool inPfl = false, atData = false;
	const wxChar hOpen = wxT('[');
	const Text del = wxT('=');
	const Text sc = wxT(';');
	const Text fs = wxT('\\');
	for
	(
		txt = file.GetFirstLine();
		!file.Eof();
		txt = file.GetNextLine()
	)
	{
		if ( txt.IsEmpty() )
			continue;
		if ( txt[ 0 ] == hOpen )
		{
			obj.fileNow = nowF;
			obj.fileOld = oldF;
			obj.nameNow = nowN;
			obj.nameOld = oldN;
			if ( inPfl )
				dat.push_back( obj );
			oldN = txt.SubString( 1, txt.Length() - 2 );
			inPfl = true;
			atData = true;
		}
		else if ( inPfl )
		{
			if ( atData )
			{
				txtT.SetString( txt, sc );
				txtT.GetNextToken();
				oldF = txtT.GetNextToken();
				obj.region = CheckRegion( txtT.GetNextToken() );
				obj.serial = txtT.GetNextToken();
				val = txtT.GetNextToken();
				GetHex( &pid, val, 2u );
				obj.profile = pid;
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
				atData = false;
			}
			else
			{
				if ( txt.StartsWith( fs ) )
					txt = txt.Right( txt.Length() - 2 );
				obj.notes += txt;
			}
		}
	}
}
