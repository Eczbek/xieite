#include <xte/trait/add_crref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<const int&&, xte::add_crref<int>>);
static_assert(xte::is_same<const int&, xte::add_crref<int&>>);
static_assert(xte::is_same<const int&&, xte::add_crref<int&&>>);
static_assert(xte::is_same<const void, xte::add_crref<void>>);
