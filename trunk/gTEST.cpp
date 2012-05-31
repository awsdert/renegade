#include "cleanType.h"
u8 gTEST[ QV_COUNT ];
u8*  gGetQTests( void ) { return gTEST; }
u8   gGetQTest( s32 index ) { return gTEST[ index ]; }
void gSetQTests( void )
{
	// DO NOT MODIFY
	gTEST[ QV_EQUAL         ] = gTEqual;
	gTEST[ QV_NOT_EQUAL     ] = gTNotE;
	gTEST[ QV_MORE_THAN     ] = gTMoreT;
	gTEST[ QV_MORE_OR_EQUAL ] = gTMoreE;
	gTEST[ QV_LESS_THAN     ] = gTLessT;
	gTEST[ QV_LESS_OR_EQUAL ] = gTLessE;
}
