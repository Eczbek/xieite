#include <xte/trait/is_specialization_of.hpp>

template<typename, auto>
struct A {};

static_assert(xte::is_specialization_of<A<int, 0>, ^^A>);
static_assert(!xte::is_specialization_of<A<int, 0>, ^^int>);
static_assert(!xte::is_specialization_of<int, ^^A>);
static_assert(!xte::is_specialization_of<int, ^^int>);
