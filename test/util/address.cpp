#include <xte/util/address.hpp>
#include <memory>

static_assert(([] {
	int x;
	return xte::address(x) == std::addressof(x);
})());
