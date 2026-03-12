#include <xte/trait/is_noex_constructible.hpp>

struct A { A() noexcept; };
struct B { B(); };

static_assert(xte::is_noex_constructible<A>);
static_assert(!xte::is_noex_constructible<B>);
