module;

#include <xieite/forward.hpp>

export module xieite:containers.decayAsTuple;

import std;

export namespace xieite::containers {
	template<typename... Arguments>
	[[nodiscard]] constexpr std::tuple<std::decay_t<Arguments>...> decayAsTuple(Arguments&&... arguments) noexcept {
		return std::tuple<std::decay_t<Arguments>...>(XIEITE_FORWARD(arguments)...);
	}
}
