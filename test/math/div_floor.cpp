#include <xte/math/approx_equal.hpp>
#include <xte/math/div_floor.hpp>
#include <limits>

static_assert(xte::div_floor(7, 2) == 3);
static_assert(xte::div_floor(-7, 2) == -4);
static_assert(xte::div_floor(7, -2) == -4);
static_assert(xte::div_floor(-7, -2) == 3);

static_assert(xte::div_floor(7, 3) == 2);
static_assert(xte::div_floor(-7, 3) == -3);
static_assert(xte::div_floor(7, -3) == -3);
static_assert(xte::div_floor(-7, -3) == 2);

static_assert(xte::div_floor(7, 4) == 1);
static_assert(xte::div_floor(-7, 4) == -2);
static_assert(xte::div_floor(7, -4) == -2);
static_assert(xte::div_floor(-7, -4) == 1);

static_assert(xte::approx_equal(xte::div_floor(7.0, 2), 3));
static_assert(xte::approx_equal(xte::div_floor(-7.0, 2), -4));
static_assert(xte::approx_equal(xte::div_floor(7.0, -2), -4));
static_assert(xte::approx_equal(xte::div_floor(-7.0, -2), 3));

static_assert(xte::approx_equal(xte::div_floor(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_floor(-7.0, 3), -3));
static_assert(xte::approx_equal(xte::div_floor(7.0, -3), -3));
static_assert(xte::approx_equal(xte::div_floor(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_floor(7.0, 4), 1));
static_assert(xte::approx_equal(xte::div_floor(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_floor(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_floor(-7.0, -4), 1));

static_assert(xte::div_floor(std::numeric_limits<int>::min(), -1, -1) == std::numeric_limits<int>::min());
