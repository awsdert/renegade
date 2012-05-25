#include "G.h"
#include "GetPFM_DLG.h"
s32  G::mGetPFMEndian( void )
{
	return pfmEndian_D->GetSelection();
}
PFM  G::mGetPFM( void )
{
	xStr text;
	PFM pfm     = gGetPFM();
	pfm.endian  = pfmEndian_D->GetSelection();
	text        = pfmName_TXT->GetValue();
	pfm.nowName = !text.IsEmpty() ? text : pfm.oldName;
	text        = pfmFile_TXT->GetValue();
	pfm.nowFile = !text.IsEmpty() ? text : pfm.oldFile;
	return pfm;
}
void G::mShowPFM( void )
{
	PFM pfm = gGetPFM();
	pfmEndian_D->Select(      pfm.endian  );
	pfmName_TXT->ChangeValue( pfm.nowName );
	pfmFile_TXT->ChangeValue( pfm.nowFile );
}
void G::mSavePFM( void )
{
	xStrT st;
	wxTextFile file_TF;
	ORG  org   = gGetOrg();
	PFM  pfm   = gGetPFM();
	xStr path, file;
	gGetPFMFile( path, file );
	xStr text  = path + org.oldFile + gGetSlash();
	if ( wxDirExists( text ) )
	{
		path   = text;
		text  += pfm.oldFile + wxT( ".hexb" );
		if ( wxFileExists( text ) )
		{
			wxRenameFile( text, path + pfm.nowFile + wxT( ".hexb" ) );
		}
	}
	file_TF.Open( file );
	for
	(
		text   = file_TF.GetFirstLine();
				!file_TF.Eof();
		text   = file_TF.GetNextLine()
	)
	{
		st.SetString( text, wxT( "=" ) );
		text = st.GetNextToken();
		if ( text.CmpNoCase( pfm.oldName ) == 0 )
		{
			file_TF.RemoveLine( file_TF.GetCurrentLine() );
			break;
		}
	}
	switch ( pfm.endian )
	{
		case ENDIAN_BIG: text = wxT( ";1" ); break;
		case ENDIAN_LB:  text = wxT( ";2" ); break;
		default:         text = wxT( ";0" ); break;
	}
	file_TF.AddLine(
			pfm.nowName + wxT( "=" ) +
			pfm.nowFile + text,
			wxTextFileType_Dos );
	pfm.oldName = pfm.nowName;
	pfm.oldFile = pfm.nowFile;
	gSetPFM( pfm );
	file_TF.Write( wxTextFileType_Dos );
	file_TF.Close();
}
void G::mLoadPFM( void )
{
	GetPFM_DLG d( this );
	if ( d.ShowModal() == wxID_OK )
	{
		mShowPFM();
		mLoadBin();
	}
}
void G::mListPFM_OnClick( wxCommandEvent& event )
{
	mLoadPFM();
}
void G::mLoadPFM_OnClick( wxCommandEvent& event )
{
	mLoadPFM();
}
void G::mSavePFM_OnClick( wxCommandEvent& event )
{
	mSavePFM();
}
void G::mSetPFM_OnClick( wxCommandEvent& event )
{
	gSetPFM( mGetPFM() );
}
