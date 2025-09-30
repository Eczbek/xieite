#ifndef DETAIL_XTE_HEADER_PREPROC_FWD
#	define DETAIL_XTE_HEADER_PREPROC_FWD
#
#	define XTE_FWD(...) static_cast<decltype(__VA_ARGS__)&&>(__VA_ARGS__)
#endif
