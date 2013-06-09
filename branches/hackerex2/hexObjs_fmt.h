#include "hexObjs_base.h"
#ifndef hexObjs_fmt_h
#define hexObjs_fmt_h

hexObjs Text getFormatName( Text id );
hexObjs TxtA getFormats( void );

struct hexObjs Fmt : dFile
{
	Fmt( void );
	Text id;
};

#endif