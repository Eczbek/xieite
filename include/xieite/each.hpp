#pragma once

#include <xieite/evaluate.hpp>
#include <xieite/scan.hpp>

#define XIEITE_EACH(macro_, ...) __VA_OPT__(XIEITE_EVALUATE(XIEITE_DETAIL_EACH_HELPER(macro_, __VA_ARGS__)))

#define XIEITE_DETAIL_EACH_HELPER(macro_, first_, ...) macro_(first_) __VA_OPT__(XIEITE_DETAIL_EACH_INDIRECT XIEITE_SCAN(()) (macro_, __VA_ARGS__))
#define XIEITE_DETAIL_EACH_INDIRECT() XIEITE_DETAIL_EACH_HELPER
