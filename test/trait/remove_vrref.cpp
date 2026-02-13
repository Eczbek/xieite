#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_vrref.hpp>

static_assert(xte::is_same<int, xte::remove_vrref<int>>);
static_assert(xte::is_same<int&, xte::remove_vrref<int&>>);
static_assert(xte::is_same<int, xte::remove_vrref<int&&>>);
static_assert(xte::is_same<int&, xte::remove_vrref<volatile int&>>);
