#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>
#include <xte/math/max.hpp>

static_assert(xte::max(0, 0) == 0);
static_assert(xte::max(0, 5) == 5);
static_assert(xte::max(-5, 5) == 5);
static_assert(xte::max(xte::lowest<int>, xte::highest<int>) == xte::highest<int>);

struct A {
	int x;

	friend constexpr bool operator<(A lhs, A rhs) {
		return lhs.x < rhs.x;
	}
};
static_assert(xte::max(A(-5), A(5)).x == 5);

struct B {
	int x;

	friend constexpr bool operator>(B lhs, B rhs) {
		return lhs.x > rhs.x;
	}
};
static_assert(xte::max(B(-5), B(5)).x == 5);

static_assert(xte::max(1, 2, 3) == 3);
static_assert(xte::max(5, 812, 75, 18, 96, 873, 555, 0, -132657, -74, 72866, 999999, 4) == 999999);
