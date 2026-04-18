#include <xte/math/rem.hpp>

static_assert(xte::rem(-3, 3) == (-3 % 3));
static_assert(xte::rem(-2, 3) == (-2 % 3));
static_assert(xte::rem(-1, 3) == (-1 % 3));
static_assert(xte::rem(0, 3) == (0 % 3));
static_assert(xte::rem(1, 3) == (1 % 3));
static_assert(xte::rem(2, 3) == (2 % 3));
static_assert(xte::rem(3, 3) == (3 % 3));
