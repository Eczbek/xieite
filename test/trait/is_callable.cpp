#include <xte/trait/is_callable.hpp>

static_assert(xte::is_callable<int()>);
static_assert(xte::is_callable<int(*)()>);
static_assert(xte::is_callable<int(&)()>);
static_assert(xte::is_callable<decltype([] {})>);

static_assert(not xte::is_callable<int>);
static_assert(not xte::is_callable<int decltype([] {})::*>);
