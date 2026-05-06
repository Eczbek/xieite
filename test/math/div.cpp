#include <xte/literal/numbers.hpp>
#include <xte/math/div.hpp>
#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>
#include <xte/preproc/feature.hpp>

using namespace xte::literal::numbers;

static_assert(xte::div(0) == 0);
static_assert(xte::div(1) == 1);
static_assert(xte::div(2) == 2);
static_assert(xte::div(3) == 3);
static_assert(xte::div(1, 2) == 0);
static_assert(xte::div(64, 4, 2) == 8);
static_assert(xte::div(xte::highest<int>, -1) == (xte::lowest<int> + 1));
static_assert(xte::div(xte::lowest<int>, -1, -1) == xte::lowest<int>);
#if XTE_FEATURE_INT_8
static_assert(xte::div(255_u8, 2_u8) == 127_u8);
#endif
