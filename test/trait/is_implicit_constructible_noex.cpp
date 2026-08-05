#include <xte/trait/is_implicit_constructible_noex.hpp>

struct A { explicit(false) A() noexcept; };
struct B { explicit(false) B(); };
struct C { explicit C() noexcept; };
struct D { explicit D(); };

static_assert(xte::is_implicit_constructible_noex<A>);
static_assert(!xte::is_implicit_constructible_noex<B>);
static_assert(!xte::is_implicit_constructible_noex<C>);
static_assert(!xte::is_implicit_constructible_noex<D>);
