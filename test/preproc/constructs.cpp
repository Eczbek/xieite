#include <xte/preproc/constructs.hpp>

template<typename T, typename... Ts>
struct derived : T, Ts... {
	int x;

	derived(int x) XTE_CONSTRUCTS(, x, ((x)), (T), ((x)), ((Ts)), ((x)))
};

struct A { A(int) noexcept {} };
struct B { B(int) noexcept {} };
struct C { C(int) noexcept {} };

static_assert(requires { derived<A, B, C>(0); });
static_assert(noexcept(derived<A, B, C>(0)));
