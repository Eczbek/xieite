#include <xte/limits.hpp>
#include <xte/math/diff.hpp>

static_assert(xte::diff(5, -5) == 10);
static_assert(xte::diff(xte::lowest<int>, xte::highest<int>) == xte::highest<unsigned int>);
