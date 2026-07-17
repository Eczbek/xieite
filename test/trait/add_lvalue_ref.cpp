#include <xte/trait/add_lvalue_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int&, xte::add_lvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::add_lvalue_ref<int&>>);
static_assert(xte::is_same<int&, xte::add_lvalue_ref<int&&>>);
static_assert(xte::is_same<void, xte::add_lvalue_ref<void>>);
