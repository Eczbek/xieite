#ifndef DETAIL_XTE_HEADER_PREPROC_CAT
#	define DETAIL_XTE_HEADER_PREPROC_CAT
#
#	define XTE_CAT(_x, ...) XTE_PCAT(_x, __VA_ARGS__)
#	define XTE_PCAT(_x, ...) _x##__VA_ARGS__
#endif
