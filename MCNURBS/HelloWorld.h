#pragma once



#ifdef _USRDLL
	#ifdef MCNURBSDLL_EXPORTS
		#define MCNURBSDLL_API __declspec(dllexport)
	#else
		#define MCNURBSDLL_API __declspec(dllimport)
	#endif
#else
	#define MCNURBSDLL_API ;
#endif


#include <string>


namespace MCNURBS {


MCNURBSDLL_API std::string HelloWorld ();


}
