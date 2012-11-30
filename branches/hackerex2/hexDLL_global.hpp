#ifndef HEXDLL_GLOBAL_H
#define HEXDLL_GLOBAL_H

// Global Includes
#include <stdint.h>
#include <vector>

// Types
#define Vect std::vector

// - Unsigned
typedef uint8_t		ui08;
typedef uint16_t	ui16;
typedef uint32_t	ui32;
typedef uint64_t	ui64;

// - Signed
typedef int8_t		si08;
typedef int16_t		si16;
typedef int32_t		si32;
typedef int64_t		si64;

// - ?
typedef size_t unsigned		Size;
typedef size_t unsigned		Addr;

// Defines

const ui32 G_HEX_H_AWSDERT = 0u;

#if ( defined( _MSC_VER ) )
	#define xsPRINTF_USIZE_T	"%Iu"
	#define xsPRINTF_SSIZE_T	"%Id"
	#define xsPRINTF_PTRDIFF_T	"%Id"
#elif ( defined( __GNUC__ ) )
	#define xsPRINTF_USIZE_T	"%zu"
	#define xsPRINTF_SSIZE_T	"%zd"
	#define xsPRINTF_PTRDIFF_T	"%zd"
#else
	#define xsPRINTF_USIZE_T	"%u"
	#define xsPRINTF_SSIZE_T	"%d"
	#define xsPRINTF_PTRDIFF_T	"%d"
#endif

#ifdef __cplusplus
	#define xsC_START extern "C" {
	#define xsC_END }
#else
	#define xsC_START
	#define xsC_END
#endif

#if ( defined( __LP64__ ) || defined( __LLP64__ ) || defined( WIN64 ) )
	#define G_OS64
#else
	#define G_OS32
#endif

#ifdef __unix__
	#define xsUNIX
	#include <unistd.h>
#elif defined( _WIN32 )
	#define xsMSW
	#include <windows.h>
#elif defined( __APPLE__ )
	#define xsOSX
	#include <TargetConditionals.h>
	#ifdef TARGET_OS_IPHONE
		#define xsOSX_IP
	#elif defined( TARGET_IPHONE_SIMULATOR )
		#define xsOSX_IPEMU
	#elif defined( TARGET_OS_MAC )
		#define xsOSX_MAC
	#else
		#define xsOSX_OTHER
	#endif
#else
	#define xsUNIV
#endif

#ifdef xsDLL_BUILD
	#ifdef xsMSW
		#define xsDLL __declspec(dllexport)
	#else
		#define xsDLL
	#endif
#else
	#ifdef xsMSW
		#define xsDLL __declspec(dllimport)
	#else
		#define xsDLL
	#endif
#endif

bool xsDLL LibGetX( ui64 address, void* value, ui32 bytes );
bool xsDLL LibSetX( ui64 address, void* value, ui32 bytes );
bool xsDLL LibGetPtr( ui64 address, ui64* ptr );
bool xsDLL LibGetPtrArray( ui16 pCount, ui64* address_array, ui64** ptr_array );

#define LibReadX		LibGetX
#define LibWriteX		LibSetX
#define LibReadPtr		LibGetPtr
#define LibReadPtrArray	LibGetPtrArray

#endif
