#ifndef DETAIL_XIEITE_HEADER_PP_EACH
#	define DETAIL_XIEITE_HEADER_PP_EACH
#
#	include "../pp/call.hpp"
#	include "../pp/eval.hpp"
#	include "../pp/paren.hpp"
#
#	define XIEITE_EACH(_fn, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_HELPER(_fn, __VA_ARGS__)))
#	define XIEITE_EACH_DELIM(_fn, _delim, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_DELIM_HELPER(_fn, _delim, __VA_ARGS__)))
#
#	define DETAIL_XIEITE_EACH_HELPER(_fn, _x, ...) _fn(_x)__VA_OPT__(, DETAIL_XIEITE_EACH_NEXT XIEITE_PAREN() (_fn, __VA_ARGS__))
#	define DETAIL_XIEITE_EACH_DELIM_HELPER(_fn, _delim, _x, ...) XIEITE_CALL(_fn)(_x) __VA_OPT__(_delim DETAIL_XIEITE_EACH_DELIM_NEXT XIEITE_PAREN() (_fn, _delim, __VA_ARGS__))
#	define DETAIL_XIEITE_EACH_NEXT() DETAIL_XIEITE_EACH_HELPER
#	define DETAIL_XIEITE_EACH_DELIM_NEXT() DETAIL_XIEITE_EACH_DELIM_HELPER
#endif
