#include <xte/math/minmax.hpp>

consteval {
	constexpr auto [min, max] = xte::minmax(5, -5);
	static_assert(min == -5);
	static_assert(max == 5);
}

struct A {
	int x;

	friend constexpr bool operator<(A lhs, A rhs) {
		return lhs.x < rhs.x;
	}
};
consteval {
	constexpr auto [min, max] = xte::minmax(A(5), A(-5));
	static_assert(min.x == -5);
	static_assert(max.x == 5);
}

struct B {
	int x;

	friend constexpr bool operator>(B lhs, B rhs) {
		return lhs.x > rhs.x;
	}
};
consteval {
	constexpr auto [min, max] = xte::minmax(B(5), B(-5));
	static_assert(min.x == -5);
	static_assert(max.x == 5);
}
