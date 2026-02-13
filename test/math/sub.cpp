#include <xte/literal/fixed_int.hpp>
#include <xte/math/sub.hpp>
#include <xte/preproc/feature.hpp>

using namespace xte::literal::fixed_int;

static_assert(xte::sub(0) == 0);
static_assert(xte::sub(1) == 1);
static_assert(xte::sub(2) == 2);
static_assert(xte::sub(3) == 3);
static_assert(xte::sub(3, 2, 1) == 0);
static_assert(xte::sub(10, 9, 8, 7, 6, 5, 4, 3, 2, 1) == -35);
static_assert(xte::sub(0u, 1u) == -1u);
#if XTE_FEATURE_INT_8
static_assert(xte::sub(0_u8, 1_u8) == 255_u8);
#endif
