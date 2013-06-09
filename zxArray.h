#include "zxTypes.h"

#ifndef zxArray_h
#define zxArray_h
template< typename T, const sint TC >
struct zxArray
{
	size_t	m_Tsize;
	T		m_obj;
	T		m_data[ TC ];
	sint	m_count;
	size_t	m_size;
	void	m_clear( void ) { m_size = 0; m_count = 0; m_Tsize = sizeof( T ); }
	sint	begin(	void ) { return 0u; }
	sint	end(	void ) { return ( ( m_count > 0 ) ? m_count - 1 : 0 ); }
	sint	rbegin(	void ) { return end(); }
	sint	rend(	void ) { return begin(); }
	const ui32 cbegin(	void ) { return begin(); }
	const ui32 cend(	void ) { return end(); }
	const ui32 crbegin(	void ) { return end(); }
	const ui32 crend(	void ) { return begin(); }
	bool	empty(	void ) { return ( m_count == 0 ); }
	sint	size(	void ) { return m_count; }
	size_t	capacity( void ) { return (m_Tsize * TC); }
	sint	max_size( void ) { return TC; }
	void	resize( sint set_count )
	{
		if ( set_count > TC )
			set_count = TC;
		for ( sint i = set_count; i < TC; ++i )
			m_data[ i ] = m_obj;
		m_count = set_count;
		m_size  = m_Tsize * m_count;
	}
	void	resize( sint set_count, const T& default_value )
	{
		sint i = m_count;
		m_obj = default_value;
		resize( set_count );
	}
	void	insert( sint b4i, T& value )
	{
		sint i = m_count;
		if ( i == TC )
			--i;
		m_count = i + 1;
		for ( ; i > b4i; --i )
			m_data[ i ] = m_data[ i - 1 ];
		m_data[ i ] = value;
	}
	void swap( zxArray& obj )
	{
		ui32 c		= obj.m_count;
		T d[TC];
		memcpy( d, obj.m_data, m_size );
		obj.m_count	= m_count;
		memcpy( obj.m_data, m_data, m_size );
		m_count	= c;
		memcpy( m_data, d, m_size );
	}
	void assign( sint set_count, const T& default_value ) { resize( set_count, default_value ); }
	void reserve( size_t min_size )
	{
		if ( min_size > m_size )
		{
			sint i = m_count + 1;
			size_t new_size = m_Tsize * i;
			for ( ++i; min_size > new_size; ++i )
				new_size = m_Tsize * i;
			if ( i > TC )
				return;
			resize( i );
		}
	}
	void pop_back( void ) { resize( m_count - 1 ); }
	void push_back( T set_value ) { resize( m_count + 1, set_value ); }
	void clear( void )
	{
		resize( 0u );
		m_clear();
	}
	T* data( void )
	{
		T* ptr = (T*)malloc( m_size );
		memcpy( ptr, m_data, m_size );
		return ptr;
	}
	zxArray( void )
	{
		m_clear();
		resize( TC );
	}
	zxArray( zxArray& obj )
	{
		m_clear();
		if ( m_size > obj.m_size )
			m_size	= obj.m_size;
		m_count	= obj.m_count;
		memcpy( m_data, obj.m_data, m_size );
	}
	zxArray( T& set_values )
	{
		m_clear();
		resize( TC, set_values );
	}
	~zxArray( void ) { clear(); }
	T& at( sint i ) { return ( i < TC ) ? m_data[ i ] : m_obj; }
	T& front( void ) { return ( m_count > 0 ) ? m_data[ 0 ] : m_obj; }
	T& back( void ) { return ( m_count > 0 ) ? m_data[ m_count - 1 ] : m_obj; }
	T& operator[] ( ui32 index ) { return ( index < TC ) ? m_data[ index ] : m_obj; }
};

#endif