#include <xte/math/float.hpp>
#include <cmath>

// TODO: is_finite, is_infinite, is_nan

static_assert(!xte::is_neg(0));
static_assert(!xte::is_neg(999));
static_assert(xte::is_neg(-1));
static_assert(xte::is_neg(-999));
static_assert(!xte::is_neg(-1u));

static_assert(xte::floor(1.5) == std::floor(1.5));
static_assert(xte::floor(1) == 1);

static_assert(xte::ceil(1.5) == std::ceil(1.5));
static_assert(xte::ceil(1) == 1);
