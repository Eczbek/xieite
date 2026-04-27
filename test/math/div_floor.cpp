#include <xte/math/div_floor.hpp>
#include <limits>

static_assert(xte::div_floor(5, 2) == 2);
static_assert(xte::div_floor(-5, 2) == -3);
static_assert(xte::div_floor(5, -2) == -3);
static_assert(xte::div_floor(-5, -2) == 2);

static_assert(xte::div_floor(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
