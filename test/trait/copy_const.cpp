#include <xte/trait/copy_const.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_const<char, int>>);
static_assert(xte::is_same<int, xte::copy_const<char, const int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char, int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char, const int>>);
static_assert(xte::is_same<int&, xte::copy_const<char, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char, int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char, const int&&>>);
static_assert(xte::is_same<int, xte::copy_const<char&, int>>);
static_assert(xte::is_same<int, xte::copy_const<char&, const int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char&, int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char&, const int>>);
static_assert(xte::is_same<int&, xte::copy_const<char&, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char&, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char&, int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char&, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char&, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char&, const int&&>>);
static_assert(xte::is_same<int, xte::copy_const<char&&, int>>);
static_assert(xte::is_same<int, xte::copy_const<char&&, const int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char&&, int>>);
static_assert(xte::is_same<const int, xte::copy_const<const char&&, const int>>);
static_assert(xte::is_same<int&, xte::copy_const<char&&, int&>>);
static_assert(xte::is_same<int&, xte::copy_const<char&&, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char&&, int&>>);
static_assert(xte::is_same<const int&, xte::copy_const<const char&&, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_const<char&&, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char&&, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_const<const char&&, const int&&>>);
