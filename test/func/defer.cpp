#include <xte/func/defer.hpp>

static_assert(([] {
	bool x = false;
	{
		xte::defer _ = [&] {
			x = true;
		};
	}
	return x;
})());
