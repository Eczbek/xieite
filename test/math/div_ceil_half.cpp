#include <xte/math/div_ceil_half.hpp>

static_assert(xte::div_ceil_half(7, 2) == 4);
static_assert(xte::div_ceil_half(7, 3) == 2);
