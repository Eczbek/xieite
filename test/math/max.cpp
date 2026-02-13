#include <xte/math/max.hpp>
#include <limits>

static_assert(xte::max(0, 0) == 0);
static_assert(xte::max(0, 5) == 5);
static_assert(xte::max(-5, 5) == 5);
static_assert(xte::max(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::max());
