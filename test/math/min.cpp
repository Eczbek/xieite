#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>
#include <xte/math/min.hpp>

static_assert(xte::min(0, 0) == 0);
static_assert(xte::min(0, 5) == 0);
static_assert(xte::min(-5, 5) == -5);
static_assert(xte::min(xte::lowest<int>, xte::highest<int>) == xte::lowest<int>);

struct A {
	int x;

	friend constexpr bool operator<(A lhs, A rhs) {
		return lhs.x < rhs.x;
	}
};
static_assert(xte::min(A(-5), A(5)).x == -5);

struct B {
	int x;

	friend constexpr bool operator>(B lhs, B rhs) {
		return lhs.x > rhs.x;
	}
};
static_assert(xte::min(B(-5), B(5)).x == -5);
