//#include <vector>
#include "hexDLL_types.h"
#include "hexDLL_zxStuff.h"
#include "xsVector.h"
#include "xsArray.h"

#ifndef Vect

//#define Vect std::vector
#define Vect xsVector

bool xsDLL LibGetX( ui64 address, void* value, ui32 bytes );
bool xsDLL LibSetX( ui64 address, void* value, ui32 bytes );
bool xsDLL LibGetPtr( ui64 address, ui64* ptr );
bool xsDLL LibGetPtrArray( ui16 pCount, ui64* address_array, ui64** ptr_array );

#define LibReadX		LibGetX
#define LibWriteX		LibSetX
#define LibReadPtr		LibGetPtr
#define LibReadPtrArray	LibGetPtrArray

#endif
