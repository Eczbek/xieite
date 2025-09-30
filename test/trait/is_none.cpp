#include <xte/trait/is_none.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_none<int>);
static_assert(not xte::is_none<char, []<xte::is_same<int>> {}, []<xte::is_same<char>> {}>);
static_assert(xte::is_none<void, []<xte::is_same<int>> {}, []<xte::is_same<char>> {}>);
