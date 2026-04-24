#include <xte/math/max.hpp>
#include <limits>

static_assert(xte::max(0, 0) == 0);
static_assert(xte::max(0, 5) == 5);
static_assert(xte::max(-5, 5) == 5);
static_assert(xte::max(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max()) == std::numeric_limits<int>::max());

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
