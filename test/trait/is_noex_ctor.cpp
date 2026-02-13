#include <xte/trait/is_noex_ctor.hpp>

struct A { A() noexcept; };
struct B { B(); };

static_assert(xte::is_noex_ctor<A>);
static_assert(!xte::is_noex_ctor<B>);
