#include "hexObjs_main.h"

// Organisation

bool Org::operator!= ( Org& obj )
{
	return ( name != obj.name || file != obj.file );
}
bool Org::operator== ( Org& obj )
{
	return ( name == obj.name && file == obj.file );
}

// Platform

bool Pfm::operator!= ( Pfm& obj )
{
	return ( name != obj.name || file != obj.file || endian != obj.endian );
}
bool Pfm::operator== ( Pfm& obj )
{
	return ( name == obj.name && file == obj.file && endian == obj.endian );
}

// Memory

bool Ram::operator!= ( Ram &obj )
{
	return ( name != obj.name || addr != obj.addr || depth != obj.depth || bytes != obj.bytes );
}
bool Ram::operator== ( Ram &obj )
{
	return ( name == obj.name && addr == obj.addr && depth == obj.depth && bytes == obj.bytes );
}

// Binary

bool Bin::operator!= ( Bin& obj )
{
	if ( name != obj.name || file != obj.file || bind != obj.bind || path != obj.path || type != obj.type || m_count != obj.m_count )
		return true;
	else
	{
		for ( ui32 i = 0u; i < m_count; ++i )
		{
			if ( at( i ) != obj[ i ] )
				return true;
		}
		return false;
	}
};
bool Bin::operator== ( Bin& obj )
{
	if ( name != obj.name || file != obj.file || bind != obj.bind || path != obj.path || type != obj.type || m_count != obj.m_count )
		return false;
	else
	{
		for ( ui32 i = 0u; i < m_count; ++i )
		{
			if ( at( i ) != obj[ i ] )
				return false;
		}
		return true;
	}
};

// Hack

bool Hack::operator== ( Hack& obj )
{
	return ( parent == obj.parent && id == obj.id && first == obj.first && next == obj.next && name == obj.name && isActive == obj.isActive && isRadio == obj.isRadio );
}
bool Hack::operator!= ( Hack& obj )
{
	return ( parent != obj.parent || id != obj.id || first != obj.first || next != obj.next || name != obj.name || isActive != obj.isActive || isRadio != obj.isRadio );
}