#pragma once

#include <xieite/eval.hpp>
#include <xieite/scan.hpp>

#define XIEITE_REV(...) __VA_OPT__(XIEITE_EVAL(XIEITE_DETAIL_REV_HELPER(__VA_ARGS__)))

#define XIEITE_DETAIL_REV_HELPER(x, ...) __VA_OPT__(XIEITE_DETAIL_REV_NEXT XIEITE_SCAN(()) (__VA_ARGS__),) x
#define XIEITE_DETAIL_REV_NEXT() XIEITE_DETAIL_REV_HELPER
