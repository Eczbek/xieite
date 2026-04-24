#include <xte/math/less.hpp>

static_assert(xte::less(0, 1));
static_assert(!xte::less(0, 0));
static_assert(xte::less(-5, 5));
static_assert(xte::less(-5, 5u));

struct A {
	int x;

	friend constexpr bool operator<(A lhs, A rhs) {
		return lhs.x < rhs.x;
	}
};
static_assert(xte::less(A(0), A(5)));

struct B {
	int x;

	friend constexpr bool operator>(B lhs, B rhs) {
		return lhs.x > rhs.x;
	}
};
static_assert(xte::less(B(0), B(5)));
