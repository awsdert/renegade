#ifndef HEXGUI_APP_H
#define HEXGUI_APP_H
#include "hex2_G.h"
class HexApp : public wxApp
{
public:
	virtual bool OnInit();
};

DECLARE_APP( HexApp );

#endif
