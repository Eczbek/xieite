#ifndef DETAIL_XIEITE_HEADER_PP_TYPE
#	define DETAIL_XIEITE_HEADER_PP_TYPE
#
#	ifdef __cplusplus
#		define XIEITE_TYPE(...) decltype(__VA_ARGS__)
#	else
#		define XIEITE_TYPE(...) typeof(__VA_ARGS__)
#	endif
#endif
