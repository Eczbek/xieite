#include <xte/trait/is_number_or_bool.hpp>

static_assert(xte::is_number_or_bool<int>);
static_assert(xte::is_number_or_bool<float>);
static_assert(xte::is_number_or_bool<bool>);
static_assert(!xte::is_number_or_bool<void*>);
