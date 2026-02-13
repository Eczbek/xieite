#ifndef DETAIL_XTE_HEADER_PREPROC_REMOVE_EMPTY
#	define DETAIL_XTE_HEADER_PREPROC_REMOVE_EMPTY
#
#	include "../preproc/any.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/if.hpp"
#	include "../preproc/paren.hpp"
#
#	define XTE_REMOVE_EMPTY(_x, ...) _x __VA_OPT__(XTE_EVAL(DETAIL_XTE_REMOVE_EMPTY(__VA_ARGS__)))
#
#	define DETAIL_XTE_REMOVE_EMPTY(_x, ...) XTE_IF(XTE_ANY(_x))(,)() _x __VA_OPT__(DETAIL_XTE_REMOVE_EMPTY_ XTE_PAREN()(__VA_ARGS__))
#	define DETAIL_XTE_REMOVE_EMPTY_() DETAIL_XTE_REMOVE_EMPTY
#endif
