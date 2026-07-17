#include <xte/trait/is_same.hpp>
#include <xte/util/as_not_const.hpp>

const int x = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_not_const(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_not_const(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<S&&, decltype(xte::as_not_const(S()))>);
