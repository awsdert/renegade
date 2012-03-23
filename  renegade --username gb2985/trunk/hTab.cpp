#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
// Hook
void ME::setAWait(s32 i) { AW = i; }
void ME::setApps(void) {
	s32 i = APPG->GetNumberRows();
	if (i > -1) {
		APPG->DeleteRows(0, i, false);
	} appLen = -1;
	AWU = wxGetLocalTimeMillis() + AWB;
#ifdef WIN32
	EnumWindows(listApps, NULL);
#endif
}
void ME::appTitle_DOnBlur( wxFocusEvent& event )
{
	xStr text = appTitle_D->GetValue();
	if ( text != wxT("") )
	{
		s32 appIndex = appTitle_D->FindString( text );
		if ( appIndex < 0 )
		{
			appIndex = appTitleAdd( text, true );
		}
		appTitle_D->Select( appIndex );
		PresetOnChange();
	}
	event.Skip();
}
void addRAM( BIN* bin )
{
	bin->ramName.Add( wxT("New RAM") );
	bin->ramFixed.Add( wxT('1') );
	bin->ramStart.Add( wxT('0') );
	bin->ramSize.Add( wxT('0') );
}
void ME::addRAM_BOnClick( wxCommandEvent& event )
{
	wxComboBox* binTitle_D = getBinType();
	s32 binIndex = binTitle_D->GetSelection();
	if ( binIndex >= 0 )
	{
		BIN* bin = getBin( binTitle_D, binIndex );
		addRAM( bin );
		setBin( binTitle_D, bin, binIndex );
		PresetOnChange();
	}
}
// Platform
void ME::PFSet( void ) {
	xStr d = hexSlash, p = wxGetCwd(), s;
	p << d + wxT("pf");
	dir.Open(p);
	if ( !dir.Exists(p) )
	{
		wxMkdir(p);
		dir.Open(p);
	}
	s32 i = group_D->GetSelection();
	PLATFORM* pf = (PLATFORM*)group_D->GetClientData( i );
	s = p + d + pf->file + wxT(".hexpf");
	if ( !checkFile.Exists(s) )
	{
		pff.Create(s);
	}
	pff.Open(s);
}
void ME::saveGroup_BOnClick( wxCommandEvent& event ) { saveGroup(); }
void ME::saveGroup( void )
{
	PFSet();
	pff.Clear();
	saveGroup( appTitle_D );
	saveGroup( fileTitle_D );
	pff.Write();
	pff.Close();
}
void ME::saveGroup( wxComboBox* binTitle_D )
{
	BIN* bin;
	s32 binIndex = 0;
	s32 binLength = binTitle_D->GetCount();
	s32 ramIndex;
	s32 ramLength;
	xStr tmp;
	const wxChar* brace1 = wxT( "[" );
	const wxChar* brace2 = wxT( "]" );
	const wxChar* info = wxT( ";" );
	const wxChar* ramText = wxT( "%X=" );
	for ( ; binIndex < binLength; binIndex++ )
	{
		bin = getBin( binTitle_D, binIndex );
		pff.AddLine( brace1 + binTitle_D->GetString( binIndex ) + brace2 );
		pff.AddLine( info + bin->binName );
		ramLength = bin->GetCount();
		for ( ramIndex = 0; ramIndex < ramLength; ramIndex++ )
		{
			tmp.Printf( ramText, ramIndex );
			pff.AddLine( tmp + bin->ramName[ ramIndex ] + info +
				bin->ramFixed[ ramIndex ] + info + bin->ramStart[ ramIndex ] +
				info + bin->ramSize[ ramIndex ] );
		}
	}
}
s32 ME::appTitleAdd( xStr title, bool isNew )
{
	BIN* bin = new BIN;
	if ( isNew )
	{
		addRAM( bin );
	}
	return appTitle_D->Append( title, bin );
}
BIN* ME::getBin( wxComboBox* choice, s32 index )
{
	if ( index < 0)
	{
		index = 0;
	}
	return (BIN*)choice->GetClientData( index );
}
void ME::setBin( wxComboBox* choice, BIN* bin, s32 index )
{
	if ( index >= 0 )
	{
		choice->SetClientData( index, bin );
	}
}
void ME::PFLoad( void )
{
	HDTI = group_D->GetSelection();
	PFSet();
	u32 mode = 0;
	appTitle_D->Clear();
	PFEA.Clear();
	xStr s, t, x;
	s32 appIndex;
	xStrT st;
	BIN* bin = NULL;
	EMD->Clear();
	const wxChar info = wxT( ';' );
	const wxChar brace1 = wxT( '[' );
	addressSize = PLATFORM_SIZE[HDTI];
	for ( s = pff.GetFirstLine(); !pff.Eof(); s = pff.GetNextLine() )
	{
		switch (mode)
		{
			case 0:
				t = s.SubString(0, 0);
				if ( t.Cmp( brace1 ) == 0 )
				{
					appIndex = appTitleAdd( s.SubString( 1, s.length() - 2 ) );
					bin = getBin( appTitle_D, appIndex );
					mode = 1;
				}
				break;
			case 1:
				t = s.SubString(0, 0);
				if ( t.Cmp( info ) == 0 )
				{
					bin->binName = s.SubString(1, -1);
					mode = 2;
				}
				break;
			case 2:
				t = s.SubString(0, 0);
				if ( t.Cmp( brace1 ) == 0 )
				{
					appIndex = appTitleAdd( s.SubString( 1, s.length() - 2 ) );
					bin = getBin( appTitle_D, appIndex );
					mode = 1;
				}
				else
				{
					st.SetString( s.SubString( 2, -1 ), info );
					x = st.GetNextToken(); // Name
					bin->ramName.Add(x);
					x = st.GetNextToken(); // Fixed?
					bin->ramFixed.Add(x);
					x = st.GetNextToken(); // Address
					bin->ramStart.Add(x);
					x = st.GetNextToken(); // Size
					bin->ramSize.Add(x);
				}
				break;
		}
	}
	pff.Close();
	appTitle_D->SetSelection( -1 );
	PresetOnChange();
	DBLoad();
}
void ME::appName_TXTOnBlur( wxFocusEvent& event )
{
	s32 appIndex = appTitle_D->GetSelection();
	if ( appIndex < 0 )
	{
		appIndex = appTitleAdd( appTitle_D->GetValue(), true );
		appTitle_D->Select( appIndex );
	}
	BIN* bin = getBin( appTitle_D, appIndex );
	bin->binName = appName_TXT->GetValue();
	setBin( appTitle_D, bin, appIndex );
}
void ME::PresetOnChange( void )
{
	wxComboBox* binTitle_D = getBinType();
	s32 binIndex = binTitle_D->GetSelection();
	ClearGrid( RAMG );
	appName_TXT->Clear();
	searchRAM_D->Clear();
	resultHackRAM_D->Clear();
	EMD->Clear();
	codeRAM_D->Clear();
	if ( binIndex >= 0 )
	{
		BIN* bin = getBin( binTitle_D, binIndex );
		u32 i = 0, l = bin->GetCount();
		if ( l < 1 )
		{
			addRAM( bin );
			l = 1;
		}
		xStr s;
		appName_TXT->SetValue( bin->binName );
		for ( ; i < l; i++) {
			RAMG->AppendRows(1, false);
			searchRAM_D->Append( bin->ramName[ i ] );
			resultHackRAM_D->Append( bin->ramName[ i ] );
			EMD->Append( bin->ramName[ i ] );
			codeRAM_D->Append( bin->ramName[ i ] );
			RAMG->SetCellValue( i, 0, bin->ramName[ i ] );
			RAMG->SetCellValue( i, 1, bin->ramFixed[ i ] );
			RAMG->SetCellValue( i, 2, bin->ramStart[ i ] );
			RAMG->SetCellValue( i, 3, bin->ramSize[ i ] );
			s.Printf( wxT( "%X" ), i ); // ID to use in Codes
			RAMG->SetRowLabelValue( i, s );
		}
		searchRAM_D->Select(0);
		resultHackRAM_D->Select(0);
		EMD->Select(0);
		codeRAM_D->Select(0);
	}
}
wxComboBox* ME::getBinType( void )
{
	if ( hookType_D->GetSelection() > 0 )
	{
		return fileTitle_D;
	}
	else
	{
		return appTitle_D;
	}
}
void ME::ram_GOnChange( wxGridEvent& event )
{
	wxComboBox* binTitle_D = getBinType();
	s32 binIndex = binTitle_D->GetSelection();
	s32 row = event.GetRow();
	s32 col = event.GetCol();
	if (binIndex >= 0 && row >= 0 && col >= 0)
	{
		BIN* bin = getBin( binTitle_D, binIndex );
		xStr text = GARAM( row, col );
		if ( text.IsEmpty() )
		{
			if ( col > 0 )
			{
				text = wxT( "0" );
			}
			else
			{
				text.Printf( wxT("RAM %i"), row );
			}
		}
		switch ( col )
		{
			case 0: bin->ramName[ row ] = text; break;
			case 1: bin->ramFixed[ row ] = text; break;
			case 2: bin->ramStart[ row ] = text; break;
			case 3: bin->ramSize[ row ] = text; break;
		}
		setBin( binTitle_D, bin, binIndex );
	}
}
