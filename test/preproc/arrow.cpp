#include <xte/preproc/arrow.hpp>

auto add(auto lhs, auto rhs) XTE_ARROW(lhs + rhs)

static_assert(requires { add(0, 0); });
static_assert(noexcept(add(0, 0)));
