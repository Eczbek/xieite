#include <xte/trait/is_ptr.hpp>

static_assert(xte::is_ptr<int*>);
static_assert(!xte::is_ptr<int>);
static_assert(xte::is_ptr<int*, 0>);
static_assert(!xte::is_ptr<int*, 1>);
static_assert(!xte::is_ptr<int*, 3>);
static_assert(xte::is_ptr<int***, 2>);
