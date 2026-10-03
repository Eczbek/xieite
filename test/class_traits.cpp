#include <xte/class_traits.hpp>
#include <xte/fixed_array.hpp>
#include <xte/qual_traits.hpp>

static_assert(xte::is_constructible<int>);
static_assert(xte::is_constructible<int, int>);
static_assert(!xte::is_constructible<int, int, int>);

struct S0 { S0(int, char, float); };

static_assert(xte::is_constructible<S0, int, char, float>);
static_assert(!xte::is_constructible<S0>);



struct S1 { S1() noexcept; };
struct S2 { S2(); };

static_assert(xte::is_constructible_noex<S1>);
static_assert(!xte::is_constructible_noex<S2>);



struct S3 { explicit(false) S3(int); };
struct S4 { explicit S4(int); };

static_assert(xte::is_implicitly_constructible<S3, int>);
static_assert(!xte::is_implicitly_constructible<S4, int>);



struct S5 { explicit(false) S5() noexcept; };
struct S6 { explicit(false) S6(); };
struct S7 { explicit S7() noexcept; };
struct S8 { explicit S8(); };

static_assert(xte::is_implicitly_constructible_noex<S5>);
static_assert(!xte::is_implicitly_constructible_noex<S6>);
static_assert(!xte::is_implicitly_constructible_noex<S7>);
static_assert(!xte::is_implicitly_constructible_noex<S8>);



// TODO: is_brace_constructible, is_brace_constructible_noex, is_copy_constructible, is_copy_constructible_noex, is_implicitly_copy_constructible, is_implicitly_copy_constructible_noex, is_move_constructible



struct S9 {
	S9() = delete;
	S9(S9 const&) = delete;
	S9(S9&&) = delete;
	void operator=(S9 const&) = delete;
	void operator=(S9&&) = delete;
};

struct S10 : S9 { explicit(false) S10(S10&&) noexcept; };
struct S11 : S9 { explicit(false) S11(S11&&); };
struct S12 : S9 { explicit(false) S12() noexcept; };
struct S13 : S9 { explicit(false) S13(); };
struct S14 : S9 { explicit S14(S14&&) noexcept; };
struct S15 : S9 { explicit S15(S15&&); };
struct S16 : S9 { explicit S16() noexcept; };
struct S17 : S9 { explicit S17(); };

static_assert(xte::is_move_constructible_noex<S10>);
static_assert(!xte::is_move_constructible_noex<S11>);
static_assert(!xte::is_move_constructible_noex<S12>);
static_assert(!xte::is_move_constructible_noex<S13>);
static_assert(xte::is_move_constructible_noex<S14>);
static_assert(!xte::is_move_constructible_noex<S15>);
static_assert(!xte::is_move_constructible_noex<S16>);
static_assert(!xte::is_move_constructible_noex<S17>);




static_assert(xte::is_implicitly_move_constructible<S10>);
static_assert(xte::is_implicitly_move_constructible<S11>);
static_assert(!xte::is_implicitly_move_constructible<S12>);
static_assert(!xte::is_implicitly_move_constructible<S13>);
static_assert(!xte::is_implicitly_move_constructible<S14>);
static_assert(!xte::is_implicitly_move_constructible<S15>);
static_assert(!xte::is_implicitly_move_constructible<S16>);
static_assert(!xte::is_implicitly_move_constructible<S17>);



static_assert(xte::is_implicitly_move_constructible_noex<S10>);
static_assert(!xte::is_implicitly_move_constructible_noex<S11>);
static_assert(!xte::is_implicitly_move_constructible_noex<S12>);
static_assert(!xte::is_implicitly_move_constructible_noex<S13>);
static_assert(!xte::is_implicitly_move_constructible_noex<S14>);
static_assert(!xte::is_implicitly_move_constructible_noex<S15>);
static_assert(!xte::is_implicitly_move_constructible_noex<S16>);
static_assert(!xte::is_implicitly_move_constructible_noex<S17>);



struct S20 { explicit(false) S20(int) noexcept; };
struct S21 { explicit(false) S21(int); };
struct S22 { explicit S22(int) noexcept; };
struct S23 { explicit S23(int); };

static_assert(xte::is_convertible<int, S20>);
static_assert(xte::is_convertible<int, S21>);
static_assert(xte::is_convertible<int, S22>);
static_assert(xte::is_convertible<int, S23>);



static_assert(xte::is_convertible_noex<int, S20>);
static_assert(!xte::is_convertible_noex<int, S21>);
static_assert(xte::is_convertible_noex<int, S22>);
static_assert(!xte::is_convertible_noex<int, S23>);



static_assert(xte::is_implicitly_convertible<int, S20>);
static_assert(xte::is_implicitly_convertible<int, S21>);
static_assert(!xte::is_implicitly_convertible<int, S22>);
static_assert(!xte::is_implicitly_convertible<int, S23>);



static_assert(xte::is_implicitly_convertible_noex<int, S20>);
static_assert(!xte::is_implicitly_convertible_noex<int, S21>);
static_assert(!xte::is_implicitly_convertible_noex<int, S22>);
static_assert(!xte::is_implicitly_convertible_noex<int, S23>);



static_assert(xte::is_assignable<int&, int>);
static_assert(!xte::is_assignable<int, int>);

struct S24 { int operator=(int) && noexcept; };
struct S25 { int operator=(int) &&; };

static_assert(!xte::is_assignable<S24&, int>);
static_assert(xte::is_assignable<S24, int>);



static_assert(xte::is_assignable_noex<int&, int>);
static_assert(!xte::is_assignable_noex<int, int>);

static_assert(xte::is_assignable_noex<S24, int>);
static_assert(!xte::is_assignable_noex<S24&, int>);
static_assert(!xte::is_assignable_noex<S25, int>);
static_assert(!xte::is_assignable_noex<S25&, int>);



// TODO: is_assignable_lvalue, is_assignable_lvalue_noex



static_assert(xte::is_assignable_to<int, int&>);
static_assert(!xte::is_assignable_to<int, int>);

static_assert(!xte::is_assignable_to<int, S24&>);
static_assert(xte::is_assignable_to<int, S24>);



static_assert(xte::is_assignable_to_noex<int, int&>);
static_assert(!xte::is_assignable_to_noex<int, int>);

static_assert(xte::is_assignable_to_noex<int, S24>);
static_assert(!xte::is_assignable_to_noex<int, S24&>);
static_assert(!xte::is_assignable_to_noex<int, S25>);
static_assert(!xte::is_assignable_to_noex<int, S25&>);



// TODO: is_copy_assignable, is_copy_assignable_noex, is_move_assignable, is_move_assignable_noex, is_destructible, is_destructible_noex, is_bool_testable, is_bool_testable_noex, is_swappable_noex



static_assert(xte::is_callable<int(), void()>);
static_assert(xte::is_callable<typename[:^^int():]*, void()>);
static_assert(xte::is_callable<typename[:^^int():]&, void()>);
static_assert(xte::is_callable<decltype([]{}), void()>);
static_assert(xte::is_callable<void(int) noexcept, void(int) noexcept>);

static_assert(!xte::is_callable<int, void()>);
static_assert(!xte::is_callable<int decltype([]{})::*, void()>);
static_assert(!xte::is_callable<void(int), void(int) noexcept>);



static_assert(xte::is_callable_lvalue<void(int), void(int)>);

struct S26 {
	void operator()(int) && {}
};
static_assert(!xte::is_callable_lvalue<S26, void(int)>);



// TODO: is_invocable, is_invocable_lvalue, member_type_of, class_type_of



struct S27 {
	int x;
	void f() {}
};

static_assert(xte::is_member_ptr_of<int S27::*, S27>);
static_assert(xte::is_member_ptr_of<decltype(&S27::x), S27>);
static_assert(xte::is_member_ptr_of<decltype(&S27::f), S27>);
static_assert(!xte::is_member_ptr_of<int, S27>);
static_assert(!xte::is_member_ptr_of<void(), S27>);



// TODO: is_derived_from



struct S28 {};
struct S29 : private S28 {};
struct S30 : public S28 {};

static_assert(xte::is_privately_derived_from<S29, S28>);
static_assert(!xte::is_privately_derived_from<S30, S28>);



template<typename, auto>
struct S31 {};

static_assert(xte::is_specialization_of<S31<int, 0>, ^^S31>);
static_assert(!xte::is_specialization_of<S31<int, 0>, ^^int>);
static_assert(!xte::is_specialization_of<int, ^^S31>);
static_assert(!xte::is_specialization_of<int, ^^int>);



template<int>
struct S32 {};

struct S33 : S32<0> {};

static_assert(xte::is_derived_from_specialization_of<S33, ^^S32>);
static_assert(!xte::is_derived_from_specialization_of<int, ^^S32>);

static_assert(xte::is_derived_from_specialization_of<xte::fixed_array<int, 3>, ^^xte::fixed_array>);



struct S98 : xte::non_copyable {};

static_assert(requires { S98(); });
static_assert(!requires (S98 s) { requires(requires { S98(s); }); });
static_assert(requires (S98 s) { S98(xte::as_xvalue(s)); });
static_assert(!requires (S98 lhs, S98 rhs) { requires(requires { lhs = rhs; }); });
static_assert(requires (S98 lhs, S98 rhs) { lhs = xte::as_xvalue(rhs); });

struct S99 : xte::non_copyable, xte::non_movable {};

static_assert(requires { S99(); });
static_assert(!([]<typename S = S99> { return requires (S s) { S(s); }; })());
static_assert(!([]<typename S = S99> { return requires (S s) { S(xte::as_xvalue(s)); }; })());
static_assert(!([]<typename S = S99> { return requires (S lhs, S rhs) { lhs = rhs; }; })());
static_assert(!([]<typename S = S99> { return requires (S lhs, S rhs) { lhs = xte::as_xvalue(rhs); }; })());
