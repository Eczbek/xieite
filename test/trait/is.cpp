#include <xte/trait/is.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is<int>);
static_assert(xte::is<int, []<xte::is_same<int>> {}>);
static_assert(not xte::is<char, []<xte::is_same<int>> {}>);
