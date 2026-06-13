#include <xte/trait/drop_lref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_lref<int>>);
static_assert(xte::is_same<int, xte::drop_lref<int&>>);
static_assert(xte::is_same<int&&, xte::drop_lref<int&&>>);
static_assert(xte::is_same<const int, xte::drop_lref<const int&>>);
