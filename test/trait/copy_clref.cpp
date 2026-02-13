#include <xte/trait/copy_clref.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_clref<char, int>>);
static_assert(xte::is_same<int, xte::copy_clref<char, const int>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char, int>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char, const int>>);
static_assert(xte::is_same<int, xte::copy_clref<char, int&>>);
static_assert(xte::is_same<int, xte::copy_clref<char, const int&>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char, int&>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_clref<char, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_clref<char, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_clref<const char, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_clref<const char, const int&&>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, int>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, const int>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, int>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, const int>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, int&>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, int&>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, const int&>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, int&&>>);
static_assert(xte::is_same<int&, xte::copy_clref<char&, const int&&>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, int&&>>);
static_assert(xte::is_same<const int&, xte::copy_clref<const char&, const int&&>>);
static_assert(xte::is_same<int, xte::copy_clref<char&&, int>>);
static_assert(xte::is_same<int, xte::copy_clref<char&&, const int>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char&&, int>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char&&, const int>>);
static_assert(xte::is_same<int, xte::copy_clref<char&&, int&>>);
static_assert(xte::is_same<int, xte::copy_clref<char&&, const int&>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char&&, int&>>);
static_assert(xte::is_same<const int, xte::copy_clref<const char&&, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_clref<char&&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_clref<char&&, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_clref<const char&&, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_clref<const char&&, const int&&>>);
