/***************************************************************
 * Name:      qTab_getTests.cpp
 * Purpose:   Code for Search Tab
 * Author:    awsdert ()
 * Created:   2012-02-13
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::GetValue( wxTextCtrl* obj, u64& value, s32 valueType, bool isSigned )
{
	xStr text = obj->GetValue();
	switch ( valueType )
	{
		case 2:
			value = getHEXFromFloat( text );
			break;
		case 1:
			if ( isSigned )
			{
				value = getHEXFromSignedDecimal( text );
			}
			else
			{
				value = getHEXFromDecimal( text );
			}
			break;
		default:
			value = getHEX( text );
	}
}
void ME::GetValues( void )
{
	s32 valueType = searchValueType_D->GetSelection();
	bool isSigned = searchIsSigned_CB->GetValue();
	// Accept
	// - Address
	GetValue( goodAGT_TXT, goodAGT, valueType, isSigned );
	GetValue( goodAGTE_TXT, goodAGTE, valueType, isSigned );
	GetValue( goodALT_TXT, goodALT, valueType, isSigned );
	GetValue( goodALTE_TXT, goodALTE, valueType, isSigned );
	// - Value
	GetValue( goodVEqual_TXT, goodVEqual, valueType, isSigned );
	GetValue( goodVNOTE_TXT, goodVNOTE, valueType, isSigned );
	GetValue( goodVGT_TXT, goodVGT, valueType, isSigned );
	GetValue( goodVGTE_TXT, goodVGTE, valueType, isSigned );
	GetValue( goodVLT_TXT, goodVLT, valueType, isSigned );
	GetValue( goodVLTE_TXT, goodVLTE, valueType, isSigned );
	// Don't Accept
	// - Address
	GetValue( badAGT_TXT, badAGT, valueType, isSigned );
	GetValue( badAGTE_TXT, badAGTE, valueType, isSigned );
	GetValue( badALT_TXT, badALT, valueType, isSigned );
	GetValue( badALTE_TXT, badALTE, valueType, isSigned );
	// - Value
	GetValue( badVEqual_TXT, badVEqual, valueType, isSigned );
	GetValue( badVNOTE_TXT, badVNOTE, valueType, isSigned );
	GetValue( badVGT_TXT, badVGT, valueType, isSigned );
	GetValue( badVGTE_TXT, badVGTE, valueType, isSigned );
	GetValue( badVLT_TXT, badVLT, valueType, isSigned );
	GetValue( badVLTE_TXT, badVLTE, valueType, isSigned );
}
// Value
u32 ME::GetGood( void )
{
	u32 value = 0u;
	if ( !searchIsBinary_CB->GetValue() )
	{
		value += ( goodVEqual_CB->GetValue() ) ? TM_EQUAL : 0u;
		value += ( goodVNOTE_CB->GetValue() ) ? TM_NOTE : 0u;
		value += ( goodVGT_CB->GetValue() ) ? TM_GT : 0u;
		value += ( goodVGTE_CB->GetValue() ) ? TM_GTE : 0u;
		value += ( goodVLT_CB->GetValue() ) ? TM_LT : 0u;
		value += ( goodVLTE_CB->GetValue() ) ? TM_LTE : 0u;
	}
	return value;
}
u32 ME::GetBad( void )
{
	u32 value = 0u;
	if ( !searchIsBinary_CB->GetValue() )
	{
		value += ( badVEqual_CB->GetValue() ) ? TM_EQUAL : 0u;
		value += ( badVNOTE_CB->GetValue() ) ? TM_NOTE : 0u;
		value += ( badVGT_CB->GetValue() ) ? TM_GT : 0u;
		value += ( badVGTE_CB->GetValue() ) ? TM_GTE : 0u;
		value += ( badVLT_CB->GetValue() ) ? TM_LT : 0u;
		value += ( badVLTE_CB->GetValue() ) ? TM_LTE : 0u;
	}
	return value;
}
u32 ME::GetOld( void )
{
	u32 value = 0u;
	if ( !searchIsBinary_CB->GetValue() )
	{
		switch ( searchType_D->GetSelection() )
		{
			case TMU_EQUAL: value = TM_EQUAL; break;
			case TMU_NOTE: value = TM_NOTE; break;
			case TMU_GT: value = TM_GT; break;
			case TMU_GTE: value = TM_GTE; break;
			case TMU_LT: value = TM_LT; break;
			case TMU_LTE: value = TM_LTE; break;
		}
	}
	return value;
}
// Binary
u32 ME::GetGoodBinary( void )
{
	u32 value = 0u;
	if ( searchIsBinary_CB->GetValue() )
	{
		value += ( goodVEqual_CB->GetValue() ) ? TM_EQUAL : 0u;
		value += ( goodVNOTE_CB->GetValue() ) ? TM_NOTE : 0u;
		value += ( goodVGT_CB->GetValue() ) ? TM_GT : 0u;
		value += ( goodVGTE_CB->GetValue() ) ? TM_GTE : 0u;
		value += ( goodVLT_CB->GetValue() ) ? TM_LT : 0u;
		value += ( goodVLTE_CB->GetValue() ) ? TM_LTE : 0u;
	}
	return value;
}
u32 ME::GetBadBinary( void )
{
	u32 value = 0u;
	if ( searchIsBinary_CB->GetValue() )
	{
		value += ( badVEqual_CB->GetValue() ) ? TM_EQUAL : 0u;
		value += ( badVNOTE_CB->GetValue() ) ? TM_NOTE : 0u;
		value += ( badVGT_CB->GetValue() ) ? TM_GT : 0u;
		value += ( badVGTE_CB->GetValue() ) ? TM_GTE : 0u;
		value += ( badVLT_CB->GetValue() ) ? TM_LT : 0u;
		value += ( badVLTE_CB->GetValue() ) ? TM_LTE : 0u;
	}
	return value;
}
u32 ME::GetOldBinary( void )
{
	u32 value = 0u;
	if ( searchIsBinary_CB->GetValue() )
	{
		switch ( searchType_D->GetSelection() )
		{
			case TMU_EQUAL: value = TM_EQUAL; break;
			case TMU_NOTE: value = TM_NOTE; break;
			case TMU_GT: value = TM_GT; break;
			case TMU_GTE: value = TM_GTE; break;
			case TMU_LT: value = TM_LT; break;
			case TMU_LTE: value = TM_LTE; break;
		}
	}
	return value;
}
// Address
u32 ME::GetGoodByte( void )
{
	u32 value = 0u;
	value += ( goodAGT_CB->GetValue() ) ? TM_GT : 0u;
	value += ( goodAGTE_CB->GetValue() ) ? TM_GTE : 0u;
	value += ( goodALT_CB->GetValue() ) ? TM_LT : 0u;
	value += ( goodALTE_CB->GetValue() ) ? TM_LTE : 0u;
	return value;
}
u32 ME::GetBadByte( void )
{
	u32 value = 0u;
	value += ( badAGT_CB->GetValue() ) ? TM_GT : 0u;
	value += ( badAGTE_CB->GetValue() ) ? TM_GTE : 0u;
	value += ( badALT_CB->GetValue() ) ? TM_LT : 0u;
	value += ( badALTE_CB->GetValue() ) ? TM_LTE : 0u;
	return value;
}
