#include "cleanType.h"
u8 gQATest[ QA_COUNT ];
u8 gQVTest[ QV_COUNT ];
u8*  gGetQATest( void ) { return gQATest; }
u8*  gGetQVTest( void ) { return gQVTest; }
void gSetQTests( void )
{
	// DO NOT MODIFY
	// Address
	gQATest[ QA_MT  ] = gTMoreT;
	gQATest[ QA_MTE ] = gTMoreE;
	gQATest[ QA_LT  ] = gTLessT;
	gQATest[ QA_LTE ] = gTLessE;
	// Value
	gQVTest[ QV_EQUAL   ] = gTEqual;
	gQVTest[ QV_NOT     ] = gTNotE;
	gQVTest[ QV_MT      ] = gTMoreT;
	gQVTest[ QV_MTE     ] = gTMoreE;
	gQVTest[ QV_LT      ] = gTLessT;
	gQVTest[ QV_LTE     ] = gTLessE;
	gQVTest[ QV_GOT     ] = gTGot;
	gQVTest[ QV_NOT_GOT ] = gTNotG;
}
