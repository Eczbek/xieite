#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_cvlref.hpp>

static_assert(xte::is_same<int, xte::remove_cvlref<int>>);
static_assert(xte::is_same<int, xte::remove_cvlref<int&>>);
static_assert(xte::is_same<int&&, xte::remove_cvlref<int&&>>);
static_assert(xte::is_same<int, xte::remove_cvlref<volatile const int&>>);
