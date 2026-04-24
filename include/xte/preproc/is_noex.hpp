#ifndef DETAIL_XTE_HEADER_PREPROC_IS_NOEX
#	define DETAIL_XTE_HEADER_PREPROC_IS_NOEX
#
#	define XTE_IS_NOEX(...) requires { requires(noexcept(__VA_ARGS__)); }
#endif
