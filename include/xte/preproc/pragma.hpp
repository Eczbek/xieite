#ifndef DETAIL_XTE_HEADER_PREPROC_PRAGMA
#	define DETAIL_XTE_HEADER_PREPROC_PRAGMA
#
#	include "../preproc/compiler.hpp"
#	include "../preproc/lang.hpp"
#	include "../preproc/quote.hpp"
#
#	if XTE_COMPILER_MSVC && XTE_LANG(CPP, <, 2011) && XTE_LANG(C, <, 1999)
#		define XTE_PRAGMA(...) __pragma(__VA_ARGS__)
#	else
#		define XTE_PRAGMA(...) _Pragma(XTE_QUOTE(__VA_ARGS__))
#	endif
#	define XTE_PRAGMA_GCC(...)
#	define XTE_PRAGMA_CLANG(...)
#	define XTE_PRAGMA_MSVC(...)
#
#	if XTE_COMPILER_GCC
#		undef XTE_PRAGMA_GCC
#		define XTE_PRAGMA_GCC(...) XTE_PRAGMA(__VA_ARGS__)
#	endif
#
#	if XTE_COMPILER_CLANG
#		undef XTE_PRAGMA_CLANG
#		define XTE_PRAGMA_CLANG(...) XTE_PRAGMA(__VA_ARGS__)
#	endif
#
#	if XTE_COMPILER_MSVC
#		undef XTE_PRAGMA_MSVC
#		define XTE_PRAGMA_MSVC(...) XTE_PRAGMA(__VA_ARGS__)
#	endif
#endif
