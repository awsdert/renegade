#include "GetDBP_DLG.h"
void GetDBP_DLG::dLoadDBP( void )
{
	DBP dbp;
	dDBPList.resize( 1, dbp );
	dbp.isDefault = false;
	dIdList.resize( 0 );
	xStr  text, path, file;
	xStrT st;
	gGetDBPFile( path, file );
	wxTextFile file_TF;
	file_TF.Open( file );
	s32 mode = 0;
	u32 area = 0u;
	for
	(
		text = file_TF.GetFirstLine();
			  !file_TF.Eof();
		text = file_TF.GetNextLine()
	)
	{
		switch ( mode )
		{
			case 0: case 2:
				if ( text.StartsWith( wxT( "[" ) ) )
				{
					if ( mode == 2 ) dNewDBP( dbp );
					dbp.nowName = text.Mid( 1, text.length() - 2 );
					dbp.oldName = dbp.oldName;
					dbp.notes   = wxT( "" );
					mode = 1;
				}
				else if ( mode == 2 )
				{
					if ( text.StartsWith( wxT( "\\" ) ) ) text = text.Mid( 1 );
					dbp.notes += text;
				}
				break;
			case 1:
				st.SetString( text, wxT( ";" ) );
				st.GetNextToken();
				dbp.nowFile = st.GetNextToken();
				dbp.oldFile = dbp.nowFile;
				text        = st.GetNextToken();
				dbp.SID     = st.GetNextToken();
				dbp.PID     = GetHex( st.GetNextToken(), 2u );
				area        = 0u;
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
				dbp.area = area;
				mode = 2;
		}
	}
	if ( mode == 2 ) dNewDBP( dbp );
	file_TF.Close();
	dLoadDBI();
}
void GetDBP_DLG::dSaveDBP( void )
{
	DBP dbp;
	xStr text, path, file, txt;
	gGetDBPFile( path, file );
	wxTextFile file_TF;
	file_TF.Open( file );
	file_TF.Clear();
	u32 area = 0u;
	u16 iCount = dDBPList.size();
	for ( u16 i = 0u; i < iCount; ++i )
	{
		dbp = dDBPList[ i ];
		text = wxT( "[" ) + dbp.nowName + wxT( "]" );
		file_TF.AddLine( text, wxTextFileType_Dos );
		txt.Clear();
		area = dbp.area;
		if ( ( area & AREA_UK ) > 0u ) txt += wxT( "uk" );
		text = wxT( ";" ) + dbp.nowFile + wxT( ";" ) + txt;
	}
}
void GetDBP_DLG::dLoadDBI( void )
{
	u32 area;
	if ( dGetAreaSel_RB->GetValue() )
	{
		area = 0u;
		if ( dAreaGet_CB[ AREA_UK_CB  ]->GetValue() ) area |= AREA_UK;
		if ( dAreaGet_CB[ AREA_US_CB  ]->GetValue() ) area |= AREA_US;
		if ( dAreaGet_CB[ AREA_JP_CB  ]->GetValue() ) area |= AREA_JP;
		if ( dAreaGet_CB[ AREA_DE_CB  ]->GetValue() ) area |= AREA_DE;
		if ( dAreaGet_CB[ AREA_AUS_CB ]->GetValue() ) area |= AREA_AUS;
	}
	else area = AREA_ALL;
	s32 index = dDBPName_LB->GetCount();
	for ( --index; index >= 0; --index )
		dDBPName_LB->Delete( index );
	s32 count = dGetCount();
	DBI* dbi = new DBI;
	DBP  dbp;
	for ( index = 0; index < count; ++index )
	{
		dbp = dDBPList[ index ];
		if ( area == 0u || ( dbp.area & area ) > 0u )
		{
			dbi->index = index;
			dNewDBI( dbi );
		}
	}
	delete dbi;
	dDBPName_LB->Select( 0 );
	dShowDBP();
}
