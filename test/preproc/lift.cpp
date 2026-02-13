#include <xte/preproc/lift.hpp>

void f(auto) noexcept;

static_assert(requires { XTE_LIFT(f)(0); });
static_assert(noexcept(XTE_LIFT(f)(0)));

static_assert(requires { XTE_LIFT_ONE(static_cast<int>)(0); });
static_assert(noexcept(XTE_LIFT_ONE(static_cast<int>)(0)));

void g() {
	auto g = [](auto) noexcept {};
	XTE_LIFT_LOCAL(g)(0);
	static_assert(noexcept(XTE_LIFT_LOCAL(g)(0)));
}

static_assert(requires { XTE_LIFT_INFIX(+)(0, 0); });
static_assert(noexcept(XTE_LIFT_INFIX(+)(0, 0)));

struct S {
	void f(auto) noexcept;
};

static_assert(requires { XTE_LIFT_MEMBER(.f)(S(), 0); });
static_assert(noexcept(XTE_LIFT_MEMBER(.f)(S(), 0)));
