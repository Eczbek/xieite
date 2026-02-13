#include <xte/math/between.hpp>

static_assert(xte::between(5, 0, 10));
static_assert(!xte::between(0, 5, 10));
static_assert(xte::between(0, 0, 10));
static_assert(!xte::between(0, 0, 10, false, false));
static_assert(xte::between(10, 0, 10));
static_assert(!xte::between(10, 0, 10, false, false));
