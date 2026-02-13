#include <xte/trait/add_ptr.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int*, xte::add_ptr<int>>);
static_assert(xte::is_same<int, xte::add_ptr<int, 0>>);
static_assert(xte::is_same<int*, xte::add_ptr<int, 1>>);
static_assert(xte::is_same<int**, xte::add_ptr<int, 2>>);
static_assert(xte::is_same<int***, xte::add_ptr<int, 3>>);
