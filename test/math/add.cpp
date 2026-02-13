#include <xte/literal/fixed_int.hpp>
#include <xte/math/add.hpp>
#include <xte/preproc/feature.hpp>

using namespace xte::literal::fixed_int;

static_assert(xte::add(0) == 0);
static_assert(xte::add(1) == 1);
static_assert(xte::add(2) == 2);
static_assert(xte::add(3) == 3);
static_assert(xte::add(1, 2, 3) == 6);
static_assert(xte::add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);
static_assert(xte::add(-1u, 1u) == 0u);
#if XTE_FEATURE_INT_8
static_assert(xte::add(255_u8, 1_u8) == 0_u8);
#endif
