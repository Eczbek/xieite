#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_vlref.hpp>

static_assert(xte::is_same<int, xte::remove_vlref<int>>);
static_assert(xte::is_same<int, xte::remove_vlref<int&>>);
static_assert(xte::is_same<int&&, xte::remove_vlref<int&&>>);
static_assert(xte::is_same<int, xte::remove_vlref<volatile int&>>);
