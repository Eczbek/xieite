#include <xte/math/bit_at.hpp>

static_assert(xte::bit_at(0b1010, 0) == 0);
static_assert(xte::bit_at(0b1010, 1) == 1);
static_assert(xte::bit_at(0b1010, 2) == 0);
static_assert(xte::bit_at(0b1010, 3) == 1);
