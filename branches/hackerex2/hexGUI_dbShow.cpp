#include "hexGUI_G.hpp"
void G::ShowOrgD( Org* obj )
{
	HexName_TXT->ChangeValue( obj->nameNow );
	HexFile_TXT->ChangeValue( obj->fileNow );
}
void G::ShowPfmD( Pfm& obj )
{
	ShowOrgD( &obj );
	HexEndian_DD->Select( obj.endian );
}
void G::ShowBinD( Bin& obj )
{
	// TODO: Implement G::ShowBinD();
	ShowOrgD( &obj );
}
void G::ShowRamD( Ram& obj )
{
	// TODO: Implement G::ShowRamD();
}
void G::ShowPflD( Pfl& obj )
{
	// TODO: Implement G::ShowPflD();
	ShowOrgD( &obj );
}
void G::ShowHack( Hack& obj )
{
	// TODO: Implement G::ShowHack();
}
void G::ShowCode( Code& obj )
{
	// TODO: Implement G::ShowCode();
}
