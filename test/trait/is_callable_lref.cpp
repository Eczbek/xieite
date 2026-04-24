#include <xte/trait/is_callable_lref.hpp>

static_assert(xte::is_callable_lref<void(int), void(int)>);

struct A {
	void operator()(int) && {}
};
static_assert(!xte::is_callable_lref<A, void(int)>);
