#pragma once

#include "../pp/call.hpp"
#include "../pp/eval.hpp"
#include "../pp/scan.hpp"

#define XIEITE_EACH(f, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_HELPER(f, __VA_ARGS__)))
#define XIEITE_EACH_DELIM(f, delim, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_DELIM_HELPER(f, delim, __VA_ARGS__)))

#define DETAIL_XIEITE_EACH_HELPER(f, x, ...) f(x)__VA_OPT__(, DETAIL_XIEITE_EACH_NEXT XIEITE_SCAN(()) (f, __VA_ARGS__))
#define DETAIL_XIEITE_EACH_DELIM_HELPER(f, delim, x, ...) XIEITE_CALL(f)(x) __VA_OPT__(delim DETAIL_XIEITE_EACH_DELIM_NEXT XIEITE_SCAN(()) (f, delim, __VA_ARGS__))
#define DETAIL_XIEITE_EACH_NEXT() DETAIL_XIEITE_EACH_HELPER
#define DETAIL_XIEITE_EACH_DELIM_NEXT() DETAIL_XIEITE_EACH_DELIM_HELPER
