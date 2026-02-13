#include <xte/util/exchange.hpp>

static_assert(([] {
	bool x = false;
	return !xte::exchange(x, true) && x;
})());
