#include <xte/qual_cast.hpp>
#include <xte/trait/is_callable.hpp>
#include <xte/trait/is_same.hpp>

int x;

static_assert(xte::is_same<int&, decltype(xte::as_lvalue(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(x))>);

int f(int*);

static_assert(requires { f(&xte::as_lvalue(0)); });



static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(0))>);
static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(x))>);



static_assert(xte::is_same<const int&&, decltype(xte::as_const(0))>);
static_assert(xte::is_same<const int&, decltype(xte::as_const(x))>);

struct S1 {
	S1() {}
	S1(S1&&) {}
	S1(const S1&) = delete;
};

static_assert(xte::is_same<const S1&&, decltype(xte::as_const(S1()))>);



static_assert(xte::is_same<volatile int&&, decltype(xte::as_volatile(0))>);
static_assert(xte::is_same<volatile int&, decltype(xte::as_volatile(x))>);



const int y = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_mutable(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_mutable(y))>);

struct S2 {
	S2() {}
	S2(S2&&) {}
	S2(const S2&) = delete;
};

static_assert(xte::is_same<S2&&, decltype(xte::as_mutable(S2()))>);



volatile int z = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_not_volatile(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_not_volatile(z))>);

struct S3 {
	S3() {}
	S3(S3&&) {}
	S3(const S3&) = delete;
};

static_assert(xte::is_same<S3&&, decltype(xte::as_not_volatile(S3()))>);



static_assert(xte::is_same<volatile const int&&, decltype(xte::like<volatile const char>(0))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::like<volatile const char>(x))>);
static_assert(xte::is_same<volatile const int&, decltype(xte::like<volatile const char&>(0))>);
static_assert(xte::is_same<volatile const int&, decltype(xte::like<volatile const char&>(x))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::like<volatile const char&&>(0))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::like<volatile const char&&>(x))>);



struct throwing_move_ctor {
	throwing_move_ctor() = default;
	throwing_move_ctor(const throwing_move_ctor&) = default;
	throwing_move_ctor(throwing_move_ctor&&) noexcept(false) {}
};

struct S0 {
	S0() = default;
	S0(const S0&) = delete;
	S0(S0&&) noexcept(false) {}
};

static_assert(^^decltype(xte::as_xvalue_if_noex(0)) == ^^int&&);
static_assert(^^decltype(xte::as_xvalue_if_noex(throwing_move_ctor())) == ^^const throwing_move_ctor&);
static_assert(!xte::is_callable<decltype(xte::as_xvalue_if_noex), S0>);
