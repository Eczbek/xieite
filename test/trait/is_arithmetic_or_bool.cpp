#include <xte/trait/is_arithmetic_or_bool.hpp>

static_assert(xte::is_arithmetic_or_bool<int>);
static_assert(xte::is_arithmetic_or_bool<float>);
static_assert(xte::is_arithmetic_or_bool<bool>);
static_assert(!xte::is_arithmetic_or_bool<void*>);
