#include <xte/math/approx_equal.hpp>
#include <xte/math/exp_search.hpp>

static_assert(xte::exp_search<int>([](int x) { return x < 42; }) == 42);
static_assert(xte::exp_search([](int x) { return x < -42; }, -100, 100) == -42);
static_assert(xte::approx_equal(xte::exp_search<double>([](double x) { return x < 999.999; }), 999.999));
