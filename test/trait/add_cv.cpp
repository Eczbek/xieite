#include <xte/trait/is_same.hpp>
#include <xte/trait/add_cv.hpp>

static_assert(xte::is_same<volatile const int, xte::add_cv<int>>);
static_assert(xte::is_same<volatile const int, xte::add_cv<const int>>);
static_assert(xte::is_same<volatile const int, xte::add_cv<volatile int>>);
static_assert(xte::is_same<volatile const int, xte::add_cv<volatile const int>>);
static_assert(xte::is_same<volatile const int&, xte::add_cv<int&>>);
