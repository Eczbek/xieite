#include <xte/trait/is_same.hpp>
#include <xte/trait/add_c.hpp>

static_assert(xte::is_same<const int, xte::add_c<int>>);
static_assert(xte::is_same<const int, xte::add_c<const int>>);
static_assert(xte::is_same<volatile const int, xte::add_c<volatile int>>);
static_assert(xte::is_same<volatile const int, xte::add_c<volatile const int>>);
static_assert(xte::is_same<const int&, xte::add_c<int&>>);
static_assert(xte::is_same<volatile const int&, xte::add_c<volatile int&>>);
