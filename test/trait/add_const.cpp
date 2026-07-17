#include <xte/trait/is_same.hpp>
#include <xte/trait/add_const.hpp>

static_assert(xte::is_same<const int, xte::add_const<int>>);
static_assert(xte::is_same<const int, xte::add_const<const int>>);
static_assert(xte::is_same<volatile const int, xte::add_const<volatile int>>);
static_assert(xte::is_same<volatile const int, xte::add_const<volatile const int>>);
static_assert(xte::is_same<const int&, xte::add_const<int&>>);
static_assert(xte::is_same<volatile const int&, xte::add_const<volatile int&>>);
