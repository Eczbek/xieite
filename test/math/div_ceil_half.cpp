#include <xte/math/div_ceil_half.hpp>
#include <limits>

static_assert(xte::div_ceil_half(7, 2) == 4);
static_assert(xte::div_ceil_half(-7, 2) == -3);
static_assert(xte::div_ceil_half(7, -2) == -3);
static_assert(xte::div_ceil_half(-7, -2) == 4);

static_assert(xte::div_ceil_half(7, 3) == 2);
static_assert(xte::div_ceil_half(-7, 3) == -2);
static_assert(xte::div_ceil_half(7, -3) == -2);
static_assert(xte::div_ceil_half(-7, -3) == 2);

static_assert(xte::div_ceil_half(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
