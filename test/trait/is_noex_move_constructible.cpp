#include <xte/trait/is_noex_move_constructible.hpp>

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

static_assert(xte::is_noex_move_constructible<A>);
static_assert(!xte::is_noex_move_constructible<B>);
static_assert(!xte::is_noex_move_constructible<C>);
static_assert(!xte::is_noex_move_constructible<D>);
static_assert(xte::is_noex_move_constructible<E>);
static_assert(!xte::is_noex_move_constructible<F>);
static_assert(!xte::is_noex_move_constructible<G>);
static_assert(!xte::is_noex_move_constructible<H>);
