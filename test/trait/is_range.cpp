#include <xte/trait/is_range.hpp>

struct S {
	int* begin();
	int* end();
};

static_assert(xte::is_range<S>);
static_assert(xte::is_range<int[5]>);
