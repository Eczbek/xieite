#include <xte/trait/is_same.hpp>
#include <xte/util/as_volatile.hpp>

int x;

static_assert(xte::is_same<volatile int&&, decltype(xte::as_volatile(0))>);
static_assert(xte::is_same<volatile int&, decltype(xte::as_volatile(x))>);

struct S {
	S() {}
	S(S&&) {}
	S(const S&) = delete;
};

static_assert(xte::is_same<volatile S&&, decltype(xte::as_volatile(S()))>);
