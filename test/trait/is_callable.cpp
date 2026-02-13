#include <xte/trait/is_callable.hpp>

static_assert(xte::is_callable<int(), void()>);
static_assert(xte::is_callable<int(*)(), void()>);
static_assert(xte::is_callable<int(&)(), void()>);
static_assert(xte::is_callable<decltype([] {}), void()>);

static_assert(!xte::is_callable<int, void()>);
static_assert(!xte::is_callable<int decltype([] {})::*, void()>);
