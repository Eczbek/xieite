#include <xte/preproc/if.hpp>

static_assert(XTE_IF(1)(true)(false));
static_assert(XTE_IF(0)(false)(true));
