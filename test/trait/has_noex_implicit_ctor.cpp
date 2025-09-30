#include <xte/trait/has_noex_implicit_ctor.hpp>

struct A { explicit(false) A() noexcept; };
struct B { explicit(false) B(); };
struct C { explicit C() noexcept; };
struct D { explicit D(); };

static_assert(xte::has_noex_implicit_ctor<A>);
static_assert(not xte::has_noex_implicit_ctor<B>);
static_assert(not xte::has_noex_implicit_ctor<C>);
static_assert(not xte::has_noex_implicit_ctor<D>);
