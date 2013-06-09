#include "hexObjs_base.h"
#ifndef hexObjs_base_region_h
#define hexObjs_base_region_h

enum
{
	REG_UK = 0,
	REG_US,
	REG_AUS,
	REG_CA,
	REG_DE,
	REG_JP,
	REG_COUNT
};

#define REGION_ALL	0xFFFFFFFF
#define REGION_UK	0x1
#define REGION_US	0x10
#define REGION_CA	0x2
#define REGION_DE	0x20
#define REGION_JP	0x100
#define REGION_AUS	0x8

// A namespace that needs to initialise it's own data
class hexObjs nsREGION
{
public:
	nsREGION( void );
	TxtA m_txt;
	ui32 m_bit[ REG_COUNT ];
	static Text getName( si32 id );
	static si32 getId( Text name );
	static Text getNames( ui32 value );
	static ui32 getValue( Text names );
};
static nsREGION oRegion;

#define getRegionName( m_id ) oRegion.getName( m_id )
#define getRegionId( m_txt ) oRegion.getId( m_txt )

#endif