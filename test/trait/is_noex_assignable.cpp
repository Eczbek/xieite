#include <xte/trait/is_noex_assignable.hpp>

static_assert(xte::is_noex_assignable<int&, int>);
static_assert(!xte::is_noex_assignable<int, int>);

struct A { int operator=(A) && noexcept; };
struct B { int operator=(B) &&; };

static_assert(xte::is_noex_assignable<A, A>);
static_assert(!xte::is_noex_assignable<A&, A>);
static_assert(!xte::is_noex_assignable<B, B>);
static_assert(!xte::is_noex_assignable<B&, B>);
