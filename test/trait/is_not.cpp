#include <xte/trait/is_not.hpp>
#include <xte/trait/is_same.hpp>

static_assert(not xte::is_not<int>);
static_assert(not xte::is_not<int, []<xte::is_same<int>> {}>);
static_assert(xte::is_not<char, []<xte::is_same<int>> {}>);
