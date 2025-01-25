#pragma once

#include "../pp/check.hpp"
#include "../pp/cat.hpp"
#include "../pp/probe.hpp"

#define XIEITE_NOT(x) XIEITE_CHECK(XIEITE_CAT_PRIM(XIEITE_DETAIL_NOT_, x))

#define XIEITE_DETAIL_NOT_0 XIEITE_PROBE(~)
