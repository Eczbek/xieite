#include <xte/func/noop.hpp>

constexpr struct {} x;

static_assert(xte::noop(0) == 0);
static_assert(&xte::noop(x) == &x);
