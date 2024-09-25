#pragma once

#include <xieite/check.hpp>
#include <xieite/concatenate.hpp>
#include <xieite/probe.hpp>

#define XIEITE_NOT(value_) XIEITE_CHECK(XIEITE_CONCATENATE_PRIMITIVE(XIEITE_DETAIL_NOT_, value_))

#define XIEITE_DETAIL_NOT_0 XIEITE_PROBE(~)
