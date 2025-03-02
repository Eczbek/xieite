#pragma once

#include "../pp/call.hpp"
#include "../pp/eval.hpp"
#include "../pp/scan.hpp"

#define XIEITE_EACH(m, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_HELPER(m, __VA_ARGS__)))
#define XIEITE_EACH_DELIM(m, delim, ...) __VA_OPT__(XIEITE_EVAL(DETAIL_XIEITE_EACH_DELIM_HELPER(m, delim, __VA_ARGS__)))

#define DETAIL_XIEITE_EACH_HELPER(m, x, ...) m(x)__VA_OPT__(, DETAIL_XIEITE_EACH_NEXT XIEITE_SCAN(()) (m, __VA_ARGS__))
#define DETAIL_XIEITE_EACH_DELIM_HELPER(m, delim, x, ...) XIEITE_CALL(m)(x)__VA_OPT__(delim DETAIL_XIEITE_EACH_DELIM_NEXT XIEITE_SCAN(()) (m, delim, __VA_ARGS__))
#define DETAIL_XIEITE_EACH_NEXT() DETAIL_XIEITE_EACH_HELPER
#define DETAIL_XIEITE_EACH_DELIM_NEXT() DETAIL_XIEITE_EACH_DELIM_HELPER
