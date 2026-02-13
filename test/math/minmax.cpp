#include <xte/math/minmax.hpp>

constexpr auto [min, max] = xte::minmax(5, -5);
static_assert(min == -5);
static_assert(max == 5);
