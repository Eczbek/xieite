#include <xte/math/approx_equal.hpp>
#include <xte/math/wrap.hpp>
#include <limits>

static_assert(xte::wrap(0, 1, 3) == 3);
static_assert(xte::wrap(1, 1, 3) == 1);
static_assert(xte::wrap(2, 1, 3) == 2);
static_assert(xte::wrap(3, 1, 3) == 3);
static_assert(xte::wrap(4, 1, 3) == 1);

static_assert(xte::wrap(-2, 1, -1) == 1);
static_assert(xte::wrap(-1, 1, -1) == -1);
static_assert(xte::wrap(0, 1, -1) == 0);
static_assert(xte::wrap(1, 1, -1) == 1);
static_assert(xte::wrap(2, 1, -1) == -1);

static_assert(xte::approx_equal(xte::wrap(3.5, 3.5, 0), 3.5));
static_assert(xte::approx_equal(xte::wrap(4.5, 3.5, 0), 0));

constexpr auto min = std::numeric_limits<short>::min();
constexpr auto max = std::numeric_limits<short>::max();
static_assert(xte::wrap(0, 0, 0) == 0);
static_assert(xte::wrap(min, 0, 0) == 0);
static_assert(xte::wrap(max, 0, 0) == 0);
static_assert(xte::wrap(0, min, 0) == 0);
static_assert(xte::wrap(0, 0, max) == 0);
static_assert(xte::wrap(0, min, max) == 0);
static_assert(xte::wrap(min, 0, max) == 0);
static_assert(xte::wrap(max, 0, max) == max);
static_assert(xte::wrap(min, min, 0) == min);
static_assert(xte::wrap(max, min, 0) == -2);
static_assert(xte::wrap(min, min, max) == min);
static_assert(xte::wrap(max, min, max) == max);
static_assert(xte::wrap(min / 2 - 1, min / 2, 0) == 0);
static_assert(xte::wrap(min + 2, min, min + 1) == min);
