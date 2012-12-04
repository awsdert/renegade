#include "hexGUI_G.hpp"
int  G::FindOrgI( OrgV& dat, Text& name )
{
	Org obj;
	int i, iEnd = dat.size();
	for ( i = 0; i < iEnd; ++i )
	{
		obj = dat[ i ];
		if ( obj.nameNow == name )
			return i;
	}
	return 0;
}
int  G::FindPfmI( PfmV& dat, Text& name )
{
	Pfm obj;
	int i, iEnd = dat.size();
	for ( i = 0; i < iEnd; ++i )
	{
		obj = dat[ i ];
		if ( obj.nameNow == name )
			return i;
	}
	return 0;
}
