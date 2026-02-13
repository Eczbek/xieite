#include <xte/math/diff.hpp>
#include <limits>

static_assert(xte::diff(5, -5) == 10);
static_assert(xte::diff(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max()) == std::numeric_limits<unsigned int>::max());
