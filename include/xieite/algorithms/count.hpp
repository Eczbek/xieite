#pragma once
#include <cstddef> // std::size_t

namespace xieite::algorithms {
	template<typename... T>
	[[nodiscard]]
	constexpr std::size_t count(T&&...) noexcept {
		return sizeof...(T);
	}
}
