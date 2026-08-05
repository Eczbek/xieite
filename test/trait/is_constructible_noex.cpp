#include <xte/trait/is_constructible_noex.hpp>

struct A { A() noexcept; };
struct B { B(); };

static_assert(xte::is_constructible_noex<A>);
static_assert(!xte::is_constructible_noex<B>);
