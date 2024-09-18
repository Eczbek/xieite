#pragma once

#include <xieite/at.hpp>

#define XIEITE_CHECK(...) XIEITE_AT_1(__VA_ARGS__, 0,)
