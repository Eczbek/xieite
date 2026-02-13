#ifndef DETAIL_XTE_HEADER_PREPROC_IF
#	define DETAIL_XTE_HEADER_PREPROC_IF
#
#	include "../preproc/eat.hpp"
#	include "../preproc/scan.hpp"
#
#	define XTE_IF(_cond) XTE_IIF(_cond)
#	define XTE_IIF(_cond) DETAIL_XTE_IIF##_cond
#
#	define DETAIL_XTE_IIF0(...) XTE_SCAN
#	define DETAIL_XTE_IIF1(...) __VA_ARGS__ XTE_EAT
#endif
