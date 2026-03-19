#include <xte/util/as.hpp>

static_assert(xte::as<int>(1.5) == 1);

struct S {
	int x;
	int y;
};
static_assert(xte::as<S>(1, 2).x == 1);
static_assert(xte::as<S>(1, 2).y == 2);
