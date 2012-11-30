#include "hexGUI_app.hpp"
#include "hexGUI_G.hpp"

IMPLEMENT_APP( HexApp );

bool HexApp::OnInit()
{
	G *g = new G( 0u );
	g->Show();
	return true;
}
