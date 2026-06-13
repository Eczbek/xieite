#include <xte/trait/drop_crref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_crref<int>>);
static_assert(xte::is_same<int&, xte::drop_crref<int&>>);
static_assert(xte::is_same<int, xte::drop_crref<int&&>>);
static_assert(xte::is_same<int, xte::drop_crref<const int&&>>);
