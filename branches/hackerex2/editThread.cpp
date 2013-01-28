#include "wx_pch.h"
#include "hexG_db.h"
editThread::editThread( hexGui* gui, hexDB& db, int& timedCTAdd ) : wxThread( wxTHREAD_DETACHED )
{
	gui->m_editOn = true;
	m_gui = gui;
	m_db = &db;
	m_add = &timedCTAdd;
}
editThread::~editThread()
{
	wxCriticalSectionLocker enter( m_gui->m_eThreadCS );
	m_gui->m_eThread = NULL;
	m_gui->m_editOn = false;
}
wxThread::ExitCode editThread::Entry( void )
{
	clock_t now, next = ( clock() + *m_add );
	do
	{
		if ( m_db->nowL != HEX_LIST_EDIT && m_db->eGridActive )
			continue;
		now = clock();
		if ( now >= next )
		{
			wxMutexGuiEnter();
			m_db->m_eGridJump( true );
			wxMutexGuiLeave();
			next = (now + *m_add);
		}
	}
	while ( *m_add > 0 && !TestDestroy() );
	return (ExitCode)( (*m_add > 0) ? 0 : 1);
}
hexGui::hexGui()
{
	m_cThread = NULL;
	m_eThread = NULL;
	m_hackOn = false;
	m_editOn = false;
	m_hackAdd = 0;
	m_editAdd = 0;
}
void hexGui::NewCodeThread( void )
{
	if ( m_hackOn )
		m_cThread->Delete();
	int wait = 0;
	while ( wait < 10000 && m_hackOn );
	if ( !m_hackOn )
	{
		m_cThread = new codeThread( this, m_db, m_hackAdd );
		if ( m_cThread->Create( sizeof( codeThread ) ) != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( _("Failed to create thread!") );
			delete m_cThread;
			m_cThread = NULL;
		}
		else if ( m_cThread->Run() != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( _("Failed to run thread!") );
			delete m_cThread;
			m_cThread = NULL;
		}
	}
	else
		wxMessageBox( _("Failed to create thread pointer!") );
}
void hexGui::NewEditThread( void )
{
	if ( m_editOn )
		m_eThread->Delete();
	int wait = 0;
	while ( wait < 10000 && m_editOn );
	if ( !m_editOn )
	{
		m_db.m_binNameE = (m_db.bin.name + osDotExe);
		m_eThread = new editThread( this, m_db, m_editAdd );
		if ( m_eThread->Create( sizeof( editThread ) ) != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( _("Failed to create thread!") );
			delete m_eThread;
			m_eThread = NULL;
		}
		else if ( m_eThread->Run() != wxTHREAD_NO_ERROR )
		{
			wxMessageBox( _("Failed to run thread!") );
			delete m_eThread;
			m_eThread = NULL;
		}
	}
	else
		wxMessageBox( _("Failed to create thread pointer!") );
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