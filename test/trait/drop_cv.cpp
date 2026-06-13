#include <xte/trait/drop_cv.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_cv<int>>);
static_assert(xte::is_same<int, xte::drop_cv<const int>>);
static_assert(xte::is_same<int, xte::drop_cv<volatile int>>);
static_assert(xte::is_same<int, xte::drop_cv<volatile const int>>);
static_assert(xte::is_same<int&, xte::drop_cv<volatile const int&>>);
