#include <xte/trait/add_vrref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<volatile int&&, xte::add_vrref<int>>);
static_assert(xte::is_same<volatile int&, xte::add_vrref<int&>>);
static_assert(xte::is_same<volatile int&&, xte::add_vrref<int&&>>);
static_assert(xte::is_same<volatile void, xte::add_vrref<void>>);
