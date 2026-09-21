#include <xte/limits.hpp>
#include <xte/math/clamp.hpp>
#include <xte/qual_cast.hpp>

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



static_assert(xte::min(xte::as_lvalue(0), xte::as_const(xte::as_lvalue(0))) == 0);

static_assert(xte::min(0, 0) == 0);
static_assert(xte::min(0, 5) == 0);
static_assert(xte::min(-5, 5) == -5);
static_assert(xte::min(xte::lowest<int>, xte::highest<int>) == xte::lowest<int>);

struct C {
	int x;

	friend constexpr bool operator<(C lhs, C rhs) {
		return lhs.x < rhs.x;
	}
};
static_assert(xte::min(C(-5), C(5)).x == -5);

struct D {
	int x;

	friend constexpr bool operator>(D lhs, D rhs) {
		return lhs.x > rhs.x;
	}
};
static_assert(xte::min(D(-5), D(5)).x == -5);



consteval {
	constexpr auto [min, max] = xte::minmax(5, -5);
	static_assert(min == -5);
	static_assert(max == 5);
}

struct E {
	int x;

	friend constexpr bool operator<(E lhs, E rhs) {
		return lhs.x < rhs.x;
	}
};
consteval {
	constexpr auto [min, max] = xte::minmax(E(5), E(-5));
	static_assert(min.x == -5);
	static_assert(max.x == 5);
}

struct F {
	int x;

	friend constexpr bool operator>(F lhs, F rhs) {
		return lhs.x > rhs.x;
	}
};
consteval {
	constexpr auto [min, max] = xte::minmax(F(5), F(-5));
	static_assert(min.x == -5);
	static_assert(max.x == 5);
}



static_assert(xte::clamp(1, 0, 2) == 1);
static_assert(xte::clamp(-1, 0, 2) == 0);
static_assert(xte::clamp(3, 0, 2) == 2);
