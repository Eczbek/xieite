#include <xte/trait/copy_lref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_lref<int, int>>);
static_assert(xte::is_same<int&, xte::copy_lref<int&, int>>);
static_assert(xte::is_same<int, xte::copy_lref<int&&, int>>);
static_assert(xte::is_same<int, xte::copy_lref<int, int&>>);
static_assert(xte::is_same<int&, xte::copy_lref<int&, int&>>);
static_assert(xte::is_same<int, xte::copy_lref<int&&, int&>>);
static_assert(xte::is_same<int&&, xte::copy_lref<int, int&&>>);
static_assert(xte::is_same<int&, xte::copy_lref<int&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_lref<int&&, int&&>>);
