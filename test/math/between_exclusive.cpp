#include <xte/math/between_exclusive.hpp>

static_assert(xte::between_exclusive(5, 0, 10));
static_assert(!xte::between_exclusive(0, 0, 10));
static_assert(!xte::between_exclusive(10, 0, 10));
