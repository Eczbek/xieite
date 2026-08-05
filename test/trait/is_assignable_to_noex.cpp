#include <xte/trait/is_assignable_to_noex.hpp>

static_assert(xte::is_assignable_to_noex<int, int&>);
static_assert(!xte::is_assignable_to_noex<int, int>);

struct A { int operator=(A) && noexcept; };
struct B { int operator=(B) &&; };

static_assert(xte::is_assignable_to_noex<A, A>);
static_assert(!xte::is_assignable_to_noex<A, A&>);
static_assert(!xte::is_assignable_to_noex<B, B>);
static_assert(!xte::is_assignable_to_noex<B, B&>);
