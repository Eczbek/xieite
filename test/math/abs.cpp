#include <xte/math/abs.hpp>
#include <xte/preproc/feature.hpp>
#include <xte/util/types.hpp>
#include <limits>

static_assert(xte::abs(0) == 0);
static_assert(xte::abs(-1) == 1);
static_assert(xte::abs(std::numeric_limits<int>::lowest()) == (std::numeric_limits<int>::max() + 1u));

#if XTE_FEATURE_INT_8
static_assert(xte::abs(std::numeric_limits<xte::i8>::min()) == xte::u8(128));
#endif
