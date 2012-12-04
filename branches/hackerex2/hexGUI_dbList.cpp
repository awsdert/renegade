#include "hexGUI_G.hpp"
void G::ListData( int s, int inMode )
{
	if ( s < 0 ) s = 0;
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		inMode = m_ListNow;
	TxtF file, temp;
	const wxChar tild = wxT('~');
	Text path, leaf, subP, nowP, tmpP;
	if ( !CheckFilesT( path, leaf, subP ) )
		return;
	nowP = path + m_sep + leaf + tild;
	tmpP = nowP + tild;
	if ( !wxFileExists( nowP ) )
		LoadData( inMode );
	if ( wxFileExists( tmpP ) )
		wxRemoveFile( tmpP );
	temp.Create( tmpP );
	temp.Open( tmpP );
	file.Open( nowP );
	if ( m_ListCfg )
	{
		int m;
		switch ( s )
		{
			case 1: m = HEX_LIST_ORG; break;
			case 2: m = HEX_LIST_PFM; break;
			case 3: m = HEX_LIST_BIN; break;
			case 4: m = HEX_LIST_PFL; break;
			default: m = HEX_LIST_SESSION;
		}
		m_ListNow = m;
		TxtA data;
		data.SetCount( 10 );
		data[ 0 ] = _("1.1 Session");
		data[ 1 ] = _("1.2 Organisation");
		data[ 2 ] = _("1.3 Platform");
		data[ 3 ] = _("1.4 Application / File");
		data[ 4 ] = _("1.5 Profile");
		data[ 5 ] = _("1.6 Hack");
		data[ 6 ] = _("1.7 Code");
		data[ 7 ] = _("2.1 Search Bytes");
		data[ 8 ] = _("2.2 Search Results");
		data[ 9 ] = _("2.3 Byte Editor");
		HexList_LB->Clear();
		HexList_LB->Append( data );
	}
	else
	{
		int sd = 0;
		Text name = HexList_LB->GetString( s );
		switch ( inMode )
		{
		case HEX_LIST_ORG:
		{
			OrgV dat1;
			LoadOrgs( dat1, file );
			sd = FindOrgI( dat1, name );
			m_org = dat1[ sd ];
			m_Org = sd;
			ShowOrgD( &m_org );
			ListOrgs( dat1 );
			SaveOrgs( dat1, file, temp );
			break;
		}
		case HEX_LIST_PFM:
		{
			PfmV dat2;
			LoadPfms( dat2, file );
			sd = FindPfmI( dat2, name );
			m_pfm = dat2[ sd ];
			m_Pfm = sd;
			ShowPfmD( m_pfm );
			ListPfms( dat2 );
			SavePfms( dat2, temp );
			break;
		}
		case HEX_LIST_BIN:
			//ShowBinD( s );
			break;
		case HEX_LIST_PFL:
			//ShowPflD( s );
			break;
		}
	}
	HexList_LB->SetSelection( s );
	file.Close();
	temp.Close();
	if ( !m_ListCfg )
		wxRenameFile( tmpP, nowP, true );
}
void G::ListOrgs( OrgV& dat )
{
	ui08 i, iEnd = dat.size();
	TxtA aTxt;
	aTxt.SetCount( iEnd );
	HexList_LB->Clear();
	for ( i = 0u; i < iEnd; ++i )
		aTxt[ i ] = dat[ i ].nameOld;
	HexList_LB->Append( aTxt );
}
void G::ListPfms( PfmV& dat )
{
	ui08 i, iEnd = dat.size();
	TxtA aTxt;
	aTxt.SetCount( iEnd );
	HexList_LB->Clear();
	for ( i = 0u; i < iEnd; ++i )
		aTxt[ i ] = dat[ i ].nameOld;
	HexList_LB->Append( aTxt );
}
