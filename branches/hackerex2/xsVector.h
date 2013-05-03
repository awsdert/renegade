#include "hexDLL_types.h"
#include "hexDLL_zxStuff.h"

#ifndef xsVector_H
#define xsVector_H
template< typename T, int TC = 0 >
class xsDLL xsVector
{
protected:
	size_t	m_Tsize;
	int		m_MaxCount;
	T		m_obj;
	T*		m_data;
	int		m_count;
	size_t	m_size;
	void	m_clear( void ) { m_size = 0; m_count = 0; m_data = NULL; m_MaxCount = 268435455; m_Tsize = sizeof( T ); }
public:
	int		begin(	void ) { return ( ( m_count > 0 ) ? 0 : -1 ); }
	int		end(	void ) { return ( m_count - 1 ); }
	int		rbegin(	void ) { return end(); }
	int		rend(	void ) { return begin(); }
	const int cbegin(	void ) { return begin(); }
	const int cend(		void ) { return end(); }
	const int crbegin(	void ) { return end(); }
	const int crend(	void ) { return begin(); }
	bool	empty(	void ) { return ( m_data == NULL ); }
	int		size(	void ) { return m_count; }
	size_t	capacity( void ) { return m_size; }
	int		max_size( void ) { return m_count; }
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
	void	resize( int set_count, const T& default_value )
	{
		int i = m_count;
		resize( set_count );
		for ( ; i < m_count; ++i )
			m_data[ i ] = default_value;
		m_obj = default_value;
	}
	void	insert( int b4i, T& value )
	{
		if ( m_count < 0 )
			m_count = 0;
		int ncount = m_count + 1, i = 0;
		T*  ndata = new T[ ncount ];
		if ( m_count > 0 && m_data != NULL )
		{
			i = ( m_count >= b4i ) ? b4i : m_count;
			memcpy( ndata, m_data, ( i * m_Tsize ) );
			if ( i == b4i )
			{
				ndata[ i ] = value;
				memcpy( &( ndata[ i + 1 ] ), &( m_data[ i ] ), ( ( m_count - i ) * m_Tsize ) );
				ni = m_count;
			}
			delete [] m_data;
		}
		if ( i < b4i )
			ndata[ ncount - 1 ] = value;
		m_count	= ncount;
		m_data	= ndata;
		m_size	= (m_Tsize * ncount);
	}
	void swap( xsVector* obj )
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
	void swap( xsVector& obj ) { swap( &obj ); }
	void assign( int set_count, const T& default_value ) { resize( set_count, default_value ); }
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
	xsVector( void )
	{
		m_clear();
		resize( TC );
	}
	xsVector( xsVector& obj )
	{
		m_clear();
		m_size	= obj.m_size;
		m_count	= obj.m_count;
		memcpy( m_data, obj.m_data, m_size );
	}
	xsVector( xsVector* obj )
	{
		m_clear();
		m_size	= obj->m_size;
		m_count	= obj->m_count;
		memcpy( m_data, obj->m_data, m_size );
	}
	xsVector( T& set_values )
	{
		m_clear();
		m_obj = set_values;
		resize( TC, set_values );
	}
	~xsVector( void ) { clear(); }
	T& at( int index )
	{
		if ( index < m_count && m_data != NULL )
			return m_data[ index ];
		else
			return m_obj;
	}
	T& front( void )
	{
		if ( m_count > 0 && m_data != NULL )
			return [ 0 ];
		else
			return m_obj;
	}
	T& back( void )
	{ 
		if ( m_count > 0 && m_data != NULL )
			return [ m_count - 1 ];
		else
			return m_obj;
	}
	T& operator[] ( int index )
	{
		if ( index < m_count && m_data != NULL )
			return m_data[ index ];
		else
			return m_obj;
	}
};
#endif
