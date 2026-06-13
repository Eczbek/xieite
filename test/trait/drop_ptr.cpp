#include <xte/trait/drop_ptr.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_ptr<int*>>);
static_assert(xte::is_same<int, xte::drop_ptr<int***, 3>>);
static_assert(xte::is_same<int*, xte::drop_ptr<int***, 2>>);
static_assert(xte::is_same<int***, xte::drop_ptr<int***, 0>>);
