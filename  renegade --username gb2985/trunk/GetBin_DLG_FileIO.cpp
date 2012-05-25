#include "GetBin_DLG.h"
void GetBin_DLG::dLoadBin( void )
{
	xStrT st;
	u8    keyNo = 0;
	long  i     = 0;
	bool  atGrp = false;
	bool  atKey = false;
	BIN*  bin;
	RAM   ram;
	xStr  key, text, path, file, name;
	gGetBinFile( path, file );
	s8 index = dBinName_LB->GetCount();
	for ( --index; index >= 0; --index )
	{
		bin = dGetBin( index );
		if ( !bin->isDefault ) dBinName_LB->Delete( index );
	}
	wxFileConfig cfgBin( dTitle, dVendor, file );
	bin            = new BIN;
	bin->isDefault = false;
	for
	(
		atGrp = cfgBin.GetFirstGroup( name, i );
		atGrp;
		atGrp = cfgBin.GetNextGroup(  name, i )
	)
	{
		bin->nowName = name;
		bin->oldName = name;
		bin->SetCount( 1 );
		cfgBin.SetPath( name );
		for
		(
			atKey = cfgBin.GetFirstEntry( key, i );
			atKey;
			atKey = cfgBin.GetNextEntry(  key, i )
		)
		{
			cfgBin.Read( key, &text );
			st.SetString( text, wxT( ";" ) );
			if ( key.CmpNoCase( wxT( "data" ) ) == 0 )
			{
				text         = st.GetNextToken();
				if ( text.CmpNoCase( wxT( "file" ) ) == 0 ) bin->isFile = true;
				else bin->isFile = false;
				bin->nowFile = st.GetNextToken();
				bin->oldFile = bin->nowFile;
				bin->bind    = st.GetNextToken();
				bin->path    = st.GetNextToken();
			}
			else
			{
				keyNo        = GetHex( key, 1u );
				if ( keyNo < 16u )
				{
					ram.name     = st.GetNextToken();
					ram.ptrDepth = GetHex( st.GetNextToken(), 1u );
					ram.byte     = GetHex( st.GetNextToken() );
					ram.size     = GetHex( st.GetNextToken() );
					if ( keyNo >= bin->GetCount() ) bin->SetCount( keyNo + 1 );
					( *bin )[ keyNo ] = ram;
				}
			}
		}
		dNewBin( bin );
	}
	delete bin;
	dBinName_LB->Select( 0 );
	dShowBin();
}
void GetBin_DLG::dSaveBin( void )
{
	RAM  ram;
	BIN* bin;
	u8   j, jCount;
	s8   i, iCount = dBinName_LB->GetCount();
	xStr key, text, path, file;
	gGetBinFile( path, file );
	wxFileConfig cfgBin( dTitle, dVendor, file );
	cfgBin.DeleteAll();
	for ( i = 0; i < iCount; ++i )
	{
		bin    = dGetBin( i );
		if ( bin->isDefault ) continue;
		key    = wxT( "data" );
		jCount = bin->GetCount();
		cfgBin.SetPath( bin->nowName );
		if ( bin->isFile ) text = wxT( "file;" );
		else text = wxT( "app;" );
		cfgBin.Write( key, text + bin->nowFile + wxT( ";" ) +
					bin->bind + wxT( ";" ) + bin->path );
		for ( j = 0u; j < jCount; ++j )
		{
			ram = ( *bin )[ j ];
			key.Printf( wxT( "%X" ), j );
			text.Printf( wxT( ";%X;%llX;%llX" ),
						ram.ptrDepth, ram.byte, ram.size );
			cfgBin.Write( key, ram.name + text );
		}
	}
}
