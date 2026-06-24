#include <xte/math/lowest.hpp>
#include <xte/math/rshift.hpp>
#include <xte/math/width.hpp>

static_assert(xte::rshift(0, 0) == 0);
static_assert(xte::rshift(1, 0) == 1);
static_assert(xte::rshift(1, 1) == 0);
static_assert(xte::rshift(1, 2) == 0);
static_assert(xte::rshift(255, 1) == 127);
static_assert(xte::rshift(255, 2) == 63);
static_assert(xte::rshift(255, 3) == 31);
static_assert(xte::rshift(255, 4) == 15);
static_assert(xte::rshift(255, 5) == 7);
static_assert(xte::rshift(255, 6) == 3);
static_assert(xte::rshift(255, 7) == 1);
static_assert(xte::rshift(255, 8) == 0);
static_assert(xte::rshift(xte::lowest<int>, xte::width<int>) == 0);

static_assert(xte::rshift(1, -1) == 2);
static_assert(xte::rshift(1, -2) == 4);
static_assert(xte::rshift(1, -3) == 8);
static_assert(xte::rshift(1, -static_cast<int>(xte::width<int>)) == 0);
