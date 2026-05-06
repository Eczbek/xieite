#include <xte/math/lowest.hpp>
#include <xte/math/rshift.hpp>
#include <xte/math/width.hpp>

static_assert(xte::rshift(0, 0) == 0);
static_assert(xte::rshift(1, 0) == 1);
static_assert(xte::rshift(1, 1) == 0);
static_assert(xte::rshift(1, 2) == 0);

static_assert(xte::rshift(xte::lowest<int>, xte::width<int>) == 0);
