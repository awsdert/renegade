#include "G.h"
void G::dump_BOnClick( wxCommandEvent& event )
{
	findUse_D->SetSelection( 0 );
	Search( 0, 0 );
}
void G::find_BOnClick( wxCommandEvent& event )
{
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, findType_D->GetSelection() );
	}
}
void G::findEqual_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_EQUAL );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_EQUAL );
	}
}
void G::findNOTE_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_NOT );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_NOT );
	}
}
void G::findGT_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_MT );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_MT );
	}
}
void G::findGTE_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_MTE );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_MTE );
	}
}
void G::findLT_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_LT );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_LT );
	}
}
void G::findLTE_BOnClick( wxCommandEvent& event )
{
	findType_D->SetSelection( QD_LTE );
	s16 no = findUse_D->GetSelection();
	if ( no < 255 )
	{
		Search( no, QD_LTE );
	}
}
void G::findUndo_BOnClick( wxCommandEvent& event )
{
	s16 no = findUse_D->GetCount() - 2;
	SetSearch( no );
}
s8 prevMode = 0;
void G::findMode_DOnChoice( wxCommandEvent& event )
{
	s8   mode = findMode_D->GetSelection();
	u8   size = gGetUSize( findSize_D->GetSelection() );
	u64  valG, valB;
	xStr txtG, txtB, text;
	for ( s8 i = 0; i < QV_COUNT; ++i )
	{
		txtG = mQVG_TXT[ i ]->GetValue();
		txtB = mQVB_TXT[ i ]->GetValue();
		switch ( prevMode )
		{
			case VAL_HEX:
				valG = GetHex( txtG, size );
				valB = GetHex( txtB, size );
				break;
			case VAL_UINT:
				valG = GetHexFromU64( txtG, size );
				valB = GetHexFromU64( txtB, size );
				break;
			case VAL_SINT:
				valG = GetHexFromS64( txtG, size );
				valB = GetHexFromS64( txtB, size );
				break;
			case VAL_SFLT:
				valG = GetHexFromF64( txtG, size );
				valB = GetHexFromF64( txtB, size );
				break;
			default:
				valG = 0u;
				valB = 0u;
		}
		switch ( mode )
		{
			case VAL_HEX:
				text = hexVLL;
				txtG.Printf( text, valG );
				txtB.Printf( text, valB );
				break;
			case VAL_UINT:
				text = wxT( "%llu" );
				txtG.Printf( text, valG );
				txtB.Printf( text, valB );
				break;
			case VAL_SINT:
				text = wxT( "%lli" );
				txtG.Printf( text, valG );
				txtB.Printf( text, valB );
				break;
			case VAL_SFLT:
				switch ( size )
				{
					case 1u: case 2u: case 4u:
						text = wxT( "%llf" ); break;
					default: text = wxT( "%lg" );
				}
				txtG.Printf( text, valG );
				txtB.Printf( text, valB );
				break;
			default:
				txtG = wxT( '0' );
				txtB = wxT( '0' );
				break;
		}
		mQVG_TXT[ i ]->ChangeValue( txtG );
		mQVB_TXT[ i ]->ChangeValue( txtB );
	}
	prevMode = mode;
}
void G::find_TXTOnChange( wxCommandEvent& event )
{
	s32 mode = findMode_D->GetSelection();
	s32 size = findSize_D->GetSelection();
	doChange( event, mode, size );
}
void G::compare_DOnChoice( wxCommandEvent& event ) {}
