#include <xte/math/div_ceil.hpp>
#include <limits>

static_assert(xte::div_ceil(5, 2) == 3);
static_assert(xte::div_ceil(-5, 2) == -2);
static_assert(xte::div_ceil(5, -2) == -2);
static_assert(xte::div_ceil(-5, -2) == 3);

static_assert(xte::div_ceil(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
