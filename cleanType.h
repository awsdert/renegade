#ifndef CLEANTYPE_H_
#define CLEANTYPE_H_
#include <stdexcept>
#include <vector>
#include <wx/string.h>
#include <wx/tokenzr.h>
#include <wx/arrstr.h>
#include <wx/fileconf.h>
#include <wx/event.h>
#include <wx/treectrl.h>
#include <wx/listctrl.h>
#include <wx/filefn.h>
#include <wx/ffile.h>
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/stdpaths.h>
#ifdef __WXMSW__
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#endif
#ifndef wxSplit
#define wx2_9_H_CPP
wxArrayString wxSplit( const wxString& str, const wxChar sep, const wxChar escape = wxT( '\\' ) );
#endif
// Unsigned
typedef uint8_t           u8;
typedef uint16_t          u16;
typedef uint32_t          u32;
typedef uint64_t          u64;
// Signed
typedef int8_t            s8;
typedef int16_t           s16;
typedef int32_t           s32;
typedef int64_t           s64;
// Float
typedef wxFloat32         f32;
typedef wxFloat64         f64;
// wxTree
typedef wxTreeItemId      xTreeID;
typedef wxTreeItemIdValue xTreeIDV;
// Common Events
typedef wxCommandEvent    xCEvent;
typedef wxFocusEvent      xFEvent;
typedef wxKeyEvent        xKEvent;
// Common types
typedef wxLongLong        xLL;
typedef wxString          xStr;
typedef wxStringTokenizer xStrT;
typedef wxArrayString     xAStr;
typedef wxArrayInt        xAInt;
// Constants
s32 MB( xStr text, xStr title = wxT("Message"), s32 mode = wxOK );
#define BLANK()
#define IsBetween( m_value, m_from, m_to ) ( m_value >= m_from && m_value <= m_to )
#define BitLeft( m_type, m_value, m_by ) ( ( m_type )m_value << m_by )
#define BitRight( m_type, m_value, m_by ) ( ( m_type )m_value >> m_by )
// - Value Types
const u32 readSize = 0x10000000;
enum { ENDIAN_LITTLE, ENDIAN_BIG, ENDIAN_LB, ENDIAN_COUNT };
#define GetAddress( m_Address, m_ToAddress, m_Size, m_Endian ) \
m_ToAddress = m_Address; \
if ( m_Endian == ENDIAN_BIG ) \
{ \
	if ( m_Size == 1u ) m_ToAddress = m_Address ^ 3u; \
	if ( m_Size == 2u ) m_ToAddress = m_Address ^ 2u; \
}
enum { SIZE_8 = 0, SIZE_16, SIZE_32, SIZE_64, SIZE_COUNT };
enum { VAL_HEX = 0, VAL_SINT, VAL_UINT, VAL_SFLT, VAL_COUNT, VAL_NAME, VAL_PATH, VAL_FILE };
enum
{
	ADD_NEXT = 0,
	ADD_PREV,
	ADD_TOP,
	ADD_BOTTOM
};
enum
{
	AREA_UK_CB = 0,
	AREA_US_CB,
	AREA_JP_CB,
	AREA_DE_CB,
	AREA_AUS_CB,
	AREA_COUNT
};
enum
{
	QA_MT = 0,
	QA_MTE,
	QA_LT,
	QA_LTE,
	QA_COUNT
};
enum
{
	QV_EQUAL = 0,
	QV_NOT,
	QV_MT,
	QV_MTE,
	QV_LT,
	QV_LTE,
	QV_GOT,
	QV_NOT_GOT,
	QV_COUNT
};
enum
{
	QD_DUMP = 0,
	QD_EQUAL,
	QD_NOT,
	QD_MT,
	QD_MTE,
	QD_LT,
	QD_LTE,
	QD_COUNT
};
#define gTEqual 0x1
#define gTNotE  0x10
#define gTMoreT 0x2
#define gTMoreE 0x20
#define gTLessT 0x4
#define gTLessE 0x40
#define gTGot   0x8
#define gTNotG  0x80
u8*   gGetQATest( void );
u8*   gGetQVTest( void );
xAStr gGetValModes( void );
u64   gGetValue( xStr text, u8 mode, u8 size = 8u );
void  gSetQTests( void );
#define AREA_UK       0x1
#define AREA_US       0x2
#define AREA_AUS      0x4
#define AREA_JP       0x8
#define AREA_DE       0x10
#define AREA_ALL      0xFFFFFFFF
xAStr gGetArea(  void );
u32*  gGetAreas( void );
void  gSetArea(  void );
#define UINT8_MAX     0xFF
#define SINT8_MAX       127
#define SINT8_MIN      -127
#define UINT16_MAX    0xFFFF
#define SINT16_MAX      32767
#define SINT16_MIN     -32767
#define UINT32_MAX    0xFFFFFFFF
#define SINT32_MAX      2147483647
#define SFLT32_MAX      3.4E+38
#define SINT32_MIN     -2147483647
#define SFLT32_MIN      3.4E-38
#define UINT64_MAX    0xFFFFFFFFFFFFFFFFLL
#define SINT64_MAX      9223372036854775807LL
#define SFLT64_MAX      1.7E+308
#define SINT64_MIN     -9223372036854775807LL
#define SFLT64_MIN      1.7E-308
// - Code Types
#define CT_WRITE     0u
#define CT_COPY      1u
#define CT_INCREMENT 2u
#define CT_DECREMENT 3u
#define CT_TEST      4u
#define CT_LIST      5u
#define CT_COUNT     6u
// - wxChar / wxString is / contains
const wxChar cSplit = wxT('|');
const wxChar cNeg   = wxT('-');
const wxChar cDot   = wxT('.');
// - wxString.Printf();
const xStr hex0     = wxT( "00000000" );
const xStr hexV	    = wxT( "%01X"     );
const xStr hexVLL	= wxT( "%01llX"   );
const xStr hex8	    = wxT( "%02X"     );
const xStr hex8LL   = wxT( "%02llX"   );
const xStr hex16	= wxT( "%04X"     );
const xStr hex16LL  = wxT( "%04llX"   );
const xStr hex32	= wxT( "%08X"     );
const xStr hex32LL  = wxT( "%08llX"   );
const xStr hex64	= wxT( "%016llX"  );
// - wxChar numbers
const wxChar c0 = wxT( '0' );
const wxChar c9 = wxT( '9' );
const wxChar cA = wxT( 'A' );
const wxChar cE = wxT( 'E' ); // Exponent
const wxChar cF = wxT( 'F' );
const wxChar cZ = wxT( 'Z' ); // wxKeyEvent
#endif
