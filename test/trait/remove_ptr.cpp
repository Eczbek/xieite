#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_ptr.hpp>

static_assert(xte::is_same<int, xte::remove_ptr<int*>>);
static_assert(xte::is_same<int, xte::remove_ptr<int***, 3>>);
static_assert(xte::is_same<int*, xte::remove_ptr<int***, 2>>);
static_assert(xte::is_same<int***, xte::remove_ptr<int***, 0>>);
