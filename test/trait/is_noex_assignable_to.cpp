#include <xte/trait/is_noex_assignable_to.hpp>

static_assert(xte::is_noex_assignable_to<int, int&>);
static_assert(!xte::is_noex_assignable_to<int, int>);

struct A { int operator=(A) && noexcept; };
struct B { int operator=(B) &&; };

static_assert(xte::is_noex_assignable_to<A, A>);
static_assert(!xte::is_noex_assignable_to<A, A&>);
static_assert(!xte::is_noex_assignable_to<B, B>);
static_assert(!xte::is_noex_assignable_to<B, B&>);
