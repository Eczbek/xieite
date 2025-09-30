#include <xte/trait/add_lref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int&, xte::add_lref<int>>);
static_assert(xte::is_same<int&, xte::add_lref<int&>>);
static_assert(xte::is_same<int&, xte::add_lref<int&&>>);
static_assert(xte::is_same<void, xte::add_lref<void>>);
