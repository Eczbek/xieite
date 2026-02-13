#include <xte/math/div_checked.hpp>
#include <limits>

static_assert(xte::div_checked(0));
static_assert(*xte::div_checked(0) == 0);
static_assert(xte::div_checked(1, 2));
static_assert(*xte::div_checked(1, 2) == 0);
static_assert(xte::div_checked(64, 4, 2));
static_assert(*xte::div_checked(64, 4, 2) == 8);

static_assert(!xte::div_checked(3, 0));
static_assert(!xte::div_checked(std::numeric_limits<int>::min(), -1));
