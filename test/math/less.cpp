#include <xte/math/less.hpp>
#include <limits>

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

static_assert(xte::less(0, std::numeric_limits<double>::infinity()));
static_assert(!xte::less(0, -std::numeric_limits<double>::infinity()));
static_assert(!xte::less(std::numeric_limits<double>::infinity(), 0));
static_assert(xte::less(-std::numeric_limits<double>::infinity(), 0));

static_assert(!xte::less(0, std::numeric_limits<double>::quiet_NaN()));
static_assert(!xte::less(std::numeric_limits<double>::quiet_NaN(), 0));
static_assert(!xte::less(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()));
