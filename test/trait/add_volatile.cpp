#include <xte/trait/is_same.hpp>
#include <xte/trait/add_volatile.hpp>

static_assert(xte::is_same<volatile int, xte::add_volatile<int>>);
static_assert(xte::is_same<volatile const int, xte::add_volatile<const int>>);
static_assert(xte::is_same<volatile int, xte::add_volatile<volatile int>>);
static_assert(xte::is_same<volatile const int, xte::add_volatile<volatile const int>>);
static_assert(xte::is_same<volatile int&, xte::add_volatile<int&>>);
static_assert(xte::is_same<volatile const int&, xte::add_volatile<const int&>>);
