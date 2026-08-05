#include <xte/data/array.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/number_types.hpp>

static_assert(xte::is_same<xte::array<int>::size_type, xte::uz>);
static_assert(xte::is_same<xte::array<int>::difference_type, xte::iptrdiff>);
