#ifndef DETAIL_XTE_HEADER_PREPROC_EACH
#	define DETAIL_XTE_HEADER_PREPROC_EACH
#
#	include "../preproc/call.hpp"
#	include "../preproc/eval.hpp"
#	include "../preproc/paren.hpp"
#
#	define XTE_EACH(_op, ...) __VA_OPT__(XTE_EVAL(DETAIL_XTE_EACH(_op, __VA_ARGS__)))
#	define XTE_EACH_DELIM(_op, _delim, ...) __VA_OPT__(XTE_EVAL(DETAIL_XTE_EACH_DELIM(_op, _delim, __VA_ARGS__)))
#
#	define DETAIL_XTE_EACH(_op, _x, ...) _op(_x)__VA_OPT__(, DETAIL_XTE_EACH_ XTE_PAREN() (_op, __VA_ARGS__))
#	define DETAIL_XTE_EACH_DELIM(_op, _delim, _x, ...) XTE_CALL(_op)(_x) __VA_OPT__(_delim DETAIL_XTE_EACH_DELIM_ XTE_PAREN() (_op, _delim, __VA_ARGS__))
#	define DETAIL_XTE_EACH_() DETAIL_XTE_EACH
#	define DETAIL_XTE_EACH_DELIM_() DETAIL_XTE_EACH_DELIM
#endif
