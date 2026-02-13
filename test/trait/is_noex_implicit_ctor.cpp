#include <xte/trait/is_noex_implicit_ctor.hpp>

struct A { explicit(false) A() noexcept; };
struct B { explicit(false) B(); };
struct C { explicit C() noexcept; };
struct D { explicit D(); };

static_assert(xte::is_noex_implicit_ctor<A>);
static_assert(!xte::is_noex_implicit_ctor<B>);
static_assert(!xte::is_noex_implicit_ctor<C>);
static_assert(!xte::is_noex_implicit_ctor<D>);
