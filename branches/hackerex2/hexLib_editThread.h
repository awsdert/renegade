#include "hexLib_app.h"

#ifndef hexLib_editThread_h
#define hexLib_editThread_h

class hexLibDLL editThread : public wxThread
{
private:
	hexGui*	m_gui;
	hexLib*	m_lib;
	int*	m_add;
public:
	editThread( hexGui* gui, hexLib& lib, int& timeETAdd );
	~editThread();
protected:
	virtual ExitCode Entry( void );
};

#endif