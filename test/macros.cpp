#include <xte/macros.hpp>
#include <xte/qual_traits.hpp>

decltype(auto) f(auto&& arg) {
	return XTE_FWD(arg);
}

int x;

static_assert(xte::is_same<int&&, decltype(f(0))>);
static_assert(xte::is_same<int&, decltype(f(x))>);



template<int x>
requires(x > 0)
int a;

template<int x>
XTE_DECLARE(int b, a<x>);

static_assert(!([]<int x = 0> { return requires { b<x>; }; })());
static_assert(requires { b<1>; });



template<int x>
requires(x > 0)
struct A {};

template<int x>
XTE_DECLARE_TYPE(struct B, A<x>) {};

static_assert(!([]<int x = 0> { return requires { typename B<x>; }; })());
static_assert(requires { typename B<1>; });



auto add(auto lhs, auto rhs) XTE_RETURNS(lhs + rhs)

static_assert(requires { add(0, 0); });
static_assert(noexcept(add(0, 0)));



template<typename base_type, typename... base_types>
struct derived : base_type, base_types... {
	int x;

	derived(int x) XTE_CONSTRUCTS(
		(x,(x))
		((base_type),(x))
		(((base_types)),(x))
	)
};

struct S0 { S0(int) noexcept {} };
struct S1 { S1(int) noexcept {} };
struct S2 { S2(int) noexcept {} };

static_assert(requires { derived<S0, S1, S2>(0); });
static_assert(noexcept(derived<S0, S1, S2>(0)));



struct castable {
	int x;

	XTE_DEFINE_CAST(constexpr, auto&& self,
		XTE_FWD(self).x
	)
};

static_assert(requires { static_cast<int&&>(castable()); });
static_assert(requires { static_cast<int const&&>(xte::as_const(castable())); });
static_assert(requires { static_cast<int&>(xte::as_lvalue(castable())); });
static_assert(requires { static_cast<int const&>(xte::as_const(xte::as_lvalue(castable()))); });



void g(auto) noexcept;

static_assert(requires { XTE_LIFT(g)(0); });
static_assert(noexcept(XTE_LIFT(g)(0)));



static_assert(requires { XTE_LIFT_UNARY(static_cast<int>)(0); });
static_assert(noexcept(XTE_LIFT_UNARY(static_cast<int>)(0)));



void h() {
	auto h = [](int) noexcept {};
	XTE_LIFT_LOCAL(g)(0);
	static_assert(noexcept(XTE_LIFT_LOCAL(h)(0)));
}

static_assert(requires { XTE_LIFT_INFIX(+)(0, 0); });
static_assert(noexcept(XTE_LIFT_INFIX(+)(0, 0)));



struct S3 {
	constexpr int f(auto) noexcept {
		return 0;
	}
};

static_assert(XTE_LIFT_MEMBER(.f)(S3(), 0) == 0);
static_assert(noexcept(XTE_LIFT_MEMBER(.f)(S3(), 0)));



struct S4 {
	int x;
};

static_assert(XTE_LIFT_VAR(.x)(S4(0)) == 0);
static_assert(noexcept(XTE_LIFT_VAR(.x)(S4(0))));
