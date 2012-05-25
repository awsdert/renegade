#include "GetOrg_DLG.h"
s8   GetOrg_DLG::dNewOrg( ORG* org )
{
	s8 index = -1;
	s8 count = dOrgName_LB->GetCount();
	if ( count < 100 )
	{
		ORG* now = new ORG;
		gGetOrg( org, now );
		index    = dOrgName_LB->Append( now->nowName, now );
	}
	return index;
}
s8   GetOrg_DLG::dSetOrg( s8 index, ORG* org )
{
	s8 count = dOrgName_LB->GetCount();
	if ( index >= 0 && index <= count )
	{
		ORG* now = new ORG;
		gGetOrg( org, now );
		ORG* old = dGetOrg( index );
		if ( !old->isDefault )
		{
			now->oldName = old->oldName;
			now->oldFile = old->oldFile;
		}
		dOrgName_LB->SetString( index, now->nowName );
		dOrgName_LB->SetClientObject( index, now );
	}
	else index = -1;
	return index;
}
ORG* GetOrg_DLG::dGetOrg( s8 index )
{
	return ( ORG* )dOrgName_LB->GetClientObject( index );
}
ORG* GetOrg_DLG::dGetOrg( void )
{
	ORG* org       = new ORG;
	org->isDefault = false;
	org->nowName   = dSetOrgName_TXT->GetValue();
	org->nowFile   = dSetOrgFile_TXT->GetValue();
	org->oldName   = org->nowName;
	org->oldFile   = org->oldFile;
	return org;
}
void GetOrg_DLG::dShowOrg( void )
{
	s8   index    = dOrgName_LB->GetSelection();
	if ( index < 0 ) index = 0;
	ORG* org      = dGetOrg( index );
	ORG  now;
	now.isDefault = org->isDefault;
	now.nowName   = org->nowName;
	now.oldName   = org->oldName;
	now.nowFile   = org->nowFile;
	now.oldFile   = org->oldFile;
	gSetOrg( now );
	dSetOrgData_P->Enable();
	dSetOrgName_TXT->ChangeValue( now.nowName );
	dSetOrgFile_TXT->ChangeValue( now.nowFile );
	if ( now.isDefault ) dSetOrgData_P->Disable();
}
