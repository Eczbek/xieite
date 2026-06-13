#include <xte/trait/drop_vlref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_vlref<int>>);
static_assert(xte::is_same<int, xte::drop_vlref<int&>>);
static_assert(xte::is_same<int&&, xte::drop_vlref<int&&>>);
static_assert(xte::is_same<int, xte::drop_vlref<volatile int&>>);
