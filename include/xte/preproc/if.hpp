#ifndef DETAIL_XTE_HEADER_PREPROC_IF
#	define DETAIL_XTE_HEADER_PREPROC_IF
#
#	include "../preproc/eat.hpp"
#	include "../preproc/scan.hpp"
#
#	define XTE_IF(...) XTE_IIF(__VA_ARGS__)
#	define XTE_IIF(_cond) DETAIL_XTE_IIF_##_cond
#
#	define DETAIL_XTE_IIF_0(...) XTE_SCAN
#	define DETAIL_XTE_IIF_1(...) __VA_ARGS__ XTE_EAT
#endif
