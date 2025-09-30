#include <xte/util/exchange.hpp>

static_assert(([] {
	bool x = false;
	return not xte::exchange(x, true) && x;
})());
