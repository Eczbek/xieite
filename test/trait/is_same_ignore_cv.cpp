#include <xte/trait/is_same_ignore_cv.hpp>

static_assert(xte::is_same_ignore_cv<int, int>);
static_assert(xte::is_same_ignore_cv<const int, int>);
static_assert(xte::is_same_ignore_cv<volatile int, int>);
static_assert(xte::is_same_ignore_cv<volatile const int, int>);
static_assert(xte::is_same_ignore_cv<int, const int>);
static_assert(xte::is_same_ignore_cv<const int, const int>);
static_assert(xte::is_same_ignore_cv<volatile int, const int>);
static_assert(xte::is_same_ignore_cv<volatile const int, const int>);
static_assert(xte::is_same_ignore_cv<int, volatile int>);
static_assert(xte::is_same_ignore_cv<const int, volatile int>);
static_assert(xte::is_same_ignore_cv<volatile int, volatile int>);
static_assert(xte::is_same_ignore_cv<volatile const int, volatile int>);
static_assert(xte::is_same_ignore_cv<int, volatile const int>);
static_assert(xte::is_same_ignore_cv<const int, volatile const int>);
static_assert(xte::is_same_ignore_cv<volatile int, volatile const int>);
static_assert(xte::is_same_ignore_cv<volatile const int, volatile const int>);

static_assert(!xte::is_same_ignore_cv<int, int&>);
