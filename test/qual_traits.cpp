#include <xte/qual_traits.hpp>

// TODO: concepts



static_assert(xte::is_same<int const, xte::add_const<int>>);
static_assert(xte::is_same<int const, xte::add_const<int const>>);
static_assert(xte::is_same<int const volatile, xte::add_const<int volatile>>);
static_assert(xte::is_same<int const volatile, xte::add_const<int const volatile>>);
static_assert(xte::is_same<int const&, xte::add_const<int&>>);
static_assert(xte::is_same<int const volatile&, xte::add_const<int volatile&>>);



static_assert(xte::is_same<int volatile, xte::add_volatile<int>>);
static_assert(xte::is_same<int const volatile, xte::add_volatile<int const>>);
static_assert(xte::is_same<int volatile, xte::add_volatile<int volatile>>);
static_assert(xte::is_same<int const volatile, xte::add_volatile<int const volatile>>);
static_assert(xte::is_same<int volatile&, xte::add_volatile<int&>>);
static_assert(xte::is_same<int const volatile&, xte::add_volatile<int const&>>);



static_assert(xte::is_same<int const volatile, xte::add_cv<int>>);
static_assert(xte::is_same<int const volatile, xte::add_cv<int const>>);
static_assert(xte::is_same<int const volatile, xte::add_cv<int volatile>>);
static_assert(xte::is_same<int const volatile, xte::add_cv<int const volatile>>);
static_assert(xte::is_same<int const volatile&, xte::add_cv<int&>>);



static_assert(xte::is_same<int&, xte::add_lvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::add_lvalue_ref<int&>>);
static_assert(xte::is_same<int&, xte::add_lvalue_ref<int&&>>);
static_assert(xte::is_same<void, xte::add_lvalue_ref<void>>);



static_assert(xte::is_same<int&&, xte::add_rvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::add_rvalue_ref<int&>>);
static_assert(xte::is_same<int&&, xte::add_rvalue_ref<int&&>>);
static_assert(xte::is_same<void, xte::add_rvalue_ref<void>>);



// TODO: add_const_lvalue_ref, add_const_rvalue_ref, add_volatile_lvalue_ref, add_volatile_rvalue_ref, add_cv_lvalue_ref, add_cv_rvalue_ref



static_assert(xte::is_same<int, xte::drop_const<int>>);
static_assert(xte::is_same<int, xte::drop_const<int const>>);
static_assert(xte::is_same<int volatile, xte::drop_const<int volatile>>);
static_assert(xte::is_same<int volatile, xte::drop_const<int const volatile>>);
static_assert(xte::is_same<int&, xte::drop_const<int const&>>);



static_assert(xte::is_same<int, xte::drop_volatile<int>>);
static_assert(xte::is_same<int const, xte::drop_volatile<int const>>);
static_assert(xte::is_same<int, xte::drop_volatile<int volatile>>);
static_assert(xte::is_same<int const, xte::drop_volatile<int const volatile>>);
static_assert(xte::is_same<int&, xte::drop_volatile<int volatile&>>);



static_assert(xte::is_same<int, xte::drop_cv<int>>);
static_assert(xte::is_same<int, xte::drop_cv<int const>>);
static_assert(xte::is_same<int, xte::drop_cv<volatile int>>);
static_assert(xte::is_same<int, xte::drop_cv<int const volatile>>);
static_assert(xte::is_same<int&, xte::drop_cv<int const volatile&>>);



static_assert(xte::is_same<int, xte::drop_lvalue_ref<int>>);
static_assert(xte::is_same<int, xte::drop_lvalue_ref<int&>>);
static_assert(xte::is_same<int&&, xte::drop_lvalue_ref<int&&>>);
static_assert(xte::is_same<int const, xte::drop_lvalue_ref<int const&>>);



static_assert(xte::is_same<int, xte::drop_rvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::drop_rvalue_ref<int&>>);
static_assert(xte::is_same<int, xte::drop_rvalue_ref<int&&>>);
static_assert(xte::is_same<int const, xte::drop_rvalue_ref<int const&&>>);



// TODO: drop_const_lvalue_ref, drop_const_rvalue_ref, drop_volatile_lvalue_ref, drop_volatile_rvalue_ref, drop_cv_lvalue_ref, drop_cv_rvalue_ref



static_assert(xte::is_same<int, xte::drop_cvref<int>>);
static_assert(xte::is_same<int, xte::drop_cvref<int&>>);
static_assert(xte::is_same<int, xte::drop_cvref<int&&>>);
static_assert(xte::is_same<int, xte::drop_cvref<int const volatile&>>);



static_assert(xte::is_same<int, xte::copy_const<char, int>>);
static_assert(xte::is_same<int, xte::copy_const<char, int const>>);
static_assert(xte::is_same<int const, xte::copy_const<char const, int>>);
static_assert(xte::is_same<int const, xte::copy_const<char const, int const>>);
static_assert(xte::is_same<int&, xte::copy_const<char, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char, int const&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const, int&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const, int const&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char, int const&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const, int&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const, int const&&>>);
static_assert(xte::is_same<int, xte::copy_const<char&, int>>);
static_assert(xte::is_same<int, xte::copy_const<char&, int const>>);
static_assert(xte::is_same<int const, xte::copy_const<char const&, int>>);
static_assert(xte::is_same<int const, xte::copy_const<char const&, int const>>);
static_assert(xte::is_same<int&, xte::copy_const<char&, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char&, int const&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const&, int&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const&, int const&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&, int const&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const&, int&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const&, int const&&>>);
static_assert(xte::is_same<int, xte::copy_const<char&&, int>>);
static_assert(xte::is_same<int, xte::copy_const<char&&, int const>>);
static_assert(xte::is_same<int const, xte::copy_const<char const&&, int>>);
static_assert(xte::is_same<int const, xte::copy_const<char const&&, int const>>);
static_assert(xte::is_same<int&, xte::copy_const<char&&, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char&&, int const&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const&&, int&>>);
static_assert(xte::is_same<int const&, xte::copy_const<char const&&, int const&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&&, int const&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const&&, int&&>>);
static_assert(xte::is_same<int const&&, xte::copy_const<char const&&, int const&&>>);



// TODO: copy_volatile, copy_cv



static_assert(xte::is_same<int, xte::copy_lvalue_ref<int, int>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int&&, int>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int, int&>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int&>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int&&, int&>>);
static_assert(xte::is_same<int&&, xte::copy_lvalue_ref<int, int&&>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_lvalue_ref<int&&, int&&>>);



static_assert(xte::is_same<int, xte::copy_rvalue_ref<int, int>>);
static_assert(xte::is_same<int, xte::copy_rvalue_ref<int&, int>>);
static_assert(xte::is_same<int&&, xte::copy_rvalue_ref<int&&, int>>);
static_assert(xte::is_same<int&, xte::copy_rvalue_ref<int, int&>>);
static_assert(xte::is_same<int&, xte::copy_rvalue_ref<int&, int&>>);
static_assert(xte::is_same<int&&, xte::copy_rvalue_ref<int&&, int&>>);
static_assert(xte::is_same<int, xte::copy_rvalue_ref<int, int&&>>);
static_assert(xte::is_same<int, xte::copy_rvalue_ref<int&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_rvalue_ref<int&&, int&&>>);



static_assert(xte::is_same<char, xte::copy_ref<int, char>>);
static_assert(xte::is_same<char, xte::copy_ref<int, char&>>);
static_assert(xte::is_same<char, xte::copy_ref<int, char&&>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char&>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char&&>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char&>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char&&>>);



// TODO: copy_const_lvalue_ref, copy_const_rvalue_ref, copy_const_ref, copy_volatile_lvalue_ref, copy_volatile_rvalue_ref, copy_volatile_ref, copy_cv_lvalue_ref, copy_cv_rvalue_ref, copy_cvref



static_assert(xte::is_same<int, int>);
static_assert(xte::is_same<int const, int const>);
static_assert(xte::is_same<int*, int*>);
static_assert(xte::is_same<int&, int&>);
static_assert(!xte::is_same<int, bool>);
static_assert(!xte::is_same<bool, int>);
static_assert(!xte::is_same<int const, int>);
static_assert(!xte::is_same<int, int const>);
static_assert(!xte::is_same<int*, int>);
static_assert(!xte::is_same<int, int*>);
static_assert(!xte::is_same<int&, int>);
static_assert(!xte::is_same<int, int&>);

static_assert(xte::is_same<int, int, int, int, int>);
static_assert(!xte::is_same<bool, int, int, int, int>);
static_assert(!xte::is_same<int, bool, int, int, int>);
static_assert(!xte::is_same<int, int, bool, int, int>);
static_assert(!xte::is_same<int, int, int, bool, int>);
static_assert(!xte::is_same<int, int, int, int, bool>);



static_assert(xte::is_same_drop_cv<int, int>);
static_assert(xte::is_same_drop_cv<int const, int>);
static_assert(xte::is_same_drop_cv<int volatile, int>);
static_assert(xte::is_same_drop_cv<int const volatile, int>);
static_assert(xte::is_same_drop_cv<int, int const>);
static_assert(xte::is_same_drop_cv<int const, int const>);
static_assert(xte::is_same_drop_cv<int volatile, int const>);
static_assert(xte::is_same_drop_cv<int const volatile, int const>);
static_assert(xte::is_same_drop_cv<int, int volatile>);
static_assert(xte::is_same_drop_cv<int const, int volatile>);
static_assert(xte::is_same_drop_cv<int volatile, int volatile>);
static_assert(xte::is_same_drop_cv<int const volatile, int volatile>);
static_assert(xte::is_same_drop_cv<int, int const volatile>);
static_assert(xte::is_same_drop_cv<int const, int const volatile>);
static_assert(xte::is_same_drop_cv<int volatile, int const volatile>);
static_assert(xte::is_same_drop_cv<int const volatile, int const volatile>);

static_assert(!xte::is_same_drop_cv<int, int&>);



static_assert(xte::is_same_any<int, bool, char, void, int>);
static_assert(!xte::is_same_any<int, bool, char, void, float>);



static_assert(xte::is_same_any_drop_cv<int, bool, char, void, int const volatile>);
static_assert(!xte::is_same_any_drop_cv<int, bool, char, void, int&>);



int x;

static_assert(xte::is_same<int&, decltype(xte::as_lvalue(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_lvalue(x))>);

int f(int*);

static_assert(requires { f(&xte::as_lvalue(0)); });



static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(0))>);
static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(x))>);



static_assert(xte::is_same<int const&&, decltype(xte::as_const(0))>);
static_assert(xte::is_same<int const&, decltype(xte::as_const(x))>);

struct S {
	S() {}
	S(S const&) = delete;
	S(S&&) {}
};

static_assert(xte::is_same<S const&&, decltype(xte::as_const(S()))>);



static_assert(xte::is_same<int volatile&&, decltype(xte::as_volatile(0))>);
static_assert(xte::is_same<int volatile&, decltype(xte::as_volatile(x))>);



int const y = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_mutable(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_mutable(y))>);

static_assert(xte::is_same<S&&, decltype(xte::as_mutable(S()))>);



int volatile z = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_not_volatile(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_not_volatile(z))>);

static_assert(xte::is_same<S&&, decltype(xte::as_not_volatile(S()))>);



static_assert(xte::is_same<int const volatile&&, decltype(xte::like<char const volatile>(0))>);
static_assert(xte::is_same<int const volatile&&, decltype(xte::like<char const volatile>(x))>);
static_assert(xte::is_same<int const volatile&, decltype(xte::like<char const volatile&>(0))>);
static_assert(xte::is_same<int const volatile&, decltype(xte::like<char const volatile&>(x))>);
static_assert(xte::is_same<int const volatile&&, decltype(xte::like<char const volatile&&>(0))>);
static_assert(xte::is_same<int const volatile&&, decltype(xte::like<char const volatile&&>(x))>);



struct throwing_move_ctor {
	throwing_move_ctor() = default;
	throwing_move_ctor(throwing_move_ctor const&) = default;
	throwing_move_ctor(throwing_move_ctor&&) noexcept(false) {}
};

struct S2 {
	S2() = default;
	S2(S2 const&) = delete;
	S2(S2&&) noexcept(false) {}
};

static_assert(^^decltype(xte::as_xvalue_if_noex(0)) == ^^int&&);
static_assert(^^decltype(xte::as_xvalue_if_noex(throwing_move_ctor())) == ^^throwing_move_ctor const&);
