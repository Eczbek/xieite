#include <xte/trait/is_same.hpp>
#include <xte/util/move.hpp>

int x;

static_assert(xte::is_same<int&&, decltype(xte::move(0))>);
static_assert(xte::is_same<int&&, decltype(xte::move(x))>);
