#ifndef DETAIL_XIEITE_HEADER_PP_TYPEOF
#	define DETAIL_XIEITE_HEADER_PP_TYPEOF
#
#	ifdef __cplusplus
#		define XIEITE_TYPEOF(...) decltype(__VA_ARGS__)
#	else
#		define XIEITE_TYPEOF(...) typeof(__VA_ARGS__)
#	endif
#endif
