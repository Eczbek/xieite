#include <xte/trait/is_ctor.hpp>

static_assert(xte::is_ctor<int>);
static_assert(xte::is_ctor<int, int>);
static_assert(!xte::is_ctor<int, int, int>);

struct S { S(int, char, float); };

static_assert(xte::is_ctor<S, int, char, float>);
static_assert(!xte::is_ctor<S>);
