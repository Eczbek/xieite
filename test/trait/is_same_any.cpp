#include <xte/trait/is_same_any.hpp>

static_assert(xte::is_same_any<int, bool, char, void, int>);
static_assert(!xte::is_same_any<int, bool, char, void, float>);
