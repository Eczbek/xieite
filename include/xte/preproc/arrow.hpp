#ifndef DETAIL_XTE_HEADER_PREPROC_ARROW
#	define DETAIL_XTE_HEADER_PREPROC_ARROW
#
#	define XTE_ARROW(...) \
		noexcept __VA_OPT__((noexcept(__VA_ARGS__)) \
		-> decltype(auto) \
		requires(requires { __VA_ARGS__; })) \
		{ __VA_OPT__(return __VA_ARGS__;) }
#endif
