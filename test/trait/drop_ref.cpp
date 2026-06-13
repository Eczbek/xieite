#include <xte/trait/drop_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::drop_ref<int>>);
static_assert(xte::is_same<int, xte::drop_ref<int&>>);
static_assert(xte::is_same<int, xte::drop_ref<int&&>>);
static_assert(xte::is_same<const int, xte::drop_ref<const int&>>);
