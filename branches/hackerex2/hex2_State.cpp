#include "wx_pch.h"
#ifdef HACKEREX2
	#include "hex2_G.h"
#else
	#include "hex1_G.h"
#endif
void G::LoadStateD( State& obj )
{
	Text oldP, nowP;
	TxtA name;
	const int iEnd = 5;
	int i, j, mode[ iEnd ];
	name.SetCount( iEnd );
	mode[0] = HEX_LIST_ORG;		name[0] = obj.orgName;
	mode[1] = HEX_LIST_PFM;		name[1] = obj.pfmName;
	mode[2] = HEX_LIST_BIN;		name[2] = obj.binName;
	mode[3] = HEX_LIST_PFL;		name[3] = obj.pflName;
	mode[4] = HEX_LIST_FORMAT;	name[4] = obj.hckFormat;
	hexDB& db = m_gui.m_db;
	db.tmpCfg = false;
	for ( i = 0; i < iEnd; ++i )
	{
		j = mode[ i ];
		db.tmpMode = j;
		db.tmpLB	 = HexList_LB;
		db.loadData( HEX_LOAD_SAVE2TEMP, name[ i ] );
		oldP = db.oldP[ j ] + cTild;
		nowP = db.nowP[ j ] + cTild;
		if ( oldP != nowP )
		{
			if ( wxFileExists( oldP ) )
				wxRemoveFile( oldP );
			db.oldP[ j ] = db.nowP[ j ];
		}
	}
}