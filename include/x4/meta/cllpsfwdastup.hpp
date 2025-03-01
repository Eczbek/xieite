#pragma once

#include <tuple>
#include "../meta/cllpsfwd.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename T, typename... Args>
	[[nodiscard]] constexpr auto cllpsfwdastup(Args&&... args) noexcept {
		return std::forward_as_tuple(x4::cllpsfwd<T>(X4FWD(args))...);
	}
}
