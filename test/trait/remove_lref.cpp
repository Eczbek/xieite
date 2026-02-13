#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_lref.hpp>

static_assert(xte::is_same<int, xte::remove_lref<int>>);
static_assert(xte::is_same<int, xte::remove_lref<int&>>);
static_assert(xte::is_same<int&&, xte::remove_lref<int&&>>);
static_assert(xte::is_same<const int, xte::remove_lref<const int&>>);
