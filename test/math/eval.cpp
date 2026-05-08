#include <xte/math/approx_equal.hpp>
#include <xte/math/eval.hpp>

static_assert(xte::eval<bool>("0 == 0"));
static_assert(xte::eval<bool>("!0"));
static_assert(xte::eval<int>("2 + 2 * 2") == 6);
static_assert(xte::eval<int>("pow(abs(-3.5) * 2, 3) - 1") == 342);
static_assert(xte::approx_equal(xte::eval<double>("0.1 + 0.2"), 0.3));
