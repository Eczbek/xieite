#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_cv.hpp>

static_assert(xte::is_same<int, xte::remove_cv<int>>);
static_assert(xte::is_same<int, xte::remove_cv<const int>>);
static_assert(xte::is_same<int, xte::remove_cv<volatile int>>);
static_assert(xte::is_same<int, xte::remove_cv<volatile const int>>);
static_assert(xte::is_same<int&, xte::remove_cv<volatile const int&>>);
