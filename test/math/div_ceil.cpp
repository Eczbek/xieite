#include <xte/math/div_ceil.hpp>

static_assert(xte::div_ceil(5, 2) == 3);
static_assert(xte::div_ceil(-5, 2) == -2);
