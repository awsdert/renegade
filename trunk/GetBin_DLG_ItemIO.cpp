#include "GetBin_DLG.h"
s8   GetBin_DLG::dNewBin( BIN* bin )
{
	s8 index = -1;
	s8 count = dBinName_LB->GetCount();
	if ( count < 100 )
	{
		BIN* now = dGetBin( bin );
		index    = dBinName_LB->Append( now->nowName, now );
	}
	return index;
}
s8   GetBin_DLG::dSetBin( s8 index, BIN* bin )
{
	s8 count = dBinName_LB->GetCount();
	if ( index >= 0 && index <= count )
	{
		BIN* now = dGetBin( bin );
		BIN* old = dGetBin( index );
		if ( !old->isDefault )
		{
			now->oldName = old->oldName;
			now->oldFile = old->oldFile;
		}
		dBinName_LB->SetString( index, now->nowName );
		dBinName_LB->SetClientObject( index, now );
	}
	else index = -1;
	return index;
}
BIN* GetBin_DLG::dGetBin( s8 index )
{
	return ( BIN* )dBinName_LB->GetClientObject( index );
}
BIN* GetBin_DLG::dGetBin( BIN* bin )
{
	BIN* now    = new BIN;
	gGetOrg( bin, now );
	now->isFile = bin->isFile;
	now->bind   = bin->bind;
	now->path   = bin->path;
	u8   index  = 0;
	u8   count  = bin->GetCount();
	for ( ; index < count; ++index )
		( *now )[ index ] = ( *bin )[ index ];
	return now;
}
BIN* GetBin_DLG::dGetBin( void )
{
	xStr text;
	BIN* bin       = new BIN;
	bin->isDefault = false;
	bin->isFile    = dIsFile_RB->GetValue();
	text           = dBinName_TXT->GetValue();
	if ( !text.IsEmpty() ) bin->nowName = text;
	text   = dBinFile_TXT->GetValue();
	if ( !text.IsEmpty() ) bin->nowFile = text;
	bin->oldName   = bin->oldName;
	bin->oldFile   = bin->nowFile;
	bin->path      = dBinPath_TXT->GetValue();
	bin->bind      = dBinBind_TXT->GetValue();
	return bin;
}
RAM GetBin_DLG::dGetRam( void )
{
	RAM  ram;
	xStr text;
	text = dRamName_TXT->GetValue();
	if ( !text.IsEmpty() ) ram.name = text;
	ram.ptrDepth = dRamDepth_SL->GetValue();
	ram.byte     = GetHex( dRamBase_TXT->GetValue() );
	ram.size     = GetHex( dRamSize_TXT->GetValue() );
	return ram;
}
void GetBin_DLG::dShowBin( void )
{
	dSetBinData_P->Enable();
	s8   index    = dBinName_LB->GetSelection();
	if ( index < 0 ) index = 0;
	BIN* bin      = dGetBin( index );
	s8   count    = bin->GetCount();
	BIN  now;
	RAM  tmpRam;
	RAM& ram      = tmpRam;
	now.isDefault = bin->isDefault;
	now.isFile    = bin->isFile;
	dIsApp_RB->SetValue( !bin->isFile );
	dIsFile_RB->SetValue( bin->isFile );
	now.nowName   = bin->nowName;
	dBinName_TXT->ChangeValue( bin->nowName );
	now.nowFile   = bin->nowFile;
	dBinFile_TXT->ChangeValue( bin->nowFile );
	now.oldName   = bin->oldName;
	now.oldFile   = bin->oldFile;
	now.path      = bin->path;
	dBinPath_TXT->ChangeValue( bin->path    );
	now.bind      = bin->bind;
	dBinBind_TXT->ChangeValue( bin->bind    );
	now.SetCount( count );
	dRamName_D->Clear();
	for ( index = 0; index < count; ++index )
	{
		ram = ( *bin )[ index ];
		now.p_data[ index ] = ram;
		dRamName_D->Append( ram.name );
	}
	gSetBin( now );
	dRamName_D->Select( 0 );
	dShowRam();
}
void GetBin_DLG::dShowRam( void )
{
	xStr text;
	s8   index = dBinName_LB->GetSelection();
	BIN* bin   = dGetBin( index );
	index      = dRamName_D->GetSelection();
	RAM  ram   = ( *bin )[ index ];
	dRamName_TXT->ChangeValue( ram.name );
	dRamDepth_SL->SetValue( ram.ptrDepth );
	text.Printf( hexVLL, ram.byte );
	dRamBase_TXT->ChangeValue( text );
	text.Printf( hexVLL, ram.size );
	dRamSize_TXT->ChangeValue( text );
	if ( bin->isDefault ) dSetBinData_P->Disable();
}
