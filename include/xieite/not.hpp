#pragma once

#include <xieite/check.hpp>
#include <xieite/cat.hpp>
#include <xieite/probe.hpp>

#define XIEITE_NOT(x) XIEITE_CHECK(XIEITE_CAT_PRIM(XIEITE_DETAIL_NOT_, x))

#define XIEITE_DETAIL_NOT_0 XIEITE_PROBE(~)
