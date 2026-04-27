#include <xte/math/approx_equal.hpp>
#include <xte/math/div_floor_half.hpp>
#include <limits>

static_assert(xte::div_floor_half(7, 2) == 3);
static_assert(xte::div_floor_half(-7, 2) == -4);
static_assert(xte::div_floor_half(7, -2) == -4);
static_assert(xte::div_floor_half(-7, -2) == 3);

static_assert(xte::div_floor_half(7, 3) == 2);
static_assert(xte::div_floor_half(-7, 3) == -2);
static_assert(xte::div_floor_half(7, -3) == -2);
static_assert(xte::div_floor_half(-7, -3) == 2);

static_assert(xte::div_floor_half(7, 4) == 2);
static_assert(xte::div_floor_half(-7, 4) == -2);
static_assert(xte::div_floor_half(7, -4) == -2);
static_assert(xte::div_floor_half(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_floor_half(7.0, 2), 3));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, 2), -4));
static_assert(xte::approx_equal(xte::div_floor_half(7.0, -2), -4));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, -2), 3));

static_assert(xte::approx_equal(xte::div_floor_half(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_floor_half(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_floor_half(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_floor_half(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_floor_half(-7.0, -4), 2));

static_assert(xte::div_floor_half(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
