#include <xte/math/approx_equal.hpp>
#include <xte/math/eval.hpp>

static_assert(xte::eval<int>("2 + 2 * 2") == 6);
static_assert(xte::eval<int>("max(1, 2, 3)") == 3);

static_assert(xte::approx_equal(xte::eval<double>("pow(abs(-3.5) * 2, 3) - 1"), 342));
