#pragma once

#include <xieite/macros/DEFER.hpp>
#include <xieite/macros/EMPTY.hpp>

#define XIEITE_OBSTRUCT(...) \
	__VA_ARGS__ XIEITE_DEFER(XIEITE_EMPTY)()
