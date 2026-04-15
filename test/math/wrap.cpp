#include <xte/math/wrap.hpp>

static_assert(xte::wrap(0, 1, 5) == 4);
static_assert(xte::wrap(0, 5, 1) == 4);
static_assert(xte::wrap(6, -5) == -4);
