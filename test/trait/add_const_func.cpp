#include <xte/trait/add_const_func.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int() const& noexcept, xte::add_const_func<int() & noexcept>>);
