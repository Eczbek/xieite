#include <xte/math/approx_equal.hpp>
#include <xte/math/wrap.hpp>

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

static_assert(xte::approx_equal(xte::wrap(3.5, 3.5), 3.5));
static_assert(xte::approx_equal(xte::wrap(4.5, 3.5), 0));
