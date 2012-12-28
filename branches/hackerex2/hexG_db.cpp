#include "hexG_db.h"

xsDLL hexDB::hexDB()
{
	nowP.SetCount( HEX_LIST_COUNT );
	oldP.SetCount( HEX_LIST_COUNT );
	mode[ HEX_LIST_SESSION ]	= HEX_LIST_ORG;
	mode[ HEX_LIST_ORG ]		= HEX_LIST_ORG;
	mode[ HEX_LIST_PFM ]		= HEX_LIST_PFM;
	mode[ HEX_LIST_BIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_APP ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_WIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_RAM ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_PFL ]		= HEX_LIST_PFL;
	mode[ HEX_LIST_FORMAT ]		= HEX_LIST_FORMAT;
	mode[ HEX_LIST_HACK ]		= HEX_LIST_HACK;
	mode[ HEX_LIST_CODE ]		= HEX_LIST_HACK;
	mode[ HEX_LIST_FIND ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_OUT ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_EDIT ]		= HEX_LIST_BIN;
}
Text xsDLL hexDB::getNowN( int inMode )
{
	Text name = getGlobalName();
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
		name = state.nameNow;
		break;
	case HEX_LIST_ORG:
		name = org.nameNow;
		break;
	case HEX_LIST_PFM:
		name = pfm.nameNow;
		break;
	case HEX_LIST_BIN:
		name = bin.nameNow;
		break;
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
		name = bin.name;
		break;
	case HEX_LIST_RAM:
		name = bin[ ramNo ].name;
		break;
	case HEX_LIST_PFL:
		name = pfl.nameNow;
		break;
	case HEX_LIST_FORMAT:
		name = format.name;
		break;
	case HEX_LIST_HACK:
		name = hacks[ hacks.hackNow ].name;
	}
	return name;
}
