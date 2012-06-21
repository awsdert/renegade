#include "G.h"
void G::mLoadSessions( void )
{
	xStr  text, path, file, name = wxT( "TotalSessions" ), value = wxT('0');
	xStr  title = gGetTitle(), vendor = gGetVendor();
	u8    i, iCount;
	gGetOrgFile( path, file );
	wxFileConfig hex_TF( title, vendor, file );
	hex_TF.SetPath( mCfgText );
	if ( hex_TF.Read( name, &text ) )
	{
		iCount = GetHexFromU64( text, 1u );
		if ( iCount > 5 ) iCount = 5;
	}
	else iCount = 0u;
	session_D->Clear();
	for ( i = 0u; i < iCount; ++i )
	{
		text.Printf( wxT( "Session %u" ), i + 1u );
		session_D->Append( text );
	}
	session_D->Select( i - 1u );
}
void G::mLoadSession( void )
{
	s8 sessionId = session_D->GetSelection();
	if ( sessionId < 0 || sessionId > 4 ) return;
	++sessionId;
	xStr sessionText;
	sessionText.Printf( wxT( "/Session_%i" ), sessionId );
	xStrT st;
	xStr  key, text, path, file, name;
	xStr  title = gGetTitle(), vendor = gGetVendor();
	gGetOrgFile( path, file );
	wxFileConfig hex_TF( title, vendor, file );
	hex_TF.SetPath( sessionText );
	if ( hex_TF.Read( mOrgText, &name ) )
	{
		hex_TF.SetPath( wxT("/") + mOrgText );
		if ( hex_TF.Read( name, &text ) )
		{
			ORG org;
			org.isDefault = false;
			org.nowName   = name;
			org.oldName   = name;
			org.nowFile   = text;
			org.oldFile   = text;
			gSetOrg( org );
			hex_TF.SetPath( sessionText );
			if ( hex_TF.Read( mPFMText, &name ) )
			{
				gGetPFMFile( path, file );
				wxFileConfig org_TF( title, vendor, file );
				if ( org_TF.Read( name, &text ) )
				{
					st.SetString( text, wxT( ";" ) );
					PFM pfm;
					pfm.isDefault = false;
					pfm.nowName   = name;
					pfm.oldName   = name;
					text          = st.GetNextToken();
					pfm.nowFile   = text;
					pfm.oldFile   = text;
					text          = st.GetNextToken();
					if ( text.CmpNoCase( wxT( "BIG" ) ) == 0 )
						pfm.endian = ENDIAN_BIG;
					else if ( text.CmpNoCase( wxT( "LB" ) ) == 0 )
						pfm.endian = ENDIAN_LB;
					else pfm.endian = ENDIAN_LITTLE;
					gSetPFM( pfm );
					if ( hex_TF.Read( mBinText, &name ) )
					{
						gGetBinFile( path, file );
						wxFileConfig pfm_TF( title, vendor, file );
						pfm_TF.SetPath( name );
						if ( pfm_TF.Read( wxT( "data" ), &text ) )
						{
							BIN bin;
							RAM ram;
							bool binKey   = false;
							long binIndex = 0;
							s8   ramNo    = 0;
							bin.isDefault = false;
							bin.nowName   = name;
							bin.oldName   = name;
							st.SetString( text, wxT( ";" ) );
							text          = st.GetNextToken();
							if ( text.CmpNoCase( wxT( "file" ) ) == 0 )
								bin.isFile = true;
							else bin.isFile = false;
							text          = st.GetNextToken();
							bin.nowFile   = text;
							bin.nowFile   = text;
							bin.bind      = st.GetNextToken();
							bin.path      = st.GetNextToken();
							for
							(
								binKey = pfm_TF.GetFirstEntry( key, binIndex );
								binKey;
								binKey = pfm_TF.GetNextEntry(  key, binIndex )
							)
							{
								if ( key.CmpNoCase( wxT("data") ) != 0 )
								{
									ramNo = GetHex( key, 1u );
									if ( ramNo >= bin.GetCount() ) bin.SetCount( ramNo );
									pfm_TF.Read( key, &text );
									st.SetString( text, wxT( ";" ) );
									ram.name     = st.GetNextToken();
									ram.ptrDepth = GetHex( st.GetNextToken(), 1u );
									ram.byte     = GetHex( st.GetNextToken() );
									ram.size     = GetHex( st.GetNextToken() );
									bin[ ramNo ] = ram;
								}
							}
							gSetBin( bin );
							if ( hex_TF.Read( mDBPText, &name ) )
							{
								gGetDBPFile( path, file );
								wxTextFile bin_TF;
								bin_TF.Open( file );
								DBP dbp;
								s32 mode = 0;
								u32 area = 0u;
								for
								(
									text = bin_TF.GetFirstLine();
										  !bin_TF.Eof();
									text = bin_TF.GetNextLine()
								)
								{
									if ( mode == 0 || mode == 2 )
									{
										if ( text.StartsWith( wxT( "[" ) ) )
										{
											if ( mode == 2 ) break;
											text = text.Mid( 1, text.length() - 2 );
											if ( text.CmpNoCase( name ) == 0 )
											{
												dbp.isDefault = false;
												dbp.nowName   = name;
												dbp.oldName   = name;
												mode = 1;
											}
										}
										else if ( mode == 2 )
										{
											if ( text.StartsWith( wxT( "\\" ) ) ) text = text.Mid( 1 );
											dbp.notes += text;
										}
									}
									else
									{
										st.SetString( text, wxT( ";" ) );
										st.GetNextToken();
										text        = st.GetNextToken();
										dbp.nowFile = text;
										dbp.oldFile = text;
										text        = st.GetNextToken();
										dbp.SID     = st.GetNextToken();
										dbp.PID     = GetHex( st.GetNextToken(), 2u );
										st.SetString( text, wxT( "," ) );
										do
										{
											text = st.GetNextToken();
											text.LowerCase();
											if ( text == wxT( "uk" ) ) 		 area |= AREA_UK;
											else if ( text == wxT( "us" ) )	 area |= AREA_US;
											else if ( text == wxT( "jp" ) )	 area |= AREA_JP;
											else if ( text == wxT( "de" ) )	 area |= AREA_DE;
											else if ( text == wxT( "aus" ) ) area |= AREA_AUS;
										} while ( st.HasMoreTokens() );
										mode = 2;
									}
								}
								gSetDBP( dbp );
							}
						}
					}
				}
			}
		}
	}
	mShowOrg();
	mShowPFM();
	mShowBin();
	mShowDBP();
	mLoadHack();
}
void G::mSaveSession( void )
{
	s8 sessionId = session_D->GetSelection();
	if ( sessionId < 0 ) return;
	++sessionId;
	xStr name;
	name.Printf( wxT( "Session_%i" ), sessionId );
	xStr  text, path, file;
	xStr  title = gGetTitle(), vendor = gGetVendor();
	gGetOrgFile( path, file );
	wxFileConfig hex_TF( title, vendor, file );
	hex_TF.SetPath( name );
	hex_TF.Write( mOrgText, gGetOrg().nowName );
	hex_TF.Write( mPFMText, gGetPFM().nowName );
	hex_TF.Write( mBinText, gGetBin().nowName );
	hex_TF.Write( mDBPText, gGetDBP().nowName );
	hex_TF.SetPath( wxT( '/' ) + mCfgText );
	name = wxT( "TotalSessions" );
	text.Printf( wxT("%01i"), session_D->GetCount() );
	hex_TF.Write( name, text );
}
void G::session_DOnChoice(   wxCommandEvent& event ) { mLoadSession(); }
void G::NewSession_OnClick(  wxCommandEvent& event )
{
	s8 iCount = session_D->GetCount();
	if ( iCount < 6 )
	{
		xStr text;
		text.Printf( wxT( "Session %i" ), iCount + 1 );
		session_D->Append( text );
		session_D->Select( iCount );
		mSaveSession();
	}
	else MB( wxT( "Cannot have more than 5 sessions" ) );
}
void G::DelSession_OnClick(  wxCommandEvent& event )
{
	s8 i = session_D->GetSelection();
	if ( i < 0 ) return;
	++i;
	xStr sessionText;
	sessionText.Printf( wxT( "Session_%i" ), i );
	xStr  path, file;
	xStr  title = gGetTitle(), vendor = gGetVendor();
	gGetOrgFile( path, file );
	wxFileConfig hex_TF( title, vendor, file );
	hex_TF.DeleteGroup( sessionText );
}
void G::LoadSession_OnClick( wxCommandEvent& event ) { mLoadSession(); }
void G::SaveSession_OnClick( wxCommandEvent& event ) { mSaveSession(); }
