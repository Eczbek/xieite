#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_cvrref.hpp>

static_assert(xte::is_same<int, xte::remove_cvrref<int>>);
static_assert(xte::is_same<int&, xte::remove_cvrref<int&>>);
static_assert(xte::is_same<int, xte::remove_cvrref<int&&>>);
static_assert(xte::is_same<int&, xte::remove_cvrref<volatile const int&>>);
