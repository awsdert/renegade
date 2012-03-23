#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
bool ME::Test( u32 mode, u64 value, u64 against )
{
	u32 m = mode;
	u64 v = value, a = against;
	bool r = false, rf = false, rt = true;
	bool used = false; bool check;
	if ( (m & TM_EQUAL) != 0 )
	{
		r = (v == a) ? rt : rf;
		used = true;
	}
	if ( (m & TM_GT) != 0 )
	{
		check = (v > a) ? rt : rf;
		if ( used )
		{
			r = ( r ) ? check : rf;
		}
		else
		{
			r = check;
		}
		used = true;
	}
	if ( (m & TM_GTE) != 0 )
	{
		check = (v >= a) ? rt : rf;
		if ( used )
		{
			r = ( r ) ? check : rf;
		}
		else
		{
			r = check;
		}
		used = true;
	}
	if ( (m & TM_NOTE) != 0 )
	{
		check = (v != a) ? rt : rf;
		if ( used )
		{
			r = ( r ) ? check : rf;
		}
		else
		{
			r = check;
		}
		used = true;
	}
	if ((m & TM_LT) != 0)
	{
		check = (v < a) ? rt : rf;
		if ( used )
		{
			r = ( r ) ? check : rf;
		}
		else
		{
			r = check;
		}
		used = true;
	}
	if ((m & TM_LTE) != 0)
	{
		check = (v <= a) ? rt : rf;
		if ( used )
		{
			r = ( r ) ? check : rf;
		}
		else
		{
			r = check;
		}
		used = true;
	}
	return r;
}
