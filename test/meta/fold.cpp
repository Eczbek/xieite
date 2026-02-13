#include <xte/meta/fold.hpp>
#include <xte/trait/is_same.hpp>

static_assert(xte::is_same<typename[:xte::fold<[]<decltype(auto) x, auto> {
	return ^^typename[:x:]*;
}, ^^int, 3>:], int***>);
