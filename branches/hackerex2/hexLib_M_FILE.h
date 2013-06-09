#include "hexLib_M_NAME.h"

#ifndef hexLib_M_FILE_h
#define hexLib_M_FILE_h

class hexLibDLL M_FILE : public M_NAME
{
private:
	bool m_fileC;
public:
	M_FILE( void );
	TxtA
		listMain;
	Text
		textPrevPath;
	btnArray
		btn_main;
	wxPanel
		*p____file;
	wxStaticBox
		*lbl__file;
	wxTextCtrl
		*tbox_file;
	void file_connect( void );
	void file_disconnect( void );
};

#endif