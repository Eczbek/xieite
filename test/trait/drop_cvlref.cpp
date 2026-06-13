#include <xte/trait/drop_cvlref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_cvlref<int>>);
static_assert(xte::is_same<int, xte::drop_cvlref<int&>>);
static_assert(xte::is_same<int&&, xte::drop_cvlref<int&&>>);
static_assert(xte::is_same<int, xte::drop_cvlref<volatile const int&>>);
