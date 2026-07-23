#include <xte/trait/is_const_func.hpp>

static_assert(xte::is_const_func<int() const>);
static_assert(xte::is_const_func<int() const volatile & noexcept>);
static_assert(!xte::is_const_func<int()>);
