#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_v.hpp>

static_assert(xte::is_same<int, xte::remove_v<int>>);
static_assert(xte::is_same<const int, xte::remove_v<const int>>);
static_assert(xte::is_same<int, xte::remove_v<volatile int>>);
static_assert(xte::is_same<const int, xte::remove_v<volatile const int>>);
static_assert(xte::is_same<int&, xte::remove_v<volatile int&>>);
