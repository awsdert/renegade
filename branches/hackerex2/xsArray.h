#include "hexDLL_types.h"
#include "hexDLL_zxStuff.h"

#ifndef xsArray_H
#define xsArray_H
template< typename T, const ui32 TC = 0 >
class xsDLL xsArray
{
protected:
	size_t	m_Tsize;
	T		m_obj;
	T		m_data[ TC ];
	ui32	m_count;
	size_t	m_size;
	void	m_clear( void ) { m_size = 0; m_count = 0; m_Tsize = sizeof( T ); }
public:
	ui32	begin(	void ) { return 0u; }
	ui32	end(	void ) { return ( ( m_count > 0u ) ? m_count - 1 : 0u ); }
	ui32	rbegin(	void ) { return end(); }
	ui32	rend(	void ) { return begin(); }
	const int cbegin(	void ) { return begin(); }
	const int cend(		void ) { return end(); }
	const int crbegin(	void ) { return end(); }
	const int crend(	void ) { return begin(); }
	bool	empty(	void ) { return ( m_count == 0u ); }
	int		size(	void ) { return m_count; }
	size_t	capacity( void ) { return (m_Tsize * TC); }
	ui32	max_size( void ) { return TC; }
	void	resize( ui32 set_count )
	{
		if ( set_count > TC )
			set_count = TC;
		for ( ui32 i = set_count; i < TC; ++i )
			m_data[ i ] = m_obj;
		m_count = set_count;
		m_size  = m_Tsize * m_count;
	}
	void	resize( int set_count, const T& default_value )
	{
		ui32 i = m_count;
		resize( set_count );
		for ( ; i < m_count; ++i )
			m_data[ i ] = default_value;
		m_obj = default_value;
	}
	void	insert( ui32 b4i, T& value )
	{
		ui32 i = m_count;
		if ( i == TC )
			--i;
		m_count = i + 1u;
		for ( ; i > b4i; --i )
			m_data[ i ] = m_data[ i - 1u ];
		m_data[ i ] = value;
	}
	void swap( xsArray* obj )
	{
		int c	 = obj->m_count;
		size_t s = obj->m_size;
		T* d	 = obj->m_data;
		obj->m_count	= m_count;
		obj->m_size		= m_size;
		obj->m_data		= m_data;
		m_count	= c;
		m_size	= s;
		m_data	= d;
	}
	void swap( xsArray& obj ) { swap( &obj ); }
	void assign( int set_count, const T& default_value ) { resize( set_count, default_value ); }
	void reserve( size_t min_size )
	{
		if ( min_size > m_size )
		{
			ui32 i = m_count + 1;
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
		T* ptr = new T[ TC ];
		memcpy( ptr, m_data, m_Tsize * TC );
		return ptr;
	}
	xsArray( void )
	{
		m_clear();
		resize( TC );
	}
	xsArray( xsArray& obj )
	{
		m_clear();
		m_size	= obj.m_size;
		m_count	= obj.m_count;
		memcpy( m_data, obj.m_data, m_size );
	}
	xsArray( xsArray* obj )
	{
		m_clear();
		m_size	= obj->m_size;
		m_count	= obj->m_count;
		memcpy( m_data, obj->m_data, m_size );
	}
	xsArray( T& set_values )
	{
		m_clear();
		resize( TC, set_values );
	}
	~xsArray( void ) { clear(); }
	T& at( ui32 index ) { return ( index < m_count ) ? m_data[ index ] : m_obj; }
	T& front( void ) { return ( m_count > 0u ) ? m_data[ 0u ] : m_obj; }
	T& back( void ) { return ( m_count > 0u ) ? m_data[ m_count - 1u ] : m_obj; }
	T& operator[] ( ui32 index ) { return ( index < m_count ) ? m_data[ index ] : m_obj; }
};
#endif