#include <xte/trait/add_rvalue_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int&&, xte::add_rvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::add_rvalue_ref<int&>>);
static_assert(xte::is_same<int&&, xte::add_rvalue_ref<int&&>>);
static_assert(xte::is_same<void, xte::add_rvalue_ref<void>>);
