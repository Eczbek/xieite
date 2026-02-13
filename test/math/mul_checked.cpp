#include <xte/math/mul_checked.hpp>

static_assert(xte::mul_checked(0));
static_assert(*xte::mul_checked(0) == 0);
static_assert(xte::mul_checked(2, 2));
static_assert(*xte::mul_checked(2, 2) == 4);
static_assert(xte::mul_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
static_assert(*xte::mul_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800);

static_assert(!xte::mul_checked(-1u, 2u));
