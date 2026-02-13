#include <xte/trait/is_same.hpp>
#include <xte/util/xvalue.hpp>

int x;

static_assert(xte::is_same<int&&, decltype(xte::xvalue(0))>);
static_assert(xte::is_same<int&&, decltype(xte::xvalue(x))>);
