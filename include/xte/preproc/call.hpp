#ifndef DETAIL_XTE_HEADER_PREPROC_CALL
#	define DETAIL_XTE_HEADER_PREPROC_CALL
#
#	define XTE_CALL(...) __VA_ARGS__ DETAIL_XTE_CALL##__VA_OPT__(_)
#
#	define DETAIL_XTE_CALL(...) __VA_ARGS__
#	define DETAIL_XTE_CALL_(...) (__VA_ARGS__)
#endif
