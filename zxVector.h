#include "zxTypes.h"

#ifndef zxVector_h
#define zxVector_h
template< typename T, int TC = 0 >
struct zxVector
{
	size_t	m_Tsize;
	sint	m_MaxCount;
	T		m_obj;
	T*		m_data;
	sint	m_count;
	size_t	m_size;
	void	m_clear( void ) { m_size = 0; m_count = 0; m_data = NULL; m_MaxCount = 0; m_Tsize = sizeof( T ); }
	sint	begin(	void ) { return ( ( m_count > 0 ) ? 0 : -1 ); }
	sint	end(	void ) { return ( m_count - 1 ); }
	sint	rbegin(	void ) { return end(); }
	sint	rend(	void ) { return begin(); }
	const sint cbegin(	void ) { return begin(); }
	const sint cend(	void ) { return end(); }
	const sint crbegin(	void ) { return end(); }
	const sint crend(	void ) { return begin(); }
	bool	empty(	void ) { return ( m_data == NULL ); }
	sint	size(	void ) { return m_count; }
	size_t	capacity( void ) { return m_size; }
	sint	max_size( void ) { return m_MaxCount; }
	void	resize( int set_count )
	{
		if ( set_count > m_MaxCount )
			set_count = m_MaxCount;
		if ( set_count > 0 )
		{
			T* ndata = new T[ set_count ];
			if ( m_data != NULL )
			{
				for ( int i = 0u; i < set_count; ++i )
				{
					if ( i < m_count )
						ndata[ i ] = m_data[ i ];
				}
				delete [] m_data;
			}
			m_data = ndata;
			m_count = set_count;
			m_size  = m_Tsize * m_count;
		}
		else
			clear();
	}
	void	resize( sint set_count, const T& default_value )
	{
		sint i = m_count;
		resize( set_count );
		for ( ; i < m_count; ++i )
			m_data[ i ] = default_value;
		m_obj = default_value;
	}
	void	insert( sint b4i, T value )
	{
		if ( m_count < 0 )
			m_count = 0;
		sint ncount = m_count + 1, i = 0;
		T*  ndata = new T[ ncount ];
		if ( m_count > 0 && m_data != NULL )
		{
			i = ( m_count >= b4i ) ? b4i : m_count;
			memcpy( ndata, m_data, ( i * m_Tsize ) );
			if ( i == b4i )
			{
				ndata[ i ] = value;
				memcpy( &( ndata[ i + 1 ] ), &( m_data[ i ] ), ( ( m_count - i ) * m_Tsize ) );
				i = m_count;
			}
			delete [] m_data;
		}
		if ( i < b4i )
			ndata[ ncount - 1 ] = value;
		m_count	= ncount;
		m_data	= ndata;
		m_size	= (m_Tsize * ncount);
	}
	void swap( zxVector& obj )
	{
		sint c	 = obj.m_count;
		size_t s = obj.m_size;
		T* d	 = obj.m_data;
		obj.m_count	= m_count;
		obj.m_size	= m_size;
		obj.m_data	= m_data;
		m_count	= c;
		m_size	= s;
		m_data	= d;
	}
	void assign( sint set_count, const T& default_value ) { resize( set_count, default_value ); }
	void reserve( size_t min_size )
	{
		if ( min_size > m_size )
		{
			int i = m_count + 1;
			size_t new_size = m_Tsize * i;
			for ( ++i; min_size > new_size; ++i )
				new_size = m_Tsize * i;
			resize( i );
		}
	}
	void shrink_to_fit( void ) {}
	void pop_back( void ) { resize( m_count - 1 ); }
	void push_back( T set_value ) { resize( m_count + 1, set_value ); }
	void clear( void )
	{
		if ( m_count > 0 && m_data != NULL )
			delete [] m_data;
		m_clear();
	}
	const T* data( void ) { return m_data; }
	zxVector( void )
	{
		m_clear();
		resize( TC );
	}
	zxVector( const zxVector& obj )
	{
		m_clear();
		m_size	= obj.m_size;
		m_count	= obj.m_count;
		memcpy( m_data, obj.m_data, m_size );
	}
	zxVector( T set_values )
	{
		m_clear();
		m_obj = set_values;
		resize( TC, set_values );
	}
	~zxVector( void ) { clear(); }
	T& at( sint index )
	{
		if ( index < m_count && m_data != NULL )
			return m_data[ index ];
		else
			return m_obj;
	}
	T& front( void )
	{
		if ( m_count > 0 && m_data != NULL )
			return m_data[ 0 ];
		else
			return m_obj;
	}
	T& back( void )
	{ 
		if ( m_count > 0 && m_data != NULL )
			return m_data[ m_count - 1 ];
		else
			return m_obj;
	}
	T& operator[] ( sint i )
	{
		return m_data[ i ];
	}
};
#endif
