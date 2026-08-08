#include <xte/trait/is_move_constructible_implicit_noex.hpp>

struct base {
	base() = delete;
	base(const base&) = delete;
	base(base&&) = delete;
	void operator=(const base&) = delete;
	void operator=(base&&) = delete;
};

struct A : base { explicit(false) A(A&&) noexcept; };
struct B : base { explicit(false) B(B&&); };
struct C : base { explicit(false) C() noexcept; };
struct D : base { explicit(false) D(); };
struct E : base { explicit E(E&&) noexcept; };
struct F : base { explicit F(F&&); };
struct G : base { explicit G() noexcept; };
struct H : base { explicit H(); };

static_assert(xte::is_move_constructible_implicit_noex<A>);
static_assert(!xte::is_move_constructible_implicit_noex<B>);
static_assert(!xte::is_move_constructible_implicit_noex<C>);
static_assert(!xte::is_move_constructible_implicit_noex<D>);
static_assert(!xte::is_move_constructible_implicit_noex<E>);
static_assert(!xte::is_move_constructible_implicit_noex<F>);
static_assert(!xte::is_move_constructible_implicit_noex<G>);
static_assert(!xte::is_move_constructible_implicit_noex<H>);
