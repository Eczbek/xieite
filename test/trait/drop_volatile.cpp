#include <xte/trait/drop_volatile.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_volatile<int>>);
static_assert(xte::is_same<const int, xte::drop_volatile<const int>>);
static_assert(xte::is_same<int, xte::drop_volatile<volatile int>>);
static_assert(xte::is_same<const int, xte::drop_volatile<volatile const int>>);
static_assert(xte::is_same<int&, xte::drop_volatile<volatile int&>>);
