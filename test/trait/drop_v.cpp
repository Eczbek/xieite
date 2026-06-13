#include <xte/trait/drop_v.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_v<int>>);
static_assert(xte::is_same<const int, xte::drop_v<const int>>);
static_assert(xte::is_same<int, xte::drop_v<volatile int>>);
static_assert(xte::is_same<const int, xte::drop_v<volatile const int>>);
static_assert(xte::is_same<int&, xte::drop_v<volatile int&>>);
