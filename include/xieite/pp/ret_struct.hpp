#ifndef DETAIL_XIEITE_HEADER_PP_RET_STRUCT
#	define DETAIL_XIEITE_HEADER_PP_RET_STRUCT
#
#	include "../pp/cat.hpp"
#
#	define XIEITE_RET_STRUCT(...) DETAIL_XIEITE_RET_STRUCT(XIEITE_CAT(DETAIL_XIEITE_struct_, __COUNTER__), __VA_ARGS__)
#
#	define DETAIL_XIEITE_RET_STRUCT(_name, ...) \
		struct _name __VA_ARGS__; \
		return _name
#endif
