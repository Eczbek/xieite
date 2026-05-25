#ifndef DETAIL_XTE_HEADER_PREPROC_CAT
#	define DETAIL_XTE_HEADER_PREPROC_CAT
#
#	define XTE_CAT(X, ...) XTE_PCAT(X, __VA_ARGS__)
#	define XTE_PCAT(X, ...) X##__VA_ARGS__
#endif
