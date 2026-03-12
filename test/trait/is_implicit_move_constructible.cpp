#include <xte/trait/is_implicit_move_constructible.hpp>

struct Base {
	Base() = delete;
	Base(const Base&) = delete;
	Base(Base&&) = delete;
	void operator=(const Base&) = delete;
	void operator=(Base&&) = delete;
};

struct A : Base { explicit(false) A(A&&) noexcept; };
struct B : Base { explicit(false) B(B&&); };
struct C : Base { explicit(false) C() noexcept; };
struct D : Base { explicit(false) D(); };
struct E : Base { explicit E(E&&) noexcept; };
struct F : Base { explicit F(F&&); };
struct G : Base { explicit G() noexcept; };
struct H : Base { explicit H(); };

static_assert(xte::is_implicit_move_constructible<A>);
static_assert(xte::is_implicit_move_constructible<B>);
static_assert(!xte::is_implicit_move_constructible<C>);
static_assert(!xte::is_implicit_move_constructible<D>);
static_assert(!xte::is_implicit_move_constructible<E>);
static_assert(!xte::is_implicit_move_constructible<F>);
static_assert(!xte::is_implicit_move_constructible<G>);
static_assert(!xte::is_implicit_move_constructible<H>);
