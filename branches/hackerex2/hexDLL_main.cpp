#include "hexDLL_global.hpp"

#ifdef xsMSW
int WINAPI DllMain( HANDLE hMod, DWORD reason, LPVOID ignore )
{
	switch ( reason )
	{
		case DLL_PROCESS_ATTACH:
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			return 0;
		default: return -1;
	}
}
#else
// TODO: Implement OSX and UNIX handling of HackerEX Library
int main( void* hMod, void* reason, void* ignore )
{
	return 0;
}
#endif
xsDLL bool LibGetX( size_t address, void* value, ui32 bytes )
{
	ui08* v = ( ui08* )value;
	volatile ui08 *a = (ui08*)address;
	try
	{
		for ( ui32 i = 0u; i < bytes; ++i )
			{ v[ i ] = a[ i ]; }
	}
	catch ( void* anyError )
	{
		anyError = NULL;
		return false;
	}
	return true;
}
xsDLL bool LibSetX( size_t address, void* value, ui32 bytes )
{
	ui08* v = ( ui08* )value;
	volatile ui08 *a = (ui08*)address;
	try
	{
		for ( ui32 i = 0u; i < bytes; ++i )
			{ a[ i ] = v[ i ]; }
	}
	catch ( void* anyError )
	{
		anyError = NULL;
		return false;
	}
	return true;
}
xsDLL bool LibGetPtr( size_t address, size_t* ptr )
{
	/*volatile ui08 *a = ( ui08* )address;
	try { ptr = &a; }
	catch ( void* any_error ) { return false; }*/
	return true;
}

xsDLL bool LibGetPtrArray( ui16 loop, size_t* address_array, size_t** ptr_array )
{
	/*volatile ui08 *a;
	try
	{
		for ( ui16 i = 0u; i < loop; ++i )
		{
			a = ( ui08* )address_array[ i ];
			ptr_array[ i ] = &a;
		}
	}
	catch ( void* any_error ) { return false; }*/
	return true;
}
