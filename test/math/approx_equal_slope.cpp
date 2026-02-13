#include <xte/math/approx_equal_slope.hpp>
#include <limits>

static_assert(xte::approx_equal_slope(0.1 + 0.2, 0.3));
static_assert(!xte::approx_equal_slope(0, 1));

static_assert(!std::numeric_limits<double>::has_infinity || xte::approx_equal_slope(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()));
