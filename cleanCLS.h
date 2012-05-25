#ifndef CLEANCLS_H_
#define CLEANCLS_H_
#include "cleanType.h"
// Hook
class ORG : public wxClientData
{
	public:
		ORG(  void );
		~ORG( void );
	public:
		bool isDefault;
		xStr oldName;
		xStr oldFile;
		xStr nowName;
		xStr nowFile;
};
class PFM : public ORG
{
	public:
		PFM(  void );
		~PFM( void );
	public:
		s8   endian;
};
class RAM
{
	public:
		RAM(  void );
		~RAM( void );
	public:
		xStr name;
		u8   ptrDepth;
		u64  byte;
		u64  size;
};
class BIN : public ORG
{
	public:
		BIN(  void );
		~BIN( void );
		RAM& operator[] ( unsigned int index );
		RAM& operator[] (   signed int index );
	public:
		std::vector< RAM > p_data;
	public:
		xStr bind;
		xStr path;
		bool isFile;
		s8   Append(   RAM  ram   );
		void SetCount( s8   count );
		s8   GetCount( void );
		void Clear();
};
// Results
class OUTDATA
{
	public:
		OUTDATA(    void );
		~OUTDATA(   void );
	private:
		void Clear( void );
	public:
		u64 address;
		u64 value;
		u8  size;
};
// Database
class DBI : public wxClientData
{
	public:
		DBI( void );
		~DBI( void );
	public:
		s32 index;
		s64 error;
};
class DBP : public ORG
{
	public:
		DBP(  void );
		~DBP( void );
	public:
		u32  area;
		u16  PID;
		xStr SID;
		xStr notes;
};
// Tree
// - Code
class CODE
{
	public:
		CODE(  void );
		~CODE( void );
		u64& operator[] ( s32 index );
		u64& operator[] ( u32 index );
	private:
		std::vector< u64 > p_value;
	public:
		u8    ram;
		u8    type;
		u8    size;
		u8    test;
		u64   slide;
		u8    loop;
		u8    ptrDepth;
		u64   byte;
		u32   increment;
		bool  isBigByte;
	public:
		void  SetCount( s16  count );
		u8    GetCount( void );
		s16   NewItem( u64 value );
		void  DelItem( s16 index );
		void  DelAll( void  );
		void  Clear();
};
// Hack
#define HACK_USE 0x1000
#define HACK_RB  0x2000
class HACK : public wxTreeItemData
{
	public:
		HACK( void );
		~HACK( void );
		CODE& operator[] ( s32 index );
		CODE& operator[] ( u32 index );
	private:
		std::vector< CODE > p_data;
	public:
		u16   id;
		bool  use;
		bool  useRB;
	public:
		void  SetCount( s8   index );
		s8    GetCount( void );
		s8    NewCode(  CODE code  );
		void  DelCode(  s8   index );
		void  Clear();
};
#endif
