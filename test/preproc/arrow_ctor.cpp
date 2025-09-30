#include <xte/preproc/arrow_ctor.hpp>

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
