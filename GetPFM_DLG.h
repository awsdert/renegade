#ifndef __GetPFM_DLG__
#define __GetPFM_DLG__

/**
@file
Subclass of cleanGetPFM_DLG, which is generated by wxFormBuilder.
*/

#include "cleanFRM.h"

//// end generated include

/** Implementing cleanGetPFM_DLG */
class GetPFM_DLG : public cleanGetPFM_DLG
{
	protected:
		// Handlers for cleanGetPFM_DLG events.
		void GetPFM_DLGOnClose(     wxCloseEvent&   event );
		void dPFMName_LBOnSelect( wxCommandEvent& event );
		void dLoadPFM_OnClick(   wxCommandEvent& event );
		void dSavePFM_OnClick(   wxCommandEvent& event );
		void  dNewPFM_OnClick(   wxCommandEvent& event );
		void  dSetPFM_OnClick(   wxCommandEvent& event );
		void  dUsePFM_OnClick(   wxCommandEvent& event );
		void  dDelPFM_OnClick(   wxCommandEvent& event );
	public:
		/** Constructor */
		GetPFM_DLG( wxWindow* parent );
	//// end generated class members
		bool isModified;
		// Methods
		s8    dNewPFM( PFM* pfm   );
		s8    dSetPFM( s8   index, PFM* pfm  );
		PFM*  dGetPFM( s8   index );
		PFM*  dGetPFM( PFM* pfm   );
		PFM*  dGetPFM( void );
		void dShowPFM( void );
		void dSavePFM( void );
		void dLoadPFM( void );

};

#endif // __GetPFM_DLG__