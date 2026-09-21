#include <xte/preproc/fwd.hpp>
#include <xte/preproc/returns.hpp>
#include <xte/qual_cast.hpp>



auto add(auto lhs, auto rhs) XTE_RETURNS(lhs + rhs)

static_assert(requires { add(0, 0); });
static_assert(noexcept(add(0, 0)));



template<typename T, typename... Ts>
struct derived : T, Ts... {
	int x;

	derived(int x) XTE_CONSTRUCTS(
		(x,(x))
		((T),(x))
		(((Ts)),(x))
	)
};

struct A { A(int) noexcept {} };
struct B { B(int) noexcept {} };
struct C { C(int) noexcept {} };

static_assert(requires { derived<A, B, C>(0); });
static_assert(noexcept(derived<A, B, C>(0)));




struct castable {
	int x;

	XTE_DEFINE_CAST(constexpr, auto&& self,
		XTE_FWD(self).x
	)
};

static_assert(requires { static_cast<int&&>(castable()); });
static_assert(requires { static_cast<const int&&>(xte::as_const(castable())); });
static_assert(requires { static_cast<int&>(xte::as_lvalue(castable())); });
static_assert(requires { static_cast<const int&>(xte::as_const(xte::as_lvalue(castable()))); });
