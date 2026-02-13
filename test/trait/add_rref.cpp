#include <xte/trait/add_rref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int&&, xte::add_rref<int>>);
static_assert(xte::is_same<int&, xte::add_rref<int&>>);
static_assert(xte::is_same<int&&, xte::add_rref<int&&>>);
static_assert(xte::is_same<void, xte::add_rref<void>>);
