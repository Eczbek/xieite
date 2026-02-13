#include <xte/preproc/fwd.hpp>
#include <xte/trait/is_same.hpp>

decltype(auto) f(auto&& arg) {
	return XTE_FWD(arg);
}

int x;

static_assert(xte::is_same<int&&, decltype(f(0))>);
static_assert(xte::is_same<int&, decltype(f(x))>);
