#include <xte/trait/drop_clref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_clref<int>>);
static_assert(xte::is_same<int, xte::drop_clref<int&>>);
static_assert(xte::is_same<int&&, xte::drop_clref<int&&>>);
static_assert(xte::is_same<int, xte::drop_clref<const int&>>);
