#include <xte/abs.hpp>
#include <xte/aliases.hpp>
#include <xte/detect/feature.hpp>
#include <xte/limits.hpp>

static_assert(xte::abs(0) == 0);
static_assert(xte::abs(-1) == 1);
static_assert(xte::abs(xte::lowest<int>) == (xte::highest<int> + 1u));

#if XTE_HAS_INT_8
static_assert(xte::abs(xte::lowest<xte::i8>) == xte::u8(128));
#endif
