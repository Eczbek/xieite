#include <xte/trait/add_vlref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<volatile int&, xte::add_vlref<int>>);
static_assert(xte::is_same<volatile int&, xte::add_vlref<int&>>);
static_assert(xte::is_same<volatile int&, xte::add_vlref<int&&>>);
static_assert(xte::is_same<volatile void, xte::add_vlref<void>>);
