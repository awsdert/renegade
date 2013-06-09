#include "wx_pch.h"
#include "hex2_app.h"
#include "hex2_G.h"

IMPLEMENT_APP( HexApp );

bool HexApp::OnInit()
{
	/*
#ifdef wxMSW
	wxSystemOptions::SetOption(wxT("msw.remap"), 2);
#endif
	//*/
	G *g = new G( 0u );
	g->Show();
	return true;
}
