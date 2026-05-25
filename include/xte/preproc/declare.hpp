#ifndef DETAIL_XTE_HEADER_PREPROC_DECLARE
#	define DETAIL_XTE_HEADER_PREPROC_DECLARE
#
#	include "../preproc/unwrap.hpp"
#
#	define XTE_DECLARE(DECL, ...) \
		requires(requires { __VA_ARGS__; }) \
		XTE_UNWRAP(DECL) = __VA_ARGS__
#	define XTE_DECLARE_TYPE(DECL, ...) \
		requires(requires { typename[:^^__VA_ARGS__:]; }) \
		XTE_UNWRAP(DECL) : __VA_ARGS__
#endif
