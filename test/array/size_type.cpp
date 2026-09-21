#include <xte/aliases.hpp>
#include <xte/array.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<xte::array<int>::size_type, xte::uz>);
static_assert(xte::is_same<xte::array<int>::difference_type, xte::iptrdiff>);
