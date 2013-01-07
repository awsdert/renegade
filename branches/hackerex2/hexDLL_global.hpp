#include <stdint.h>
#include <vector>

#ifndef HEXDLL_GLOBAL_H
#define HEXDLL_GLOBAL_H

// Global Includes

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
#define SSize signed size_t
#define SAddr signed size_t
#define USize unsigned size_t
#define UAddr unsigned size_t

// Defines

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
	#define xsC_EXT		extern "C"
	#define xsC_START	extern "C" {
	#define xsC_END		}
#else
	#define xsC_EXT
	#define xsC_START
	#define xsC_END
#endif

#if ( defined( __LP64__ ) || defined( __LLP64__ ) || defined( WIN64 ) )
	#define xsOS64
#else
	#define xsOS32
#endif

#if defined( __WXUNIX__ ) || defined( __unix__ )
	#define xsUNIX
	#define xsDLL_EXP
	#define xsDLL_IMP
	#include <unistd.h>
#elif defined( __WXMSW__ ) || defined( _WIN32 )
	#define xsMSW
	#define xsDLL_EXP __declspec(dllexport)
	#define xsDLL_IMP __declspec(dllimport)
	#include <windows.h>
#elif defined( __WXOSX__ ) || defined( __APPLE__ )
	#define xsOSX
	#define xsDLL_EXP
	#define xsDLL_IMP
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
	#define xsDLL_EXP
	#define xsDLL_IMP
#endif

#ifdef xsDLL_BUILD
	#define xsDLL xsDLL_EXP
#else
	#define xsDLL xsDLL_IMP
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
