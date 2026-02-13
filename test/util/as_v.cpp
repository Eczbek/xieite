#include <xte/trait/is_same.hpp>
#include <xte/util/as_v.hpp>

int x;

static_assert(xte::is_same<volatile int&&, decltype(xte::as_v(0))>);
static_assert(xte::is_same<volatile int&, decltype(xte::as_v(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<volatile S&&, decltype(xte::as_v(S()))>);
