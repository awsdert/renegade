#include "hexDLL_types.h"

#ifndef hexDll_main_h
#define hexDll_main_h

bool zxDLL LibGetX( ui64 address, void* value, ui32 bytes );
bool zxDLL LibSetX( ui64 address, void* value, ui32 bytes );
bool zxDLL LibGetPtr( ui64 address, ui64* ptr );
bool zxDLL LibGetPtrArray( ui16 pCount, ui64* address_array, ui64** ptr_array );

#define LibReadX		LibGetX
#define LibWriteX		LibSetX
#define LibReadPtr		LibGetPtr
#define LibReadPtrArray	LibGetPtrArray

#endif
