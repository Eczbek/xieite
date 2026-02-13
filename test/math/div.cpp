#include <xte/literal/fixed_int.hpp>
#include <xte/math/div.hpp>
#include <xte/preproc/feature.hpp>
#include <limits>

using namespace xte::literal::fixed_int;

static_assert(xte::div(0) == 0);
static_assert(xte::div(1) == 1);
static_assert(xte::div(2) == 2);
static_assert(xte::div(3) == 3);
static_assert(xte::div(1, 2) == 0);
static_assert(xte::div(64, 4, 2) == 8);
static_assert(xte::div(std::numeric_limits<int>::min(), -1) == 0);
#if XTE_FEATURE_INT_8
static_assert(xte::div(255_u8, 2_u8) == 127_u8);
#endif
