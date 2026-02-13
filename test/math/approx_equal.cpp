#include <xte/math/approx_equal.hpp>

static_assert(xte::approx_equal(0.1 + 0.2, 0.3));
static_assert(!xte::approx_equal(0, 1));
