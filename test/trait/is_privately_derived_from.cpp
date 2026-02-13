#include <xte/trait/is_privately_derived_from.hpp>

struct A {};
struct B : private A {};
struct C : public A {};

static_assert(xte::is_privately_derived_from<B, A>);
static_assert(!xte::is_privately_derived_from<C, A>);
