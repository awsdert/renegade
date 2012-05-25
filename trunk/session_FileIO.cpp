#include "G.h"
void G::mLoadSession( s8 sessionId )
{
	// TODO(awsdert) Rewrite Session Loading
	xStrT st;
	xStr  key, text, path, file, name;
	xStr  title = gGetTitle(), vendor = gGetVendor();
	gGetOrgFile( path, file );
	wxFileConfig hex_TF( title, vendor, file );
	hex_TF.SetPath( lLastText );
	if ( hex_TF.Read( lOrgText, &name ) )
	{
		hex_TF.SetPath( wxT("/") + lOrgText );
		if ( hex_TF.Read( name, &text ) )
		{
			ORG org;
			org.isDefault = false;
			org.nowName   = name;
			org.oldName   = name;
			org.nowFile   = text;
			org.oldFile   = text;
			gSetOrg( org );
			hex_TF.SetPath( wxT("/") + lLastText );
			if ( hex_TF.Read( lPFMText, &name ) )
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
					if ( hex_TF.Read( lBinText, &name ) )
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
							if ( hex_TF.Read( lDBPText, &name ) )
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
