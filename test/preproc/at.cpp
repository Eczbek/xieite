#include <xte/preproc/at.hpp>

static_assert(XTE_AT(0)(1, 2, 3, 4, 5) == 1);
static_assert(XTE_AT(1)(1, 2, 3, 4, 5) == 2);
static_assert(XTE_AT(2)(1, 2, 3, 4, 5) == 3);
static_assert(XTE_AT(3)(1, 2, 3, 4, 5) == 4);
static_assert(XTE_AT(4)(1, 2, 3, 4, 5) == 5);
