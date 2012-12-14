#include "hexGUI_G.hpp"
void G::LoadData( int doAct, int inMode, Text name )
{
	/**
		@param doAct
		determines which file version is retrieved and how it is treated, also tells the function whether to List the retrieved names
		@param inMode
		determines which file set is retrieved and what data to expect, in some cases a file is not loaded but data from a local object instead
		@param name
		is which object to keep hold of when loading data, in some cases this is ignored. In the event a name cannot be found the default object will be used.
	**/
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		inMode = m_ListNow;
	const wxChar tild = wxT('~');
	bool isFileTmp = false, isTempTmp = false;
	TxtF file, temp;
	Text path, leaf, subP;
	if ( !m_ListCfg && !CheckFilesT( path, leaf, subP, inMode ) )
		return;
	TxtA data;
	Text nowP	= path + m_sep + leaf;
	Text nowPL	= nowP;
	Text tmpP	= nowP + tild;
	Text tmpPL	= tmpP;
	switch ( doAct )
	{
	case HEX_LOAD_SAVE2TEMP:
		isTempTmp = true;
		break;
	case HEX_LOAD_SAVE2FILE:
		nowPL = tmpP;
		tmpPL = nowP;
		isFileTmp = true;
		break;
	case HEX_LOAD_LIST:
		if ( !m_ListCfg && nowP != dataOld[ inMode ] && !LoadData( data, file, temp, nowP, tmpP, inMode, name, false, true ) )
			return;
		data.Clear();
		nowPL = tmpP;
		tmpPL = tmpP + tild;
		isFileTmp = true;
		isTempTmp = true;
		break;
	default: return;
	}
	if ( !m_ListCfg )
	{
		dataNow[ inMode ] = nowP;
		if ( !LoadData( data, file, temp, nowPL, tmpPL, inMode, name, isFileTmp, isTempTmp ) )
			return;
	}
	if ( doAct == HEX_LOAD_LIST )
	{
		if ( m_ListCfg )
		{
			data.Clear();
			data.SetCount( HEX_LIST_COUNT );
			data[ HEX_LIST_SESSION	] = _("Session");
			data[ HEX_LIST_ORG		] = _("Organisation");
			data[ HEX_LIST_PFM		] = _("Platform");
			data[ HEX_LIST_BIN		] = _("Binary (Application / File)");
			data[ HEX_LIST_RAM		] = _("Byte Sections of Binary");
			data[ HEX_LIST_PFL		] = _("Profile");
			data[ HEX_LIST_HACK		] = _("Hack");
			data[ HEX_LIST_CODE		] = _("Code");
			data[ HEX_LIST_FIND		] = _("Search Bytes");
			data[ HEX_LIST_OUT		] = _("Search Results");
			data[ HEX_LIST_EDIT		] = _("Byte Editor");
		}
		else
		{
			switch ( inMode )
			{
				case HEX_LIST_ORG:
					name = m_org.nameNow;
					ShowOrgD( &m_org );
					break;
				case HEX_LIST_PFM:
					name = m_pfm.nameNow;
					ShowPfmD( m_pfm );
					break;
				case HEX_LIST_BIN:
					name = m_bin.nameNow;
					ShowBinD( m_bin );
					break;
				case HEX_LIST_PFL:
					name = m_pfl.nameNow;
					ShowPflD( m_pfl );
					break;
			}
			data.Sort();
			const Text Def = _("Default");
			bool en = ( name != Def );
			if ( inMode == HEX_LIST_RAM )
				en = true;
			else
				wxRenameFile( tmpPL, nowPL, true );
			for ( int i = 0; i < m_ListEnd; ++i )
				m_List_Ps[ i ]->Enable( en );
		}
		HexList_LB->Clear();
		HexList_LB->Append( data );
	}
}
bool G::LoadData( TxtA& data, TxtF& file, TxtF& temp, Text& nowP, Text& tmpP, int& inMode, Text& name, bool isFileTmp, bool isTempTmp )
{
	bool closeFiles = true;
	switch ( inMode )
	{
	case HEX_LIST_ORG:
	case HEX_LIST_PFM:
	case HEX_LIST_BIN:
	case HEX_LIST_PFL:
		if ( !wxFileExists( tmpP ) )
			temp.Create( tmpP );
		file.Open( nowP );
		temp.Open( tmpP );
		if ( !file.IsOpened() || !temp.IsOpened() )
			return false;
		temp.Clear();
		temp.Write( wxTextFileType_Dos );
		break;
	case HEX_LIST_RAM: closeFiles = false; break;
	}
	Ram ram;
	int i, iEnd;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
			m_org = LoadOrgs( m_org, file, temp, data, name, isFileTmp, isTempTmp );
			break;
		case HEX_LIST_PFM:
			m_pfm = LoadPfms( m_pfm, file, temp, data, name, isFileTmp, isTempTmp );
			break;
		case HEX_LIST_BIN:
			m_bin = LoadBins( m_bin, file, temp, data, name, isFileTmp, isTempTmp );
			break;
		case HEX_LIST_RAM:
			iEnd = m_bin.size();
			for ( i = 0; i < iEnd; ++i )
			{
				ram = m_bin[ i ];
				data.Add( ram.name );
			}
			break;
		case HEX_LIST_PFL:
			m_pfl = LoadPfls( m_pfl, file, temp, data, name, isFileTmp, isTempTmp );
			break;
	}
	if ( closeFiles )
	{
		closeFiles = temp.Write( wxTextFileType_Dos );
		closeFiles = ( file.Close() && temp.Close() && closeFiles );
	}
	else
		closeFiles = true;
	return closeFiles;
}
