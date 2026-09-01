#include <xte/preproc/count.hpp>

static_assert(XTE_COUNT() == 0);
static_assert(XTE_COUNT(a) == 1);
static_assert(XTE_COUNT(,,) == 3);
