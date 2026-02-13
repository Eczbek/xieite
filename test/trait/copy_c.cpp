#include <xte/trait/copy_c.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, xte::copy_c<char, int>>);
static_assert(xte::is_same<int, xte::copy_c<char, const int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char, int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char, const int>>);
static_assert(xte::is_same<int&, xte::copy_c<char, int&>>);
static_assert(xte::is_same<int&, xte::copy_c<char, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char, int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char, const int&&>>);
static_assert(xte::is_same<int, xte::copy_c<char&, int>>);
static_assert(xte::is_same<int, xte::copy_c<char&, const int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char&, int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char&, const int>>);
static_assert(xte::is_same<int&, xte::copy_c<char&, int&>>);
static_assert(xte::is_same<int&, xte::copy_c<char&, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char&, int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char&, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char&, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char&, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char&, const int&&>>);
static_assert(xte::is_same<int, xte::copy_c<char&&, int>>);
static_assert(xte::is_same<int, xte::copy_c<char&&, const int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char&&, int>>);
static_assert(xte::is_same<const int, xte::copy_c<const char&&, const int>>);
static_assert(xte::is_same<int&, xte::copy_c<char&&, int&>>);
static_assert(xte::is_same<int&, xte::copy_c<char&&, const int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char&&, int&>>);
static_assert(xte::is_same<const int&, xte::copy_c<const char&&, const int&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char&&, int&&>>);
static_assert(xte::is_same<int&&, xte::copy_c<char&&, const int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char&&, int&&>>);
static_assert(xte::is_same<const int&&, xte::copy_c<const char&&, const int&&>>);
