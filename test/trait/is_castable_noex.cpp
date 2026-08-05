#include <xte/trait/is_castable_noex.hpp>

struct A { A(int) noexcept; };
struct B { B(int); };

static_assert(xte::is_castable_noex<int, A>);
static_assert(!xte::is_castable_noex<int, B>);
