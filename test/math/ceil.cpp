#include <xte/math/ceil.hpp>
#include <cmath>

static_assert(xte::ceil(1.5) == std::ceil(1.5));
static_assert(xte::ceil(1) == 1);
