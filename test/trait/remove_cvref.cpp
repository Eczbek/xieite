#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_cvref.hpp>

static_assert(xte::is_same<int, xte::remove_cvref<int>>);
static_assert(xte::is_same<int, xte::remove_cvref<int&>>);
static_assert(xte::is_same<int, xte::remove_cvref<int&&>>);
static_assert(xte::is_same<int, xte::remove_cvref<volatile const int&>>);
