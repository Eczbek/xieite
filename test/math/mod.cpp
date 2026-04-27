#include <xte/math/mod.hpp>

static_assert(xte::mod(3, 8) == 3);
static_assert(xte::mod(-3, 8) == 5);
static_assert(xte::mod(3, -8) == -5);
static_assert(xte::mod(-3, -8) == -3);

static_assert(xte::mod(-21, 4) == 3);
