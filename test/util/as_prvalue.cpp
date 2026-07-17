#include <xte/trait/is_same.hpp>
#include <xte/util/as_prvalue.hpp>

static_assert(xte::is_same<decltype((xte::as_prvalue(0))), int>);
