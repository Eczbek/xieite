#include <xte/identity.hpp>

constexpr struct {} x;

static_assert(xte::identity(0) == 0);
static_assert(&xte::identity(x) == &x);
