#include <xte/trait/is_same.hpp>
#include <xte/util/as_c.hpp>

int x;

static_assert(xte::is_same<const int&&, decltype(xte::as_c(0))>);
static_assert(xte::is_same<const int&, decltype(xte::as_c(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<const S&&, decltype(xte::as_c(S()))>);
