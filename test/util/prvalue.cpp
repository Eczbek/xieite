#include <xte/trait/is_same.hpp>
#include <xte/util/prvalue.hpp>

static_assert(xte::is_same<decltype((xte::prvalue(0))), int>);
