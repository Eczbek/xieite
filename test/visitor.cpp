#include <xte/visitor.hpp>

static_assert((xte::visitor {
	[](...) { return false; },
	[](int) { return true; }
})(0));
