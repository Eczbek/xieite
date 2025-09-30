#include <xte/trait/is_same_any_unqual.hpp>

static_assert(xte::is_same_any_unqual<int, bool, char, void, volatile const int>);
static_assert(not xte::is_same_any_unqual<int, bool, char, void, int&>);
