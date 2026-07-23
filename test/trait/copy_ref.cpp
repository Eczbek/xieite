#include <xte/trait/copy_ref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<char, xte::copy_ref<int, char>>);
static_assert(xte::is_same<char, xte::copy_ref<int, char&>>);
static_assert(xte::is_same<char, xte::copy_ref<int, char&&>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char&>>);
static_assert(xte::is_same<char&, xte::copy_ref<int&, char&&>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char&>>);
static_assert(xte::is_same<char&&, xte::copy_ref<int&&, char&&>>);
