#include <xte/preproc/arrow.hpp>
#include <xte/util/as_c.hpp>
#include <xte/util/like.hpp>
#include <xte/util/lvalue.hpp>

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

struct Cast {
	int x;

	XTE_ARROW_CAST(constexpr, auto&& self,
		xte::like<decltype(self)&&>(self.x)
	)
};

static_assert(requires { static_cast<int&&>(Cast()); });
static_assert(requires { static_cast<const int&&>(xte::as_c(Cast())); });
static_assert(requires { static_cast<int&>(xte::lvalue(Cast())); });
static_assert(requires { static_cast<const int&>(xte::as_c(xte::lvalue(Cast()))); });
