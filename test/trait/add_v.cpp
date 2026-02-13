#include <xte/trait/is_same.hpp>
#include <xte/trait/add_v.hpp>

static_assert(xte::is_same<volatile int, xte::add_v<int>>);
static_assert(xte::is_same<volatile const int, xte::add_v<const int>>);
static_assert(xte::is_same<volatile int, xte::add_v<volatile int>>);
static_assert(xte::is_same<volatile const int, xte::add_v<volatile const int>>);
static_assert(xte::is_same<volatile int&, xte::add_v<int&>>);
static_assert(xte::is_same<volatile const int&, xte::add_v<const int&>>);
