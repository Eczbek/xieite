#pragma once

#include <concepts>
#include "../fn/visitor.hpp"
#include "../meta/t.hpp"

namespace xieite {
	template<typename... Ts>
	concept is_same_any = xieite::visitor(
		[](...) static {  return false; },
		[]<typename U, typename... Us>(xieite::t<U>, xieite::t<Us>...) static {  return (... || std::same_as<U, Us>); }
	)(xieite::t<Ts>()...);
}
