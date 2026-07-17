#include <xte/trait/copy_lvalue_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_lvalue_ref<int, int>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int&&, int>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int, int&>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int&>>);
static_assert(xte::is_same<int, xte::copy_lvalue_ref<int&&, int&>>);
static_assert(xte::is_same<int&&, xte::copy_lvalue_ref<int, int&&>>);
static_assert(xte::is_same<int&, xte::copy_lvalue_ref<int&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_lvalue_ref<int&&, int&&>>);
