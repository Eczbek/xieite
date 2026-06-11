#include <xte/data/ptr.hpp>

static_assert(([] {
	bool x = false;
	for (bool y : xte::ptr<bool>::make(true)) {
		x = y;
	}
	return x;
})());

static_assert(([] {
	bool x = true;
	for (bool y : xte::ptr<bool>()) {
		x = y;
	}
	return x;
})());

static_assert(([] {
	bool x = false;
	for (bool y : xte::ptr<bool[]>::make(1, true)) {
		x = y;
	}
	return x;
})());

static_assert(([] {
	bool x = true;
	for (bool y : xte::ptr<bool[]>()) {
		x = y;
	}
	return x;
})());

struct A {
	int x = 1;
	constexpr int f() { return 2; }
};
static_assert(xte::ptr<A>::make()->*&A::x == 1);
static_assert((xte::ptr<A>::make()->*&A::f)() == 2);
