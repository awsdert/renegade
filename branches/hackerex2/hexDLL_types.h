#include <stdint.h>
#include <ctime>
#ifndef ui08

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

#endif
