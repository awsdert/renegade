#ifndef HEXGUI_APP_H
#define HEXGUI_APP_H
#include "hexGUI_global.hpp"
class HexApp : public wxApp
{
public:
	virtual bool OnInit();
};

DECLARE_APP( HexApp );

#endif
