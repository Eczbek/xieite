#include <xte/math/digits.hpp>

static_assert(xte::digits(0) == 1);
static_assert(xte::digits(123) == 3);
static_assert(xte::digits(123, 10) == 3);
static_assert(xte::digits(0b1010, 2) == 4);
static_assert(xte::digits(1+1+1+1+1, 1) == 5);
