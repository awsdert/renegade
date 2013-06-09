#include "main.h"
void fmtGetCodes( Codes& data, TxtA& block )
{
	int l = 0, lEnd = block.GetCount(), c = 0, cEnd = data.size();
	Text txt; TxtA ta;
	for ( ; l < lEnd; ++c )
	{
		if ( c == cEnd )
		{
			++cEnd;
			data.resize( cEnd );
		}
		fmtGetCode( data[ c ], block, l, lEnd );
	}
}
TxtA fmtGetCodes( Codes& data )
{
	Code obj;
	TxtA block;
	int c = 0, cEnd = data.size();
	for ( ; c < cEnd; ++c )
	{
		obj	= data[ c ];
		if ( obj.depth > 0xF || obj.loop > 0xFF || obj.addr[ 1 ] > zxF8LL )
			return block;
		getCode( data[ c ], block );
	}
	return block;
}