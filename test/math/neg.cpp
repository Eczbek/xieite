#include <xte/math/neg.hpp>

static_assert(!xte::neg(0));
static_assert(!xte::neg(999));
static_assert(xte::neg(-1));
static_assert(xte::neg(-999));
static_assert(!xte::neg(-1u));
