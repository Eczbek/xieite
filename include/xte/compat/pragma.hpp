#ifndef DETAIL_XTE_HEADER_PREPROC_PRAGMA
#	define DETAIL_XTE_HEADER_PREPROC_PRAGMA
#
#	include "../detect/compiler.hpp"
#	include "../detect/lang.hpp"
#
#	if XTE_COMPILER_GCC
#		define XTE_PRAGMA_GCC(...) XTE_PRAGMA(__VA_ARGS__##__VA_OPT__())
#	else
#		define XTE_PRAGMA_GCC(...)
#	endif
#	if XTE_COMPILER_CLANG
#		define XTE_PRAGMA_CLANG(...) XTE_PRAGMA(__VA_ARGS__##__VA_OPT__())
#	else
#		define XTE_PRAGMA_CLANG(...)
#	endif
#	if XTE_COMPILER_MSVC
#		define XTE_PRAGMA_MSVC(...) XTE_PRAGMA(__VA_ARGS__##__VA_OPT__())
#	else
#		define XTE_PRAGMA_MSVC(...)
#	endif
#	if !XTE_COMPILER_MSVC || XTE_LANG(CPP, >=, 2011) || XTE_LANG(C, >=, 1999)
#		define XTE_PRAGMA(...) _Pragma(#__VA_ARGS__)
#	else
#		define XTE_PRAGMA(...) __pragma(__VA_ARGS__)
#	endif
#endif
