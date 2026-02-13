#include <xte/trait/add_cvlref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<volatile const int&, xte::add_cvlref<int>>);
static_assert(xte::is_same<volatile const int&, xte::add_cvlref<int&>>);
static_assert(xte::is_same<volatile const int&, xte::add_cvlref<int&&>>);
static_assert(xte::is_same<volatile const void, xte::add_cvlref<void>>);
