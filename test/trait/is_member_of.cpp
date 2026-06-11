#include <xte/trait/is_member_of.hpp>

struct A {
	int x;
	void f() {}
};

static_assert(xte::is_member_of<int A::*, A>);
static_assert(xte::is_member_of<decltype(&A::x), A>);
static_assert(xte::is_member_of<decltype(&A::f), A>);
static_assert(!xte::is_member_of<int, A>);
static_assert(!xte::is_member_of<void(), A>);
