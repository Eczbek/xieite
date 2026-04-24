#include <xte/data/fixed_array.hpp>
#include <xte/data/ptr_diff.hpp>

constexpr xte::fixed_array data = { 1, 2, 3 };
static_assert(xte::ptr_diff(data.begin(), data.end(), data.size()) == 3);
