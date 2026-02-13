#include <xte/trait/is_same_any_ignore_cv.hpp>

static_assert(xte::is_same_any_ignore_cv<int, bool, char, void, volatile const int>);
static_assert(!xte::is_same_any_ignore_cv<int, bool, char, void, int&>);
