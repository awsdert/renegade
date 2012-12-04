#include "hexGUI_db.hpp"
Org::Org( void )
{
	Text Tmp = wxT("Default"), tmp = wxT("default");
	fileNow = tmp;
	fileOld = tmp;
	nameNow = Tmp;
	nameOld = Tmp;
}
Pfm::Pfm( void ) : Org() {};
Bin::Bin( void ) : Org() {};
Bin::~Bin( void ) {};
