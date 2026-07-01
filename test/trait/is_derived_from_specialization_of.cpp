#include <xte/data/fixed_array.hpp>
#include <xte/trait/is_derived_from_specialization_of.hpp>

template<int>
struct A {};

struct B : A<0> {};

using C = B;

static_assert(xte::is_derived_from_specialization_of<C, ^^A>);
static_assert(!xte::is_derived_from_specialization_of<int, ^^A>);

static_assert(xte::is_derived_from_specialization_of<xte::fixed_array<int, 3>, ^^xte::fixed_array>);
