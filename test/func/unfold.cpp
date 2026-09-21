#include <xte/aliases.hpp>
#include <xte/func/unfold.hpp>

static_assert(10 == xte::unfold<5>([]<xte::uz... i> { return (... + i); }));

static_assert(noexcept(xte::unfold<0>([]<xte::uz...> noexcept {})));
