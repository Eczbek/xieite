#ifndef DETAIL_XTE_HEADER_PREPROC_IF
#	define DETAIL_XTE_HEADER_PREPROC_IF
#
#	include "../preproc/eat.hpp"
#	include "../preproc/scan.hpp"
#
#	define XTE_IF(B) XTE_IIF(B)
#	define XTE_IIF(B) DETAIL_XTE_IIF##B
#
#	define DETAIL_XTE_IIF0(...) XTE_SCAN
#	define DETAIL_XTE_IIF1(...) __VA_ARGS__ XTE_EAT
#endif
