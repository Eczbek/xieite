#include <xte/trait/add_cvrref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<volatile const int&&, xte::add_cvrref<int>>);
static_assert(xte::is_same<volatile const int&, xte::add_cvrref<int&>>);
static_assert(xte::is_same<volatile const int&&, xte::add_cvrref<int&&>>);
static_assert(xte::is_same<volatile const void, xte::add_cvrref<void>>);
