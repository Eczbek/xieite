#include <xte/math/trailing_zeros.hpp>
#include <xte/math/width.hpp>
#include <limits>

static_assert(xte::trailing_zeros(0b0) == xte::width<int>);
static_assert(xte::trailing_zeros(0b1) == 0);
static_assert(xte::trailing_zeros(0b10) == 1);
static_assert(xte::trailing_zeros(0b100) == 2);
static_assert(xte::trailing_zeros(std::numeric_limits<int>::lowest()) == ~-xte::width<int>);
