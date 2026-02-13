#include <xte/preproc/arrow.hpp>

auto add(auto lhs, auto rhs) XTE_ARROW(lhs + rhs)

static_assert(requires { add(0, 0); });
static_assert(noexcept(add(0, 0)));

template<typename T, typename... Us>
struct Derived : T, Us... {
	int x;

	Derived(int x) XTE_ARROW_CTOR(, x, ((x)), (T), ((x)), ((Us)), ((x)))
};

struct A { A(int) noexcept {} };
struct B { B(int) noexcept {} };
struct C { C(int) noexcept {} };

static_assert(requires { Derived<A, B, C>(0); });
static_assert(noexcept(Derived<A, B, C>(0)));
