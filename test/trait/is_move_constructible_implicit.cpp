#include <xte/trait/is_move_constructible_implicit.hpp>

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

static_assert(xte::is_move_constructible_implicit<A>);
static_assert(xte::is_move_constructible_implicit<B>);
static_assert(!xte::is_move_constructible_implicit<C>);
static_assert(!xte::is_move_constructible_implicit<D>);
static_assert(!xte::is_move_constructible_implicit<E>);
static_assert(!xte::is_move_constructible_implicit<F>);
static_assert(!xte::is_move_constructible_implicit<G>);
static_assert(!xte::is_move_constructible_implicit<H>);
