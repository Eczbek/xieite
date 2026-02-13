#include <xte/math/add_checked.hpp>

static_assert(xte::add_checked(0));
static_assert(*xte::add_checked(0) == 0);
static_assert(xte::add_checked(1, 2));
static_assert(*xte::add_checked(1, 2) == 3);
static_assert(xte::add_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
static_assert(*xte::add_checked(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);

static_assert(!xte::add_checked(-1u, 1u));
