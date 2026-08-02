#include <xte/util/make.hpp>
#include <cfloat>

static_assert(xte::make<int>(1.5) == 1);
static_assert(xte::make<unsigned char>(65535.1234) == 255);

struct S {
	int x;
	int y;
};
static_assert(xte::make<S>(1, 2).x == 1);
static_assert(xte::make<S>(1, 2).y == 2);

static_assert(xte::make<int>(INFINITY) == 0);
static_assert(xte::make<int>(NAN) == 0);
