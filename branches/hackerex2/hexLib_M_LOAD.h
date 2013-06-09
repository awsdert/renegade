#include "hexLib_base.h"

#ifndef hexLib_M_LOAD_h
#define hexLib_M_LOAD_h

struct hexLibDLL M_LOAD
{
	Text name;
	hexLang *m_lang;
	TxtF *des, *src;
	bool loadNow, loadDef;
	M_LOAD( void );
	bool check( void );
};

#endif