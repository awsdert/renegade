#ifndef VERSION_H_
#define VERSION_H_

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "21";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2012";
	static const char UBUNTU_VERSION_STYLE[] = "12.06";
	
	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 6;
	static const long BUILD = 6;
	static const long REVISION = 0;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 2576;
	#define RC_FILEVERSION 1,6,6,0
	#define RC_FILEVERSION_STRING "1, 6, 6, 0\0"
	static const char FULLVERSION_STRING[] = "1.6.6.0";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 34;
	

}
#endif //VERSION_H_
