#pragma once

#include "../pp/check.hpp"
#include "../pp/cat.hpp"
#include "../pp/probe.hpp"

#define XIEITE_NOT(x) XIEITE_CHECK(XIEITE_PCAT(DETAIL_XIEITE_NOT_, x))

#define DETAIL_XIEITE_NOT_0 XIEITE_PROBE(~)
