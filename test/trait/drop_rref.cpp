#include <xte/trait/drop_rref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_rref<int>>);
static_assert(xte::is_same<int&, xte::drop_rref<int&>>);
static_assert(xte::is_same<int, xte::drop_rref<int&&>>);
static_assert(xte::is_same<const int, xte::drop_rref<const int&&>>);
