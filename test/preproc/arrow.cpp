#include <xte/preproc/arrow.hpp>
#include <xte/preproc/fwd.hpp>
#include <xte/util/as_c.hpp>
#include <xte/util/lvalue.hpp>

auto add(auto lhs, auto rhs) XTE_ARROW(lhs + rhs)

static_assert(requires { add(0, 0); });
static_assert(noexcept(add(0, 0)));

template<typename T, typename... Ts>
struct Derived : T, Ts... {
	int x;

	Derived(int x) XTE_ARROW_CTOR(, x, ((x)), (T), ((x)), ((Ts)), ((x)))
};

struct A { A(int) noexcept {} };
struct B { B(int) noexcept {} };
struct C { C(int) noexcept {} };

static_assert(requires { Derived<A, B, C>(0); });
static_assert(noexcept(Derived<A, B, C>(0)));

struct Cast {
	int x;

	XTE_ARROW_CAST(constexpr, auto&& self,
		XTE_FWD(self).x
	)
};

static_assert(requires { static_cast<int&&>(Cast()); });
static_assert(requires { static_cast<const int&&>(xte::as_c(Cast())); });
static_assert(requires { static_cast<int&>(xte::lvalue(Cast())); });
static_assert(requires { static_cast<const int&>(xte::as_c(xte::lvalue(Cast()))); });
