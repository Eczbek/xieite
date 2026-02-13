#include <xte/math/min.hpp>
#include <limits>

static_assert(xte::min(0, 0) == 0);
static_assert(xte::min(0, 5) == 0);
static_assert(xte::min(-5, 5) == -5);
static_assert(xte::min(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::lowest());
