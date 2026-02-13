#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_crref.hpp>

static_assert(xte::is_same<int, xte::remove_crref<int>>);
static_assert(xte::is_same<int&, xte::remove_crref<int&>>);
static_assert(xte::is_same<int, xte::remove_crref<int&&>>);
static_assert(xte::is_same<int, xte::remove_crref<const int&&>>);
