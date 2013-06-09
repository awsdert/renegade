#include "hex2_wxFB.h"
#include "hexLib_main.h"

#ifndef HEXGUI_G
#define HEXGUI_G

/**
@file
Subclass of HexGUI, which is generated by wxFormBuilder.
*/
const int NO_OF_PANELS = 18;
class G : public HexGUI
{
	public:
		G( wxWindow* parent, bool user = false ); ~G();
		/** Internal Stuff */
		bool m_bCwd;
		hexGui m_gui;
		// List
		bool	m_bListCfg;
		// GUI
		wxPanel* m_aPanels[ NO_OF_PANELS ];
		void	ShowPanels( int inMode, bool inCfg );
		void	UpdatePanels();
		void	UpdateList( hexLib& db, Text name = getGlobalName() );
		void	UpdateTheme( Text name = wxT(""), si32 size = 22 );
		bool	Find( HANDLE& hApp, BinF& hBin );
		bool	Read( HANDLE& hApp, BinF& hBin );
		bool	Read( HANDLE& hApp, BinF& hBin, wxTextCtrl* oText );
		// Shared DB Functions
		bool	CheckFilesT( hexLib& db, Text& path, Text& leaf, Text& ext, Text& subP );
		bool	CheckDirs( hexLib& db, Text& path, Text& leaf );
		void	ShowData( hexLib& db );
		bool	EditHasInvalidName( Text& name );
		void	EditData( hexLib& db );
		/** Sessions **/
		void	LoadStateD( State& obj );
		void	ShowStateD( State& obj );
		/** Organisations **/
		void	ShowOrgD( Org* obj );
		bool	EditOrgD( Org* obj );
		/** Platforms */
		void	ShowPfmD( Pfm& obj );
		bool	EditPfmD( Pfm& obj );
		/** Binaries ( Applications / Files ) */
		void	ShowBinD( Bin& obj );
		bool	EditBinD( Bin& obj );
		void	ShowRamD( Ram& obj );
		void	EditRamD( Ram& obj );
		/** Profiles ( Hacklists ) */
		void	ShowPflD( Pfl& obj );
		bool	EditPflD( Pfl& obj );
		void	ShowRegion( ui32 region );
		ui32	EditRegion( void );
		/** Formats **/
		void	ShowFormat( Fmt& obj );
		/** Hacklist */
		void	ListHcks( Hacks& data );
		void	ShowHack( Hacks& data, int hackNo = 0 );
		bool	EditHack( Hacks& data, int hackNo = 0 );
		void	ShowCode( Code& obj );
		bool	EditCode( Code& obj );
		void	ShowCodeValue( wxTextCtrl* tbox, Code& obj, int v );
		void	EditCodeValue( wxTextCtrl* tbox, Code& obj, int v );
};

#endif