#include <xte/trait/drop_cvref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_cvref<int>>);
static_assert(xte::is_same<int, xte::drop_cvref<int&>>);
static_assert(xte::is_same<int, xte::drop_cvref<int&&>>);
static_assert(xte::is_same<int, xte::drop_cvref<volatile const int&>>);
