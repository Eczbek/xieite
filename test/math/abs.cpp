#include <xte/literal/fixed_int.hpp>
#include <xte/math/abs.hpp>
#include <limits>

static_assert(xte::abs(0) == 0);
static_assert(xte::abs(-1) == 1);
static_assert(xte::abs(std::numeric_limits<int>::lowest()) == (std::numeric_limits<int>::max() + 1u));

using namespace xte::literal::fixed_int;

static_assert(xte::abs(-99_i8) == 99_i8);
