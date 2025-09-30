#include <xte/preproc/wrapped.hpp>

static_assert(XTE_WRAPPED((0)));
static_assert(not XTE_WRAPPED(0));
