#include <stdio.h>
#include <stdint.h>
#include <tchar.h>
#include <string>
#include "hexDLL_zxStuff.h"

#ifdef zxWXTypes

#include <wx/string.h>

#endif

#ifndef zxTypes_h
#define zxTypes_h

#define zxBITS_PER_BYTE CHAR_BIT

#ifndef zxWXTypes

#ifdef _UNICODE
#define wxT( m_txt ) __T( m_txt )
#else
#define wxT( m_txt ) m_txt
#endif

typedef TCHAR		wxChar;
typedef std::string	Text;

#else

typedef wxString	Text;

#endif

typedef uint8_t		ui08;
typedef int8_t		si08;
typedef uint16_t	ui16;
typedef int16_t		si16;
typedef uint32_t	ui32;
typedef int32_t		si32;
typedef uint64_t	ui64;
typedef int64_t		si64;
typedef signed	 int sint;
typedef unsigned int uint;
typedef signed	 long long sill;
typedef unsigned long long uill;
typedef unsigned char uc;
typedef signed	 char sc;

#ifndef __cplusplus
#ifndef _BOOL
#define _BOOL
typedef ui08 bool;
static const bool false = 0u;
static const bool true = !false;
#endif
#endif

#define zxVar_t_auto 0u
#define zxVar_t_malloc 1u
#ifdef __cplusplus
#define zxVar_t_new 2u
#endif
#define zxVar_t_copy 3u
#define zxVar_t_copyReverse 4u
#define zxVar_t_copyAsLEndian 5u
#define zxVar_t_copyAsBEndian 6u
#define zxVar_t_copyAsLBEndian 7u
#define zxVar_t_allowGrow 0x10
#define zxVar_t_allowFree 0x20

#endif