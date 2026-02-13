#include <xte/math/leading_zeros.hpp>
#include <xte/math/width.hpp>
#include <limits>

static_assert(xte::leading_zeros(0) == xte::width<int>);
static_assert(xte::leading_zeros(1) == (xte::width<int> - 1));
static_assert(xte::leading_zeros(2) == (xte::width<int> - 2));
static_assert(xte::leading_zeros(4) == (xte::width<int> - 3));
static_assert(xte::leading_zeros(8) == (xte::width<int> - 4));
static_assert(xte::leading_zeros(16) == (xte::width<int> - 5));

static_assert(xte::leading_zeros(std::numeric_limits<int>::max()) == 1);
static_assert(xte::leading_zeros(std::numeric_limits<int>::lowest()) == 0);

static_assert(xte::leading_zeros(std::numeric_limits<unsigned int>::max()) == 0);
