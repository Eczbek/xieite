#include <xte/trait/is_any.hpp>
#include <xte/trait/is_same.hpp>

static_assert(not xte::is_any<int>);
static_assert(xte::is_any<char, []<xte::is_same<int>> {}, []<xte::is_same<char>> {}>);
static_assert(not xte::is_any<void, []<xte::is_same<int>> {}, []<xte::is_same<char>> {}>);
