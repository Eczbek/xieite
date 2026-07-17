#include <xte/trait/is_callable.hpp>

static_assert(xte::is_callable<int(), void()>);
static_assert(xte::is_callable<int(*)(), void()>);
static_assert(xte::is_callable<int(&)(), void()>);
static_assert(xte::is_callable<decltype([]{}), void()>);
static_assert(xte::is_callable<void(int) noexcept, void(int) noexcept>);

static_assert(!xte::is_callable<int, void()>);
static_assert(!xte::is_callable<int decltype([]{})::*, void()>);
static_assert(!xte::is_callable<void(int), void(int) noexcept>);
