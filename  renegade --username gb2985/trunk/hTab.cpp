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
// Platform
void ME::PFSet(void) {
	xStr d = hexSlash, p = wxGetCwd(), s;
	p << d + wxT("pf");
	dir.Open(p);
	if ( !dir.Exists(p) )
	{
		wxMkdir(p);
		dir.Open(p);
	}
	s = p + d + DBFA[HDTI] + wxT(".hexpf");
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
	u32 mode = 0, appIndex = 0, ramIndex = 0, ramLength = 0, listLength = appName.GetCount();
	xStr tmp;
	const wxChar* brace1 = wxT( "[" );
	const wxChar* brace2 = wxT( "]" );
	const wxChar* info = wxT( ";" );
	const wxChar* ramText = wxT( "%X=" );
	for ( ; ramIndex < listLength; )
	{
		switch ( mode )
		{
			case 0:
				pff.AddLine( brace1 + appTitle_D->GetString( appIndex ) + brace2 );
				mode = 1;
				break;
			case 1:
				pff.AddLine( info + appName[ appIndex ] );
				ramLength = appEnd[ appIndex ];
				appIndex++;
				mode = 2;
				break;
			case 2:
				if ( ramIndex < ramLength )
				{
					tmp.Printf( ramText, ramIndex );
					pff.AddLine( tmp + ramName [ ramIndex ] + info +
						ramFixed [ ramIndex ] + info + ramStart [ ramIndex ] +
						info + ramSize [ ramIndex ] );
					ramIndex++;
				}
				else
				{
					mode = 0;
				}
		}
	}
	pff.Write();
	pff.Close();
}
void ME::PFLoad( void )
{
	HDTI = group_D->GetSelection();
	PFSet();
	u32 m = 0, i = 0, ram = 0; s32 l = -1;
	appTitle_D->Clear();
	PFEA.Clear();
	xStr s, t, x;
	xStrT st;
	addressSize = PLATFORM_SIZE[HDTI];
	ClearGrid(RAMG);
	appName.Clear();
	appNum.Clear();
	appEnd.Clear();
	ramName.Clear();
	ramFixed.Clear();
	ramSize.Clear();
	ramStart.Clear();
	EMD->Clear();
	for (s = pff.GetFirstLine();!pff.Eof();s = pff.GetNextLine()) {
		switch (m) {
		case 0:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT("[")) == 0) {
				t = s.SubString(1, s.length() - 2);
				appTitle_D->Append(t);
				m = 1;
			} break;
		case 1:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT(";")) == 0) {
				t = s.SubString(1, -1);
				appName.Add(t);
				appNum.Add(ram);
				appEnd.Add(ram);
				m = 2; l++;
			} break;
		case 2:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT("[")) == 0) {
				t = s.SubString(1, s.length() - 2);
				appTitle_D->Append(t);
				m = 1;
			} else {
				t = s.SubString(2, -1);
				st.SetString(t, wxT(";"));
				x = st.GetNextToken(); // Name
				ramName.Add(x);
				x = st.GetNextToken(); // Fixed?
				ramFixed.Add(x);
				x = st.GetNextToken(); // Address
				ramStart.Add(x);
				x = st.GetNextToken(); // Size
				ramSize.Add(x);
				ram++; appEnd[l]++;
				i++; m = 1;
			} break;
		}
	}
	pff.Close();
	appTitle_D->SetSelection(0);
	PresetOnChange();
	DBLoad();
}
void ME::PresetOnChange( void )
{
	s32 ai = appTitle_D->GetSelection();
	if ( ai >= 0 )
	{
		u32 i, l = appEnd[ ai ], j;
		xStr s;
		APPT->SetValue( appName[ ai ] );
		ClearGrid(RAMG);
		for (i = appNum[ai], j = 0;i < l;i++, j++) {
			RAMG->AppendRows(1, false);
			RAMG->SetCellValue(j, 0, ramName[ i ]);
			RAMG->SetCellValue(j, 1, ramFixed[ i ]);
			RAMG->SetCellValue(j, 2, ramStart[ i ]);
			RAMG->SetCellValue(j, 3, ramSize[ i ]);
			s.Printf( wxT( "%X" ), j ); // ID to use in Codes
			RAMG->SetRowLabelValue( i, s );
		}
	}
}
void ME::ram_GOnChange( wxGridEvent& event )
{
	s32 appIndex = appTitle_D->GetSelection();
	s32 row = event.GetRow();
	s32 col = event.GetCol();
	if (appIndex >= 0 && row >= 0 && col >= 0)
	{
		u32 ramIndex = appNum[ appIndex ] + row;
		xStr text = GARAM( row, col );
		switch ( col )
		{
			case 0: ramName[ ramIndex ] = text; break;
			case 1: ramFixed[ ramIndex ] = text; break;
			case 2: ramStart[ ramIndex ] = text; break;
			case 3: ramSize[ ramIndex ] = text; break;
		}
	}
}
