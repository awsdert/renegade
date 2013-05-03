#include "zxTypes.h"

#ifndef zxInt_h
#define zxInt_h

struct xsDLL zxInt
{
	bool	m_signed;
	bool	m_isSInt;
	bool	m_isUInt;
	bool	m_ignoreSign;
	ui08**	m_ptr; // If using external pointer and allowed to delete/free &/or grow
	ui08*	m_data;
	ui08	m_size; // No of bytes
	ui16	m_bits; // No of bits used
	ui08	m_free; // free, delete or delete []
	si16	m_lastByte;
	void	m_clear( void );
	zxInt( void );
	zxInt( zxInt &value );
	~zxInt( void );
	zxInt&	operator=	( zxInt &value );
	ui08&	operator[]	( ui08	index );
	// Bitwise
	zxInt	operator>>	( ui16	bits );
	zxInt&	operator>>=	( ui16	bits );
	zxInt	operator<<	( ui16	bits );
	zxInt&	operator<<=	( ui16	bits );
	zxInt	operator|	( zxInt value );
	zxInt&	operator|=	( zxInt value );
	zxInt	operator&	( zxInt value );
	zxInt&	operator&=	( zxInt value );
	zxInt	operator^	( zxInt value );
	zxInt&	operator^=	( zxInt value );
	zxInt	operator~	( void );
	// Mathematic
	zxInt	operator+	( zxInt value );
	zxInt&	operator+=	( zxInt value );
	zxInt&	operator++	( void );
	zxInt	operator-	( zxInt value );
	zxInt&	operator-=	( zxInt value );
	zxInt&	operator--	( void );
	zxInt	operator%	( ui08	value );
	zxInt	operator/	( ui08	value );
	zxInt&	operator/=	( ui08	value );
	zxInt	operator*	( zxInt	value );
	zxInt&	operator*=	( zxInt	value );
	// Comparison
	bool	operator==	( zxInt	&value );
	bool	operator!=	( zxInt	&value );
	bool	operator>	( zxInt	&value );
	bool	operator<	( zxInt	&value );
	bool	operator>=	( zxInt	&value );
	bool	operator<=	( zxInt	&value );
	// Needed by all operators
	void	clear( void );
	si08	m_cmp( zxInt& value, bool *isSameType = NULL );
	void	m_and( zxInt& source, zxInt& value );
	void	m__or( zxInt& source, zxInt& value );
	void	m_xor( zxInt& source, zxInt& value );
	void	m_not( zxInt& source );
	void	m_add( zxInt& source, zxInt& value );
	void	m_rem( zxInt& source, zxInt& value );
	zxInt	m_div( zxInt& source, ui08  value );
	void	m_mul( zxInt& source, zxInt& value );
	void	m_shiftL( zxInt& source, ui16 bits );
	void	m_shiftR( zxInt& source, ui16 bits );
	// Other
	Text	toString( ui08 base = 10u );
	bool	isSigned( void );
	ui08	getSize( void );
	void	setSize( ui08 size );
	ui16	getBits( void );
	void	setBits( ui16 bits );
	// Handling pointers
	bool	grow( ui08 addBytes = 1u );
	void	copy( void *source, ui08 size = 0u );
	si08	give( void *source, ui08 size = 0u, bool isSigned = false, ui08 treatAs = zxVar_t_auto );
	void*	take( ui08& freeAs );
	void*	borrow( void );
	bool	setPtr(	void  *source, ui08 size = 0u, bool isSigned = false, ui08 treatAs = zxVar_t_auto );
};
struct xsDLL zxUInt : zxInt
{
	zxUInt( void );
	zxUInt( uill value );
	zxUInt( zxInt& value );
	~zxUInt( void );
	zxUInt& operator=	( zxUInt value );
	// Mathematic
	zxUInt	operator+	( zxUInt value );
	zxUInt&	operator+=	( zxUInt value );
	zxUInt	operator-	( zxUInt value );
	zxUInt&	operator-=	( zxUInt value );
	zxUInt	operator*	( zxUInt value );
	zxUInt&	operator*=	( zxUInt value );
	/* *
	zxUInt	operator%	( zxUInt value );
	zxUInt	operator/	( zxUInt value );
	zxUInt& operator/=	( zxUInt value );
	/* */
	// Bitwise
	zxUInt	operator|	( zxUInt value );
	zxUInt& operator|=	( zxUInt value );
	zxUInt	operator&	( zxUInt value );
	zxUInt& operator&=	( zxUInt value );
	zxUInt	operator^	( zxUInt value );
	zxUInt&	operator^=	( zxUInt value );
	// Comparison
	bool	operator==	( zxUInt value );
	bool	operator!=	( zxUInt value );
	bool	operator>	( zxUInt value );
	bool	operator<	( zxUInt value );
	bool	operator>=	( zxUInt value );
	bool	operator<=	( zxUInt value );
};
struct xsDLL zxSInt : zxInt
{
	zxSInt( void );
	zxSInt( sill value );
	zxSInt( zxInt& value );
	~zxSInt( void );
	zxSInt& operator=	( zxSInt value );
	// Mathematic
	zxSInt	operator+	( zxSInt value );
	zxSInt&	operator+=	( zxSInt value );
	zxSInt	operator-	( zxSInt value );
	zxSInt&	operator-=	( zxSInt value );
	zxSInt	operator*	( zxSInt value );
	zxSInt&	operator*=	( zxSInt value );
	/* *
	zxSInt	operator%	( zxSInt value );
	zxSInt	operator/	( zxSInt value );
	zxSInt& operator/=	( zxSInt value );
	/* */
	// Bitwise
	zxSInt	operator|	( zxSInt value );
	zxSInt& operator|=	( zxSInt value );
	zxSInt	operator&	( zxSInt value );
	zxSInt& operator&=	( zxSInt value );
	zxSInt	operator^	( zxSInt value );
	zxSInt&	operator^=	( zxSInt value );
	// Comparison
	bool	operator==	( zxSInt value );
	bool	operator!=	( zxSInt value );
	bool	operator>	( zxSInt value );
	bool	operator<	( zxSInt value );
	bool	operator>=	( zxSInt value );
	bool	operator<=	( zxSInt value );
};

void  showHex( void* value, ui08 size );
zxInt parseInt( Text source, ui08 base = 10u );

#endif