#include <xte/util/as_const.hpp>
#include <xte/util/as_lvalue.hpp>
#include <xte/util/assign.hpp>

static_assert(xte::assign(xte::as_lvalue(false), true));
static_assert(xte::assign(xte::as_lvalue(0), xte::as_const(xte::as_lvalue(1))) == 1);

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
