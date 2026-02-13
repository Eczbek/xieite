#ifndef DETAIL_XTE_HEADER_PREPROC_DECLARE
#	define DETAIL_XTE_HEADER_PREPROC_DECLARE
#
#	include "../preproc/unwrap.hpp"
#
#	define XTE_DECLARE(_declaration, ...) \
		requires(requires { __VA_ARGS__; }) \
		XTE_UNWRAP(_declaration) = __VA_ARGS__
#	define XTE_DECLARE_TYPE(_declaration, ...) \
		requires(requires { typename[:^^__VA_ARGS__:]; }) \
		XTE_UNWRAP(_declaration) : __VA_ARGS__
#endif
