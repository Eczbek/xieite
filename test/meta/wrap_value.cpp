#include <xte/meta/wrap_value.hpp>
#include <compare>

static_assert([](int x) { return x; }(xte::wrap_value<0>()) == 0);
static_assert(xte::wrap_value<0>()() == 0);
static_assert(std::is_eq(xte::wrap_value<0>() <=> 0));
static_assert(xte::wrap_value<0>() == 0);
