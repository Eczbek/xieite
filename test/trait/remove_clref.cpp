#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_clref.hpp>

static_assert(xte::is_same<int, xte::remove_clref<int>>);
static_assert(xte::is_same<int, xte::remove_clref<int&>>);
static_assert(xte::is_same<int&&, xte::remove_clref<int&&>>);
static_assert(xte::is_same<int, xte::remove_clref<const int&>>);
