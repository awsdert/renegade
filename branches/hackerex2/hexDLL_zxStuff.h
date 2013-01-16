#ifndef xsDLL

#if ( defined( _MSC_VER ) )
	#define xsPRINTF_USIZE_T	wxT("%Iu")
	#define xsPRINTF_SSIZE_T	wxT("%Id")
	#define xsPRINTF_XSIZE_T	wxT("%IX")
	#define xsPRINTF_PTRDIFF_T	wxT("%Id")
#elif ( defined( __GNUC__ ) )
	#define xsPRINTF_USIZE_T	wxT("%zu")
	#define xsPRINTF_SSIZE_T	wxT("%zd")
	#define xsPRINTF_XSIZE_T	wxT("%zX")
	#define xsPRINTF_PTRDIFF_T	wxT("%zd")
#else
	#define xsPRINTF_USIZE_T	wxT("%u")
	#define xsPRINTF_SSIZE_T	wxT("%d")
	#define xsPRINTF_XSIZE_T	wxT("%X")
	#define xsPRINTF_PTRDIFF_T	wxT("%d")
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

#endif
