#ifndef __G__
#define __G__

/**
@file
Subclass of cleanFRM, which is generated by wxFormBuilder.
*/

#include "cleanFRM.h"

//// end generated include

/** Implementing cleanFRM */
class G : public cleanFRM
{
	protected:
		// Handlers for cleanFRM events.
		void GOnIdle(  wxIdleEvent&  event );
		void GOnClose( wxCloseEvent& event );
		void byte_TXTOnKeyDown(   wxKeyEvent&     event );
		void byte_TXTOnChange(    wxCommandEvent& event );
		void name_TXTOnChange(    wxCommandEvent& event );
		void path_TXTOnChange(    wxCommandEvent& event );
		void file_TXTOnChange(    wxCommandEvent& event );
		void edit_TXTOnChange(    wxCommandEvent& event );
		// Hook
		// - Organisation
		void mListOrg_OnClick(    wxCommandEvent& event );
		void mLoadOrg_OnClick(    wxCommandEvent& event );
		void mSaveOrg_OnClick(    wxCommandEvent& event );
		void mSetOrg_OnClick(     wxCommandEvent& event );
		// - Platform
		void mListPFM_OnClick(     wxCommandEvent& event );
		void mLoadPFM_OnClick(     wxCommandEvent& event );
		void mSavePFM_OnClick(     wxCommandEvent& event );
		void mSetPFM_OnClick(      wxCommandEvent& event );
		// - Application / File
		void mListBin_OnClick(    wxCommandEvent& event );
		void mLoadBin_OnClick(    wxCommandEvent& event );
		void mSaveBin_OnClick(    wxCommandEvent& event );
		void mSetBin_OnClick(     wxCommandEvent& event );
		void HookBin_BOnClick(    wxCommandEvent& event );
		void UseHook_DOnChoice(   wxCommandEvent& event );
		void binWait_DOnChange(   wxCommandEvent& event );
		void binPath_BOnClick(    wxCommandEvent& event );
		void binBind_BOnClick(    wxCommandEvent& event );
		void LaunchBin_BOnClick(    wxCommandEvent& event );
		// - RAM
		void NewRam_BOnClick(     wxCommandEvent& event );
		void SetRam_BOnClick(     wxCommandEvent& event );
		void ramName_DOnChoice(   wxCommandEvent& event );
		// - List Apps
		void UseApp_BOnClick(     wxCommandEvent& event );
		void ListApps_BOnClick(   wxCommandEvent& event );
		void ListApps_DOnChoice(  wxCommandEvent& event );
		// Search Tab
		void find_TXTOnKeyDown(   wxKeyEvent&     event );
		void find_TXTOnChange(    wxCommandEvent& event );
		void findUse_DOnChoice(   wxCommandEvent& event );
		void findMode_DOnChoice(  wxCommandEvent& event );
		void dump_BOnClick(       wxCommandEvent& event );
		void find_BOnClick(       wxCommandEvent& event );
		void findUndo_BOnClick(   wxCommandEvent& event );
		void findLT_BOnClick(     wxCommandEvent& event );
		void findLTE_BOnClick(    wxCommandEvent& event );
		void findEqual_BOnClick(  wxCommandEvent& event );
		void findNOTE_BOnClick(   wxCommandEvent& event );
		void findGTE_BOnClick(    wxCommandEvent& event );
		void findGT_BOnClick(     wxCommandEvent& event );
		void compare_DOnChoice( wxCommandEvent& event );
		// Result Tab
		void out_LCOnSelect(       wxListEvent&    event );
		void outData_LCOnSelect(   wxListEvent&    event );
		void outSetHack_BOnClick(  wxCommandEvent& event );
		void outDelHack_BOnClick(  wxCommandEvent& event );
		void out_TXTOnChange(      wxCommandEvent& event );
		void out_TXTOnKeyDown(     wxKeyEvent&     event );
		void SetOut_BOnClick(      wxCommandEvent& event );
		void DelOut_BOnClick(      wxCommandEvent& event );
		// Editor Tab
		void editByte_BOnClick(    wxCommandEvent& event );
		void editValue_BOnClick(   wxCommandEvent& event );
		void editRam_DOnChange(    wxCommandEvent& event );
		void editUpdate_DOnChoice( wxCommandEvent& event );
		void edit_GOnMouseWheel(   wxMouseEvent&   event );
		void edit_GOnEdit(         wxGridEvent&    event );
		void edit_GOnSelect(       wxGridEvent&    event );
		void editShow_BOnClick(    wxCommandEvent& event );
		void editGet_BOnClick(     wxCommandEvent& event );
		void editSet_BOnClick(     wxCommandEvent& event );
		// Database Tab
		void SetDBP_BOnClick(      wxCommandEvent& event );
		void LoadDBP_BOnClick(     wxCommandEvent& event );
		void SaveDBP_BOnClick(     wxCommandEvent& event );
		void dbpFile_TXTOnChange(  wxCommandEvent& event );
		void dbpPage_SNOnChange(   wxSpinEvent&    event );
		void dbpFile_TXTOnKeyDown( wxKeyEvent&     event );
		void area_RBOnChange(      wxCommandEvent& event );
		void dbpArea_RBOnChange(   wxCommandEvent& event );
		// Hack Tab
		// - Hack Tree
		void mShowHack_OnClick( wxCommandEvent& event );
		void NewHack_BOnClick( wxCommandEvent& event );
		void DelHack_OnClick( wxCommandEvent& event );
		void tree_TOnKeyUp( wxKeyEvent& event );
		void tree_TOnKeyDown( wxKeyEvent& event );
		void tree_TOnSelect( wxTreeEvent& event );
		void tree_TOnBeginDrag( wxTreeEvent& event );
		void tree_TOnEndDrag( wxTreeEvent& event );
		void GetHacks_BOnClick( wxCommandEvent& event );
		void SetHacks_BOnClick( wxCommandEvent& event );
		void DelHack_BOnClick(    wxCommandEvent& event );
		void UseHack_BOnClick(    wxCommandEvent& event );
		void MoveHack_BOnClick(    wxCommandEvent& event );
	public:
		/** Constructor */
		G( wxWindow* parent );
	//// end generated class members
		void     AddApp( wxString id, wxString exe, wxString title );
		s32      GetListLength( void );
	private:
		std::vector< wxCheckBox* > lArea_CB;
		std::vector< wxCheckBox* > mQVG_CB;
		std::vector< wxTextCtrl* > mQVG_TXT;
		std::vector< u64         > mQVGArray;
		std::vector< wxCheckBox* > mQVB_CB;
		std::vector< wxTextCtrl* > mQVB_TXT;
		std::vector< u64         > mQVBArray;
		std::vector< OUTDATA     > mOutArray;
		void     mLoadSession( s8 sessionId = -1 );
		u64      hookArray[ 16 ];
		uHandle  appHandle;
		s32      isHooked;
		bool     hookApp;
		wxFile   bin_BF;
		xTreeID  treePrev;
		xStr     lLastText, lOrgText, lPFMText, lBinText, lDBPText;
		void     NewHook( void );
		void     UseHook( void );
		void     UseHook( xTreeID root, s32 endian, s8 cIndex = 0, s8 cCount = 0 );
		void     DelHook( void );
		u32      hookAdd,   listAdd,   editAdd;
		xLL      hookUntil, listUntil, editUntil;
		void     SetTime( void );
		void     SetTime( u32 &value, s32 mode );
		void     CheckByte( void );
		// - Organisations
		xStr      mGetOrgFile( void );
		ORG       mGetOrg( void );
		void     mShowOrg( void );
		void     mSaveOrg( void );
		void     mLoadOrg( void );
		// - Platforms
		PFM       mGetPFM(       void );
		xStr      mGetPFMFile(   void );
		s32       mGetPFMEndian( void );
		void     mShowPFM( void );
		void     mSavePFM( void );
		void     mLoadPFM( void );
		// - Application / File
		BIN       mGetBin( void );
		void     mShowBin( void );
		void     mSaveBin( void );
		void     mLoadBin( void );
		// - Ram
		RAM       mGetRam(  void );
		u32       mGetRam( u64 &ramStart, u64 &ramEnd, s8 ramNo = 0 );
		RAM       mGetRam(     s8 index );
		xStr      mGetRamName( s8 index );
		u8        mGetRamPtr(  s8 index );
		u64       mGetRamByte( s8 index );
		u64       mGetRamSize( s8 index );
		void     mShowRam( void );
		// - Application Lister
		void           ListApps(    void );
		void           ListWindows( void );
		// Search Tab
		u64       gAGT, gAGTE, gALT, gALTE;
		u64       bAGT, bAGTE, bALT, bALTE;
		u64       GetValue( wxTextCtrl* obj, u8 mode );
		u32       GetGood( void );
		u32       GetBad(  void );
		u32       GetGoodByte( void );
		u32       GetBadByte(  void );
		void      SetSearch( s16 no );
		void      Search( s16 no, s8 type );
		// Results Tab
		void      ShowOut( s16 no, u8 size );
		// Editor Tab
		bool isEdit;
		bool isFocus;
		s32  editRow;
		s32  editCol;
		void FillEditor(  void );
		void editSetItem( wxGridEvent& event );
		void editSetRam( u64 address, u64 value, u8 size );
		// Database Tab
		DBP            mGetDBP(  void );
		void          mShowDBP(  void );
		void          mSaveDBP(  void );
		void          mLoadDBP(  void );
		// Hack Tab
		// - Tree
		wxTextFile hack_TF;
		xTreeID  GetHackID( void );
		xTreeID  GetHackRoot( void );
		xTreeID  GetHackRoot( xTreeID );
		xTreeID  mNewHack( xTreeID root, xStr name, HACK* hack, xTreeID id, s8 mode = ADD_BOTTOM, bool show = false );
		xTreeID  mSetHack( xTreeID id, xStr  name );
		xTreeID  mSetHack( xTreeID id, HACK* hack );
		HACK*    mGetHack( HACK* hack );
		HACK*    mGetHack( xTreeID id );
		void     mDelHack( xTreeID id );
		void     mUseHack( xTreeID id );
		xTreeID  mFindHack( u16     id );
		xTreeID  mFindHack( xTreeID root, u16     id    );
		void     mMoveHack( xTreeID from, xTreeID to    );
		void     mMoveHack( xTreeID tid,  s32     where );
		void     mShowHack( void );
		void     mOpenHack( void );
		void     mSaveHack( void );
		void     mSaveHack( xTreeID root, u16 &id, u16 parentID );
		void     mLoadHack( void );
};
#endif // __G__
