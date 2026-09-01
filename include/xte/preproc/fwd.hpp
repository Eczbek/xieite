#ifndef DETAIL_XTE_HEADER_PREPROC_FWD
#	define DETAIL_XTE_HEADER_PREPROC_FWD
#
#	define XTE_FWD(X) static_cast<decltype(X)&&>(X)
#endif
