#include <xte/trait/is_assignable.hpp>

static_assert(xte::is_assignable<int&, int>);
static_assert(!xte::is_assignable<int, int>);

struct S { int operator=(S) &&; };

static_assert(!xte::is_assignable<S&, S>);
static_assert(xte::is_assignable<S, S>);
