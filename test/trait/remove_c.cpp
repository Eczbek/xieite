#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_c.hpp>

static_assert(xte::is_same<int, xte::remove_c<int>>);
static_assert(xte::is_same<int, xte::remove_c<const int>>);
static_assert(xte::is_same<volatile int, xte::remove_c<volatile int>>);
static_assert(xte::is_same<volatile int, xte::remove_c<volatile const int>>);
static_assert(xte::is_same<int&, xte::remove_c<const int&>>);
