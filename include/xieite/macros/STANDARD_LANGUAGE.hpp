#ifndef XIEITE_HEADER_MACROS_STANDARD_LANGUAGE
#	define XIEITE_HEADER_MACROS_STANDARD_LANGUAGE

#	if defined(__STDC__)
#		define XIEITE_STANDARD_LANGUAGE_C_1989
#		define XIEITE_STANDARD_LANGUAGE_C_1990
#	endif

#	if defined(__STDC_VERSION__)
#		if __STDC_VERSION__ >= 199409
#			define XIEITE_STANDARD_LANGUAGE_C_1994
#		endif

#		if __STDC_VERSION__ >= 199901
#			define XIEITE_STANDARD_LANGUAGE_C_1999
#		endif

#		if __STDC_VERSION__ >= 201112
#			define XIEITE_STANDARD_LANGUAGE_C_2011
#		endif

#		if __STDC_VERSION__ >= 201710
#			define XIEITE_STANDARD_LANGUAGE_C_2018
#		endif
#	endif

#	if defined(__cplusplus)
#		if __cplusplus >= 199711
#			define XIEITE_STANDARD_LANGUAGE_CPP_1998
#		endif

#		if __cplusplus >= 201103
#			define XIEITE_STANDARD_LANGUAGE_CPP_2011
#		endif

#		if __cplusplus >= 201402
#			define XIEITE_STANDARD_LANGUAGE_CPP_2014
#		endif

#		if __cplusplus >= 201703
#			define XIEITE_STANDARD_LANGUAGE_CPP_2017
#		endif

#		if __cplusplus >= 202002
#			define XIEITE_STANDARD_LANGUAGE_CPP_2020
#		endif

#		if __cplusplus >= 202100
#			define XIEITE_STANDARD_LANGUAGE_CPP_2023
#		endif
#	endif

#	if defined(__cplusplus_cli) && (__cplusplus_cli >= 200406)
#		define XIEITE_STANDARD_LANGUAGE_CPP_CLI
#	endif

#	if defined(__embedded_cplusplus)
#		define XIEITE_STANDARD_LANGUAGE_CPP_EMBEDDED
#	endif

#endif
