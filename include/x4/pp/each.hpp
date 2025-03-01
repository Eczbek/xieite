#pragma once

#include "../pp/eval.hpp"
#include "../pp/scan.hpp"

#define X4EACH(m, ...) __VA_OPT__(X4EVAL(DETAIL_X4EACHHELPER(m, __VA_ARGS__)))
#define X4EACHDELIM(m, delim, ...) __VA_OPT__(X4EVAL(DETAIL_X4EACHDELIMHELPER(m, delim, __VA_ARGS__)))

#define DETAIL_X4EACHHELPER(m, x, ...) m(x)__VA_OPT__(, DETAIL_X4EACHNEXT X4SCAN(()) (m, __VA_ARGS__))
#define DETAIL_X4EACHDELIMHELPER(m, delim, x, ...) m(x)__VA_OPT__(delim DETAIL_X4EACHDELIMNEXT X4SCAN(()) (m, delim, __VA_ARGS__))
#define DETAIL_X4EACHNEXT() DETAIL_X4EACHHELPER
#define DETAIL_X4EACHDELIMNEXT() DETAIL_X4EACHDELIMHELPER
