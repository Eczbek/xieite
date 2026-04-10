#include <xte/trait/add_unbounded_array.hpp>
#include <xte/trait/is_same.hpp>
#include <meta>

static_assert(xte::is_same<int[], xte::add_unbounded_array<int>>);
static_assert(!std::meta::can_substitute(^^xte::add_unbounded_array, { ^^void }));
static_assert(!std::meta::can_substitute(^^xte::add_unbounded_array, { ^^int[] }));
