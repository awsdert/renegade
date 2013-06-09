#include "hexLib_app.h"

#ifndef hexLib_codeThread_h
#define hexLib_codeThread_h

class hexLibDLL codeThread : public wxThread
{
protected:
	hexGui*		m_gui;
	hexLib*		m_lib;
	int*		m_add;
public:
	codeThread( hexGui* gui, hexLib& lib, int& timeCTAdd );
	~codeThread();
protected:
	virtual ExitCode Entry( void );
private:
	Hacks*		hacks;
	Codes		codes;
	bool		m_hooked;
	ui64		m_ram[ 0x10 ];
	size_t		m_addrSize;
	void		m_useCodes( zxProc& proc, si32& h, si32& hEnd, ui16 c, ui16 cEnd, bool doHacks );
};

#endif