#include <xte/util/assign.hpp>

static_assert(([] {
	int x;
	xte::assign(x, 1.5);
	return x == 1;
})());

struct A {
	constexpr A() = default;
	constexpr A(const A&) = delete;
	constexpr A(A&&) = default;
	A& operator=(const A&) = delete;
	A& operator=(A&&) = delete;
};

consteval {
	A a;
	xte::assign(a, A());
}
