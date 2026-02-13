#include <xte/math/rshift.hpp>
#include <xte/math/width.hpp>
#include <limits>

static_assert(xte::rshift(0, 0) == 0);
static_assert(xte::rshift(1, 0) == 1);
static_assert(xte::rshift(1, 1) == 0);
static_assert(xte::rshift(1, 2) == 0);

static_assert(xte::rshift(std::numeric_limits<int>::lowest(), xte::width<int>) == 0);
