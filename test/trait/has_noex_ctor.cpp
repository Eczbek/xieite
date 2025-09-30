#include <xte/trait/has_noex_ctor.hpp>

struct A { A() noexcept; };
struct B { B(); };

static_assert(xte::has_noex_ctor<A>);
static_assert(not xte::has_noex_ctor<B>);
