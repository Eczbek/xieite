#include <xte/trait/is_assignable_to.hpp>

static_assert(xte::is_assignable_to<int, int&>);
static_assert(!xte::is_assignable_to<int, int>);

struct S { int operator=(S) &&; };

static_assert(!xte::is_assignable_to<S, S&>);
static_assert(xte::is_assignable_to<S, S>);
