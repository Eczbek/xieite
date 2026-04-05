#include <xte/util/cast.hpp>

static_assert(xte::cast<int>(1.5) == 1);

struct S {
	int x;
	int y;
};
static_assert(xte::cast<S>(1, 2).x == 1);
static_assert(xte::cast<S>(1, 2).y == 2);
