#pragma once

#include <tuple>
#include <type_traits>
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename... Args>
	[[nodiscard]] constexpr std::tuple<std::decay_t<Args>...> decayastup(Args&&... args) noexcept {
		return std::tuple<std::decay_t<Args>...>(X4FWD(args)...);
	}
}
