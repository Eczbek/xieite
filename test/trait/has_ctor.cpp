#include <xte/trait/has_ctor.hpp>

static_assert(xte::has_ctor<int>);
static_assert(xte::has_ctor<int, int>);
static_assert(not xte::has_ctor<int, int, int>);

struct S { S(int, char, float); };

static_assert(xte::has_ctor<S, int, char, float>);
static_assert(not xte::has_ctor<S>);
