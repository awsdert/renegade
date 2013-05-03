#include "wx_pch.h"
#include "hexDB_main.h"
/* *
bool LoadData( hexDB& db, int& doAct, TxtA& tData, Text& pNow, Text& pTmp, Text& name, bool& isFileTmp, bool& isTempTmp );
void hexDB::loadData( int doAct, Text name )
{
	int		atMode = mode[ tmpMode ];
	if ( tmpMode < 0 || tmpMode > HEX_LIST_COUNT )
		return;
	Text path, leaf, subP, ext;
	if ( !tmpCfg && !m_checkFiles( path, leaf, ext, subP ) )
		return;
	TxtA tData;
	bool useS	= ( atMode == HEX_LIST_HACK );
	Text useP	= useS ? subP : path;
	Text useE	= useS ? cDot + format.fileOld.Lower() : ext;
	useP += xsDirSep + leaf + useE;
	Text pNow	= useP;
	Text pTmp	= pNow + cTild;
	Text tmp;
	bool doRename = false, isSame = true, doLoad = false;
	if ( !tmpCfg )
	{
		bool isFileTmp = false, isTempTmp = false;
		isSame = ( pNow == oldP[ atMode ] );
		nowP[ atMode ] = pNow;
		if ( !isSame )
		{
			tmp = oldP[ atMode ] + cTild;
			if ( wxFileExists( tmp ) )
				wxRemoveFile( tmp );
			if ( wxFileExists( pTmp ) )
				wxRemoveFile( pTmp );
		}
		else if ( wxFileExists( pTmp ) )
		{
			pNow = pTmp;
			pTmp = pNow + cTild;
			switch ( tmpMode )
			{
			case HEX_LIST_RAM:
			case HEX_LIST_APP:
			case HEX_LIST_WIN:
				break;
			default:
				doRename = true;
			}
		}
		switch ( doAct )
		{
		case HEX_LOAD_SAVE2TEMP:
			isTempTmp = true;
			break;
		case HEX_LOAD_SAVE2FILE:
			pTmp = useP;
			pNow = useP + cTild;
			doLoad = ( tmpMode == HEX_LIST_HACK );
			doRename  = false;
			isFileTmp = true;
			break;
		case HEX_LOAD_LIST:
			isFileTmp = doRename;
			isTempTmp = true;
			break;
		default: return;
		}
		if ( !LoadData( *this, doAct, tData, pNow, pTmp, name, isFileTmp, isTempTmp ) )
			return;
	}
	if ( doAct == HEX_LOAD_LIST )
	{
		if ( tmpCfg )
		{
			tData.Clear();
			tData.SetCount( HEX_LIST_COUNT );
			tData[ HEX_LIST_THEME	] = _("Themes");
			tData[ HEX_LIST_SESSION	] = _("Sessions");
			tData[ HEX_LIST_ORG		] = _("Organisations");
			tData[ HEX_LIST_PFM		] = _("Platforms");
			tData[ HEX_LIST_BIN		] = _("Binaries (Application / File)");
			tData[ HEX_LIST_APP		] = _("Applications (Any)");
			tData[ HEX_LIST_WIN		] = _("Applications (Visible)");
			tData[ HEX_LIST_RAM		] = _("Parts of Binary Memory");
			tData[ HEX_LIST_PFL		] = _("Profiles");
			tData[ HEX_LIST_FORMAT	] = _("Hack Formats");
			tData[ HEX_LIST_HACK	] = _("Hacks");
			tData[ HEX_LIST_CODE	] = _("Codes");
			tData[ HEX_LIST_FIND	] = _("Search Memory");
			tData[ HEX_LIST_OUT		] = _("Search Results");
			tData[ HEX_LIST_EDIT	] = _("Memory Editor");
			tmpLB->Clear();
			tmpLB->Append( tData );
		}
		else
		{
			tmpLB->Clear();
			switch ( tmpMode )
			{
				case HEX_LIST_APP:
				case HEX_LIST_WIN:
					ListApps( *this );
					break;
				case HEX_LIST_HACK:
				case HEX_LIST_CODE:
					if ( !isSame )
						ListHacks( hacksTree, hacks );
					ListCodes( codesTree, appsLB, codes, format.format, isSame ? codeNo : -1 );
					break;
				default:
					tData.Sort();
					if ( doRename )
						wxRenameFile( pTmp, pNow, true );
					tmpLB->Append( tData );
			}
		}
	}
}
/* *
bool LoadData( hexLib& lib, int& doAct, TxtA& tData, Text& pNow, Text& pTmp, Text& name, bool& isFileTmp, bool& isTempTmp )
{
	int  m = 0, atMode = lib.getMode();
	bool b = true, isSame = ( lib.nowP[ atMode ] == lib.oldP[ atMode ] ), addObj = ( isSame && db.getNowN( db.tmpMode ) != getGlobalName() );
	switch ( db.tmpMode )
	{
	case HEX_LIST_THEME:
	case HEX_LIST_SESSION:
	case HEX_LIST_ORG:
		m = 1;
		break;
	case HEX_LIST_PFM:
	case HEX_LIST_BIN:
	case HEX_LIST_PFL:
	case HEX_LIST_FORMAT:
		m = 2;
		break;
	}
	TxtF file, temp;
	if ( m > 0 )
	{
		if ( !wxFileExists( pNow ) )
			file.Create( pNow );
		if ( !wxFileExists( pTmp ) )
			temp.Create( pTmp );
	}
	if ( m == 1 )
	{
		Text appName	= wxT("HackerEX");
		Text vendor		= wxT("Awsdert");
		if ( isTempTmp )
			wxCopyFile( pNow, pTmp, true );
		CfgF cfgN( appName, vendor, pNow );
		CfgF cfgT( appName, vendor, pTmp );
		switch ( db.tmpMode )
		{
			case HEX_LIST_SESSION:
				db.state	= LoadStates(	db.state,	cfgN, cfgT, tData, name, isFileTmp, isTempTmp );
				name = db.state.nameNow;
				break;
			case HEX_LIST_ORG:
				db.org		= LoadOrgs(		db.org,	cfgN, cfgT, tData, name, isFileTmp, isTempTmp );
				name = db.org.nameNow;
				break;
		}
	}
	else if ( m == 2 )
	{
		file.Open( pNow );
		temp.Open( pTmp );
		if ( !file.IsOpened() || !temp.IsOpened() )
			return false;
		temp.Clear();
		temp.Write( wxTextFileType_Dos );
		switch ( db.tmpMode )
		{
			case HEX_LIST_PFM:
				db.pfm		= LoadPfms(		db.pfm,		file, temp, tData, name, addObj, isFileTmp, isTempTmp );
				name = db.pfm.nameNow;
				break;
			case HEX_LIST_BIN:
				db.bin		= LoadBins(		db.bin,		file, temp, tData, name, addObj, isFileTmp, isTempTmp );
				name = db.bin.nameNow;
				break;
			case HEX_LIST_PFL:
				db.pfl		= LoadPfls(		db.pfl,		file, temp, tData, name, addObj, isFileTmp, isTempTmp );
				name = db.pfl.nameNow;
				break;
			case HEX_LIST_FORMAT:
				db.format	= LoadFormats(	db.format,	file, temp, tData, name, addObj, isFileTmp, isTempTmp );
				name = db.format.name;
				break;
		}
		b = temp.Write( wxTextFileType_Dos );
		temp.Close();
		file.Close();
	}
	else
	{
		switch ( db.tmpMode )
		{
			case HEX_LIST_APP:
			case HEX_LIST_WIN:
				name = db.bin.name;
				break;
			case HEX_LIST_RAM:
			{
				Ram ram;
				int iEnd = db.bin.size();
				for ( int i = 0; i < iEnd; ++i )
				{
					ram = db.bin[ i ];
					tData.Add( ram.name );
				}
				break;
			}
			case HEX_LIST_HACK:
			case HEX_LIST_CODE:
				if ( doAct == HEX_LOAD_SAVE2FILE )
					db.saveCodes( isSame );
				if ( !isSame )
					db.loadCodes( pNow, db.hacks, db.codes );
				else
					db.getCodes( db.hacks.hackNow );
				name = db.hacks[ db.hacks.hackNow ].name;
				break;
		}
	}
	return b;
}
/* */