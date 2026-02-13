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
