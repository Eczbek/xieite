#include <xte/math/diff.hpp>
#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>

static_assert(xte::diff(5, -5) == 10);
static_assert(xte::diff(xte::lowest<int>, xte::highest<int>) == xte::highest<unsigned int>);
