#include <xte/trait/drop_rvalue_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_rvalue_ref<int>>);
static_assert(xte::is_same<int&, xte::drop_rvalue_ref<int&>>);
static_assert(xte::is_same<int, xte::drop_rvalue_ref<int&&>>);
static_assert(xte::is_same<const int, xte::drop_rvalue_ref<const int&&>>);
