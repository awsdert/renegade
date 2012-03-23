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
void ME::DBSet( void )
{
	xStr d = hexSlash, p, s;
	p = wxGetCwd();
	dir.Open( p );
	p << d + wxT( "db" );
	if ( !dir.Exists( p ) )
	{
		wxMkdir(p);
		dir.Open(p);
	}
	s32 i = group_D->GetSelection();
	PLATFORM* pf = (PLATFORM*)group_D->GetClientData( i );
	s << p + d + pf->file + wxT( ".hexdb" );
	if ( !checkFile.Exists( s ) )
	{
		dbf.Create(s);
	}
	dbf.Open(s);
}
void ME::DBLoad(void) {
	DBSet();
	xStr s, t, t1, t2, t3;
	xStrT st; dl = 0;
	// This and DB->Delete don't seem to do their job
	DB->DeleteAllItems(); bool u = false;
	// Ignore this, works fine
	DBI* cv = new DBI; u8 m = 0, m2;
	for (t = dbf.GetFirstLine(); !dbf.Eof(); t = dbf.GetNextLine()) {
		s = t.SubString(0, 0);
		switch (m) {
		case 1: m2 = 0;
			// Read generic data, no problems here
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
				DBAdd(t1, cv); // Add then reset DBI data below
				cv->afp = t.SubString(1, t.length() - 2);
				cv->afn.Clear();
				m = 1;
			} else {
				if (s.Cmp(wxT("\\")) == 0) { t = t.SubString(1, -1); }
				cv->afn += t; // Append to notes
			}
			break;
		default:
			if (s.Cmp(wxT("[")) == 0) {
				// Get filename
				cv->afp = t.SubString(1, t.length() - 2);
				m = 1; u = true;
			}
		}
	} if (u) { DBAdd(t1, cv); }
	delete cv; xTIDV v;
	di = DB->GetFirstChild(rdi, v);
	DB->SelectItem(di);
	dbf.Close();
	HTLoad();
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
void ME::DBSave(void) { // Convert all hack items to a list that can re-build from
	DBSet(); dbf.Clear();
	xStr s, l, n; wxChar c = wxT(';');
	xTID i;
	xStrT st;
	xTIDV v; DBI* d;
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
xTID ME::DBRoot(void) { return rdi; }
xTID ME::DBRoot(xTID& i) {
	xTID c; // Prevents overide of child id
	if (i.IsOk() && i != rdi) { c = DB->GetItemParent(i); }
	else { c = rdi; } return c;
}
void ME::DBDel(void) { xTID i = DB->GetSelection(); DBDel(i); }
void ME::DBDel(xTID& i) { DB->Delete(i); }
DBI* ME::DBCopy(DBI* from, DBI* to) {
	to->afi = from->afi; // App ID - used only for export once implimented
	to->afn = from->afn; // Notes
	to->afp = from->afp; // Hacklist Filename
	to->afr = from->afr; // Region - not in use yet
	to->afs = from->afs; // Serial ID - mainly for games
	return to;
}
void ME::DBAdd(void) {
	DBI* cv = new DBI; // Subclass of wxTreeItemData, used for generic Profile data
	xStr s;
	s.Printf(wxT("New Hack Tree %i"), dl);
	cv->afp = s; // Set Profile's file name to s
	cv->afn = wxT("Notes");
	DBAdd(s, cv);
	delete cv;
}
void ME::DBAdd(xStr s, DBI* cv) {
	DBI* t = new DBI;
	t = DBCopy(cv, t); // Calling code might still need it's object so transfer data to new object
	di = DB->AppendItem(rdi, s, -1, -1, t); // rdi = root
	rdi = DBRoot(di); // Force rdi to contain correct id should it change
	DB->SelectItem(di); dl++;
}
void ME::DBAddBClick(wxCommandEvent& event) { DBAdd(); }
void ME::validateFileName(wxKeyEvent& event)
{
	s32 key = event.GetKeyCode();
	wxChar txt = key;
	bool doEvent = false;
	xStr text = txt;
	text = text.Upper();
	xStr checkName = wxT( "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ (-)" ), t;
	if ( key > 255 || checkName.Contains( text ) )
	{
		doEvent = true;
	}
	else
	{
		switch ( key )
		{
			case WXK_BACK:
			case WXK_DELETE:
			case WXK_INSERT:
			case WXK_LEFT:
			case WXK_RIGHT:
			case WXK_UP:
			case WXK_DOWN:
				doEvent = true;
		}
	}
	event.Skip(doEvent);
}
void ME::DBFileTOnKeyD(wxKeyEvent& event)
{
	validateFileName(event);
}
