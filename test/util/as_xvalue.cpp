#include <xte/trait/is_same.hpp>
#include <xte/util/as_xvalue.hpp>

int x;

static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(0))>);
static_assert(xte::is_same<int&&, decltype(xte::as_xvalue(x))>);
