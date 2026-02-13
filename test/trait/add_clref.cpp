#include <xte/trait/add_clref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<const int&, xte::add_clref<int>>);
static_assert(xte::is_same<const int&, xte::add_clref<int&>>);
static_assert(xte::is_same<const int&, xte::add_clref<int&&>>);
static_assert(xte::is_same<const void, xte::add_clref<void>>);
