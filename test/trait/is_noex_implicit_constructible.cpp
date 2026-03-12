#include <xte/trait/is_noex_implicit_constructible.hpp>

struct A { explicit(false) A() noexcept; };
struct B { explicit(false) B(); };
struct C { explicit C() noexcept; };
struct D { explicit D(); };

static_assert(xte::is_noex_implicit_constructible<A>);
static_assert(!xte::is_noex_implicit_constructible<B>);
static_assert(!xte::is_noex_implicit_constructible<C>);
static_assert(!xte::is_noex_implicit_constructible<D>);
