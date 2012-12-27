#include "hex2_G.h"
void G::LoadData( hexDB& db, LBox* lbox, int doAct, Text name )
{
	/**
		@param doAct
		determines which file version is retrieved and how it is treated, also tells the function whether to List the retrieved names
		@param inMode
		determines which file set is retrieved and what data to expect, in some cases a file is not loaded but data from a local object instead
		@param name
		is which object to keep hold of when loading data, in some cases this is ignored. In the event a name cannot be found the default object will be used.
	**/
	bool	inCfg	= db.tmpCfg;
	int		inMode	= db.tmpMode, atMode = db.mode[ inMode ];
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		return;
	Text path, leaf, subP, ext;
	if ( !inCfg && !CheckFilesT( db, path, leaf, ext, subP ) )
		return;
	TxtA data;
	bool useS	= ( atMode == HEX_LIST_HACK );
	Text useP	= useS ? subP : path;
	Text useE	= useS ? cDot + db.format.fileOld.Lower() : ext;
	useP += xsDirSep + leaf + useE;
	Text nowP	= useP;
	Text tmpP	= nowP + cTild;
	Text tmp;
	bool doRename = false;
	if ( !inCfg )
	{
		bool isFileTmp = false, isTempTmp = false;
		if ( nowP != db.oldP[ atMode ] )
		{
			tmp = db.oldP[ atMode ] + cTild;
			if ( wxFileExists( tmp ) )
				wxRemoveFile( tmp );
			if ( wxFileExists( tmpP ) )
				wxRemoveFile( tmpP );
		}
		else if ( wxFileExists( tmpP ) )
		{
			nowP = tmpP;
			tmpP = nowP + cTild;
			switch ( inMode )
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
			tmpP = useP;
			nowP = useP + cTild;
			doRename  = false;
			isFileTmp = true;
			break;
		case HEX_LOAD_LIST:
			isFileTmp = doRename;
			isTempTmp = true;
			break;
		default: return;
		}
		db.nowP[ atMode ] = nowP;
		if ( !inCfg && !LoadData( db, data, nowP, tmpP, name, isFileTmp, isTempTmp ) )
			return;
	}
	if ( doAct == HEX_LOAD_LIST )
	{
		if ( inCfg )
		{
			data.Clear();
			data.SetCount( HEX_LIST_COUNT );
			data[ HEX_LIST_SESSION	] = _("Session");
			data[ HEX_LIST_ORG		] = _("Organisation");
			data[ HEX_LIST_PFM		] = _("Platform");
			data[ HEX_LIST_BIN		] = _("Binary (Application / File)");
			data[ HEX_LIST_APP		] = _("Application (Any)");
			data[ HEX_LIST_WIN		] = _("Application (Visible)");
			data[ HEX_LIST_RAM		] = _("Parts of Binary Memory");
			data[ HEX_LIST_PFL		] = _("Profile");
			data[ HEX_LIST_FORMAT	] = _("Format of Hacks");
			data[ HEX_LIST_HACK		] = _("Hacks");
			data[ HEX_LIST_CODE		] = _("Codes");
			data[ HEX_LIST_FIND		] = _("Search Memory");
			data[ HEX_LIST_OUT		] = _("Search Results");
			data[ HEX_LIST_EDIT		] = _("Memory Editor");
			lbox->Clear();
			lbox->Append( data );
		}
		else
		{
			lbox->Clear();
			switch ( inMode )
			{
			case HEX_LIST_APP:
			case HEX_LIST_WIN:
				break;
			case HEX_LIST_HACK:
				ListHacks( db.hacksTree, db.hacks );
				break;
			default:
				data.Sort();
				if ( doRename )
					wxRenameFile( tmpP, nowP, true );
				lbox->Append( data );
			}
		}
	}
}
bool G::LoadData( hexDB& db, TxtA& data, Text& nowP, Text& tmpP, Text& name, bool isFileTmp, bool isTempTmp )
{
	int  mode = 0, inMode = db.tmpMode, atMode = db.mode[ inMode ];
	bool b = true, samePath = ( db.nowP[ atMode ] == db.oldP[ atMode ] ), addObj = ( samePath && db.getNowN( inMode ) != getGlobalName() );
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
	case HEX_LIST_ORG:
		mode = 1;
		break;
	case HEX_LIST_PFM:
	case HEX_LIST_BIN:
	case HEX_LIST_PFL:
	case HEX_LIST_FORMAT:
	case HEX_LIST_HACK:
	case HEX_LIST_CODE:
		mode = 2;
		break;
	}
	TxtF file, temp;
	if ( mode > 0 )
	{
		if ( !wxFileExists( nowP ) )
			file.Create( nowP );
		if ( !wxFileExists( tmpP ) )
			temp.Create( tmpP );
	}
	if ( mode == 1 )
	{
		Text appName	= wxT("HackerEX");
		Text vendor		= wxT("Awsdert");
		if ( isTempTmp )
			wxCopyFile( nowP, tmpP, true );
		CfgF cfgN( appName, vendor, nowP );
		CfgF cfgT( appName, vendor, tmpP );
		switch ( inMode )
		{
			case HEX_LIST_SESSION:
				db.state	= LoadStates(	db.state,	cfgN, cfgT, data, name, isFileTmp, isTempTmp );
				name = db.state.nameNow;
				break;
			case HEX_LIST_ORG:
				db.org		= LoadOrgs(		db.org,		cfgN, cfgT, data, name, isFileTmp, isTempTmp );
				name = db.org.nameNow;
				break;
		}
	}
	else if ( mode == 2 )
	{
		file.Open( nowP );
		temp.Open( tmpP );
		if ( !file.IsOpened() || !temp.IsOpened() )
			return false;
		temp.Clear();
		temp.Write( wxTextFileType_Dos );
		switch ( inMode )
		{
			case HEX_LIST_PFM:
				db.pfm		= LoadPfms(		db.pfm,		file, temp, data, name, addObj, isFileTmp, isTempTmp );
				name = db.pfm.nameNow;
				break;
			case HEX_LIST_BIN:
				db.bin		= LoadBins(		db.bin,		file, temp, data, name, addObj, isFileTmp, isTempTmp );
				name = db.bin.nameNow;
				break;
			case HEX_LIST_PFL:
				db.pfl		= LoadPfls(		db.pfl,		file, temp, data, name, addObj, isFileTmp, isTempTmp );
				name = db.pfl.nameNow;
				break;
			case HEX_LIST_FORMAT:
				db.format	= LoadFormats(	db.format,	file, temp, data, name, addObj, isFileTmp, isTempTmp );
				name = db.format.name;
				break;
			case HEX_LIST_HACK:
				if ( !samePath )
					db.hacks.clear();
				db.codes	= LoadHacks(	db.codes,	file, temp, db.hacks, db.pfl.profile, addObj, db.format.format );
				name = db.hacks[ db.hacks.hackNow ].name;
				break;
		}
		b = temp.Write( wxTextFileType_Dos );
		temp.Close();
		file.Close();
	}
	else
	{
		switch ( inMode )
		{
			case HEX_LIST_APP:
			case HEX_LIST_WIN:
				db.appsLB->Clear();
				LoadApps( db );
				break;
			case HEX_LIST_RAM:
			{
				Bin& obj3 = db.bin;
				Ram ram;
				int iEnd = obj3.size();
				for ( int i = 0; i < iEnd; ++i )
				{
					ram = obj3[ i ];
					data.Add( ram.name );
				}
				break;
			}
		}
	}
	return b;
}
