#include <xte/preproc/lift.hpp>

void f(auto) noexcept;

static_assert(requires { XTE_LIFT(f)(0); });
static_assert(noexcept(XTE_LIFT(f)(0)));

static_assert(requires { XTE_LIFT_UNARY(static_cast<int>)(0); });
static_assert(noexcept(XTE_LIFT_UNARY(static_cast<int>)(0)));

void g() {
	auto g = [](int) noexcept {};
	XTE_LIFT_LOCAL(g)(0);
	static_assert(noexcept(XTE_LIFT_LOCAL(g)(0)));
}

static_assert(requires { XTE_LIFT_INFIX(+)(0, 0); });
static_assert(noexcept(XTE_LIFT_INFIX(+)(0, 0)));

struct A {
	constexpr int f(auto) noexcept {
		return 0;
	}
};

static_assert(XTE_LIFT_MEMBER(.f)(A(), 0) == 0);
static_assert(noexcept(XTE_LIFT_MEMBER(.f)(A(), 0)));

struct B {
	int x;
};

static_assert(XTE_LIFT_VAR(.x)(B(0)) == 0);
static_assert(noexcept(XTE_LIFT_VAR(.x)(B(0))));
