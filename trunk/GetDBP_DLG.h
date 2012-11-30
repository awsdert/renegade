#ifndef __chooseDBP_DLG__
#define __chooseDBP_DLG__

/**
@file
Subclass of cleanChooseDBP_DLG, which is generated by wxFormBuilder.
*/

#include "cleanFRM.h"

//// end generated include
#include "cleanAll.h"
/** Implementing cleanChooseDBP_DLG */
class GetDBP_DLG : public cleanGetDBP_DLG
{
	protected:
		// Handlers for cleanChooseDBP_DLG events.
		void dUseDBP_OnClick(     wxCommandEvent& event );
		void dNewDBP_OnClick(     wxCommandEvent& event );
		void dSetDBP_OnClick(     wxCommandEvent& event );
		void dGetDBP_OnClick(     wxCommandEvent& event );
		void dDelDBP_OnClick(     wxCommandEvent& event );
		void dLoadDBP_OnClick(    wxCommandEvent& event );
		void dSaveDBP_OnClick(    wxCommandEvent& event );
		void dSetArea_RBOnClick(  wxCommandEvent& event );
		void dDBPName_LBOnSelect( wxCommandEvent& event );
		void GetDBP_DLGOnClose(   wxCloseEvent&   event );
	public:
		/** Constructor */
		GetDBP_DLG( wxWindow* parent );
	//// end generated class members
		// Arrays
		std::vector< wxCheckBox* > dAreaGet_CB;
		std::vector< wxCheckBox* > dAreaSet_CB;
		std::vector< DBP > dDBPList;
		std::vector< u16 >  dIdList;
		// Variables
		u16  fromID; // Highest used ID
		bool isModified;
		// Profile Functions
		s32   dNewDBP( DBP  dbp  );
		void  dSetDBP( s32  index, DBP  dbp  );
		DBP   dGetDBP( void );
		DBP&  dGetDBP( s32  index );
		void  dDelDBP( s32  index );
		void  dSetCount( s32 count );
		s32   dGetCount( void );
		void dShowDBP(   void );
		void dSaveDBP(   void );
		void dLoadDBP(   void );
		// Displayed Profile Functions
		s32   dNewDBI( DBI* dbi  );
		void  dSetDBI( s32  index, DBI* dbi  );
		DBI*  dGetDBI( DBI* dbi   );
		DBI*  dGetDBI( s32  index );
		void  dDelDBI( s32  index );
		void dLoadDBI( void );
};

#endif // __chooseDBP_DLG__