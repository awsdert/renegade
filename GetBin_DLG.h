#ifndef __GetBin_DLG__
#define __GetBin_DLG__

/**
@file
Subclass of cleanGetBin_DLG, which is generated by wxFormBuilder.
*/

#include "cleanFRM.h"

//// end generated include

/** Implementing cleanGetBin_DLG */
class GetBin_DLG : public cleanGetBin_DLG
{
	protected:
		// Handlers for cleanGetBin_DLG events.
		void GetBin_DLGOnClose(     wxCloseEvent&   event );
		void dOrgName_LBOnSelect( wxCommandEvent& event );
		void dBinPath_BOnClick(   wxCommandEvent& event );
		void dBinBind_BOnClick(   wxCommandEvent& event );
		void dUseBin_OnClick(    wxCommandEvent& event );
		void dLoadBin_OnClick(   wxCommandEvent& event );
		void dSaveBin_OnClick(   wxCommandEvent& event );
		void dNewBin_OnClick(    wxCommandEvent& event );
		void dSetBin_OnClick(    wxCommandEvent& event );
		void dDelBin_OnClick(    wxCommandEvent& event );
		void dNewRam_BOnClick(    wxCommandEvent& event );
		void dSetRam_BOnClick(    wxCommandEvent& event );
	public:
		/** Constructor */
		GetBin_DLG( wxWindow* parent );
	//// end generated class members
		xStr dTitle;
		xStr dVendor;
		xStr dSlash;
		// Methods
		s8    dNewBin( BIN* bin   );
		s8    dSetBin( s8   index, BIN* bin  );
		BIN*  dGetBin( s8   index );
		BIN*  dGetBin( BIN* bin   );
		BIN*  dGetBin( void );
		RAM   dGetRam( void );
		void dShowBin( void );
		void dShowRam( void );
		void dSaveBin( void );
		void dLoadBin( void );
};

#endif // __GetBin_DLG__
