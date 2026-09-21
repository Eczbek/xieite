#include <xte/approx_equal.hpp>
#include <xte/limits.hpp>
#include <xte/math/div.hpp>

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

static_assert(xte::div_floor(xte::lowest<int>, -1, -1) == xte::lowest<int>);



static_assert(xte::div_ceil(7, 2) == 4);
static_assert(xte::div_ceil(-7, 2) == -3);
static_assert(xte::div_ceil(7, -2) == -3);
static_assert(xte::div_ceil(-7, -2) == 4);

static_assert(xte::div_ceil(7, 3) == 3);
static_assert(xte::div_ceil(-7, 3) == -2);
static_assert(xte::div_ceil(7, -3) == -2);
static_assert(xte::div_ceil(-7, -3) == 3);

static_assert(xte::div_ceil(7, 4) == 2);
static_assert(xte::div_ceil(-7, 4) == -1);
static_assert(xte::div_ceil(7, -4) == -1);
static_assert(xte::div_ceil(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_ceil(7.0, 2), 4));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, 2), -3));
static_assert(xte::approx_equal(xte::div_ceil(7.0, -2), -3));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, -2), 4));

static_assert(xte::approx_equal(xte::div_ceil(7.0, 3), 3));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_ceil(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, -3), 3));

static_assert(xte::approx_equal(xte::div_ceil(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, 4), -1));
static_assert(xte::approx_equal(xte::div_ceil(7.0, -4), -1));
static_assert(xte::approx_equal(xte::div_ceil(-7.0, -4), 2));

static_assert(xte::div_ceil(xte::lowest<int>, -1, -1) == xte::lowest<int>);



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



static_assert(xte::div_magnify(7, 2) == 4);
static_assert(xte::div_magnify(-7, 2) == -4);
static_assert(xte::div_magnify(7, -2) == -4);
static_assert(xte::div_magnify(-7, -2) == 4);

static_assert(xte::div_magnify(7, 3) == 3);
static_assert(xte::div_magnify(-7, 3) == -3);
static_assert(xte::div_magnify(7, -3) == -3);
static_assert(xte::div_magnify(-7, -3) == 3);

static_assert(xte::div_magnify(7, 4) == 2);
static_assert(xte::div_magnify(-7, 4) == -2);
static_assert(xte::div_magnify(7, -4) == -2);
static_assert(xte::div_magnify(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_magnify(7.0, 2), 4));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, 2), -4));
static_assert(xte::approx_equal(xte::div_magnify(7.0, -2), -4));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, -2), 4));

static_assert(xte::approx_equal(xte::div_magnify(7.0, 3), 3));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, 3), -3));
static_assert(xte::approx_equal(xte::div_magnify(7.0, -3), -3));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, -3), 3));

static_assert(xte::approx_equal(xte::div_magnify(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_magnify(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_magnify(-7.0, -4), 2));

static_assert(xte::div_magnify(xte::lowest<int>, -1, -1) == xte::lowest<int>);



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

static_assert(xte::div_floor_half(xte::lowest<int>, -1, -1) == xte::lowest<int>);



static_assert(xte::div_ceil_half(7, 2) == 4);
static_assert(xte::div_ceil_half(-7, 2) == -3);
static_assert(xte::div_ceil_half(7, -2) == -3);
static_assert(xte::div_ceil_half(-7, -2) == 4);

static_assert(xte::div_ceil_half(7, 3) == 2);
static_assert(xte::div_ceil_half(-7, 3) == -2);
static_assert(xte::div_ceil_half(7, -3) == -2);
static_assert(xte::div_ceil_half(-7, -3) == 2);

static_assert(xte::div_ceil_half(7, 4) == 2);
static_assert(xte::div_ceil_half(-7, 4) == -2);
static_assert(xte::div_ceil_half(7, -4) == -2);
static_assert(xte::div_ceil_half(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_ceil_half(7.0, 2), 4));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, 2), -3));
static_assert(xte::approx_equal(xte::div_ceil_half(7.0, -2), -3));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, -2), 4));

static_assert(xte::approx_equal(xte::div_ceil_half(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_ceil_half(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_ceil_half(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_ceil_half(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_ceil_half(-7.0, -4), 2));

static_assert(xte::div_ceil_half(xte::lowest<int>, -1, -1) == xte::lowest<int>);



static_assert(xte::div_trunc_half(7, 2) == 3);
static_assert(xte::div_trunc_half(-7, 2) == -3);
static_assert(xte::div_trunc_half(7, -2) == -3);
static_assert(xte::div_trunc_half(-7, -2) == 3);

static_assert(xte::div_trunc_half(7, 3) == 2);
static_assert(xte::div_trunc_half(-7, 3) == -2);
static_assert(xte::div_trunc_half(7, -3) == -2);
static_assert(xte::div_trunc_half(-7, -3) == 2);

static_assert(xte::div_trunc_half(7, 4) == 2);
static_assert(xte::div_trunc_half(-7, 4) == -2);
static_assert(xte::div_trunc_half(7, -4) == -2);
static_assert(xte::div_trunc_half(-7, -4) == 2);

static_assert(xte::approx_equal(xte::div_trunc_half(7.0, 2), 3));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, 2), -3));
static_assert(xte::approx_equal(xte::div_trunc_half(7.0, -2), -3));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, -2), 3));

static_assert(xte::approx_equal(xte::div_trunc_half(7.0, 3), 2));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, 3), -2));
static_assert(xte::approx_equal(xte::div_trunc_half(7.0, -3), -2));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, -3), 2));

static_assert(xte::approx_equal(xte::div_trunc_half(7.0, 4), 2));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, 4), -2));
static_assert(xte::approx_equal(xte::div_trunc_half(7.0, -4), -2));
static_assert(xte::approx_equal(xte::div_trunc_half(-7.0, -4), 2));

static_assert(xte::div_trunc_half(xte::lowest<int>, -1, -1) == xte::lowest<int>);


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

static_assert(xte::div_magnify_half(xte::lowest<int>, -1, -1) == xte::lowest<int>);
