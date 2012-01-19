#ifndef HEXCB
#defin
BOOL CALLBACK appList2(HWND hwnd, LPARAM user) {
	int a = (int)user;
	if (a > -2) {
		//int i = 0;
		wxString s1; s1 = wxT(""); wxString s2 = wxT("");
		wxString* s3; s3 = appS1; wxString* s4; s4 = appS2;
		wxString s5 = wxT("");
		WCHAR t1; LPTSTR t2 = NULL;
		LPDWORD pid = NULL;
		GetWindowThreadProcessId(hwnd, pid);
		s2 = getAppExe(pid); a++;
		s1.Printf(wxT("%i"), pid);
		/*appS1 = new wxString[a];
		appS2 = new wxString[a];
		for (i = 0;i < a;i++) {
			appS1[i].append(s3[i]);
			appS2[i].append(s4[i]);///
		}
		appS1[a].append(s1);
		appS2[a].append(s2);*/
		int i1 = GetWindowText(hwnd, &t1, 50);
		if (i1 == 0) { i1 = SendMessage(hwnd, WM_GETTEXT, sizeof(LPTSTR), (LPARAM)t2); }
		if (i1 > 0) {
			s2.Printf(wxT("%s"), t1);
			/*hexWin->gApp->AppendRows(1);
			hexWin->gApp->SetCellValue(appLen, 0, s1);
			hexWin->gApp->SetCellValue(appLen, 1, s2);
			//s.Printf(wxT("%i"), pe32.th32ProcessID);
			hexWin->gApp->SetRowLabelValue(appLen, s);*/
			useCB = FALSE;
		} appLen = a;
		addApp(s1, s2, s5);
		return FALSE;
	} appWin++; return TRUE;
}
#endif
