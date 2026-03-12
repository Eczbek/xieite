#include <xte/trait/is_constructible.hpp>

static_assert(xte::is_constructible<int>);
static_assert(xte::is_constructible<int, int>);
static_assert(!xte::is_constructible<int, int, int>);

struct S { S(int, char, float); };

static_assert(xte::is_constructible<S, int, char, float>);
static_assert(!xte::is_constructible<S>);
