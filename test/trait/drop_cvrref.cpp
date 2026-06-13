#include <xte/trait/drop_cvrref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_cvrref<int>>);
static_assert(xte::is_same<int&, xte::drop_cvrref<int&>>);
static_assert(xte::is_same<int, xte::drop_cvrref<int&&>>);
static_assert(xte::is_same<int&, xte::drop_cvrref<volatile const int&>>);
