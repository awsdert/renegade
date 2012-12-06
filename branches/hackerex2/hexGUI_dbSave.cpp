#include "hexGUI_G.hpp"
void G::SaveData( int inMode )
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
	file.Clear();
	switch ( inMode )
	{
		case HEX_LIST_ORG:
		{
			OrgV dat1;
			LoadOrgs( dat1, temp );
			SaveOrgs( dat1, temp, file, false );
			break;
		}
		case HEX_LIST_PFM:
		{
			PfmV dat2;
			LoadPfms( dat2, temp );
			SavePfms( dat2, file, false );
			break;
		}
		case HEX_LIST_BIN:
		{
			BinV dat3;
			LoadBins( dat3, temp );
			SaveBins( dat3, file, false );
			break;
		}
		case HEX_LIST_PFL:
		{
			PflV dat4;
			LoadPfls( dat4, temp );
			SavePfls( dat4, temp, file, false );
			break;
		}
	}
	file.Close();
	temp.Close();
	wxRemoveFile( tmpP );
}
void G::SaveOrgs( OrgV& dat, TxtF& file, TxtF& temp, bool isTmpFile )
{
	Text lineTxt;
	const Text orgHead = wxT("[Organisation]");
	const wxChar sc = wxT(';');
	bool inOrg = false, done = false;
	Org obj;
	for
	(
		lineTxt = file.GetFirstLine();
		!file.Eof();
		lineTxt = file.GetNextLine()
	)
	{
		if ( !inOrg )
		{
			if ( !done && lineTxt == orgHead )
			{
				inOrg = true;
				done = true;
				continue;
			}
			temp.AddLine( lineTxt, wxTextFileType_Dos );
		}
		else if ( lineTxt.IsEmpty() )
			inOrg = false;
	}
	int i, iEnd = dat.size();
	lineTxt.Clear();
	temp.AddLine( lineTxt, wxTextFileType_Dos );
	temp.AddLine( orgHead, wxTextFileType_Dos );
	for ( i = 1; i < iEnd; ++i )
	{
		obj = dat[ i ];
		lineTxt = obj.nameOld + wxT("=") + obj.fileOld;
		if ( isTmpFile )
			lineTxt += sc + obj.nameNow + sc + obj.fileNow;
		temp.AddLine( lineTxt, wxTextFileType_Dos );
	}
	temp.Write( wxTextFileType_Dos );
}
void G::SavePfms( PfmV& dat, TxtF& file, bool isTmpFile )
{
	Text lineTxt, eTxt;
	Pfm obj;
	ui08 edn = 0u;
	const wxChar del = wxT('=');
	const wxChar sc = wxT(';');
	int i, iEnd = dat.size();
	for ( i = 1; i < iEnd; ++i )
	{
		obj = dat[ i ];
		edn = obj.endian;
		GetTxt( eTxt, &edn );
		lineTxt = obj.nameOld + del + obj.fileOld + sc + eTxt;
		if ( isTmpFile )
			lineTxt += sc + obj.nameNow + sc + obj.fileNow;
		file.AddLine( lineTxt, wxTextFileType_Dos );
	}
	file.Write( wxTextFileType_Dos );
}
void G::SaveBins( BinV& dat, TxtF& file, bool isTmpFile )
{
	Bin obj;
	Ram ram;
	Text txt, val;
	ui08 ptr;
	ui08 v64;
	int i, iEnd = dat.size();
	ui08 j, jEnd;
	const wxChar* data = wxT("data=");
	const wxChar del = wxT('=');
	const wxChar sc  = wxT(';');
	const wxChar bOpen = wxT('[');
	const wxChar bClose = wxT(']');
	const wxChar* app = wxT("app");
	const wxChar* win = wxT("win");
	const wxChar* fle = wxT("file");
	for ( i = 0; i < iEnd; ++i )
	{
		obj = dat[ i ];
		txt = bOpen + obj.nameOld + bClose;
		file.AddLine( txt, wxTextFileType_Dos );
		txt = data;
		switch ( obj.type )
		{
			case 1u: txt += app; break;
			case 2u: txt += win; break;
			default: txt += fle;
		}
		txt += sc + obj.fileOld + sc + obj.name + sc + obj.path;
		if ( isTmpFile )
			txt += sc + obj.nameNow + sc + obj.fileNow;
		jEnd = obj.size();
		for ( j = 0u; j < jEnd; ++j )
		{
			ram = obj[ j ];
			GetTxt( txt, &j );
			txt += del + ram.name;
			ptr = ram.depth;
			GetTxt( val, &ptr );
			txt += sc + val;
			v64 = ram.addr;
			GetTxt( val, &v64, 8u );
			txt += sc + val;
			v64 = ram.bytes;
			GetTxt( val, &v64, 8u );
			txt += sc + val;
			file.AddLine( txt, wxTextFileType_Dos );
		}
	}
}
void G::SavePfls( PflV& dat, TxtF& file, TxtF& temp, bool isTmpFile )
{
	Pfl obj;
	ui16 pid = 0u;
	TxtT txtT;
	Text txt, val;
	const Text nl = wxT('\n');
	const wxChar sColon	= wxT(';');
	const wxChar hOpen	= wxT('[');
	const wxChar hClose	= wxT(']');
	const wxChar fSlash	= wxT('\\');
	int i, iEnd = dat.size();
	for ( i = 0; i < iEnd; ++i )
	{
		// Header
		obj = dat[ i ];
		txt = hOpen + obj.nameOld + hClose;
		file.AddLine( txt, wxTextFileType_Dos );
		// Data
		txt = obj.fileOld;
		txt += fSlash + CheckRegion( obj.region );
		txt += fSlash + obj.serial;
		pid = obj.profile;
		GetTxt( val, &pid, 2u );
		txt += fSlash + val;
		if ( isTmpFile )
			txt += fSlash + obj.nameNow + fSlash + obj.fileNow;
		file.AddLine( txt, wxTextFileType_Dos );
		// Notes
		val = HexNotes_TA->GetValue();
		txtT.SetString( val, nl );
		for
		(
			txt = txtT.GetNextToken();
			txtT.HasMoreTokens();
			txt = txtT.GetNextToken()
		)
		{
			if ( txt[ 0u ] == fSlash || txt[ 0u ] == hOpen || txt[ 0u ] == sColon )
				txt = fSlash + txt;
			file.AddLine( txt, wxTextFileType_Dos );
		}
	}
	file.Write( wxTextFileType_Dos );
}
