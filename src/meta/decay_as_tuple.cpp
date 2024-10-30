module;

#include <xieite/fwd.hpp>

export module xieite:decay_as_tuple;

import std;

export namespace xieite {
	template<typename... Args>
	[[nodiscard]] constexpr std::tuple<std::decay_t<Args>...> decay_as_tuple(Args&&... args) noexcept {
		return std::tuple<std::decay_t<Args>...>(XIEITE_FWD(args)...);
	}
}
