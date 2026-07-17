#include <xte/trait/drop_const.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_const<int>>);
static_assert(xte::is_same<int, xte::drop_const<const int>>);
static_assert(xte::is_same<volatile int, xte::drop_const<volatile int>>);
static_assert(xte::is_same<volatile int, xte::drop_const<volatile const int>>);
static_assert(xte::is_same<int&, xte::drop_const<const int&>>);
