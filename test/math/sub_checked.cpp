#include <xte/math/sub_checked.hpp>

static_assert(xte::sub_checked(0));
static_assert(*xte::sub_checked(0) == 0);
static_assert(xte::sub_checked(2, 1));
static_assert(*xte::sub_checked(2, 1) == 1);
static_assert(xte::sub_checked(10, 9, 8, 7, 6, 5, 4, 3, 2, 1));
static_assert(*xte::sub_checked(10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == -35);

static_assert(!xte::sub_checked(0u, 1u));
