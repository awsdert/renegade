#ifndef HEXGUI_DB_H
#define HEXGUI_DB_H

#include "hexGUI_global.hpp"
#include "hexDB_hack.hpp"

class Org
{
public:
	Org( void );
	Text fileNow;
	Text fileOld;
	Text nameNow;
	Text nameOld;
};

class Pfm : public Org
{
public:
	Pfm( void );
	ui08 endian;
};

class Ram
{
public:
	Ram( void );
	void Clear( void );
	ui64 addr;
	ui08 depth;
	ui64 bytes;
	Text name;
};

class Bin : public Org
{
private:
	ui16 m_count;
public:
	Bin( void );
	Text name;
	Text path;
	ui08 type;
	Ram  ram[ 16u ];
	ui16 size( void );
	ui16 resize( ui16 count, bool clearAll = false );
	Ram& operator[] ( ui16 i );
};

#define REGION_ALL	0xFFFFFFFF
#define REGION_UK	0x1
#define REGION_US	0x10
#define REGION_DE	0x2
#define REGION_JP	0x100
#define REGION_AUS	0x8

class Pfl : public Org
{
public:
	ui32 region;
	ui32 format; // The current format in use, default = 0u
	ui16 profile;
	Text serial;
	Text notes;
};

#endif
