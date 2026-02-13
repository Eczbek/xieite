#include <xte/func/unroll.hpp>
#include <xte/util/types.hpp>

static_assert(([] {
	xte::uz x = 0;
	xte::unroll<5>([&]<xte::uz i> {
		x += i;
	});
	return x == 10;
})());

static_assert(noexcept(xte::unroll<0>([]<xte::uz> {})));
static_assert(!noexcept(xte::unroll<1>([]<xte::uz> {})));
