#include <xte/trait/is_noex_castable.hpp>

struct A { A(int) noexcept; };
struct B { B(int); };

static_assert(xte::is_noex_castable<int, A>);
static_assert(!xte::is_noex_castable<int, B>);
