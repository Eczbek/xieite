#include <xte/func/nop.hpp>

constexpr struct {} x;

static_assert(xte::nop(0) == 0);
static_assert(&xte::nop(x) == &x);
