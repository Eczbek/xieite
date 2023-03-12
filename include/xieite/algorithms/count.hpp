#pragma once
#include <cstddef> // std::size_t

namespace xieite::algorithms {
	template<typename... TT>
	[[nodiscard]]
	constexpr std::size_t count(TT&&...) noexcept {
		return sizeof...(TT);
	}
}
