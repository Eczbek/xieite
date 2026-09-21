#include <xte/approx_equal.hpp>
#include <xte/limits.hpp>
#include <xte/math/avg.hpp>

static_assert(xte::avg(2, 4) == 3);
static_assert(xte::avg(1, 2, 3, 4, 5) == 3);
static_assert(xte::avg(2, 3) == 2);
static_assert(xte::avg(-2, -3) == -2);
static_assert(xte::avg(xte::lowest<int>, xte::highest<int>) == -1);
static_assert(xte::approx_equal(xte::avg(2.0, 3.0), 2.5));

constexpr unsigned char n = 16;
static_assert(xte::avg(n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n) == n);
