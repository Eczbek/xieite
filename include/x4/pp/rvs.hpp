#pragma once

#include "../pp/eval.hpp"
#include "../pp/scan.hpp"

#define X4RVS(...) __VA_OPT__(X4EVAL(DETAIL_X4RVS0(__VA_ARGS__)))

#define DETAIL_X4RVS0(x, ...) __VA_OPT__(DETAIL_X4RVS1 X4SCAN(()) (__VA_ARGS__),) x
#define DETAIL_X4RVS1() DETAIL_X4RVS0
