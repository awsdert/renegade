#include "wx_pch.h"
#include "hexLib_gui.h"
editThread::editThread( hexGui* gui, hexLib& lib, int& timedCTAdd ) : wxThread( wxTHREAD_DETACHED )
{
	m_gui->m_find->isAuto = true;
	m_gui = gui;
	m_lib = &lib;
	m_add = &timedCTAdd;
}
editThread::~editThread()
{
	wxCriticalSectionLocker enter( m_gui->m_eThreadCS );
	m_gui->m_eThread = NULL;
	m_gui->m_find->isAuto = false;
}
wxThread::ExitCode editThread::Entry( void )
{
	clock_t now, next = ( clock() + *m_add );
	do
	{
		if ( m_gui->m_find->isActive )
			continue;
		now = clock();
		if ( now >= next )
		{
			wxMutexGuiEnter();
			m_gui->m_find->eJump();
			wxMutexGuiLeave();
			next = (now + *m_add);
		}
	}
	while ( !TestDestroy() &&
		m_gui->m_find->wait > 0 &&
		m_lib->getGuiMode() == HEX_LIST_EDIT );
	return (ExitCode)( (*m_add > 0) ? 0 : 1);
}
hexGui::hexGui()
{
	m_cThread = NULL;
	m_eThread = NULL;
	m_find = &m_lib.m_find;
	m_tree = &m_lib.m_tree;
	m_tree->isAuto = false;
	m_find->isAuto = false;
	m_tree->wait = 0;
	m_find->wait = 0;
}
void hexGui::NewCodeThread( void )
{
	if ( m_tree->isAuto )
		m_cThread->Delete();
	si16 wait = 0;
	while ( wait < 10000 && m_tree->isAuto );
	if ( !m_tree->isAuto )
	{
		m_cThread = new codeThread( this, m_lib, m_tree->wait );
		if ( m_cThread->Create( sizeof( codeThread ) ) != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( m_lang->text[ m_lang->txt_failedtocreatethread ] );
			delete m_cThread;
			m_cThread = NULL;
		}
		else if ( m_cThread->Run() != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( m_lang->text[ m_lang->txt_failedtorunthread ] );
			delete m_cThread;
			m_cThread = NULL;
		}
	}
	else
		wxMessageBox( m_lang->text[ m_lang->txt_failedtocreatethreadpointer ] );
}
void hexGui::NewEditThread( void )
{
	if ( m_find->isAuto )
		m_eThread->Delete();
	int wait = 0;
	while ( wait < 10000 && m_find->isAuto );
	if ( !m_find->isAuto )
	{
		m_eThread = new editThread( this, m_lib, m_find->wait );
		if ( m_eThread->Create( sizeof( editThread ) ) != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( m_lang->text[ m_lang->txt_failedtocreatethread ] );
			delete m_eThread;
			m_eThread = NULL;
		}
		else if ( m_eThread->Run() != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( m_lang->text[ m_lang->txt_failedtorunthread ] );
			delete m_eThread;
			m_eThread = NULL;
		}
	}
	else
		wxMessageBox( m_lang->text[ m_lang->txt_failedtocreatethreadpointer ] );
}
int hexGui::SetGTime( int i )
{
	int sec = 1000, min = sec * 60, v;
	switch ( i )
	{
	case 1: v = 500; break;
	case 2: v = sec; break;
	case 3: v = sec * 5; break;
	case 4: v = sec * 30; break;
	case 5: v = min; break;
	case 6: v = min * 5; break;
	case 7: v = min * 30; break;
	case 8: v = min * 60; break;
	default: v = 0;
	}
	return v;
}