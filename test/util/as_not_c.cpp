#include <xte/trait/is_same.hpp>
#include <xte/util/as_not_c.hpp>

const int x = 0;

static_assert(xte::is_same<int&&, decltype(xte::as_not_c(0))>);
static_assert(xte::is_same<int&, decltype(xte::as_not_c(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<S&&, decltype(xte::as_not_c(S()))>);
