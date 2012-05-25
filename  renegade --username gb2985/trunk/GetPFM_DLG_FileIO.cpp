#include "GetPFM_DLG.h"
void GetPFM_DLG::dLoadPFM( void )
{
	xStrT st;
	PFM*  pfm;
	xStr  key, text, path, file;
	gGetPFMFile( path, file );
	wxFileConfig pfm_TF( gGetTitle(), gGetVendor(), file );
	long  i = 0;
	bool  atKey = false;
	s8    index = dPFMName_LB->GetCount();
	for ( --index; index >= 0; --index )
	{
		pfm = dGetPFM( index );
		if ( !pfm->isDefault ) dPFMName_LB->Delete( index );
	}
	pfm            = new PFM;
	pfm->isDefault = false;
	for
	(
		atKey = pfm_TF.GetFirstEntry( key, i );
		atKey;
		atKey = pfm_TF.GetNextEntry(  key, i )
	)
	{
		if ( key.IsEmpty() ) continue;
		pfm->nowName = key;
		pfm->oldName = key;
		pfm_TF.Read( key, &text );
		if ( text.IsEmpty() )
		{
			dNewPFM( pfm );
			continue;
		}
		st.SetString( text, wxT( ";" ) );
		pfm->nowFile = st.GetNextToken();
		pfm->oldFile = pfm->nowFile;
		text         = st.GetNextToken();
		if ( text.CmpNoCase( wxT( "BIG" ) ) == 0 ||
			text == wxT( "1" ) ) pfm->endian = ENDIAN_BIG;
		else if ( text.CmpNoCase( wxT( "LB" ) ) == 0 ||
			text == wxT( "2" ) ) pfm->endian = ENDIAN_LB;
		else pfm->endian = ENDIAN_LITTLE;
		dNewPFM( pfm );
	}
	dPFMName_LB->Select( 0 );
	dShowPFM();
}
void GetPFM_DLG::dSavePFM( void )
{
	PFM* pfm;
	xStr text, path, file;
	s8   count = dPFMName_LB->GetCount();
	gGetPFMFile( path, file );
	wxFileConfig pfm_TF( gGetTitle(), gGetVendor(), file );
	for ( s8 index = 0; index < count; ++index )
	{
		pfm = dGetPFM( index );
		if ( !pfm->isDefault )
		{
			switch ( pfm->endian )
			{
				case ENDIAN_BIG: text = wxT( ";1" ); break;
				case ENDIAN_LB:  text = wxT( ";2" ); break;
				default:         text = wxT( ";0" ); break;
			}
			pfm_TF.Write( pfm->nowName, pfm->nowFile + text );
		}
	}
}
