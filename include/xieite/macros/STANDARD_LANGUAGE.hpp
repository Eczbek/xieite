#ifndef XIEITE_HEADER_MACROS_STANDARD_LANGUAGE
#	define XIEITE_HEADER_MACROS_STANDARD_LANGUAGE

#	define XIEITE_STANDARD_LANGUAGE_C_1989 false
#	define XIEITE_STANDARD_LANGUAGE_C_1990 false
#	ifdef __STDC__
#		define XIEITE_STANDARD_LANGUAGE_C_1989 true
#		define XIEITE_STANDARD_LANGUAGE_C_1990 true
#	endif

#	ifdef __STDC_VERSION__
#		define XIEITE_STANDARD_LANGUAGE_C_1994 false
#		if (__STDC_VERSION__ >= 199409)
#			define XIEITE_STANDARD_LANGUAGE_C_1994 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_C_1999 false
#		if (__STDC_VERSION__ >= 199901)
#			define XIEITE_STANDARD_LANGUAGE_C_1999 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_C_2011 false
#		if (__STDC_VERSION__ >= 201112)
#			define XIEITE_STANDARD_LANGUAGE_C_2011 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_C_2018 false
#		if (__STDC_VERSION__ >= 201710)
#			define XIEITE_STANDARD_LANGUAGE_C_2018 true
#		endif
#	endif

#	ifdef __cplusplus
#		define XIEITE_STANDARD_LANGUAGE_CPP_1998 false
#		if (__cplusplus >= 199711)
#			define XIEITE_STANDARD_LANGUAGE_CPP_1998 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_CPP_2011 false
#		if (__cplusplus >= 201103)
#			define XIEITE_STANDARD_LANGUAGE_CPP_2011 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_CPP_2014 false
#		if (__cplusplus >= 201402)
#			define XIEITE_STANDARD_LANGUAGE_CPP_2014 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_CPP_2017 false
#		if (__cplusplus >= 201703)
#			define XIEITE_STANDARD_LANGUAGE_CPP_2017 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_CPP_2020 false
#		if (__cplusplus >= 202002)
#			define XIEITE_STANDARD_LANGUAGE_CPP_2020 true
#		endif

#		define XIEITE_STANDARD_LANGUAGE_CPP_2023 false
#		if (__cplusplus >= 202100)
#			define XIEITE_STANDARD_LANGUAGE_CPP_2023 true
#		endif
#	endif

#	define XIEITE_STANDARD_LANGUAGE_CPP_CLI false
#	if defined(__cplusplus_cli) && (__cplusplus_cli >= 200406)
#		define XIEITE_STANDARD_LANGUAGE_CPP_CLI true
#	endif

#	define XIEITE_STANDARD_LANGUAGE_CPP_EMBEDDED false
#	ifdef __embedded_cplusplus
#		define XIEITE_STANDARD_LANGUAGE_CPP_EMBEDDED true
#	endif

#endif
