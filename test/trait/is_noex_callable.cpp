#include <xte/trait/is_noex_callable.hpp>

static_assert(xte::is_noex_callable<void(int) noexcept, void(int)>);
static_assert(!xte::is_noex_callable<void(int), void(int)>);
