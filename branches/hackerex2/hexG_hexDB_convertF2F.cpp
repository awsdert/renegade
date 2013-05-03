#include "wx_pch.h"
#include "hexG_db.h"
void hexDB::convertF2F( int toFormat )
{
	if ( toFormat == format.format )
		return;
	Text txt, dbPath = wxGetCwd() + xsDirSep + wxT("org") + xsDirSep + org.fileOld + xsDirSep +
		pfm.fileOld + xsDirSep + bin.fileOld + xsDirSep + pfl.fileOld + xsDirSep + pfl.fileOld;
	Text pOld = nowP[ HEX_LIST_FORMAT ] + cTild, pNow = pOld + cTild, fName = getFormatName( toFormat );
	TxtF file, temp;
	TxtA block;
	BinF bf;
	temp.Create( pNow );
	file.Open( pOld );
	temp.Open( pNow );
	Format now = LoadFormats( format, file, temp, block, fName, false, true, true );
	block.Clear();
	file.Close();
	temp.Close();
	wxRemoveFile( pNow );
	pOld = dbPath + cDot + format.fileOld;
	pNow = dbPath + cDot + now.fileOld;
	if ( wxFileExists( pNow ) )
		wxRemoveFile( pNow );
	temp.Create( pNow );
	temp.Open( pNow );
	Hacks hData;
	Codes cData;
	loadCodes( pOld, hData, cData );
	ui32 hi, hc = hData.size();
	ui16 ci, cc;
	pOld += wxT("_files~") + xsDirSep;
	ui08* data = new ui08[ m_codeBytes ];
	cData.resize( 0 );
	for ( hi = 0u; hi < hc; ++hi )
	{
		if ( hData[ hi ].used )
		{
			pNow.Printf( wxT("%04X.bin"), hi );
			bf.Open( pOld + pNow );
			cc = ( bf.Length() / m_codeBytes );
			cData.resize( cc );
			for ( ci = 0u; ci < cc; ++ci )
			{
				bf.Read( data, m_codeBytes );
				m_getCode( cData[ ci ], data );
			}
			bf.Close();
			switch ( toFormat )
			{
			case HL_HEX1:
				MakeTxt_Hex1( cData, block );
				SaveHack_Hex( temp, hData[ hi ], hi, cc, block );
				break;
			}
			cData.resize( 0 );
			block.Clear();
		}
	}
	delete [] data;
}