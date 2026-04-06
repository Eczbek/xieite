#include <xte/math/is_neg.hpp>

static_assert(!xte::is_neg(0));
static_assert(!xte::is_neg(999));
static_assert(xte::is_neg(-1));
static_assert(xte::is_neg(-999));
static_assert(!xte::is_neg(-1u));
