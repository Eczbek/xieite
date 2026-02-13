#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_rref.hpp>

static_assert(xte::is_same<int, xte::remove_rref<int>>);
static_assert(xte::is_same<int&, xte::remove_rref<int&>>);
static_assert(xte::is_same<int, xte::remove_rref<int&&>>);
static_assert(xte::is_same<const int, xte::remove_rref<const int&&>>);
