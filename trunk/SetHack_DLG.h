#ifndef __SetHack_DLG__
#define __SetHack_DLG__

/**
@file
Subclass of cleanSetHack_DLG, which is generated by wxFormBuilder.
*/

#include "cleanFRM.h"

//// end generated include

/** Implementing cleanSetHack_DLG */
class SetHack_DLG : public cleanSetHack_DLG
{
	protected:
		// Handlers for cleanSetHack_DLG events.
		void dSetHack_OnClick(  wxCommandEvent& event );
		void dLoadHack_OnClick( wxCommandEvent& event );
		void dSaveHack_OnClick( wxCommandEvent& event );
		void dNewCode_OnClick(  wxCommandEvent& event );
		void dSetCode_OnClick(  wxCommandEvent& event );
		void dGetCode_OnClick(  wxCommandEvent& event );
		void dDelCode_OnClick(  wxCommandEvent& event );
		void dCode_LCOnSelect(  wxListEvent&    event );
	public:
		/** Constructor */
		SetHack_DLG( wxWindow* parent );
	//// end generated class members
		HACK   dHack;
		s16    dIndex;
		u8     dRamCount;
		bool   dModified;
		CODE   dGetCode(  void );
		void   dDelCode(  s16  index );
		void   dShowCode( void );
		void   dShowCode( CODE code );
		void   dGetHack(  void );
		void   dSetHack(  void );
		void   dShowHack( void );
};

#endif // __SetHack_DLG__