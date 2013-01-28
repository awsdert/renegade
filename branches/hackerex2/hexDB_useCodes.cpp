#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
codeThread::codeThread( hexGui* gui, hexDB& db, int& timedCTAdd ) : wxThread( wxTHREAD_DETACHED )
{
	gui->m_hackOn = true;
	m_addrSize = sizeof( size_t );
	m_gui = gui;
	m_db = &db;
	m_add = &timedCTAdd;
}
codeThread::~codeThread()
{
	wxCriticalSectionLocker enter( m_gui->m_cThreadCS );
	m_gui->m_cThread = NULL;
	m_gui->m_hackOn = false;
}
wxThread::ExitCode codeThread::Entry( void )
{
	ui64 addr = 0u, temp = 0;
	ui08 i, p, iEnd = m_db->bin.size(), pEnd;
	ui32 h, hEnd = m_db->hacks.size();
	clock_t now, next = ( clock() + *m_add );
	bool doHook = true;
	Text name = (m_db->bin.name) + osDotExe;
	do
	{
		osHdl hApp = NewAppHandle( name );
		if ( hApp == NULL )
		{
			wxMessageBox( wxT("Failed to hook binary, could not hack it") );
			DelAppHandle( hApp );
			return (ExitCode)-1;
		}
		for ( i = 0u; i < 0x10; ++i )
		{
			if ( i >= iEnd )
			{
				m_ram[ i ] = 0u;
				continue;
			}
			addr = m_db->bin[ i ].addr;
			pEnd = m_db->bin[ i ].depth;
			for ( p = 0u; p < pEnd; ++p )
			{
				if ( GetAppRam( hApp, addr, &temp, m_addrSize ) != m_addrSize )
				{
					i = 0xFF;
					break;
				}
				addr = temp;
				temp = 0;
			}
			m_ram[ i ] = addr;
		}
		if ( i == 0xFF )
		{
			wxMessageBox( wxT("Failed to aquire memory addresses of binary, could not hack it") );
			DelAppHandle( hApp );
			return (ExitCode)-2;
		}
		if ( doHook )
		{
			h = 0xFFFFF;
			m_db->m_getCodes( codes, h, true );
			m_useCodes( hApp, h, hEnd, 0u, codes.size(), true );
		}
		now = clock();
		doHook = ( now >= next );
		if ( doHook )
			next = ( now + *m_add );
		DelAppHandle( hApp );
	}
	while ( *m_add > 0 && !TestDestroy() );
	return (ExitCode)0;
}
void codeThread::m_useCodes( osHdl hApp, ui32& h, ui32& hEnd, ui16 c, ui16 cEnd, bool doHacks )
{
	Code obj;
	bool test = false, endTest, isCopy, isNW, isNA;
	ui08 p, pEnd, mbits, nibble, act;
	ui16 l, lEnd, v, vAdd, i, t;
	size_t rbytes, wbytes;
	ui64 vUse, vInc, rVal;
	ui64 addr, tAddr, vAddr, inca;
	Text txt, htxt;
	for ( ; (c < cEnd); ++c )
	{
		obj = codes[ c ];
		l = 0u;
		lEnd = obj.loop;
		addr = ( m_ram[ obj.ram ] + obj.addr[ 0 ] );
		//addr = (( m_ram[ obj.ram ] + obj.addr[ 0 ] ) << m_moveAddr );
		pEnd = obj.depth;
		inca = ( obj.addr[ 1 ] * obj.bytes );
		//inca = (( obj.addr[ 1 ] * obj.bytes ) << m_moveAddr );
		isCopy = ( obj.type == HEX_CT_COPY );
		for ( p = 0u; (p < pEnd && c < cEnd); ++p )
		{
			rbytes = 0u;
			tAddr = 0;
			if ( GetAppRam( hApp, addr, &tAddr, m_addrSize ) != m_addrSize )
				c = cEnd;
			addr = tAddr;
		}
		if ( c == cEnd )
			break;
		/*
		htxt.Printf( wxT("hack: %X\ncode: %X\naddr"), h, c );
		txt.Printf( xsPRINTF_XSIZE_T, addr );
		wxMessageBox( htxt + txt );
		//*/
		if ( obj.type < HEX_CT_LIST )
		{
			vUse = obj[0];
			switch ( obj.bytes )
			{
			case 8u: mbits = 0u;	break;
			case 4u: mbits = 32u;	break;
			case 2u: mbits = 48u;	break;
			default: mbits = 56u;
			}
			if ( lEnd > 0u && obj.type < HEX_CT_TEST )
				vInc = obj[1];
			else
				vInc = 0u;
			//vUse <<= mbits;
			//vInc <<= mbits;
		}
		rVal = 0u;
		rbytes = obj.bytes;
		act = ( obj.info & 0xF );
		nibble = (( obj.info & 0xF0 ) >> 0);
		switch ( obj.type )
		{
			case HEX_CT_WRITE:
			{
				do
				{
					if ( SetAppRam( hApp, addr, &vUse, rbytes ) != rbytes )
						c = cEnd;
					switch ( nibble )
					{
					case HEX_CT_DEC: addr -= inca; break;
					default: addr += inca;
					}
					switch ( act )
					{
					case HEX_CT_DEC: vUse -= vInc; break;
					default: vUse += vInc;
					}
					++l;
				}
				while ( l < lEnd && c < cEnd );
				if ( c >= cEnd )
					doHacks = false;
				break;
			}
			case HEX_CT_COPY:
			{
				vAddr = ( m_ram[ obj.ram ] + obj[0] );
				//vAddr = ( obj[0] << m_moveAddr );
				switch ( nibble )
				{
				case HEX_CT_INC: isNA = false; break;
				default: isNA = true; isNW = ( nibble == HEX_CT_WRITE );
					for ( p = 0, pEnd = isNW ? act : obj.depth; p < pEnd; ++p )
					{
						tAddr = 0;
						if ( GetAppRam( hApp, addr, &tAddr, m_addrSize ) != m_addrSize )
							c = cEnd;
						vAddr = tAddr;
					}
				}
				do
				{
					if ( GetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					tAddr = 0;
					if ( !isNW )
					{
						switch ( act )
						{
						case HEX_CT_INC: tAddr = (addr + vAddr); break;
						default: tAddr = vAddr;
						}
					}
					else
						tAddr = vAddr;
					if ( SetAppRam( hApp, tAddr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					switch ( nibble )
					{
					case HEX_CT_DEC: addr -= inca; break;
					default: addr += inca;
					}
					if ( !isNW )
					{
						switch ( act )
						{
						case HEX_CT_DEC: vAddr -= inca; break;
						default: vAddr += inca;
						}
					}
					else
						vAddr += inca;
					++l;
				}
				while ( l < lEnd && c < cEnd );
				if ( c >= cEnd )
					doHacks = false;
				break;
			}
			case HEX_CT_INC:
			{
				do
				{
					if ( GetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					rVal += vUse;
					if ( SetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					rVal = 0u;
					switch ( nibble )
					{
					case HEX_CT_DEC: addr -= inca; break;
					default: addr += inca;
					}
					++l;
				}
				while ( l < lEnd && c < cEnd );
				if ( c >= cEnd )
					doHacks = false;
				break;
			}
			case HEX_CT_DEC:
			{
				do
				{
					if ( GetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					rVal -= vUse;
					if ( SetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
						c = cEnd;
					rVal = 0u;
					switch ( nibble )
					{
					case HEX_CT_DEC: addr -= inca;
					default: addr += inca;
					}
					++l;
				}
				while ( l < lEnd && c < cEnd );
				if ( c >= cEnd )
					doHacks = false;
				break;
			}
			case HEX_CT_TEST:
			{
				endTest = false;
				if ( GetAppRam( hApp, addr, &rVal, rbytes ) != rbytes )
					endTest = true;
				test = false;
				switch ( obj.info & 0xFF )
				{
				case HEX_IS_DC: test = ( ( rVal & vUse ) == vUse ); break;
				case HEX_IS_NC: test = ( ( rVal & vUse ) != vUse ); break;
				case HEX_IS_EQ: test = ( rVal == vUse ); break;
				case HEX_IS_NE: test = ( rVal != vUse ); break;
				case HEX_IS_GT: test = ( rVal >  vUse ); break;
				case HEX_IS_GE: test = ( rVal >= vUse ); break;
				case HEX_IS_LT: test = ( rVal <  vUse ); break;
				case HEX_IS_LE: test = ( rVal <= vUse ); break;
				case HEX_IS_RT: test = ( rVal >  vUse && rVal <  vInc ); break;
				case HEX_IS_RE: test = ( rVal >= vUse && rVal <= vInc ); break;
				default: endTest = true; doHacks = false; c = cEnd;
				}
				if ( obj.loop > 0u )
				{
					if ( !endTest && test )
						m_useCodes( hApp, h, hEnd, c + 1, (( c + obj.loop ) > cEnd ) ? cEnd : (c + obj.loop), false );
					c += obj.loop;
				}
				else if ( endTest || !test )
				{
					doHacks = false;
					c = cEnd;
				}
				break;
			}
			case HEX_CT_LIST:
			{
				vAdd = ( 8u / obj.bytes );
				do
				{
					tAddr = addr;
					for ( v = 0u, i = 0u; v < obj.info; v += vAdd, ++i )
					{
						t = (obj.info - v);
						wbytes = ( t < vAdd ) ? ( obj.bytes * t ) : 8;
						// NOTE: List code may be incorrectly handled
						mbits = ( t < vAdd ) ? ( 64u - ( ( 8 - wbytes ) * 8u ) ) : 0u;
						vUse = ( obj[i] >> mbits );
						if ( SetAppRam( hApp, tAddr, &vUse, wbytes ) != wbytes )
							c = cEnd;
						tAddr += wbytes;
					}
					switch ( nibble )
					{
					case HEX_CT_DEC: addr -= inca; break;
					default: addr += inca;
					}
					++l;
				}
				while ( l < lEnd && c < cEnd );
				if ( c >= cEnd )
					doHacks = false;
				break;
			}
			default: c = cEnd;
		}
	}
	obj.clearCode();
	if ( !doHacks || TestDestroy() )
		return;
	if ( h <= 0xFFFFF )
	{
		for ( ui32 ht = ( h == 0xFFFFF ) ? 0u : m_db->hacks[ h ].first; ht < hEnd; ht = m_db->hacks[ ht ].next )
		{
			if ( ( m_db->hacks[ ht ].info & HACK_USE ) == 0u )
				continue;
			m_db->m_getCodes( codes, ht, true );
			m_useCodes( hApp, ht, hEnd, 0u, codes.size(), true );
		}
	}
}