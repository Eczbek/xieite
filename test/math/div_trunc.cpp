#include <xte/math/approx_equal.hpp>
#include <xte/math/div_trunc.hpp>
#include <xte/math/lowest.hpp>

static_assert(xte::div_trunc(7, 2) == 3);
static_assert(xte::div_trunc(-7, 2) == -3);
static_assert(xte::div_trunc(7, -2) == -3);
static_assert(xte::div_trunc(-7, -2) == 3);

static_assert(xte::div_trunc(7, 3) == 2);
static_assert(xte::div_trunc(-7, 3) == -2);
static_assert(xte::div_trunc(7, -3) == -2);
static_assert(xte::div_trunc(-7, -3) == 2);

static_assert(xte::div_trunc(7, 4) == 1);
static_assert(xte::div_trunc(-7, 4) == -1);
static_assert(xte::div_trunc(7, -4) == -1);
static_assert(xte::div_trunc(-7, -4) == 1);

static_assert(xte::approx_equal(xte::div_trunc(7.0, 2), 3));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, 2), -3));
static_assert(xte::approx_equal(xte::div_trunc(7.0, -2), -3));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, -2), 3));

static_assert(xte::approx_equal(xte::div_trunc(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_trunc(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_trunc(7.0, 4), 1));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, 4), -1));
static_assert(xte::approx_equal(xte::div_trunc(7.0, -4), -1));
static_assert(xte::approx_equal(xte::div_trunc(-7.0, -4), 1));

static_assert(xte::div_trunc(xte::lowest<int>, -1, -1) == xte::lowest<int>);
