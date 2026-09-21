#include <xte/aliases.hpp>
#include <xte/func/repeat.hpp>

static_assert(([] {
	xte::uz x = 0;
	xte::repeat<5>([&]<xte::uz i> {
		x += i;
	});
	return x == 10;
})());

static_assert(noexcept(xte::repeat<0>([]<xte::uz> {})));
static_assert(!noexcept(xte::repeat<1>([]<xte::uz> {})));

// static_assert(3 == xte::repeat<3>([]<xte::uz>(int x) { return x + 1; }, 0));
