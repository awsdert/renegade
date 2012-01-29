/***************************************************************
 * Name:      DB.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <string.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
DBI::DBI(void) : wxTreeItemData() {
	afr = 0x00;
	afi = 0x00000;
	afn = wxT("");
	afs = wxT("");
}
DBI::DBI(wxTreeItemData*) : wxTreeItemData() {}
DBI::~DBI(void) {
	afr = 0x00; afi = 0x0000;
	afn.Clear(); afs.Clear();
}
void hexWin::DBSet(void) {
	int afi = cbGroup->GetSelection();
	if (afi < 0) { afi = PS2; }
	wxString p, s; p = wxGetCwd();
	if (p.Find(wxT('\\'))) { myDiv = wxT('\\'); }
	else { myDiv = wxT('/'); }
	wxChar d = myDiv;
	dir.Open(p);
	p << d << wxT("db");
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s << p << d << dbFile[afi] << wxT(".hexdb");
	if (!dbf.Open(s)) {
		dbf.Create(s);
		dbf.Open(s);
	}
}
void hexWin::DBLoad(void) {
	DBSet();
	wxString t, t1, t2, t3;
	DB->Delete(rdi);
	DBI* cv = new DBI; int j, m = 0, m2;
	for (t = dbf.GetFirstLine(); !dbf.Eof(); t = dbf.GetNextLine()) {
		switch (m) {
		case 1: DBAdd(t1, cv);
			cv = new DBI;
			cv->afp = t3;
			m = 0; t1.Clear();
		break;
		case 2: m2 = -1;
			for (j = 0;j < (int)t.Length();j++) {
				t3 = t.GetChar(j);
				if (t3.Cmp(wxT(";")) == 0) {
					m2++;
					if (m2 == 1) { t1 = t2; }
					else if (m2 == 3) { cv->afs = t2; }
					else if (m2 == 4) { cv->afi = getHEX(t2); }
					t2.Clear();
				} else { t2 << t3; }
			} m = 3; break;
		case 3:
			if (t.StartsWith(wxT("["))) {
				t3 = t.SubString(1, t.length() - 2);
				m = 1;
			} else { cv->afn += t; }
			break;
		default:
			if (t.StartsWith(wxT("["))) {
				cv->afp = t.SubString(1, t.length() - 2);
				m = 2;
			}
		}
	} if (!!t1) { DBAdd(t1, cv); }
}
void hexWin::DBLoadBOnClick(wxCommandEvent& event) { DBLoad(); }
void hexWin::DBSave(void) {
	DBSet(); wxString s, l, n; wxChar c = wxT(';');
	wxTreeItemId i;
	wxTreeItemIdValue v; DBI* d;
	wxTextFileType t = wxTextFileType_Dos;
	i = DB->GetFirstChild(rdi, v);
	while (i.IsOk()) {
		d = (DBI*)DB->GetItemData(i);
		s = wxT("[") + d->afp + wxT("]");
		dbf.AddLine(s, t);
		l = DB->GetItemText(i);
		n.Printf(wxT("%04X"), d->afi);
		s = c + l + c + wxT("uk") + c + d->afs + c + n;
		dbf.AddLine(s, t);
		i = DB->GetNextChild(rdi, v);
	} dbf.Write(t);
	dbf.Close();
}
wxTreeItemId hexWin::DBRoot(void) { return DB->GetRootItem(); }
wxTreeItemId hexWin::DBRoot(wxTreeItemId& i) {
	if (i.IsOk()) { i = DB->GetItemParent(i); }
	if (!i.IsOk()) { i = DB->GetRootItem(); }
	return i;
}
void hexWin::DBSaveBOnClick(wxCommandEvent& event) { DBSave(); }
void hexWin::DBDel(void) { wxTreeItemId i = DB->GetSelection(); DBDel(i); }
void hexWin::DBDel(wxTreeItemId& i) { DB->Delete(i); }
void hexWin::DBDelBOnClick(wxCommandEvent& event) { DBDel(); }
void hexWin::DBAdd(void) {
	DBI* cv = new DBI;
	wxString s;
	s.Printf(wxT("New Hack Tree %i"), dl);
	cv->afp = s;
	cv->afn = wxT("Notes");
	DBAdd(s, cv);
}
void hexWin::DBAdd(wxString s, DBI* cv) {
	if (dl < 1) { rdi = DBRoot(); }
	di = DB->AppendItem(rdi, s, -1, -1, cv);
	if (dl < 1) { rdi = DBRoot(di); }
	DB->SelectItem(di); dl++;
}
void hexWin::DBAddBClick(wxCommandEvent& event) { DBAdd(); }
void hexWin::DBSelect(void) {
	if (di != pdi) {
		pdi = di;
		DBI* cv = (DBI*)DB->GetItemData(di);
		DBNotes->SetValue(cv->afn);
	}
}
void hexWin::DBSelectC(wxTreeEvent& event) {
	di = event.GetItem();
	DBSelect();
}
void hexWin::DBFileTOnKeyD(wxKeyEvent& event) {
	int k = event.GetKeyCode();
	wxChar c = event.GetUnicodeKey();
	wxString s = wxT("01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ (-)"), t;
	t = s.Lower();
	if (k == 8 || k == WXK_DELETE || k == WXK_INSERT ||
		(k >= 35 && k <= 40) || k > 255) { event.Skip(); }
	else if (s.Contains(c) || t.Contains(c)) {
		DBFileT->WriteText(c);
	}
}
