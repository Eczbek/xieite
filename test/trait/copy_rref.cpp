#include <xte/trait/copy_rref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_rref<int, int>>);
static_assert(xte::is_same<int, xte::copy_rref<int&, int>>);
static_assert(xte::is_same<int&&, xte::copy_rref<int&&, int>>);
static_assert(xte::is_same<int&, xte::copy_rref<int, int&>>);
static_assert(xte::is_same<int&, xte::copy_rref<int&, int&>>);
static_assert(xte::is_same<int&&, xte::copy_rref<int&&, int&>>);
static_assert(xte::is_same<int, xte::copy_rref<int, int&&>>);
static_assert(xte::is_same<int, xte::copy_rref<int&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_rref<int&&, int&&>>);
