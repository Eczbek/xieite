#include <xte/trait/is_implicit_move_ctor.hpp>

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

static_assert(xte::is_implicit_move_ctor<A>);
static_assert(xte::is_implicit_move_ctor<B>);
static_assert(!xte::is_implicit_move_ctor<C>);
static_assert(!xte::is_implicit_move_ctor<D>);
static_assert(!xte::is_implicit_move_ctor<E>);
static_assert(!xte::is_implicit_move_ctor<F>);
static_assert(!xte::is_implicit_move_ctor<G>);
static_assert(!xte::is_implicit_move_ctor<H>);
