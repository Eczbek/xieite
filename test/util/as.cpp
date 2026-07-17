#include <xte/trait/is_same.hpp>
#include <xte/util/as.hpp>

struct S {};

int x;

static_assert(xte::is_same<volatile const int&&, decltype(xte::as<volatile const S>(0))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::as<volatile const S>(x))>);
static_assert(xte::is_same<volatile const int&, decltype(xte::as<volatile const S&>(0))>);
static_assert(xte::is_same<volatile const int&, decltype(xte::as<volatile const S&>(x))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::as<volatile const S&&>(0))>);
static_assert(xte::is_same<volatile const int&&, decltype(xte::as<volatile const S&&>(x))>);
