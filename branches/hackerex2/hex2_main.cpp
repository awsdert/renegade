#include "wx_pch.h"
#include "hex2_app.h"
#include "hex2_G.h"

IMPLEMENT_APP( HexApp );

bool HexApp::OnInit()
{
	G *g = new G( 0u );
	g->Show();
	return true;
}
