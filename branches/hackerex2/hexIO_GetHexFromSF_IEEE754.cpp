#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize )
{
	from.UpperCase();
	int db = 0, dB = 0, dBEnd = tSize, dBLast = ( tSize - 1u ), dbEnd = dBEnd * 8;
	ui08 *data = reinterpret_cast< ui08* >( to );
	for ( ; dB >= 0; --dB )
		data[ dB ] = 0u;
	ui16 v16 = 0u;
	ui32 eVU = 0u, v32 = 0u;
	int eb = 0, eB = 0, eBEnd = 0, ebEnd = 0, eBLast = 0, eMax = 0, eMin = 0;
	switch ( tSize )
	{
		case 2u:
			eMax = 15;
			eBEnd = 1;
			ebEnd = 5;
			break;
		case 4u:
		case 6u:
			eMax = 128;
			eBEnd = 2;
			ebEnd = 8;
			break;
		case 8u:
			eMax = 1024;
			eBEnd = 3;
			ebEnd = 11;
		case 10u:
		case 16u:
			eMax = 16384;
			eBEnd = 3;
			ebEnd = 15;
			break;
		default:
			data[ 0 ] = 0x80;
			return false;
	}
	const int mBEnd = ( tSize - eBEnd ), mbEnd = (( dbEnd - ebEnd ) - 1);
	int mb = 0, mB = 0, mBLast = mBEnd - 1, mPos = 0, me = 0;
	eMin = -( eMax - 1 );
	wxChar c = from[ 0 ];
	ui08 *mVI = new ui08[ mBEnd ], *mVF = new ui08[ mBEnd ];
	for ( ; mB < mBEnd; ++mB )
	{
		mVI[ mB ] = 0u;
		mVF[ mB ] = 0u;
	}
	int i = 0, iEnd = from.Length();
	bool r = true,  isNeg = ( c == cNeg ), isPos = ( c == cPos ), isDot = false, isExp = false, is0 = true;
	eBLast = eBEnd - 1;
	if ( !isNeg && !isPos )
		isPos = true;
	else
		++i;
	mB = mBLast;
	dB = 0;
	// Capture
	while ( db < dbEnd )
	{
		if ( i < iEnd )
		{
			c = from[ i ];
			++i;
			if ( c >= c0 && c <= c9 )
			{
				if ( db >= mbEnd && !isExp )
					break;
				if ( is0 )
					mB = mBLast;
				is0 = false;
				v16 *= 10u;
				v16 += ( c - c0 );
			}
			else if ( !isExp && !isDot && c == cDot )
			{
				isDot = true;
				v16 = 0u;
				mPos = mB;
			}
			else if ( !isExp && c == cE )
			{
				isExp = true;
				v16 = 0u;
				++i;
			}
			else
			{
				r = false;
				continue;
			}
		}
		else
			break;
		if ( isExp )
		{
			eVU = v16;
			if ( ( eVU * 10u ) >= v32 )
				break;
		}
		else
		{
			if ( c > c0 && c<= c9 )
				is0 = false;
			if ( isDot )
				mVF[ mB ] = ( v16 & 0xFF );
			else
				mVI[ mB ] = ( v16 & 0xFF );
			if ( v16 > 0xFFF )
			{
				--mB; db += 8u;
				if ( db >= mbEnd )
					v16 = 0u;
				else
					v16 >>= 8u;
			}
		}
	}
	ui08 *dbv = new ui08[ dbEnd ];
	dbv[ 0 ] = isNeg ? 1u : 0u;
	for ( db = 1; db < dbEnd; ++db )
		dbv[ db ] = false;
	// Mantissa
	// FIXME(awsdert) IEEE754 Mantissa needs fixing
	i = 0;
	mB = mPos;
	while ( ( mVI[ mB ] & 0x80 ) == 0u && mB < mBEnd )
	{
		mVI[ mB ] <<= 1u;
		++i;
		if ( i == 7 )
		{
			++mB; i = 0;
		}
	}
	for ( i = 0, mb = 0, db = ebEnd, me = 0; mB < mBEnd; ++i, ++mb, ++db, ++v32, --me )
	{
		mVI[ mB ] <<= 1u;
		dbv[ db ] = (( mVI[ mB ] & 0x80 ) >> 7u );
		if ( i == 7 )
		{
			++mB; i = 0;
		}
	}
	v32 = 0u;
	dB = dBLast;
	dBLast -= 8;
	for ( i = 0; mb < mbEnd; ++mb, ++db )
	{
		eB = mPos;
		v16 = mVF[ eB ];
		for ( --eB; eB >= 0; --eB )
		{
			v16 *= 2u;
			mVF[ eB + 1 ] = ( v16 & 0xFF );
			v16 >>= 8u;
			mVF[ eB ] = v16;
		}
		is0 = ( mVF[ mPos ] == 0u );
		if ( isNeg )
			dbv[ db ] = is0 ? 1uLL : 0uLL;
		else
			dbv[ db ] = is0 ? 0uLL : 1uLL;
		mVF[ mPos ] = 0u;
	}
	// Exponent
	if ( !isExp )
	{
		eVU = me;
	}
	// - Check Range
	v32 = eMax;
	while ( eVU > v32 )
		eVU /= 10u;
	v32 = -eMin;
	if ( isNeg && eVU > v32 )
		eVU -= 1u;
	// - Push bits forward
	// NOTE(awsdert) IEEE754 Exponent might not be recorded correctly
	db = ebEnd - 8;
	while ( db > 0 )
		db -= 8;
	for ( ; db < 0; ++db )
		eVU <<= 1u;
	// - Place bits in main variable
	if ( isNeg )
		eVU += eMax;
	//*/
	for ( db = 1, eb = 0; eb < ebEnd; ++eb, ++db )
	{
		dbv[ db ] = (( eVU & 0x80000000 ) >> 31u );
		eVU <<= 1u;
	}
	// Put everything into pointed variable
	for ( db = 0, dB = dBEnd - 1, i = 7; db < dbEnd; ++db, --i )
	{
		data[ dB ] |= ( dbv[ db ] << i );
		if ( i == 0 )
		{
			--dB; i = 7;
		}
	}
	delete [] mVI;
	delete [] mVF;
	delete [] dbv;
	return r;
}
void xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) {}
