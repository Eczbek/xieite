#include <xte/math/floor.hpp>
#include <cmath>

static_assert(xte::floor(1.5) == std::floor(1.5));
static_assert(xte::floor(1) == 1);
