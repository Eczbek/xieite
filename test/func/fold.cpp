#include <xte/func/fold.hpp>

static_assert(15 == xte::fold([](int lhs, int rhs) { return lhs + rhs; }, 1, 2, 3, 4, 5));
