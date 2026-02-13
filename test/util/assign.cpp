#include <xte/util/assign.hpp>

static_assert(([] {
	int x;
	xte::assign(x, 1.5);
	return x == 1;
})());
