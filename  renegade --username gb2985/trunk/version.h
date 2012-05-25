#ifndef VERSION_H_
#define VERSION_H_

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "25";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2012";
	static const char UBUNTU_VERSION_STYLE[] = "12.05";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 0;
	static const long BUILD = 1;
	static const long REVISION = 0;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1564;
	#define RC_FILEVERSION 1,0,1,0
	#define RC_FILEVERSION_STRING "1, 0, 1, 0\0"
	static const char FULLVERSION_STRING[] = "1.0.1.0";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 46;
	

}
#endif //VERSION_H_
