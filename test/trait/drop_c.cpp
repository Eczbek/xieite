#include <xte/trait/drop_c.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_c<int>>);
static_assert(xte::is_same<int, xte::drop_c<const int>>);
static_assert(xte::is_same<volatile int, xte::drop_c<volatile int>>);
static_assert(xte::is_same<volatile int, xte::drop_c<volatile const int>>);
static_assert(xte::is_same<int&, xte::drop_c<const int&>>);
