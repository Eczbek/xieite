#include <xte/trait/drop_vrref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_vrref<int>>);
static_assert(xte::is_same<int&, xte::drop_vrref<int&>>);
static_assert(xte::is_same<int, xte::drop_vrref<int&&>>);
static_assert(xte::is_same<int&, xte::drop_vrref<volatile int&>>);
