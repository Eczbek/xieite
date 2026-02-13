#include <xte/func/unfold.hpp>
#include <xte/util/types.hpp>

static_assert(xte::unfold<5>([]<xte::uz... i> {
	return (... + i);
}) == 10);

static_assert(noexcept(xte::unfold<0>([]<xte::uz...> noexcept {})));
