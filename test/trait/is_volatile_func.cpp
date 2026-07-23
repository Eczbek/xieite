#include <xte/trait/is_volatile_func.hpp>

static_assert(xte::is_volatile_func<int() volatile>);
static_assert(xte::is_volatile_func<int() const volatile & noexcept>);
static_assert(!xte::is_volatile_func<int()>);
