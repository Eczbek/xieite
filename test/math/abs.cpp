#include <xte/math/abs.hpp>
#include <xte/math/highest.hpp>
#include <xte/math/lowest.hpp>
#include <xte/preproc/feature.hpp>
#include <xte/util/numbers.hpp>

static_assert(xte::abs(0) == 0);
static_assert(xte::abs(-1) == 1);
static_assert(xte::abs(xte::lowest<int>) == (xte::highest<int> + 1u));

#if XTE_FEATURE_INT_8
static_assert(xte::abs(xte::lowest<xte::i8>) == xte::u8(128));
#endif
