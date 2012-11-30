#ifndef HEXGUI_DB_H
#define HEXGUI_DB_H

#include "hexGUI_global.hpp"
#include "hexDB_hack.hpp"

class Org
{
public:
	Text fileNow;
	Text fileOld;
	Text nameNow;
	Text nameOld;
};

class Pfm : public Org
{
public:
	Pfm( void );
	int endian;
};

class Ram
{
public:
	Ram( void );
	ui64 addr;
	ui08 depth;
	ui64 bytes;
	Text name;
};

class Bin : public Org
{
public:
	Bin( void );
	~Bin( void );
	Ram& operator[] ( unsigned int );
	Vect< Ram > ram;
	Text name;
	Text path;
	ui08 type;
};

class Pfl : public Org
{
public:
	ui32 format; // The current format in use, default = 0u
	ui16 profile;
	Text serial;
	Text notes;
};

class OrgV : public Vect< Org > {};
class PfmV : public Vect< Pfm > {};
class BinV : public Vect< Bin > {};
class PflV : public Vect< Pfl > {};

#endif
