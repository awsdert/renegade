#ifndef zxDLL

#define zxStuff_Revision 0x00000000

#if defined( _MSC_VER )
	#define zxPRINTF_USIZE_T	wxT("%Iu")
	#define zxPRINTF_SSIZE_T	wxT("%Id")
	#define zxPRINTF_XSIZE_T	wxT("%IX")
	#define zxPRINTF_PTRDIFF_T	wxT("%Id")
#elif defined( __GNUC__ )
	#define zxPRINTF_USIZE_T	wxT("%zu")
	#define zxPRINTF_SSIZE_T	wxT("%zd")
	#define zxPRINTF_XSIZE_T	wxT("%zX")
	#define zxPRINTF_PTRDIFF_T	wxT("%zd")
#else
	#define zxPRINTF_USIZE_T	wxT("%u")
	#define zxPRINTF_SSIZE_T	wxT("%d")
	#define zxPRINTF_XSIZE_T	wxT("%X")
	#define zxPRINTF_PTRDIFF_T	wxT("%d")
#endif

#ifdef __cplusplus
	#define zxC_EXT		extern "C"
	#define zxC_START	extern "C" {
	#define zxC_END		}
#else
	#define zxC_EXT
	#define zxC_START
	#define zxC_END
#endif

#if ( defined( __LP64__ ) || defined( __LLP64__ ) || defined( WIN64 ) )
	#define zxOS64
#else
	#define zxOS32
#endif

#if defined( __unix__ )
	#define zxUNIX
	#define zxDLL_EXP
	#define zxDLL_IMP
	#include <unistd.h>
#elif defined( _WIN32 )
	#define zxMSW
	#define zxDLL_EXP __declspec(dllexport)
	#define zxDLL_IMP __declspec(dllimport)
	#include <windows.h>
#elif defined( __APPLE__ )
	#define zxOSX
	#define zxDLL_EXP
	#define zxDLL_IMP
	#include <TargetConditionals.h>
	#ifdef TARGET_OS_IPHONE
		#define zxOSX_IP
	#elif defined( TARGET_IPHONE_SIMULATOR )
		#define zxOSX_IPEMU
	#elif defined( TARGET_OS_MAC )
		#define zxOSX_MAC
	#else
		#define zxOSX_OTHER
	#endif
#else
	#define zxANY
	#define zxDLL_EXP
	#define zxDLL_IMP
#endif

#ifdef zxDLL_BUILD
	#define zxDLL zxDLL_EXP
#else
	#define zxDLL zxDLL_IMP
#endif

#endif
