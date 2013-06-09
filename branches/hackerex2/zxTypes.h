#include <stdint.h>
#include "zxDLL.h"

#ifndef zxTypes_h
#define zxTypes_h

#define zxBITS_PER_BYTE CHAR_BIT

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
typedef signed	 long long int sill;
typedef unsigned long long int uill;
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

#define zxF8LL 0xFFFFFFFFLL
#define zxGETHEX( m_src, m_bits, m_move ) ( ( m_src & ( m_bits << m_move ) ) >> m_move )

#endif