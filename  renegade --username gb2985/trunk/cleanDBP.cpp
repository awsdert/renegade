#include "G.h"
#include "GetDBP_DLG.h"
DBP G::mGetDBP( void )
{
	DBP dbp;
	u32 area = 0u;
	if ( !dbpAreaAll_RB->GetValue() )
	{
		if ( lArea_CB[ AREA_UK_CB  ]->GetValue() ) area += AREA_UK;
		if ( lArea_CB[ AREA_US_CB  ]->GetValue() ) area += AREA_US;
		if ( lArea_CB[ AREA_JP_CB  ]->GetValue() ) area += AREA_JP;
		if ( lArea_CB[ AREA_DE_CB  ]->GetValue() ) area += AREA_DE;
		if ( lArea_CB[ AREA_AUS_CB ]->GetValue() ) area += AREA_AUS;
	}
	dbp.area    = area;
	dbp.nowFile = dbpFile_TXT->GetValue();
	dbp.notes   = dbpNotes_TA->GetValue();
	dbp.SID     = dbpSID_TXT->GetValue();
	dbp.PID     = GetHex( dbpPID_TXT->GetValue() );
	return dbp;
}
void G::mShowDBP( void )
{
	xStr text;
	DBP  dbp  = gGetDBP();
	u32  area = dbp.area;
	dbpAreaAll_RB->SetValue(   ( area == 0u ) );
	dbpAreaCheck_RB->SetValue( ( area != 0u ) );
	lArea_CB[ AREA_UK_CB  ]->SetValue( ( area == 0u || ( area & AREA_UK  ) > 0u ) );
	lArea_CB[ AREA_US_CB  ]->SetValue( ( area == 0u || ( area & AREA_US  ) > 0u ) );
	lArea_CB[ AREA_JP_CB  ]->SetValue( ( area == 0u || ( area & AREA_JP  ) > 0u ) );
	lArea_CB[ AREA_DE_CB  ]->SetValue( ( area == 0u || ( area & AREA_DE  ) > 0u ) );
	lArea_CB[ AREA_AUS_CB ]->SetValue( ( area == 0u || ( area & AREA_AUS ) > 0u ) );
	dbpName_TXT->ChangeValue( dbp.nowName   );
	dbpFile_TXT->ChangeValue( dbp.nowFile   );
	dbpNotes_TA->ChangeValue( dbp.notes     );
	dbpSID_TXT->ChangeValue(  dbp.SID );
	text.Printf( hexV, dbp.PID );
	dbpPID_TXT->ChangeValue(  text    );
}
void G::mSaveDBP( void )
{
	DBP dbp = gGetDBP();
	xStr text, path, file, name, tmp;
	gGetDBPFile( path, file );
	wxTextFile dbp_TF;
	u64 iCount = dbp_TF.GetLineCount();
	u64 j = 0u, k = 0u;
	bool mode  = false;
	for ( u64 i = 0u; i < iCount; ++i )
	{
		text = dbp_TF[ i ];
		if ( text.StartsWith( wxT( "[" ) ) )
		{
			if ( mode )
			{
				for ( ; j < i; ++j )
					dbp_TF.RemoveLine( k );
				break;
			}
			else
			{
				name = text.Mid( 1, text.length() - 1 );
				if ( name == dbp.oldName )
				{
					j    = i;
					k    = i;
					mode = true;
				}
			}
		}
	}
	text  = wxT( '[' ) + dbp.nowName + wxT( ']' );
	dbp_TF.AddLine( text, wxTextFileType_Dos );
	tmp.Printf( hex16, dbp.PID );
	text  = wxT( ';' ) + dbp.nowFile;
	text += wxT( ';' ) + name;
	text += wxT( ';' ) + dbp.SID;
	text += wxT( ';' ) + tmp;
	dbp_TF.Write( wxTextFileType_Dos );
	dbp_TF.Close();
}
void G::mLoadDBP( void )
{
	GetDBP_DLG d( this );
	d.ShowModal();
	mShowDBP();
}
void G::SetDBP_BOnClick( wxCommandEvent& event )
{
	gSetDBP( mGetDBP() );
}
void G::LoadDBP_BOnClick( wxCommandEvent& event )
{
	mLoadDBP();
}
void G::dbpPage_SNOnChange( wxSpinEvent& event )
{
	mLoadDBP();
}
void G::SaveDBP_BOnClick( wxCommandEvent& event )
{
	mSaveDBP();
}
void G::dbpFile_TXTOnChange( wxCommandEvent& event )
{
	doChange( event, VAL_FILE );
}
void G::dbpFile_TXTOnKeyDown( wxKeyEvent& event )
{
	doKeyDown( event, VAL_FILE );
}
void G::dbpArea_RBOnChange( wxCommandEvent& event )
{
	gEnable( !dbpAreaAll_RB->GetValue(), dbpAreaCB_P );
}

