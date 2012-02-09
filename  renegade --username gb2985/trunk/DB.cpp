/***************************************************************
 * Name:      DB.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::DBSet(void) {
	wxString p, s; p = wxGetCwd();
	if (p.Find(wxT('\\'))) { myDiv = wxT('\\'); }
	else { myDiv = wxT('/'); }
	wxChar d = myDiv;
	dir.Open(p);
	p << d << wxT("db");
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s << p << d << DBFA[HDTI] << wxT(".hexdb");
	if (!dbf.Open(s)) {
		dbf.Create(s);
		dbf.Open(s);
	}
}
void ME::DBLoad(void) {
	DBSet();
	wxString s, t, t1, t2, t3;
	wxStringTokenizer st; dl = 0;
	DB->CollapseAndReset(rdi); bool u = false;
	DBI* cv = new DBI; u8 m = 0, m2;
	for (t = dbf.GetFirstLine(); !dbf.Eof(); t = dbf.GetNextLine()) {
		s = t.SubString(0, 0);
		switch (m) {
		case 1: m2 = 0;
			st.SetString(t, wxT(";"));
			while (st.HasMoreTokens()) {
				s = st.GetNextToken();
				if (m2 == 1) { t1 = s; }
				else if (m2 == 3) { cv->afs = s; }
				else if (m2 == 4) { cv->afi = getHEX(s); }
				m2++;
			} m = 2; break;
		case 2:
			if (s.Cmp(wxT("[")) == 0) {
				DBAdd(t1, cv);
				cv->afp = t.SubString(1, t.length() - 2);
				cv->afn.Clear();
				m = 1;
			} else {
				if (s.Cmp(wxT("\\")) == 0) { t = t.SubString(1, -1); }
				cv->afn += t;
			}
			break;
		default:
			if (s.Cmp(wxT("[")) == 0) {
				cv->afp = t.SubString(1, t.length() - 2);
				m = 1; u = true;
			}
		}
	} if (u) { DBAdd(t1, cv); }
	delete cv;
	wxTreeItemIdValue v;
	di = DB->GetFirstChild(rdi, v);
	DB->SelectItem(di);
}
void ME::DBSelect(void) {
	if (di.IsOk() && di != pdi) {
		pdi = di;
		DBI* cv = (DBI*)DB->GetItemData(di);
		DBFileT->SetValue(cv->afp);
		DBNotes->SetValue(cv->afn);
		//HTLoad();
	}
}
void ME::DBSelectC(wxTreeEvent& event) { di = event.GetItem(); DBSelect(); }
void ME::DBLoadBOnClick(wxCommandEvent& event) { DBLoad(); }
void ME::DBSave(void) {
	DBSet(); dbf.Clear();
	wxString s, l, n; wxChar c = wxT(';');
	wxTreeItemId i;
	wxStringTokenizer st;
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
		st.SetString(d->afn, wxT("\n"));
		while (st.HasMoreTokens()) {
			l = st.GetNextToken();
			s = l.SubString(0, 0);
			if (s.Cmp(wxT("[")) == 0 || s.Cmp(wxT("\\")) == 0) {
				l = wxT("\\") + l;
			} dbf.AddLine(l, t);
		}
		i = DB->GetNextChild(rdi, v);
	} dbf.Write(t);
	dbf.Close();
}
wxTreeItemId ME::DBRoot(void) { return DB->GetRootItem(); }
wxTreeItemId ME::DBRoot(wxTreeItemId& i) {
	wxTreeItemId c;
	if (i.IsOk() && i != rdi) { c = DB->GetItemParent(i); }
	else { c = rdi; }
	return c;
}
void ME::DBSaveBOnClick(wxCommandEvent& event) { DBSave(); }
void ME::DBDel(void) { wxTreeItemId i = DB->GetSelection(); DBDel(i); }
void ME::DBDel(wxTreeItemId& i) { DB->Delete(i); }
void ME::DBDelBOnClick(wxCommandEvent& event) { DBDel(); }
DBI* ME::DBCopy(DBI* from, DBI* to) {
	to->afi = from->afi;
	to->afn = from->afn;
	to->afp = from->afp;
	to->afr = from->afr;
	to->afs = from->afs;
	return to;
}
void ME::DBAdd(void) {
	DBI* cv = new DBI;
	wxString s;
	s.Printf(wxT("New Hack Tree %i"), dl);
	cv->afp = s;
	cv->afn = wxT("Notes");
	DBAdd(s, cv);
	delete cv;
}
void ME::DBAdd(wxString s, DBI* cv) {
	DBI* t = new DBI;
	t = DBCopy(cv, t);
	di = DB->AppendItem(rdi, s, -1, -1, t);
	rdi = DBRoot(di);
	DB->SelectItem(di); dl++;
}
void ME::DBAddBClick(wxCommandEvent& event) { DBAdd(); }
void ME::DBFileTOnKeyD(wxKeyEvent& event) {
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
