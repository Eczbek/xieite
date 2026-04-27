#include <xte/math/approx_equal.hpp>
#include <xte/math/div_magnify_half.hpp>
#include <limits>

static_assert(xte::div_magnify_half(7, 2) == 4);
static_assert(xte::div_magnify_half(-7, 2) == -4);
static_assert(xte::div_magnify_half(7, -2) == -4);
static_assert(xte::div_magnify_half(-7, -2) == 4);

static_assert(xte::div_magnify_half(7, 3) == 2);
static_assert(xte::div_magnify_half(-7, 3) == -2);
static_assert(xte::div_magnify_half(7, -3) == -2);
static_assert(xte::div_magnify_half(-7, -3) == 2);

static_assert(xte::div_magnify_half(7, 4) == 2);
static_assert(xte::div_magnify_half(-7, 4) == -2);
static_assert(xte::div_magnify_half(7, -4) == -2);
static_assert(xte::div_magnify_half(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_magnify_half(7.0, 2), 4));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, 2), -4));
static_assert(xte::approx_equal(xte::div_magnify_half(7.0, -2), -4));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, -2), 4));

static_assert(xte::approx_equal(xte::div_magnify_half(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_magnify_half(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_magnify_half(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_magnify_half(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_magnify_half(-7.0, -4), 2));

static_assert(xte::div_magnify_half(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
