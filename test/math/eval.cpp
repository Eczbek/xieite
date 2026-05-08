#include <xte/math/approx_equal.hpp>
#include <xte/math/eval.hpp>

static_assert(xte::eval<bool>("0 == false"));
static_assert(xte::eval<bool>("!0"));
static_assert(xte::eval<int>("2 + 2 * 2") == 6);
static_assert(xte::eval<int>("pow(abs(-3.5) * 2, 3) - 1") == 342);
static_assert(xte::approx_equal(xte::eval<double>("0.1 + 0.2"), 0.3));
static_assert(xte::eval<bool>("pow(pow(2.3, 58), 1. / 58) == 2.3"));
static_assert(xte::eval<bool>("pow(33, 33) == 129110040087761027839616029934664535539337183380513"));
static_assert(xte::eval<bool>("floor(tau + pi) == 9"));
static_assert(xte::eval<bool>("inf > 9999999"));
static_assert(xte::eval<int>("true && 5") == 5);
static_assert(xte::eval<int>("false || 5") == 5);
