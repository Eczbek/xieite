#include <xte/data/opt.hpp>
#include <xte/util/as_xvalue.hpp>

struct A {
	A(int) {}
	A(A&&) = delete;
};

static_assert(requires { xte::opt<A>(0); });

static_assert(([] {
	xte::opt<int> x;
	return !x;
})());
static_assert(([] {
	xte::opt<int> x = 5;
	return !!x;
})());
static_assert(([] {
	xte::opt<int> x = 5;
	xte::opt<int> y = xte::as_xvalue(x);
	return !x && y;
})());

static_assert(xte::opt(5).and_then([](int x) { return x; }) == 5);
static_assert(xte::opt<int>().or_else([] { return 5; }) == 5);

struct B {
	int x = 1;
	constexpr int f() { return 2; }
};
static_assert(xte::opt<B>(B())->*&B::x == 1);
static_assert((xte::opt<B>(B())->*&B::f)() == 2);
