#ifndef CLEANALL_H_
#define CLEANALL_H_
#include "cleanType.h"
#include "cleanHex.h"
#include "cleanAPP.h"
#include "cleanCLS.h"
#include <wx/app.h>
class hexApp : public wxApp
{
    public:
        virtual bool OnInit();
};
DECLARE_APP( hexApp );
void  gEnable( bool enable, wxWindow* obj );
xAStr gGetTests(  void );
xAStr gGetSizes(  void );
u8    gGetUSize( s8 size );
s8    gGetSSize( u8 size );
xStr  gGetTitle(  void );
xStr  gGetVendor( void );
xStr  gGetSlash(  void );
void  gGetOrg(  ORG*  org, ORG* now );
void  gSetOrg(  ORG   org );
void  gSetPFM(  PFM   pfm );
void  gSetBin(  BIN   bin );
void  gSetDBP(  DBP   dbp );
void  gSetHack( HACK* hack );
xAStr gGetArea( void );
ORG   gGetOrg(  void );
PFM   gGetPFM(  void );
BIN   gGetBin(  void );
DBP   gGetDBP(  void );
HACK* gGetHack( void );
void  gGetOrgFile(  xStr &path, xStr &file );
void  gGetPFMFile(  xStr &path, xStr &file );
void  gGetBinFile(  xStr &path, xStr &file );
void  gGetDBPFile(  xStr &path, xStr &file );
void  gGetHackFile( xStr &path, xStr &file );
void  gValidateFileName( wxKeyEvent& event );
void  gClose( wxDialog* d );
xAStr BuildCode( CODE& code );
void  BuildCode( CODE& code, s32 &index, xAStr &array );
void  doChange( wxCommandEvent& event, s32 mode = 0, s32 theSize = 0 );
void  doKeyDown( wxKeyEvent& event, s32 mode = 0 );
#endif
