#include "GetPFM_DLG.h"
s8   GetPFM_DLG::dNewPFM( PFM* pfm )
{
	s8 index = -1;
	s8 count = dPFMName_LB->GetCount();
	if ( count < 100 )
	{
		PFM* now = dGetPFM( pfm );
		index    = dPFMName_LB->Append( now->nowName, now );
	}
	return index;
}
s8   GetPFM_DLG::dSetPFM( s8 index, PFM* pfm )
{
	s8 count = dPFMName_LB->GetCount();
	if ( index >= 0 && index <= count )
	{
		PFM* now = dGetPFM( pfm );
		PFM* old = dGetPFM( index );
		if ( !old->isDefault )
		{
			now->oldName = old->oldName;
			now->oldFile = old->oldFile;
		}
		dPFMName_LB->SetString( index, now->nowName );
		dPFMName_LB->SetClientObject( index, now );
	}
	else index = -1;
	return index;
}
PFM* GetPFM_DLG::dGetPFM( s8 index )
{
	return ( PFM* )dPFMName_LB->GetClientObject( index );
}
PFM* GetPFM_DLG::dGetPFM( PFM* pfm )
{
	PFM* now    = new PFM;
	gGetOrg( pfm, now );
	now->endian = pfm->endian;
	return now;
}
PFM* GetPFM_DLG::dGetPFM( void )
{
	PFM* now       = new PFM;
	now->isDefault = false;
	now->nowName   = dSetPFMName_TXT->GetValue();
	now->nowFile   = dSetPFMFile_TXT->GetValue();
	now->endian    = dSetPFMEndian_D->GetSelection();
	now->oldName   = now->nowName;
	now->oldFile   = now->oldFile;
	return now;
}
void GetPFM_DLG::dShowPFM( void )
{
	dSetPFMData_P->Enable();
	s8   index    = dPFMName_LB->GetSelection();
	if ( index < 0 ) index = 0;
	PFM* pfm      = dGetPFM( index );
	PFM  now;
	now.isDefault = pfm->isDefault;
	now.nowName   = pfm->nowName;
	now.nowFile   = pfm->nowFile;
	now.oldName   = pfm->oldName;
	now.oldFile   = pfm->oldFile;
	now.endian    = pfm->endian;
	gSetPFM( now );
	dSetPFMEndian_D->Select(      now.endian  );
	dSetPFMName_TXT->ChangeValue( now.nowName );
	dSetPFMFile_TXT->ChangeValue( now.nowFile );
	if ( now.isDefault ) dSetPFMData_P->Disable();
}
