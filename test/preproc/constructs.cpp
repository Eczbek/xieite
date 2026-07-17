#include <xte/preproc/constructs.hpp>

template<typename T, typename... Ts>
struct Derived : T, Ts... {
	int x;

	Derived(int x) XTE_CONSTRUCTS(, x, ((x)), (T), ((x)), ((Ts)), ((x)))
};

struct A { A(int) noexcept {} };
struct B { B(int) noexcept {} };
struct C { C(int) noexcept {} };

static_assert(requires { Derived<A, B, C>(0); });
static_assert(noexcept(Derived<A, B, C>(0)));
