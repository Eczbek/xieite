#include <xte/trait/is_callable_lvalue.hpp>

static_assert(xte::is_callable_lvalue<void(int), void(int)>);

struct A {
	void operator()(int) && {}
};
static_assert(!xte::is_callable_lvalue<A, void(int)>);
