#include <xte/trait/add_array.hpp>
#include <xte/trait/is_same.hpp>
#include <meta>

static_assert(xte::is_same<int[1], xte::add_array<int, 1>>);
static_assert(xte::is_same<int[999], xte::add_array<int, 999>>);
static_assert(!std::meta::can_substitute(^^xte::add_array, { ^^int, std::meta::reflect_constant(0) }));
