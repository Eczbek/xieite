#ifndef DETAIL_XIEITE_HEADER_PP_CAT
#	define DETAIL_XIEITE_HEADER_PP_CAT
#
#	define XIEITE_CAT(_x, ...) XIEITE_PCAT(_x, __VA_ARGS__)
#	define XIEITE_CATR(_x, ...) XIEITE_PCATR(_x, __VA_ARGS__)
#	define XIEITE_PCAT(_x, ...) _x##__VA_ARGS__
#	define XIEITE_PCATR(_x, ...) __VA_ARGS__##_x
#	define XIEITE_CAT_A(_x) XIEITE_PCAT(_x,
#	define XIEITE_CAT_B(_x) XIEITE_PCATR(_x,
#endif
