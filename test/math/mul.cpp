#include <xte/literal/fixed_int.hpp>
#include <xte/math/mul.hpp>
#include <xte/preproc/feature.hpp>

using namespace xte::literal::fixed_int;

static_assert(xte::mul(0) == 0);
static_assert(xte::mul(1) == 1);
static_assert(xte::mul(2) == 2);
static_assert(xte::mul(3) == 3);
static_assert(xte::mul(1, 2, 3) == 6);
static_assert(xte::mul(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 3628800);
static_assert(xte::mul(-1u, 2u) == (-1u << 1));
#if XTE_FEATURE_INT_8
static_assert(xte::mul(255_u8, 2_u8) == 254_u8);
#endif
