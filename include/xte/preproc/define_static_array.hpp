#ifndef DETAIL_XTE_HEADER_PREPROC_DEFINE_STATIC_ARRAY
#	define DETAIL_XTE_HEADER_PREPROC_DEFINE_STATIC_ARRAY
#
#	include "../preproc/compiler.hpp"
#	include <meta>
#
#	if XTE_COMPILER_GCC && !XTE_COMPILER_CLANG
#		define XTE_DEFINE_STATIC_ARRAY(...) [:::std::meta::reflect_constant_array(__VA_ARGS__):]
#	else
#		define XTE_DEFINE_STATIC_ARRAY(...) (::std::define_static_array(__VA_ARGS__))
#	endif
#endif
