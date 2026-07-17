#include <xte/trait/is_same.hpp>
#include <xte/util/as_const.hpp>

int x;

static_assert(xte::is_same<const int&&, decltype(xte::as_const(0))>);
static_assert(xte::is_same<const int&, decltype(xte::as_const(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<const S&&, decltype(xte::as_const(S()))>);
