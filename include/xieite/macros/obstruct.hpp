#pragma once

#include "../macros/defer.hpp"
#include "../macros/empty.hpp"

#define XIEITE_OBSTRUCT(...) __VA_ARGS__ XIEITE_DEFER(XIEITE_EMPTY)()
