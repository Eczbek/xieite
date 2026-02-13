#include <xte/trait/is_same.hpp>
#include <xte/trait/remove_ref.hpp>

static_assert(xte::is_same<int, xte::remove_ref<int>>);
static_assert(xte::is_same<int, xte::remove_ref<int&>>);
static_assert(xte::is_same<int, xte::remove_ref<int&&>>);
static_assert(xte::is_same<const int, xte::remove_ref<const int&>>);
