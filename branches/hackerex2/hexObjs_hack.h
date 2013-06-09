#include "hexObjs_code.h"
#ifndef hexObjs_hack_h
#define hexObjs_hack_h

struct hexObjs Hack : dName
{
	Hack( void );
	void	clear( void );
	/** PPPPHHHH URTTOOOO
	Profile ID, Hack Index, is active, is radio list, Code Total ( Uncounted will be added still ), Parent(Owner) Id **/
	si32	id, parent, first, next;
	bool	isRadio;
	bool	isActive;
	bool	port;
	bool	operator== ( Hack& obj );
	bool	operator!= ( Hack& obj );
};

struct hexObjs Hacks : zxArray< Hack, 0x10000 >
{
	Hacks( void );
	si32	find( Text name, si32 parent = -1 );
	si32	hackOld;
	si32	hackNow;
	Text	path;
	Codes	getCodes( si32 i );
	void	setCodes( si32 i, Codes& codes );
	void	m_getCode( Code& obj, ui08* data );
	void	m_setCode( Code& obj, ui08* data );
};

#endif