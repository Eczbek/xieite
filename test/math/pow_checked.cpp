#include <xte/math/pow_checked.hpp>

static_assert(*xte::pow_checked(50, 2) == 2500);
static_assert(!xte::pow_checked(50000, 2));
