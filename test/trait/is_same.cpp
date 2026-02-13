#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<int, int>);
static_assert(xte::is_same<const int, const int>);
static_assert(xte::is_same<int*, int*>);
static_assert(xte::is_same<int&, int&>);
static_assert(!xte::is_same<int, bool>);
static_assert(!xte::is_same<bool, int>);
static_assert(!xte::is_same<const int, int>);
static_assert(!xte::is_same<int, const int>);
static_assert(!xte::is_same<int*, int>);
static_assert(!xte::is_same<int, int*>);
static_assert(!xte::is_same<int&, int>);
static_assert(!xte::is_same<int, int&>);

static_assert(xte::is_same<int, int, int, int, int>);
static_assert(!xte::is_same<bool, int, int, int, int>);
static_assert(!xte::is_same<int, bool, int, int, int>);
static_assert(!xte::is_same<int, int, bool, int, int>);
static_assert(!xte::is_same<int, int, int, bool, int>);
static_assert(!xte::is_same<int, int, int, int, bool>);
